#define CHARGER 0
#define LOCKER 1
/*int latchPin[2] = {8,4};
int clockPin[2] = {9,5};
int dataPin[2] = {10,6};*/
/***** Pin Declaration for Due *******/
/* Charger Control On 0 Bit
/*int latchPin[2] = {31,30};
int clockPin[2] = {33,32};
int dataPin[2] = {35,34};*/
/* Locker Control on 0 Bit */
int latchPin[2] = {30,31};
int clockPin[2] = {32,33};
int dataPin[2] = {34,35};
int nTotalLocker =16;// Must be 8 multiplier to create Packet
/*
 * 0    - All pin set to HIGH
 * 255  - All pin set to Low
 */
int nChargerStatus[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //All Charger Closed
int nSeq = 0;
void setup()
{
  Serial.begin(115200); 
  for(int i=0;i<2;i++) // Initialize Locker And Charger Register PIN 0- Charger, 1 - Locker
  {
    pinMode(dataPin[i], OUTPUT);
    pinMode(latchPin[i], OUTPUT);
    pinMode(clockPin[i], OUTPUT);       
    for(int j =0;j<(nTotalLocker/8);j++)
      sendDataToRegister(getLockerOFFCode(-1),i); //8 Bit Packet
  }
  Serial.println("Setup Completed. All Locker OFF");
}
//bool test = true;
void loop() 
{ 
  delay(5000);
  /*if(test)
  {
    Serial.println("Charger 2 ON ");  
    switchCharger(2,1); // Command To on Locker, ON          
    Serial.println("**********************************");  
    test =false;
  }*/
  /*for(int i=0;i<2;i++)
  {
    Serial.print("************Running Sequence : ");
    Serial.print(i);
    Serial.println("************");
    Serial.print("Register sequence : ");
    Serial.print(0);
    Serial.println("Status - All ON Sent");  
    sendDataToRegister(getLockerONCode(-1),0);
    Serial.print("Register sequence : ");
    Serial.print(1);
    Serial.println("Status - All ON Sent");
    sendDataToRegister(getLockerONCode(-1),1);
    delay(15000);
    Serial.print("Register sequence : ");
    Serial.print(0);
    Serial.println("Status - All OFF Sent");  
    sendDataToRegister(getLockerOFFCode(-1),0);  
    Serial.print("Register sequence : ");
    Serial.print(1);
    Serial.println("Status - All OFF Sent");
    sendDataToRegister(getLockerOFFCode(-1),1); 
    delay(15000);
  }*/
  
  if(Serial.available() > 0)
  {    
    //nSeq =0;
    if(nSeq <= 11)
    {
      switch(nSeq)
      {
        case 0:       
           Serial.println("Charger 2 ON ");  
           switchLocker(2,1);
           delay(7000);
           switchLocker(2,0);
           switchCharger(2,1); // Command To on Locker, ON          
           Serial.println("**********************************");  
           break;
        case 1:   
           Serial.println("Charger 2,4 ON "); 
           switchLocker(4,1);
           delay(7000);
           switchLocker(4,0);
           switchCharger(4,1); // Command To on Locker, ON  
           Serial.println("**********************************");            
           break;
        case 2:    
           Serial.println("Charger 2,4,6 ON ");
           switchLocker(6,1);
           delay(7000);
           switchLocker(1,0);
           switchCharger(6,1); // Command To on Locker, ON  
           Serial.println("**********************************"); 
           break;
        case 3:
           Serial.println("Charger 2,4,6,8 ON "); 
           switchLocker(8,1);
           delay(7000);
           switchLocker(8,0);
           switchCharger(8,1); // Command To on Locker, ON  
           Serial.println("**********************************"); 
           break;
        case 4:
           Serial.println("Charger 2,4,6,8,1 ON "); 
           switchLocker(1,1);
           delay(7000);
           switchLocker(1,0);
           switchCharger(1,1); // Command To on Locker, ON  
           Serial.println("**********************************"); 
           break;
        case 5:       
           Serial.println("Charger 10 ON ");  
           switchLocker(10,1);
           delay(7000);
           switchLocker(10,0);
           switchCharger(10,1); // Command To on Locker 
           Serial.println("**********************************");  
           break;
        case 6:   
           Serial.println("Charger 10,12 ON ");  
           switchLocker(12,1);
           delay(7000);
           switchLocker(12,0);
           switchCharger(12,1); // Command To on Locker 
           Serial.println("**********************************");  
           break;
        case 7:    
           Serial.println("Charger 10,12,14 ON ");
           switchLocker(14,1);
           delay(7000);
           switchLocker(14,0);
           switchCharger(14,1); // Command To on Locker             
           Serial.println("**********************************");  
           break;
        case 8:
           Serial.println("Charger 10,12,14,16 ON ");
           switchLocker(16,1);
           delay(7000);
           switchLocker(16,0);
           switchCharger(16,1); // Command To on Locker 
           Serial.println("**********************************");  
           break;
         case 9:
           Serial.println("Charger 10,12,14,16,9 ON ");
           switchLocker(9,1);
           delay(7000);
           switchLocker(9,0);
           switchCharger(9,1); // Command To on Locker 
           Serial.println("**********************************");  
           break;
        case 10:
          switchCharger(10,0); // Command To on Locker, OFF  
          delay(2000);
          switchCharger(12,0); // Command To on Locker, OFF  
          delay(2000);
          switchCharger(14,0); // Command To on Locker, OFF  
          delay(2000);
          switchCharger(16,0); // Command To on Locker, OFF
          delay(2000);
          switchCharger(9,0); // Command To on Locker, OFF         
          switchCharger(2,0); // Command To on Locker, OFF  
          delay(2000);
          switchCharger(4,0); // Command To on Locker, OFF  
          delay(2000);
          switchCharger(6,0); // Command To on Locker, OFF  
          delay(2000);
          switchCharger(8,0); // Command To on Locker, OFF  
          delay(2000);
          switchCharger(1,0); // Command To on Locker, OFF  
           /*Serial.println("All Charger OFF ");
           delay(500);
           nChargerStatus[12] = 0;
           nChargerStatus[14] = 0;
           nChargerStatus[8] = 0;
           nChargerStatus[11] = 0;
           sendDataToRegister(getLockerOFFCode(-1),1); */
           Serial.println("**********************************");
           break;   
      }  
      delay(1000);
      nSeq++;
    }
  }
}
void switchLocker(int LockerNo,uint8_t nCmd)//nCmd - 0- Close,1 - OPEN
{
  if(nCmd == 1)
    Serial.print("OPEN Command for Locker No");
  else
    Serial.print("CLOSE Command for Locker No");
  Serial.println(LockerNo);        
  int noBitPacket = nTotalLocker/8;
  int packetData[noBitPacket]; //8 bit Packet 
  for(int nPacketNo =0;nPacketNo < noBitPacket;nPacketNo++)//create no of packet data as per total locker
  {         
    packetData[nPacketNo] = getLockerOFFCode(-1); // initial All 8 BIT OFF         
    if(nPacketNo == 0 && ( LockerNo >=1 && LockerNo <=8)) // Command To Open Locker On First Register
    {
      if(nCmd)
        packetData[nPacketNo] = getLockerONCode(LockerNo);  
      else
        packetData[nPacketNo] |= getLockerOFFCode(LockerNo);  
    }   
    else if(nPacketNo == 1 && ( LockerNo >=9 && LockerNo <=16))// Command To Open Locker On Second Register
    {
      if(nCmd)
        packetData[nPacketNo] = getLockerONCode(LockerNo);   
      else
        packetData[nPacketNo] |= getLockerOFFCode(LockerNo);     
    }       
  } 
  int nMSBBit = (noBitPacket - 1);  
  for(int j=nMSBBit;j>=0;j--) //send Last Packet First (MSB to LSB)
  {
    Serial.print("Data Sent On register pos  ");
    Serial.print(j);
    Serial.print(" : ");
    Serial.println(packetData[j]);
    Serial.print(", binary  : ");
    Serial.println(packetData[j], BIN);
    sendDataToRegister(packetData[j],LOCKER) ; // turn on/off locker as per data
  }
}
void switchCharger(int LockerNo,uint8_t nON)//nOn - 0- OFF,1 - ON
{
  if(nON ==1)
     Serial.print("ON Command for Charger No");
  else
    Serial.print("OFF Command for Charger No");
  Serial.println(LockerNo);
  Serial.print("ALL CHARGER STATUS : ");
  for(int i =0;i<nTotalLocker;i++)
  {    
    if(nChargerStatus[i] == 1)
      Serial.print("1,");
    else
      Serial.print("0,");    
  }
  Serial.println();
  int noBitPacket = nTotalLocker/8;
  int nStart = 0;
  int nEnd=0;
  int packetData[noBitPacket]; //8 bit Packet 
  bool bCmdUpdate = false;
  for(int nPacketNo =0;nPacketNo<noBitPacket;nPacketNo++)//create no of packet data as per total locker
  {
    bCmdUpdate = false;
    nStart = nPacketNo*8;
    nEnd =nStart + 7;
    if(nPacketNo ==0)
    {
      Serial.println("Shift Register Selection 1 (Locker/Charger 1-8). StartPos - "); 
      Serial.print(nStart);
      Serial.print(" & EndPos - ");
      Serial.println(nEnd);        
      //nStart =0;
      //nEnd=7;
    }
    else if(nPacketNo == 1)
    {
      Serial.println("Shift Register Selection 2 (Locker/Charger 9-16). StartPos - "); 
      Serial.print(nStart);
      Serial.print(" & EndPos - ");
      Serial.println(nEnd);
      //nStart =8;
      //nEnd=15;
    }      
    packetData[nPacketNo] = getLockerOFFCode(-1); // initial All 8 BIT OFF
    for(int i =nStart;i<=nEnd;i++)
    {     
      if(nChargerStatus[i] == 1)//Check Charger ON Status
      {
        int nNo =i+1;   
        int nCurrentLockerCode = getLockerONCode(nNo);      
        /*Serial.print("Code : ");
        Serial.print(nCurrentLockerCode);
        Serial.print(", Binary : ");
        Serial.println(nCurrentLockerCode,BIN);*/
        packetData[nPacketNo] &= nCurrentLockerCode;
      }    
    }
    
    if(nPacketNo == 0 && ( LockerNo >=1 && LockerNo <=8)) // data update in first Packet
    {
	  bCmdUpdate = true;	  
    }   
    else if(nPacketNo == 1 && ( LockerNo >=9 && LockerNo <=16))// data update in Second Packet
    {
      bCmdUpdate = true;      
    }
	if(bCmdUpdate)
	{
      if(nON == 1) //Command To ON
      {
        nChargerStatus[LockerNo-1] = 1; // Charger is ON   
        packetData[nPacketNo] &= getLockerONCode(LockerNo);
      }
      else
      {  
        nChargerStatus[LockerNo-1] = 0; //Charger is OFF
        packetData[nPacketNo] |= getLockerOFFCode(LockerNo);             
      }
	}
  } 
  int nMSBBit = (noBitPacket-1);  
  for(int j=nMSBBit;j>=0;j--) //send Last Packet First (MSB to LSB)
  {
    Serial.print("Data Sent On register pos  ");
    Serial.print(j);
    Serial.print(" : ");
    Serial.println(packetData[j]);
    Serial.print(", binary  : ");
    Serial.println(packetData[j], BIN);
    sendDataToRegister(packetData[j],CHARGER) ; // turn on/off locker as per data
  }
}
int getLockerOFFCode(int receivelockno)//1
{
  int nLockerCode;
  switch(receivelockno)
  {
    case 1:
    case 9:
      nLockerCode = B00000001;
      break;
    case 2:
    case 10:
      nLockerCode =  B00000010;
      break;
    case 3:
    case 11:
      nLockerCode =  B00000100;
      break;
    case 4:
    case 12:
      nLockerCode =  B00001000;
      break;
    case 5:
    case 13:
      nLockerCode =  B00010000;
      break;
    case 6:
    case 14:
      nLockerCode =  B00100000;
      break;
    case 7:
    case 15:
      nLockerCode =  B01000000;
      break;
    case 8:
    case 16:
      nLockerCode =  B10000000;
      break;
    default: 
      nLockerCode =  B11111111; 
      break;                              
  } 
  //Serial.print("Binary OFF Code Return: ");
 // Serial.println(nLockerCode,BIN);
  return nLockerCode;  
}
int getLockerONCode(int receivelockno)//1
{
  int nCurrentLockerCode;
  switch(receivelockno)
  {
    case 1:
    case 9:      
      nCurrentLockerCode = B11111110;
      break;
    case 2:
    case 10:
       nCurrentLockerCode =  B11111101;
       break;
    case 3:
    case 11:
       nCurrentLockerCode =  B11111011;
       break;
    case 4:
    case 12:
       nCurrentLockerCode =  B11110111;
       break;
    case 5:
    case 13:
       nCurrentLockerCode =  B11101111;
       break;
    case 6:
    case 14:
       nCurrentLockerCode =  B11011111;
       break;
    case 7:
    case 15:
       nCurrentLockerCode =  B10111111;
       break;
    case 8:
    case 16:
       nCurrentLockerCode =  B01111111;
       break;
    default: 
       nCurrentLockerCode =  B00000000;  
       break;                             
  } 
 // Serial.print("Binary ON Code Return: ");
  //Serial.println(nCurrentLockerCode,BIN);
  return nCurrentLockerCode;
}
void sendDataToRegister(int rData, int nIndex) // turn on/off locker as per data
{  
  /*Serial.print("Commnad sent to Register : ");
  Serial.println(nIndex);
  Serial.print("RData : ");
  Serial.print(rData);
  Serial.print(", Binary : ");
  Serial.println(rData,BIN);*/
  digitalWrite(latchPin[nIndex], LOW);
  shiftOut(dataPin[nIndex], clockPin[nIndex],MSBFIRST, rData);
  digitalWrite(latchPin[nIndex], HIGH);
}
