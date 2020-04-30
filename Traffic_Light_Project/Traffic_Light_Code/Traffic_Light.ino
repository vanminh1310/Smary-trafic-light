// Traiffic Light (05-04-2017)

int sensorPin = A0; // Red Bright value from LDR sensor to Controll LED Street
int sensorValue = 0; // variable to store the value from the sensor
//----------------------
int PIN_0 = 12; // PIN_A
int PIN_1 = 1;  // PIN_B
int PIN_2 = 2;  // PIN_C
int PIN_3 = 3;  // PIN_D
int PIN_4 = 4;  // PIN_E
int PIN_5 = 5;  // PIN_F
int PIN_6 = 6;  // PIN_G
int S1_1 = 8;   // 7Segment1 D1
int S1_2 = 9;   // 7Segment1 D2
int S2_1 = 10;  // 7Segment2 D1
int S2_2 = 11;  // 7Segment2 D2

// Direction 1
int LED1 = 14;  // pin voltag LED Traffic Light (S1 Green)
int LED2 = 15;  // pin voltag LED Traffic Light (S1 Yellow)
int LED3 = 16;  // pin voltag LED Traffic Light (S1 Red)
int LED4 = 17;  // pin voltag LED Traffic Light (S1 Green Turn Left)
int LED5 = 18;  // pin voltag LED Traffic Light (S1 Red Turn Left)

// Direction 2
int LED6 = 30;  // pin voltag LED Traffic Light (S2 Green)
int LED7 = 31;  // pin voltag LED Traffic Light (S2 Yellow)
int LED8 = 32;  // pin voltag LED Traffic Light (S2 Red)
int LED9 = 33;  // pin voltag LED Traffic Light (S2 Green Turn Left)
int LED10 = 34; // pin voltag LED Traffic Light (S2 Red Turn Left)

int LED_Street1 = 40; // pin voltag LED Streat Light
int LED_Street2 = 41; // pin voltag LED Streat Light
int LED_Street3 = 42; // pin voltag LED Streat Light
int LED_Street4 = 43; // pin voltag LED Streat Light

int a1 = 0;     // index array in first segment digit 1
int a2 = 0;     // index array in first segment digit 2
int b1 = 0;     // index array in second segment digit 1
int b2 = 0;     // index array in second segment digit 1
int i = 0;
int j = 0;

int DELAY =1;  // Delay light segment
int TIME = 0;   // time loading

// Matrix Number of 7 segment
int Arduino_Pins[7] = {PIN_0, PIN_1, PIN_2, PIN_3, PIN_4, PIN_5, PIN_6};   // an array of pin numbers to which LEDs
int Segment_Pins[10][7] = {{0,0,0,0,0,0,1}, // 0
                           {1,0,0,1,1,1,1}, // 1
                           {0,0,1,0,0,1,0}, // 2
                           {0,0,0,0,1,1,0}, // 3
                           {1,0,0,1,1,0,0}, // 4
                           {0,1,0,0,1,0,0}, // 5
                           {0,1,0,0,0,0,0}, // 6
                           {0,0,0,1,1,1,1}, // 7
                           {0,0,0,0,0,0,0}, // 8
                           {0,0,0,0,1,0,0}, // 9
                           };

