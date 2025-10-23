int pinoPot = A0; 
int pinoBuzzer = 8;
void setup() {
  pinMode(pinoBuzzer, OUTPUT);
  Serial.begin(9600);
}
void loop() {

  int valorPot = analogRead(pinoPot);
  
  int frequencia = map(valorPot, 0, 1023, 100, 2000);
  
  tone(pinoBuzzer, frequencia);
  
  Serial.print("Frequência: ");
  Serial.println(frequencia);
  delay(50); 
}
