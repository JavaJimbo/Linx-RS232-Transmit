' ServoRobotnik - Spin program for Prop Servo Rev 2 Board
'
' 7-25-2008 JBS:  First version just tests servos and HOST serial I/O
'                 Syntax: HOST.start(TX, RX, 0, BAUDRATE)
' 7-26-2008 JBS:  Implemented ATMEL memory read, write, page transfer,
'                 also MIDI I/O and HOST STX, ETX processing.
' 7-27-2008 JBS:  Implemented parsing routine. Converts ASCII to integers.
' 7-28-2008 JBS:  Full MIDI support for TASCAM and keyboard.
' 7-30-2008 JBS:  Got the Timer working pretty well.
' 8-1-2008 JBS:   Timer mode works with MIDI and sensing MIDI halts.
' 8-2-2008 JBS:   Implemented Ticks. For now, frames and ticks are incremented together
'                 for both TASCAM and TIMER modes.
'                 Stopping TASCAM is sensed by TIMER to set RunMode to HALT.
'
' 8-13-2008 JBS:   PrintTime now prints the current time in the format {H:M:S:F}    
' 8-14-2008 JBS:  Time transmitted as >{H:M:S:F} 30 times per second.
' 8-17-2008 JBS:  Works OK at 57600 baud with 2048 byte command buffer,
'                 Command buffer is then copied to data buffer.
' 9-16-2008 JBS:  "You've come to the right place, 9-16-2008" Version 1.0 saved.
' 9-27-2008 JBS:  Got rid of RunMode and Ticker. Now time is only sent out by MIDI.
' 9-28-2008 JBS:  Finally settled on updating time by quarterframes, and using frames
'                 to transmit time 30 times per second. Eliminated TimerCounter.
'                                                                                                                        


CON
    _clkmode = xtal1 + pll16x                               
    _xinfreq = 5_000_000                                'Note Clock Speed for your setup!!    
  CR = 13
  DLE = "\" 
  STX = ">"
  ETX = 13
  PanServo = 0                                        'Select DEMO servo to pan
  MAXBUFFER = 2048
  
  KEYBOARD = 2    
  MAXCODE = 9

  BAUDRATE = 57600
  
DAT
  strStartup        byte  "Look out there's a monster coming.",CR,0

VAR
  long Stack[64]
  long HostStack[64]
  long MIDIStack[64]
  long TestStack[16]
  long TimerStack[16]
  Byte HostCommandBuffer[MAXBUFFER]
  Byte HostDataBuffer[MAXBUFFER]
  long HostEscapeFlag
  Long HostIndex
  Byte ParseIndex
        
  Byte MIDIBuffer[MAXBUFFER]
  Byte MidiInByte
  Byte MidiOutByte  
  Byte MidiInPtr
  Byte MidiOutPtr
  Byte MIDIcount
  Byte MidiNote
  Byte MidiVelocity
  Byte MidiMode

  
  Word address
  Byte ReturnByte
  Byte ATMEL_Data_Out[MAXBUFFER]
  Byte ATMEL_Data_In[MAXBUFFER]
  Byte strPrintMe[32]
  Byte AtmelInByte
  Byte AtmelOutByte
  Word testPage
  Long CommandFlag
  Long PreviousMidiMode
  Byte TimeCodeIndex
  Byte QuarterFrames  
  Byte Frames
  Byte Seconds
  Byte PreviousFrames  
  Byte Minutes
  Byte Hours
  Long TimeCodeFlag
  long PushFlag
  Long StartTime
  Long DiffTime
  Long stringAddress

    
OBJ
  SERVO : "Servo32v3"
  HOST : "ExtendedHostSerial"
  MIDI : "ExtendedHostSerial"
  NUM  : "Numbers"       

