#include <SoftwareSerial.h>
//Servo
SoftwareSerial servoSerial(2,3);
int tempDormindo = 2000;
int LED = 0;
void setup()
{
  pinMode(13, OUTPUT);
  servoSerial.begin(2400);
  Serial.begin(2400);
}

void loop()
{
  float t1 = mediaTemperatura(A0);
  float t2 = mediaTemperatura(A1);
  float tensao = mediaTensao(A2);
  if(LED % 2 == 0)
  {
    analogWrite(6, 50);
  }
  else
  {
    analogWrite(6, 0);
  }
  LED++;
  
  
  String Stringao = ("ArduinoServo1@"+(String)t1 + "#" + (String)t2 + "$" + (String)tensao)+ "&";
  //Serial.println(Stringao);
  servoSerial.write(Stringao.c_str());
  Serial.println(Stringao);
 // LowPower.sleep(2000);

  delay(1000);
}
float mediaTemperatura(int porta)
{
  float media = 0.0;
  for(int i = 0; i < 20 ; i++)
  {
    media += ((analogRead(porta) * (5.0/1023)) - 0.5) * 100;
    
  }
  return media / 20;
}
float mediaTensao(int porta)
{
  float media = 0.0;
  for(int i = 0; i < 20 ; i++)
  {
    media += (analogRead(porta) * (5.0/1023)) *11;
    
  }
  return media / 20;
  
}
