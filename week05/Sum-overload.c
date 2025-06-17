int a1 = 2;
int a2 = 3;
int a3;

float f1 = 2.5;
float f2 = 3.6;
float f3;

void setup() {
  Serial.begin(115200);
  Serial.println();

  a3 = sum(a1,a2);
  Serial.println(a3);

  sum(f1,f2,f3);
  Serial.println(f3);
}

void loop() {
}

int sum(int a, int b) {
  int c = a + b;
  return c;
}

void sum(float a, float b, float& c) {
  c = a + b;
}
