includes Test;
configuration TestAppC {
}
implementation {
  components TestC, MainC;
  components LedsC, new TimerMilliC();

  components ActiveMessageC as AMC;
  components new AMSenderC(AM_TEST_DATA_MSG) as AMSC;

  TestC.Boot -> MainC;
  TestC.Leds -> Leds;
  TestC.MilliTimer -> TimerMilliC;

  TestC.RadioControl -> AMC;
  TestC.RadioSend -> AMSC;

  components new SensirionSht11C() as Sht11Ch0C;
  Test.Temp -> Sht11Ch0C.Temperature;
  Test.Humi -> Sht11Ch0C.Humidity;

  components new IlluAdcC() as Illu;
  TestC.Illu -> Illu;

  components BatteryC;
  TestC.Battery -> BatteryC;
}
