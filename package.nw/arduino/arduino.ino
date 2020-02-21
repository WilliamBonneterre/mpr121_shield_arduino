// Include the library (https://github.com/qub1750ul/Arduino_SharpIR)
#include <SharpIR.h>

// Create a new instance of the SharpIR class (supported models: GP2Y0A41SK0F, GP2Y0A21YK0F, GP2Y0A02YK0F)
SharpIR sensor(SharpIR::GP2Y0A21YK0F, A0);
int distance = 0;

void setup() {
  Serial.begin(1000000);
}

void loop() {

  distance = sensor.getDistance();
  Serial.println(String("distance=") + distance);

  if (Serial.available() > 0) {

    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);

  }

  //  delay(50);

}
