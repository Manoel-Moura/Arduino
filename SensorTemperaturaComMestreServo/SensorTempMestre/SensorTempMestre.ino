#include <LiquidCrystal.h>

#include <SoftwareSerial.h>
//Mestre
SoftwareSerial mestreSerial(2, 3);
LiquidCrystal lcd(12, 11, 5, 4, 10, 9);
String entrada ;
String sensorTemp1 = "";
String sensorTemp2 = "";
String tensao = "";
String stringLCD = "";
String nServo = "";
void setup()
{
  lcd.begin(16, 2);
  Serial.begin(2400);
  pinMode(13, OUTPUT);
  mestreSerial.begin(2400);
  lcd.print("T-1   T-2   Ten");


}
//LowPower.sleep();
void loop()
{
  entrada = "";
  stringLCD = "";
  if (mestreSerial.available())
  {
    while (true)
    {
      char letra = (char)mestreSerial.read();
      if (letra != '&' && letra != 'ÿ') {
        entrada += letra;
      } else {
        break;
      }
    }
  }
  if (!entrada.equals(""))
  {
    Serial.println(entrada);
  }

  quebraStringao(entrada);
  //Concatenando uma String para o LCD
    for (int i = 0; i <  entrada.length(); i++)
  {
    if(entrada.charAt(i) == '#' || entrada.charAt(i) == '$')
    {
      stringLCD += " ";
    }
     else if (entrada.charAt(i) == '@')
    {
      stringLCD = "";
    }
    else
    {
      stringLCD += entrada.charAt(i);
    }
  }
  //LCD
  if (!stringLCD.equals(""))
  {
  lcd.setCursor(0, 1);
  lcd.print(stringLCD);
  }
  //Monitor Serial
  if (!sensorTemp1.equals(""))
  {
  Serial.print("\n\n");
  Serial.print(nServo);
    
  Serial.print("\nTemp1 ");
  Serial.println(sensorTemp1);

  Serial.print("Temp2: ");
  Serial.println(sensorTemp2);

  Serial.print("tensao: ");
  Serial.println(tensao);
  Serial.println("\n");
  }

  delay(1000);
}

void quebraStringao(String entradaServo)
{
  String palavra = "";
  for (int i = 0; i <  entradaServo.length(); i++)
  {
    if (entradaServo.charAt(i) == '@')
    {
      nServo = palavra;
      palavra = "";
    }
    else if(entradaServo.charAt(i) == '#')
    {
      sensorTemp1 = palavra;
      palavra = "";
    }
    else if (entradaServo.charAt(i) == '$')
    {
      sensorTemp2 = palavra;
      palavra = "";
    }
    else
    {
      palavra += entradaServo.charAt(i);
    }

  }
  tensao = palavra;
}