//================================================================================================================= void setup
void setup() 
{
  pinMode(PIN_0,OUTPUT);
  pinMode(PIN_1,OUTPUT);
  pinMode(PIN_2,OUTPUT);
  pinMode(PIN_3,OUTPUT);
  pinMode(PIN_4,OUTPUT);
  pinMode(PIN_5,OUTPUT);
  pinMode(PIN_6,OUTPUT);
  
  pinMode(S1_1,OUTPUT);
  pinMode(S1_2,OUTPUT);
  pinMode(S2_1,OUTPUT);
  pinMode(S2_2,OUTPUT);
  
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  pinMode(LED5,OUTPUT);
  
  pinMode(LED6,OUTPUT);
  pinMode(LED7,OUTPUT);
  pinMode(LED8,OUTPUT);
  pinMode(LED9,OUTPUT);
  pinMode(LED10,OUTPUT);
  
  pinMode(LED_Street1,OUTPUT);
  pinMode(LED_Street2,OUTPUT);
  pinMode(LED_Street3,OUTPUT);
  pinMode(LED_Street4,OUTPUT);

}
//-------------------------------------------- LDR 
void LDR_Sensor() // function Control Street Light
{
  sensorValue = analogRead(sensorPin);
    if (sensorValue < 100) // Street Light is bright
  {
    Serial.println("LED light on");
    digitalWrite(LED_Street1, HIGH);
    digitalWrite(LED_Street2, HIGH);
    digitalWrite(LED_Street3, HIGH);
    digitalWrite(LED_Street4, HIGH);
    //delay(1000);
  }
  else // Street Light is dark
  {
  digitalWrite(LED_Street1, LOW);
  digitalWrite(LED_Street2, LOW);
  digitalWrite(LED_Street3, LOW);
  digitalWrite(LED_Street4, LOW);
  }
}
//================================================================================================================= void s1d1
void s1d1()
{
    digitalWrite(S1_1,0);
    digitalWrite(S1_2,1);
    digitalWrite(S2_1,0);
    digitalWrite(S2_2,0);
    for(j=0;j<7;j++)  
    {      
      digitalWrite(Arduino_Pins[j],Segment_Pins[a1][j]);
      
    } // End J Loop
    delay(DELAY);
}
//================================================================================================================= void s1d2
void s1d2()
{
  //  Second Digit

    digitalWrite(S1_1,1);
    digitalWrite(S1_2,0);
    digitalWrite(S2_1,0);
    digitalWrite(S2_2,0);
    for(j=0;j<7;j++)  
    {      
      digitalWrite(Arduino_Pins[j],Segment_Pins[a2][j]);
      
    } // End J Loop
    delay(DELAY);
}
//================================================================================================================= void s2d1
void s2d1()
{
    digitalWrite(S1_1,0);
    digitalWrite(S1_2,0);
    digitalWrite(S2_1,0);
    digitalWrite(S2_2,1);
    for(j=0;j<7;j++)  
    {      
      digitalWrite(Arduino_Pins[j],Segment_Pins[b1][j]);
      
    } // End J Loop
    delay(DELAY);
}
//================================================================================================================= void s2d2
void s2d2()
{
    digitalWrite(S1_1,0);
    digitalWrite(S1_2,0);
    digitalWrite(S2_1,1);
    digitalWrite(S2_2,0);
    for(j=0;j<7;j++)  
    {      
      digitalWrite(Arduino_Pins[j],Segment_Pins[b2][j]);
      
    } // End J Loop
    delay(DELAY);
}
//================================================================================================================= void loop
void loop() 
{
  Serial.println(sensorValue);
//  digitalWrite(LED1,0);
//  digitalWrite(LED2,0);
//  digitalWrite(LED3,0);
//  digitalWrite(LED4,0);
//  digitalWrite(LED5,0);
//  digitalWrite(LED6,0);
  digitalWrite(LED7,0);
//  digitalWrite(LED8,0);
//  digitalWrite(LED9,0);
//  digitalWrite(LED10,0);
  
  int count = 0;
  //-----------------
  // 25 second (a2a1 = 25)
  a2 = 2; // digit 2
  a1 = 5; // digit 1
  //-----------------

  //-----------------
  // 51 second (b2b1 = 51)
  b2 = 5; // digit 2
  b1 = 1; // digit 1
  //-----------------
  
  // front 25 + 3
  // left 20 + 3
  
  for(i=50;i>=0;i--)
  {
    LDR_Sensor();
    count++;
    
    for(TIME=0;TIME<=250;TIME++)
    {
      //LDR_Sensor();
      s1d1();
      s1d2();
      s2d1();
      s2d2();    
    } // End Loop TIME

//---------------------------- conditional
      a1--;
      b1--;
      
    //----------------
      if(a1<0)
    {
      a1 = 9;
      a2--; 
    } // End If a1<9
    if(b1<0)
    {
      b1 = 9;
      b2--; 
    } // End If b1<9
    //-------------------------------------
    digitalWrite(LED8,1);
    digitalWrite(LED10,1);
    if (count < 25)
    {
    digitalWrite(LED1,1);
    digitalWrite(LED2,0);
    digitalWrite(LED3,0);
    digitalWrite(LED4,0);
    digitalWrite(LED5,1);
    }
  
   else if(count==25)
   {
    digitalWrite(LED1,0);
    digitalWrite(LED2,1);
    digitalWrite(LED3,0);
    digitalWrite(LED4,0);
    digitalWrite(LED5,1);
    a2 = 0;
    a1 = 3;    
   } // End if count== 20
  
   else if(count==28)
   {
    digitalWrite(LED1,0);
    digitalWrite(LED2,0);
    digitalWrite(LED3,1);
    digitalWrite(LED4,1);
    digitalWrite(LED5,0);
    a2 = 2; 
    a1 = 0;    
   }
      
   else if(count==48)
   {
    digitalWrite(LED1,0);
    digitalWrite(LED2,1);
    digitalWrite(LED3,0);
    digitalWrite(LED4,0);
    digitalWrite(LED5,0);
    a2 = 0;
    a1 = 3;    
   } // End if count==21

  } // End i Loop 35 

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//  digitalWrite(LED1,0);
  digitalWrite(LED2,0);
//  digitalWrite(LED3,0);
//  digitalWrite(LED4,0);
//  digitalWrite(LED5,0);
//  digitalWrite(LED6,0);
//  digitalWrite(LED7,0);
//  digitalWrite(LED8,0);
//  digitalWrite(LED9,0);
//  digitalWrite(LED10,0);
  
  count = 0;
  a2 = 5; // dob
  a1 = 1; // reay
  
  b2 = 2; // dob
  b1 = 5; // reay
  
  // front 25 + 3
  // left 20 + 3
  
  for(i=50;i>=0;i--)
  {
    LDR_Sensor();
    count++;
    
    for(TIME=0;TIME<=250;TIME++)
    {
      //LDR_Sensor();
      s1d1();
      s1d2();
      s2d1();
      s2d2();    
    } // End Loop TIME

//---------------------------- conditional
      a1--;
      b1--;
      
    //----------------
      if(a1<0)
    {
      a1 = 9;
      a2--; 
    } // End If a1<9
    if(b1<0)
    {
      b1 = 9;
      b2--; 
    } // End If b1<9
    //-------------------------------------
    digitalWrite(LED3,1);
    digitalWrite(LED5,1);
    if (count < 25)
    {
    digitalWrite(LED6,1);
    digitalWrite(LED7,0);
    digitalWrite(LED8,0);
    digitalWrite(LED9,0);
    digitalWrite(LED10,1);
    }
  
   else if(count==25)
   {
    digitalWrite(LED6,0);
    digitalWrite(LED7,1);
    digitalWrite(LED8,0);
    digitalWrite(LED9,0);
    digitalWrite(LED10,1);
    b2 = 0;
    b1 = 3;    
   } // End if count== 20
  
   else if(count==28)
   {
    digitalWrite(LED6,0);
    digitalWrite(LED7,0);
    digitalWrite(LED8,1);
    digitalWrite(LED9,1);
    digitalWrite(LED10,0);
    b2 = 2; 
    b1 = 0;    
   }
      
   else if(count==48)
   {
    digitalWrite(LED6,0);
    digitalWrite(LED7,1);
    digitalWrite(LED8,0);
    digitalWrite(LED9,0);
    digitalWrite(LED10,0);
    b2 = 0;
    b1 = 3;    
   } // End if count==21

  } // End i Loop 35 

}
//=================================================================================================================
