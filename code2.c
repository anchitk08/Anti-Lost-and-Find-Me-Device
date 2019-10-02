//*************************************************
int led = 13;
int buzzer = 10;
int inPin = 9;
int find_me_pin = 8;
unsigned long previousMillis=0;
char incomingByte;
int action_flag=0, invert_flag=0;

//*************************************************
void serialFlush(){
  while(Serial.available() > 0) {
    char t = Serial.read();
  }
}   
//*************************************************
void buzzer_led_beep()
{
  int i;
  for(i=1;i<=5;i++)
  {
    
    delay(500);
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
    delay(500);
  }
}
//*************************************************
void check_action_flag()
{
  if(action_flag==2)
  {
    if(invert_flag==0)
    { 
      invert_flag=1;
      digitalWrite(led, HIGH);
      digitalWrite(buzzer, HIGH);
    }
    else
    {
      invert_flag=0;
      digitalWrite(led, LOW);
      digitalWrite(buzzer, LOW);
    }
  }
  
  if(action_flag==1)
  {
    if(invert_flag==0)
    { 
      invert_flag=1;
      digitalWrite(led, HIGH);
      digitalWrite(buzzer, HIGH);
    }
    else
    {
      invert_flag=0;
      digitalWrite(led, LOW);
      digitalWrite(buzzer, LOW);
    }
  }
  else if(action_flag==0)
  {
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
  }
}
//*************************************************
void setup() 
{ 
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);  
  pinMode(inPin, INPUT);
  pinMode(find_me_pin, INPUT);
  digitalWrite(find_me_pin, HIGH);  
  digitalWrite(led, HIGH);
  digitalWrite(buzzer, HIGH);
  digitalWrite(inPin, HIGH);
  delay(500);
  digitalWrite(led, LOW);
  digitalWrite(buzzer, LOW);
}
//*************************************************
void loop()
{
  Serial.print("B");
  if (Serial.available() > 0)
  {
    incomingByte = Serial.read();
    if(incomingByte=='A')
    {
      previousMillis = millis();
      if(action_flag==2)
      {
      
      }
      else
      {
        action_flag=0;
      }
      serialFlush();
    }
    else
    {
      serialFlush();
    }
    
    if(incomingByte=='C')
    {
      action_flag=2;
    }
  }
  if(millis() - previousMillis > 5000)
  {
    //Serial.println("Not Detected !!!");
    if(action_flag==2)
    {
    
    }
    else
    {
      action_flag=1;
    }
  }
  
  if(digitalRead(inPin)==HIGH)
  {
    if(action_flag==2)
    {
    
    }
    else
    {
      action_flag=0;
    }
  }
  
  if(digitalRead(find_me_pin)==LOW)
  {
    delay(1000);
    Serial.print("D");  
    while(digitalRead(find_me_pin)==LOW);
  }
  
  check_action_flag();

  delay(100);
}
//*************************************************
