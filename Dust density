#Arduino code
int Vo = A0;
int V_led = 12;

float V_value = 0;
float Voltage = 0;
float dustDensity = 0;

void setup() {
  Serial.begin(9600);
  pinMode(V_led, OUTPUT);
  pinMode(Vo, INPUT);
}
void loop() {
  digitalWrite(V_led, LOW);
  delayMicroseconds(200);
  V_value = analogRead(Vo);
  delayMicroseconds(40);
  digitalWrite(V_led, HIGH);
  delayMicroseconds(9680);

  Voltage = V_value*5.0 / 1023.0;
  dustDensity = (Voltage - 0.5) / 0.005;

  Serial.print("dust=" );
  Serial.println(dustDensity);

  delay(1000);
}
=========================================================================================================================
# Dust density sensor code connect with Arduino
from influxdb_client import InfluxDBClient
import serial
import time

serial_port = 'COM13'
baud_rate = 9600
timeout = 2

# === InfluxDB v2 setting ===
influxdb_url = "http://localhost:8086"
influxdb_token = "okY7-2QRCAMm4vs4n9gA3LFgS57QFly0piJ4rJ0xm3_K8_KBHiJvNeIgnOJauMUAVnLFvI8sE27q4WtG2sq5JA=="
influxdb_org = "test"
influxdb_bucket = "dust"

# === InfluxDB Client reset ===
client = InfluxDBClient(url=influxdb_url, token=influxdb_token, org=influxdb_org, bucket=influxdb_bucket)
write_api = client.write_api()

# === Open serial port ===
try:
    ser = serial.Serial(serial_port, baud_rate, timeout = timeout)
    print(f"Connected to {serial_port} at {baud_rate} baud")
except:
    print("Failed to connect to serial port")
    exit()
try:
    while True:
        if ser.in_waiting > 0:
            # Reading serial data from Arduino
            line = ser.readline().decode('utf-8').strip()

            # If The Data exist recoding to InfluxDB
            if "=" in line:
                key, value = line.split("=")
                # Remove any extra space in key & value
                key = key.strip()
                value = value.strip()
                try:
                    value = float(value)
                    data=f"sensor_data,device=arduino {key}={value}"
                    write_api.write(bucket=influxdb_bucket, record=data)
                    print(f"Data written to influxDB: {key}={value}")
                except ValueError:
                    print("Invalid data format")

        time.sleep(1)
except KeyboardInterrupt:
    print("Program is shut down.")

finally:
    ser.close()
