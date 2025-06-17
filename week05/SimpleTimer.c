#include <SimpleTimer.h> // Need to install library
SimpleTimer timerCnt;

unsigned long loopCnt;

void timerCntFunc() {
  Serial.println(loopCnt);
  loopCnt = 0;
}

void setup() {
  Serial.begin(115200);
  Serial.println();

  timerCnt.setInterval(1000,timerCntFunc); // milli-sec
}

void loop() {
  timerCnt.run();
  loopCnt++;
}
