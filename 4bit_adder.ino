bool XOR(bool a, bool b){
  return (a + b) % 2;
}

bool AND(bool a, bool b){
  return a && b;
}

bool OR(bool a, bool b){
  return a || b;
}

bool FullAdderSum(bool x, bool y, bool z){
  return XOR(XOR(x, y), z);
}

bool FullAdderCurry(bool x, bool y, bool z){
  return OR(AND(z, XOR(x, y)), AND(x, y));
}

//Digits of the first number X3X2X1X0
int X0 = 6;
int X1 = 7;
int X2 = 8;
int X3 = 9;

//Digits of the first number Y3Y2Y1Y0
int Y0 = 10;
int Y1 = 11;
int Y2 = 12;
int Y3 = 13;

//Digits of the result R4R3R2R1R0
int R0 = A0;
int R1 = A1;
int R2 = A2;
int R3 = A3;
int R4 = A4;

void setup() {
  Serial.begin(9600);
  pinMode(X0, INPUT);
  pinMode(X1, INPUT);
  pinMode(X2, INPUT);
  pinMode(X3, INPUT);

  pinMode(Y0, INPUT);
  pinMode(Y1, INPUT);
  pinMode(Y2, INPUT);
  pinMode(Y3, INPUT);

  pinMode(R0, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3, OUTPUT);
  pinMode(R4, OUTPUT);

  digitalWrite(R0, LOW);
  digitalWrite(R1, LOW);
  digitalWrite(R2, LOW);
  digitalWrite(R3, LOW);
  digitalWrite(R4, LOW);
}

void loop() {
  bool x0 = digitalRead(X0);
  bool y0 = digitalRead(Y0);
  
  bool sum0 = FullAdderSum(x0, y0, 0);
  bool curry0 = FullAdderCurry(x0, y0, 0);

  bool x1 = digitalRead(X1);
  bool y1 = digitalRead(Y1);
  
  bool sum1 = FullAdderSum(x1, y1, curry0);
  bool curry1 = FullAdderCurry(x1, y1, curry0);

  bool x2 = digitalRead(X2);
  bool y2 = digitalRead(Y2);

  bool sum2 = FullAdderSum(x2, y2, curry1);
  bool curry2 = FullAdderCurry(x2, y2, curry1);

  bool x3 = digitalRead(X3);
  bool y3 = digitalRead(Y3);

  bool sum3 = FullAdderSum(x3, y3, curry2);
  bool curry3 = FullAdderCurry(x3, y3, curry2);

  digitalWrite(R0, sum0);
  digitalWrite(R1, sum1);
  digitalWrite(R2, sum2);
  digitalWrite(R3, sum3);
  digitalWrite(R4, curry3);
  
}
