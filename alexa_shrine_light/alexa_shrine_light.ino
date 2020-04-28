//Testing the NodeMCU and 4-channel relay module


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(D7,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Relay On");
  digitalWrite(D7,HIGH);
  delay(1000);
  Serial.println("Relay Off");
  digitalWrite(D7,LOW);
  delay(2000);
}
