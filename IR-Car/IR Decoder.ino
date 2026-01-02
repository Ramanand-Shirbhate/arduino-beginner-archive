
#include <IRremote.h>

#define IRPIN 7

IRrecv irrecv(IRPIN);
decode_results result;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  Serial.println("Enabled IRin");
}

void loop(){
  if (irrecv.decode(&result)) 
  {
    Serial.println(result.value);
    irrecv.resume(); 
  }
}