PUB RobotnikServo

  MIDIcount:=0
  MidiOutPtr:=0
  MidiInPtr:=0
  MidiNote:=24
  
  TimeCodeIndex:=0
  TimeCodeFlag:=FALSE


  QuarterFrames:=0
  Frames:=0
  PreviousFrames:=0
  Seconds:=0
  
  Minutes:=0
  Hours:=0     
    
  HostEscapeFlag:=FALSE
  CommandFlag:=FALSE
  PushFlag:=FALSE
  ParseIndex:=0
  HostIndex:=0  

  'Preset ALL servos to center position
  SERVO.Set(27,1500)
  SERVO.Set(26,1500)
  SERVO.Set(25,1500)
  SERVO.Set(24,1500)

  SERVO.Set(19,1500)
  SERVO.Set(18,1500)
  SERVO.Set(17,1500)
  SERVO.Set(16,1500)

  cognew(RobotServo, @Stack)
  cognew(getHostBuffer, @HostStack)
  cognew(getMIDIBuffer, @MIDIStack)
  cognew(Timer, @TimerStack)
  
  HOST.str(@strStartup)  
  
  dira[15]~
  InitializeATMEL
  AtmelOutByte:=$77
  address:=0
  testPage:=1
  dira[2]~~
  
  'PUSHBUTTON ROUTINE GOES HERE
  repeat    
    If (INA[15]==0)
      If(PushFlag==FALSE)
        PushFlag:=TRUE
      Else
        PushFlag:=FALSE                                
      repeat while (INA[15]==0)

    '$$$$      
    If(CommandFlag==TRUE)                            
      HOST.str(@HostCommandBuffer)
      HOST.tx(CR)
      CommandFlag:=FALSE
'      HOST.str(String("Parsing...", CR))
'      ParseIndex:=0      
'      repeat while (CommandFlag==TRUE)
'        CommandFlag:=parseHostBuffer                              

    If TimeCodeFlag==TRUE
      TimeCodeFlag:=FALSE
      ProcessTimeCode
      PrintTime
      
    If (Frames<>PreviousFrames)
      PreviousFrames:=Frames
      PrintTime
      !outa[2] 

        
Pub   DelayMs (delayTime) | startCount, OneMs
      startCount:=cnt 
      OneMS:= clkfreq / 1_000
      repeat delayTime
        waitcnt(startCount += OneMs)      

