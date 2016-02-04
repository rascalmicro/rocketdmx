/* Welcome to DmxSimple. This library allows you to control DMX stage and
** architectural lighting and visual effects easily from Arduino. DmxSimple
** is compatible with the Tinker.it! DMX shield and all known DIY Arduino
** DMX control circuits.
**
** DmxSimple is available from: http://code.google.com/p/tinkerit/
** Help and support: http://groups.google.com/group/dmxsimple       */

/* To use DmxSimple, you will need the following line. Arduino will
** auto-insert it if you select Sketch > Import Library > DmxSimple. */

#include <DmxSimple.h>

int SENSOR_ONE = 16;
int SENSOR_TWO = 17;
int SENSOR_THREE = 18;
int SENSOR_FOUR = 19;

void setup() {
  /* The most common pin for DMX output is pin 3, which DmxSimple
  ** uses by default. If you need to change that, do it here. */
  DmxSimple.usePin(6);

  /* DMX devices typically need to receive a complete set of channels
  ** even if you only need to adjust the first channel. You can
  ** easily change the number of channels sent here. If you don't
  ** do this, DmxSimple will set the maximum channel number to the
  ** highest channel you DmxSimple.write() to. */
  DmxSimple.maxChannel(18);
  pinMode(SENSOR_ONE, INPUT);
  pinMode(SENSOR_TWO, INPUT);
  pinMode(SENSOR_THREE, INPUT);
  pinMode(SENSOR_FOUR, INPUT);
  Serial.begin(9600);
}

void loop() {
  int brightness = 125;
  int count;
  /* Simple loop to ramp up brightness */
  for (count = 0; count <= 255; count++) {
    if(digitalRead(SENSOR_ONE) || digitalRead(SENSOR_TWO) || digitalRead(SENSOR_THREE) || digitalRead(SENSOR_FOUR)) {
        Serial.println("Motion detected");
        DmxSimple.write(4, brightness + 110);
        DmxSimple.write(5, brightness + 110);
        DmxSimple.write(6, brightness);
    } else {
        Serial.println("xxxxxxx");
        DmxSimple.write(4, brightness);
        DmxSimple.write(5, brightness + 110);
        DmxSimple.write(6, brightness + 110);
    }
    /* Small delay to slow down the ramping */
    delay(50);
  }
}
