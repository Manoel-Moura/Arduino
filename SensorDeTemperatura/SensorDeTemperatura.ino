#define pino A0 //define a porta a ser lida

float temperatura = 0.0; // variavel para armazenar a temperatura
float temperaturaAnterior = 0.0; // variavel para armazenar a temperatura anterior
int amostra = 10;        // numero de amostras a serem lidas, para almentar a presição

void setup() {
 Serial.begin(9600);  // iniciando o terminal

}

void loop() {

  temperatura = mediaTemperatura(amostra); // variavel temperatura recebe o retorna da minha função de media de temperatura
  if(temperatura != temperaturaAnterior){
    temperaturaAnterior = temperatura;
    //Serial.print("Temperatura: ");      // print da temperatura
    Serial.println(temperatura);
     //Serial.print(" °C\n"); 
  }

 delay(2000);                        //delay de 2 segundos

}

float mediaTemperatura(int amostra){
  float temperatura = 0.0, mediaTemperatura = 0.0 , entrada = 0.0;
  for(int i = 0; i < amostra; i++){
    entrada =  analogRead(pino)*(5.0/1023);   // entrada recebe leitura da porta e multiplica pela ração (tensão max / leitura max)
    temperatura = (entrada) * 100;            
    mediaTemperatura += temperatura;
  }
  return mediaTemperatura / amostra;
}
