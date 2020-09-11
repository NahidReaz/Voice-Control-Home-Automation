#include <SoftwareSerial.h>
SoftwareSerial BLU(0,1);
String voice;
int Blue   = 2;  //Connect To Pin #2 
int Green  = 3;  //Connect To Pin #3 
int White = 4;  //Connect To Pin #4 
int Red    = 5;  //Connect To Pin #5 
 
void allon()
{
     
  digitalWrite(Red, HIGH); 
     
  digitalWrite(White, HIGH); 
     
  digitalWrite(Green, HIGH); 
     
  digitalWrite(Blue, HIGH); 
     
}
void alloff()
{
     
  digitalWrite(Red, LOW); 
     
  digitalWrite(White, LOW); 
     
  digitalWrite(Green, LOW); 
     
  digitalWrite(Blue, LOW); 
     
}
void setup() 
{
  
  Serial.begin(9600);
    
  BLU.begin(9600);
    
  pinMode(Red, OUTPUT); 
  
  pinMode(White, OUTPUT); 
  
  pinMode(Green, OUTPUT); 
  
  pinMode(Blue, OUTPUT); 
  
}
void loop() 
{
  
  while (Serial.available())     //Check if there is an available byte to read
  {   
    delay(10);                   //Delay added to make thing stable 
  
    char c = Serial.read();      //Conduct a serial read
  
    if (c == '#') 
    {
      break;                     //Exit the loop when the # is detected after the word
 
    }   
    voice += c; 
 
  }  
  
  if (voice.length() > 0) 
  {
    if(voice == "*turn on all LED") 
    {
      allon();
    }  
    else if(voice == "*turn off all LED")
    {
      alloff();
    } 
    else if(voice == "*switch on red") 
    {
      digitalWrite(Red,HIGH);
    } 
  
    else if(voice == "*switch on white") 
    {
      digitalWrite(White,HIGH);
    }
  
    else if(voice == "*switch on green") 
    {
      digitalWrite(Green,HIGH);
    }
  
    else if(voice == "*switch on blue") 
    {
      digitalWrite(Blue,HIGH);
    }
     else if(voice == "*switch off red") 
    {
      digitalWrite(Red,LOW);
    } 
  
    else if(voice == "*switch off white") 
    {
      digitalWrite(White,LOW);
    }
  
    else if(voice == "*switch off green") 
    {
      digitalWrite(Green,LOW);
    }
  
    else if(voice == "*switch off blue") 
    {
      digitalWrite(Blue,LOW);
    }
    voice="";            //Reset variable
  }
}
