int value = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(8, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = digitalRead(8);
  Serial.println(value);
  digitalWrite(13, value);
}