'This routine prints the current time in the format {H:M:S:F}    
Pub PrintTime
      HOST.tx(">")
      
      stringAddress:=NUM.ToStr(Hours, NUM#DEC)
      BYTE[stringAddress][0]:="{"
      HOST.str(stringAddress)      

      stringAddress:=NUM.ToStr(Minutes, NUM#DEC)
      BYTE[stringAddress][0]:=":"
      HOST.str(stringAddress)

      stringAddress:=NUM.ToStr(Seconds, NUM#DEC)
      BYTE[stringAddress][0]:=":"
      HOST.str(stringAddress)                     

      stringAddress:=NUM.ToStr(Frames, NUM#DEC)
      BYTE[stringAddress][0]:=":"
      HOST.str(stringAddress)                           

      HOST.str(String("}"))      
      HOST.tx(CR)
                                  
Var
  Byte TestIndex
Pub MemoryTest
'      repeat TestIndex from 0 to 15
'        ATMEL_Data_Out[TestIndex]:=AtmelOutByte
'        AtmelOutByte++
'      HOST.str(String("Writing memory...", CR))        
'      ATMEL_Buffer_Write(address, 16)
'      ATMEL_Page_Program(testPage)      
      HOST.str(String("Reading memory...", CR))
      ATMEL_Page_Transfer(testPage)            
      ATMEL_Buffer_Read(address, 16)
      address++
      testPage++                           
      repeat TestIndex from 0 to 15
          AtmelInByte:=ATMEL_Data_In[TestIndex]
          HOST.str(NUM.ToStr(AtmelInByte, NUM#HEX))
          HOST.tx(" ")      

      

Pub RobotServo | Temp     
  SERVO.Start
  'Start Servo handler
  repeat              
    repeat temp from 1000 to 2000                  
      waitcnt (cnt+125_000)
      SERVO.Set(27,temp)
      SERVO.Set(26,temp)
      SERVO.Set(25,temp)
      SERVO.Set(24,temp)

      SERVO.Set(19,temp)
      SERVO.Set(18,temp)
      SERVO.Set(17,temp)
      SERVO.Set(16,temp)
                              
    repeat temp from 2000 to 1000
      waitcnt (cnt+125_000)
      SERVO.Set(27,temp)
      SERVO.Set(26,temp)
      SERVO.Set(25,temp)
      SERVO.Set(24,temp)

      SERVO.Set(19,temp)
      SERVO.Set(18,temp)
      SERVO.Set(17,temp)
      SERVO.Set(16,temp)


VAR
  Byte arraySize
PUB testArray(ptr)
  arraySize:=strsize(ptr)    
  repeat arraySize
    HOST.tx(byte[ptr++])

VAR
  Byte mask
  Byte Index

CON
  SPIout = 11
  SPIin = 10
  SPIclk = 12
  ATMEL_CS = 13
  ATMEL_BUSY = 14

PUB InitializeATMEL  
  dira[SPIout]~~
  dira[SPIin]~
  dira[SPIclk]~~
  dira[ATMEL_CS]~~
  dira[ATMEL_BUSY]~

  outa[SPIclk]:=0
  outa[SPIout]:=0
  outa[ATMEL_CS]:=1                    
      
PUB SendReceiveSPI(dataOut): dataIn 
  mask:=$80
  dataIn:=$00
  
  repeat Index from 0 to 7
    if((mask&dataOut)<>0)
      outa[SPIout]:=1
    else
      outa[SPIout]:=0
    'waitcnt (cnt+125_000)      
    outa[SPIclk]:=1
    
    if(ina[SPIin]==1)
      dataIn:=dataIn|mask
      
    mask:=mask>>1
    'waitcnt (cnt+125_000)      
    outa[SPIclk]:=0



VAR
  BYTE byteHIGH
  BYTE byteLOW
  BYTE dummy 
  WORD tempAddress
  WORD i  

PUB ATMEL_Buffer_Write(bufferAddress, numberOfBytes)       
  byteHIGH := 0
  byteLOW := 0

  tempAddress := bufferAddress
  byteLOW := tempAddress & $00FF
  tempAddress := tempAddress >> 8
  byteHIGH := tempAddress & $00FF

  outa[ATMEL_CS]:=0

  SendReceiveSPI($84)
  SendReceiveSPI($00)
  SendReceiveSPI(byteHIGH)
  SendReceiveSPI(byteLOW)            
  SendReceiveSPI($00)

  repeat i from 0 to numberOfBytes  
    dummy:=SendReceiveSPI(ATMEL_Data_Out[i])  

  outa[ATMEL_CS]:=1

VAR
  BYTE ByteIn

PUB ATMEL_Buffer_Read(bufferAddress, numberOfBytes)       
  byteHIGH := 0
  byteLOW := 0

  tempAddress := bufferAddress
  byteLOW := tempAddress & $00FF
  tempAddress := tempAddress >> 8
  byteHIGH := tempAddress & $00FF
                      
  outa[ATMEL_CS]:=0                                             

  SendReceiveSPI($D4)
  SendReceiveSPI($00)
  SendReceiveSPI(byteHIGH)
  SendReceiveSPI(byteLOW)
  SendReceiveSPI($00)
  SendReceiveSPI($00)          

  repeat i from 0 to numberOfBytes-1
    ByteIn:=SendReceiveSPI($00)
    ATMEL_Data_In[i]:=ByteIn              

  outa[ATMEL_CS]:=1


PUB ATMEL_Page_Program(page)
  tempAddress:=page<<3
  byteLOW:=tempAddress&$00F8
  tempAddress:=tempAddress>>8
  byteHIGH:=tempAddress&$00FF

  outa[ATMEL_CS]:=0  
  SendReceiveSPI($82)      
  SendReceiveSPI(byteHIGH)
  SendReceiveSPI(byteLOW)
  SendReceiveSPI($00)
  outa[ATMEL_CS]:=1

  repeat while (INA[ATMEL_BUSY]==0)    


PUB ATMEL_Page_Transfer(page)
  tempAddress:=page<<3
  byteLOW:=tempAddress&$00F8
  tempAddress:=tempAddress>>8
  byteHIGH:=tempAddress&$00FF

  outa[ATMEL_CS]:=0  
  SendReceiveSPI($53)
  SendReceiveSPI(byteHIGH)
  SendReceiveSPI(byteLOW)
  SendReceiveSPI($0) 
  outa[ATMEL_CS]:=1        

  repeat while (INA[ATMEL_BUSY]==0)

CON
  BACKSPACE = 8

VAR
  BYTE HostRxByte

'$$$$  
Pub getHostBuffer
    HOST.start(3, 4, 0, BAUDRATE)
    HOST.rxflush
    HostEscapeFlag:=FALSE
    HostIndex:=0
    
    repeat                                                                            
      HostRxByte:=HOST.Rx

      If(HostIndex<MAXBUFFER)
        HostCommandBuffer[HostIndex]:=HostRxByte
        HostIndex++      
      
      If(HostEscapeFlag==FALSE)      
        If (HostRxByte==DLE)
          HostEscapeFlag:=TRUE
          If (HostIndex > 0) 
            HostIndex--
        If (HostRxByte==STX)
          HostCommandBuffer[0]:=STX
          HostIndex:=1                 
        If (HostRxByte==ETX)
          HostCommandBuffer[HostIndex]:=0
          HostIndex++
          bytemove (@HostDataBuffer, @HostCommandBuffer, HostIndex)          
          HostIndex:=0
          CommandFlag:=TRUE               
      Else
        HostEscapeFlag:=FALSE          

      'If((HostRxByte==BACKSPACE)AND(HostIndex>0))
      '  HOST.tx(" ")
      '  HOST.tx(BACKSPACE)
      '  HostIndex--'            


Var
  Long ch
  Long command
  Byte stringIndex
  Byte stringBuffer[MAXBUFFER]
  Long commandError
  Long commaFlag
  Long macroEnable
  Long systemEnable
  Long boardEnable
  Long numberVal
  
Pub parseHostBuffer : moreCommands
  If (ParseIndex==0)
    macroEnable:=FALSE
    systemEnable:=FALSE
    boardEnable:=FALSE
    
  commandError:=0
  command:=0    
  stringIndex:=0
  commaFlag:=FALSE
  ch:=255
    
  Repeat While ((ch<>";")AND(ch<>0)AND(ParseIndex<MAXBUFFER))
    ch:=HostCommandBuffer[ParseIndex++]
    HOST.tx(ch)
    'Make sure all alpha chracters are UPPERCASE:
    ch:=convertToUpperCase(ch)

    If (ch==",")
      commaFlag:=TRUE

    'If character is letter or number, stick it in array:
    If (isAlphaNum(ch)==TRUE)
      If (stringIndex<MAXBUFFER)
        stringBuffer[stringIndex++]:=ch
    'Otherwise, if string is complete, process it:            
    ElseIf (stringIndex>0)
      stringBuffer[stringIndex]:=0
      stringIndex:=0
      'If first character is an ASCII "0" to "9",
      'assume stringBuffer contains an integer.
      'Convert that ASCII string to an integer now: 
      If (isNum(stringBuffer[0])==TRUE)
        numberVal:=asciiToInteger
      Else
        numberVal:=-1
      If ((command=="#")OR(command=="$")OR(command=="."))
        boardEnable:=processAlpha(command)
      ElseIf (command=="(")
        macroEnable:=processMacro(command)
      ElseIf (command=="%")
        systemEnable:=processSystem(command)        
      Else                             
        commandError:=processCommand(command)
            
    If (ch==":")
      commaFlag:=FALSE
    
    If (isCommand(ch)==TRUE)
      command:=ch
            
  If (ch==";")
    moreCommands:=TRUE
  Else
    moreCommands:=FALSE
    HostIndex:=0

'This checks an input string to see whether it is
'a valid name or number string, and returns TRUE
'if it is. It returns FALSE if an error
'is encountered. A valid name string must be
'preceded by a "$" if it is a puppet name,
'or a "." if it is a board name.                                                                    
Pub processAlpha(CommandCh) : resultFlag                     
  HOST.str(String(" Name received: "))
  HOST.str(@stringBuffer)
  HOST.tx(CR)

'This checks an input string to see whether it is
'a valid command string, and returns TRUE
'if it is. It returns FALSE if an error
'is encountered.                                                                    
Pub processCommand(CommandCh) : resultFlag
  HOST.str(String(" Command received: "))
  HOST.str(@stringBuffer)
  HOST.tx(CR)                     

'This checks an input string to see whether it is
'a valid MACRO, and returns TRUE
'if it is. It returns FALSE if an error
'is encountered.                                                                    
Pub processMACRO(CommandCh) : resultFlag                     
  HOST.str(String(" Macro received: "))
  HOST.str(@stringBuffer)
  HOST.tx(CR)

'This checks an input string to see whether it is
'a valid MACRO, and returns TRUE
'if it is. It returns FALSE if an error
'is encountered.                                                                    
Pub processSystem(CommandCh) : resultFlag                     
  HOST.str(String(" System received: "))
  HOST.str(@stringBuffer)
  HOST.tx(CR)
                                                                                                                                                                
'This returns TRUE if input character is A-Z or 0-9
'otherwise returns FALSE. All input characters
'should be uppercase, but lowercase is considered anyway
Pub isAlphaNum(testChar) : alphaResult
  If((testChar=>"A")AND(testChar=<"Z"))                                                        
    alphaResult:=TRUE    
  ElseIf((testChar=>"a")AND(testChar=<"z"))
    alphaResult:=TRUE    
  ElseIf((testChar=>"0")AND(testChar=<"9"))
    alphaResult:=TRUE    
  Else      
    alphaResult:=FALSE
    
'This routine identifies command characters
'and returns TRUE or FALSE 
Pub isCommand(inChar) : status
  case inChar
    "$","#",".","<","/","?","!","&","*","%","(",")","+","_","=","^","%","{","}","[","]","(",  ")" : status:=TRUE
    OTHER: status :=FALSE       
      
Pub convertToUpperCase(inChar) : uppercase
    If((inChar=>"a")AND(inChar=<"z"))
        uppercase:=inChar-32
    Else          
      uppercase:=inChar              

Var
  BYTE char
  BYTE digit
  BYTE digitIndex
  LONG powerOfTen
  LONG value
  LONG AsciiDigitFlag  
'This routine is called if stringBuffer[]
'has been filled with numeric digits 0-9
'It calculates and returns the positive decimal value.
'If an error is encountered, it returns -1      
Pub asciiToInteger : decimalValue
  AsciiDigitFlag:=TRUE
  'Find end of number string. Set digit  
  digitIndex:=0                       
  char:=255
  repeat while ((char<>0)AND(digitIndex<MAXBUFFER))
    char:=stringBuffer[digitIndex++]

  digitIndex--    

  powerOfTen:=1
  value:=0

  'Now, going backwards through string,
  'convert each character from ASCII to digit 0 to 9,
  'multiply times power of ten, and add to integer value.
  'If any character is not an ASCII to digit 0 to 9,
  'then set error flag.
  repeat while (digitIndex>0)
    digitIndex--
    char:=stringBuffer[digitIndex]
    If (isNum(char)==FALSE)
      AsciiDigitFlag:=FALSE      
    value:=value+(asciiToDigit(char)*powerOfTen)
    powerOfTen:=powerOfTen*10

  If (AsciiDigitFlag==FALSE)
    decimalValue:=-1
  Else          
    decimalValue:=value

'This returns TRUE if input character is ASCII 0-9
'otherwise returns FALSE.
Pub isNum(testChar) : numResult
  If((testChar=>"0")AND(testChar=<"9"))                                                        
    numResult:=TRUE
  Else
    numResult:=FALSE  

'This routine converts an ASCII numeric character
'to a value from 0 to 9. If it isn't an ASCII character
'from "0" to "9" it returns a -1 to indicate error.  
Pub asciiToDigit(inChar) : digitValue
  digitValue:=inChar-"0"  
  if((digitValue<0)OR(digitValue>9))
    digitValue:=-1 


Var
  Long TimerDelay
  Long TimeBase

Pub Timer
  TimerDelay:=clkfreq/120
  TimeBase:=cnt
  repeat
    waitcnt(TimeBase+=TimerDelay)
    If(PushFlag==TRUE)
      updateTime    
      
Pub updateTime
    QuarterFrames++
    Frames:=QuarterFrames/4
    If(QuarterFrames=>119)
      QuarterFrames:=0
      Seconds++
      If(Seconds>59)
        Seconds:=0
        Minutes++                  
      If(Minutes>59)
        Minutes:=0
        Hours++

'This routine is called when the TASCAM sends out a SMPTE time code string
'which is initiated by the MIDI F0 start digit and ends with F7.
'The string is always 10 digits long, including the F0 and F7,
'F0 is digit #0 and F7 is digit #9
'Hours, Minutes, Seconds, and Frames are digits #5,6,7,8                                                                   
Pub ProcessTimeCode
  Hours:=MIDIBuffer[5]
  If (Hours=>96)
    Hours:=Hours-96
  Minutes:=MIDIBuffer[6]
  Seconds:=MIDIBuffer[7]
  Frames:=MIDIBuffer[8]
  QuarterFrames:=Frames*4    



Pub getMIDIBuffer         
  MIDI.start(1, 0, 0, 31250)
  MIDI.rxflush
  MidiInPtr:=0
  repeat                                                                            
    MidiInByte:=MIDI.Rx

    If(MidiInByte==$F1)
      updateTime          
      TimeCodeFlag:=FALSE

    If(MidiInByte==$F7)
      TimeCodeFlag:=TRUE
    If (MidiInByte==$F0)
      MidiInPtr:=0                  
      MidioutPtr:=0
              
    If((MidiInByte<>$F1)AND(MidiInByte<>$FE))    
      MIDIBuffer[MidiInPtr]:=MidiInByte
      MidiInPtr++
      IF(MidiInPtr=>MAXBUFFER)
        MidiInPtr:=0                    

'    If (MidiMode==KEYBOARD)      
'      IF(MidiInByte<>$FE)
'        MIDIBuffer[MidiInPtr]:=MidiInByte
'        MidiInPtr++
'        IF(MidiInPtr=>MAXBUFFER)
'          MidiInPtr:=0

'    If((MidiInByte==$F1)AND(MidiMode<>RUN))
'      MidiMode:=RUN
'      HOST.str(String("Mode = RUN", CR))
'    ElseIf((MidiInByte==$F0)AND(MidiMode<>STOP))
'      MidiMode:=STOP
'      HOST.str(String("Mode = STOP", CR))      
'    ElseIf((MidiInByte==$FE)AND(MidiMode<>KEYBOARD))
'      MidiMode:=KEYBOARD
'      HOST.str(String("Mode = KEYBOARD", CR))
'      '!outa[2]           

'
'      If(MidiMode==KEYBOARD)      
'        If(MidiOutPtr==MAXBUFFER)
'          MidiOutPtr:=0
'        If (MidiOutByte&$80<>0)
'          MIDIcount:=0
'          HOST.tx(CR)        
'        Else  
'          MIDIcount++          
'        If MIDIcount>2   
'          HOST.tx(CR)
'          MIDIcount:=1             
'        HOST.str(NUM.ToStr(MidiOutByte, NUM#HEX))
'          HOST.tx(" ")
                                                