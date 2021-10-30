#include <IRremote.h>

IRsend irsend; //Instanciando classe IRsend

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  irsend.sendSony(0xa90, 12);
  delay(1000);

}
