class buzzer
{
private:
  int pin;
  int freq;
  
public:
  buzzer(int p) : pin(p), freq(0) {}
  void begin(){
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }
  void frequencia(int f){
    long periodo = 1000000L / f;
    long meioPeriodo = periodo / 2;
    unsigned long duracao = 50;
    unsigned long ciclos = (duracao * 1000L) / periodo;
    for (unsigned long i = 0; i < ciclos; i++) {
      digitalWrite(pin, HIGH);
      delayMicroseconds(meioPeriodo);
      digitalWrite(pin, LOW);
      delayMicroseconds(meioPeriodo);
    }
  }
};

class pot
{
private:
  int pin;
  int read;
  int freq;
public:
  pot(int p) : pin(p), read(0), freq(0){}
  void begin(){
    pinMode(pin, INPUT);
  }
  int lerFrequencia(){
    read = analogRead(pin);
    freq = map(read, 0, 1023, 100, 2000);
    return freq;
  }
};


buzzer buz1(6);
pot pot1(0);

void setup() {
  buz1.begin();
  pot1.begin();
}
void loop() {
  buz1.frequencia(pot1.lerFrequencia());
}