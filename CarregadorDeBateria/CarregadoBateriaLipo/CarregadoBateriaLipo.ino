#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int TMP = 15;
int cont = 0;
float R1 = 10000.0;
float R2 = 100000.0;
float mediaTemperatura;
float tensaoMedia;
float tensaoMedia2;
float tensaoMediaAnterior;
int multiplicador = 10;
int Led = 10;
//Corrente
int sensor = A2;
int valorSensor = 0;
float const multiplicadorCorrente = 0.0049;
float corrente = 0;


void setup() 
{
  pinMode(TMP, INPUT);
  pinMode(Led,OUTPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() 
{

  tensaoMedia = lerTencao(A0,20) * multiplicador;
  corrente = lerCorrente(sensor, 20);
  tensaoMedia2 = tensaoMedia +1;
  Serial.print("Tensao: ");
  Serial.print(tensaoMedia);
  Serial.print("\t corrente: ");
  Serial.println(corrente, 3);
  mediaTemperatura = lerTemperatura(TMP,20);
  Serial.print("\nTemperatura: ");
  Serial.println(mediaTemperatura);
  Serial.print("\n\n");
  digitalWrite(Led,HIGH);
  //LCD tensão
  lcd.setCursor(0,0); 
  lcd.print("Ten:");
  lcd.setCursor(0,1);
  lcd.print(tensaoMedia,2);
  lcd.setCursor(5,0); 
  lcd.print("Cor:");
  lcd.setCursor(5,1);
  lcd.print(corrente,2);
  lcd.setCursor(11,0); 
  lcd.print("Temp:");
  lcd.setCursor(11,1);
  lcd.print(mediaTemperatura,2);
  if(tensaoMediaAnterior > tensaoMedia2)
  {
    while(mediaTemperatura <= 50.0)
    {
      digitalWrite(Led,HIGH);
      mediaTemperatura = lerTemperatura(TMP,20);
      lcd.setCursor(11,0); 
     lcd.print("Temp:");
      lcd.setCursor(11,1);
    lcd.print(mediaTemperatura);

    }
    digitalWrite(Led,LOW);
    tensaoMediaAnterior = 0;
    delay(10000);
  }
   tensaoMediaAnterior = tensaoMedia;
  delay(1000);
}
 float lerTencao(int portaAnalogica, int amostras)
 {
   float valorAnalogico;
   float mediaTensao;
   float tensaoEntrada;
   
   for(int i = 0;i < amostras; i++)
   {
     valorAnalogico = analogRead(portaAnalogica);
     tensaoEntrada = (valorAnalogico * 5.0) / 1024;
     mediaTensao += tensaoEntrada / (R2/(R1+R2));
   }
   return mediaTensao / amostras;
 }

float lerTemperatura(int portaAnalogica, int amostras)
{
  float entrada;
  float temperatura;
  float mediaTemperatura;
  for(int i = 0;i < amostras; i++)
   {
      entrada = analogRead(TMP)*(5.0/1023);
      temperatura = (entrada - 0.5)*100;
       mediaTemperatura += temperatura;
   }
  return mediaTemperatura / amostras;  
}
float lerCorrente(int portaAnalogica, int amostras) {
  float valorCorrete;
  float somaCorrente;
  
  for (int i = 0; i < amostras; i++) {
    valorCorrete = analogRead(portaAnalogica) * multiplicadorCorrente;
    somaCorrente += valorCorrete;
  }
  return somaCorrente / amostras;
}
