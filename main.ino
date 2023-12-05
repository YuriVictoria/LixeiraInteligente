//Carrega a biblioteca do sensor ultrassonico e do servo
#include <Ultrasonic.h>
#include <Servo.h>
 
//Define os pinos para o trigger e echo do sensor ultrassonico e da tampa
#define PINO_TRIGGER_TAMPA 4
#define PINO_ECHO_TAMPA 5
#define PINO_TRIGGER_CAPACIDADE 6
#define PINO_ECHO_CAPACIDADE 7

//Define pino do servo
#define PINO_SERVO 9

//Define pino do led
#define PINO_LED 3

//Inicializa os sensores nos pinos definidos acima
Ultrasonic tampa(PINO_TRIGGER_TAMPA, PINO_ECHO_TAMPA);;
Ultrasonic capacidade(PINO_TRIGGER_CAPACIDADE, PINO_ECHO_CAPACIDADE);

//Inicializa o servo
int pos = 0;
Servo s;

void setup()
{
  pinMode(PINO_LED, OUTPUT);
  s.attach(PINO_SERVO);
  s.write(pos);
}
 
void loop()
{
  estadoCapacidade();
  
  //Le as informacoes do sensor em cm
  long microsecTampa = tampa.timing();
  float sensorTampa = tampa.convert(microsecTampa, Ultrasonic::CM);

  if(sensorTampa <= 5 && !abertaTampa())
    abrirTampa();

  else if(sensorTampa <= 5 && abertaTampa())
    fecharTampa();
}

float capacidadeEmCm(){
  long microsecCapacidade = capacidade.timing();
  return capacidade.convert(microsecCapacidade, Ultrasonic::CM);
}

void estadoCapacidade(){
  if(capacidadeEmCm() < 10)
    analogWrite(PINO_LED, HIGH);
  else
    analogWrite(PINO_LED, LOW);
}

int abertaTampa() {
  if(s.read() == 0)
    return 0; //Fechada
  else
    return 1; //Aberta
}

void abrirTampa() {
  for(pos; pos <= 180; pos++) {
    s.write(pos);
    delay(15);
  }    
  delay(3000);
}

void fecharTampa() {
  for(pos; pos >= 0; pos--) {
    s.write(pos);
    delay(15);
  }
  delay(3000);
}
