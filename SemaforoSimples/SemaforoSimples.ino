int i=0;
int led;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}
void piscaled(int led)
{
  do
  {
  digitalWrite(led, LOW);
  delay(200);
  digitalWrite(led,HIGH );
  delay(300);
  digitalWrite(led, LOW);
  delay(100);
    i=i+1;
  }while(i<=3);
  i=0; 
  
}

void loop()
{ 
  //vermelho
  digitalWrite(13, HIGH);
  delay(2500); 
  piscaled(13);
  
  
  //Amarelo
  digitalWrite(12, HIGH);
  delay(2500); 
  piscaled(12);
  
  //Verde
  digitalWrite(11, HIGH);
  delay(2500);
  piscaled(11);
   
}
