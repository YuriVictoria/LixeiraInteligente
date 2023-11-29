//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>
#include <Servo.h>
 
//Define os pinos para o trigger e echo
#define PINO_TRIGGER_TAMPA 4
#define PINO_ECHO_TAMPA 5

#define PINO_TRIGGER_CAPACIDADE 6
#define PINO_ECHO_CAPACIDADE 7

#define PINO_SERVO 9

#define LED 3

//Inicializa o sensor nos pinos definidos acima
Ultrasonic tampa(PINO_TRIGGER_TAMPA, PINO_ECHO_TAMPA);;

Ultrasonic capacidade(PINO_TRIGGER_CAPACIDADE, PINO_ECHO_CAPACIDADE);

Servo s;

void setup()
{
  //para o led RGB Ânodo comum
  // Funciona no 0
  pinMode(LED, OUTPUT);

  Serial.begin(9600);
  s.attach(PINO_SERVO);
  s.write(0);
}
 
void loop()
{
  //Le as informacoes do sensor, em cm e pol
  float sensorTampa;
  long microsec = tampa.timing();
  
  sensorTampa = tampa.convert(microsec, Ultrasonic::CM);
  //Exibe informacoes no serial monitor

  estadoCapacidade();

  Serial.println(sensorTampa);

  if(sensorTampa <= 5 && !estadoTampa())
    abrirTampa();

  else if(sensorTampa <= 5 && estadoTampa())
    fecharTampa();
}

void abrirTampa() {
  Serial.println("Abrir tampa"); //função motor
    
  for(int pos = 0; pos <= 90; pos++) {
    s.write(pos);
    delay(15);
  }
    
  delay(3000);
}

void fecharTampa() {
    Serial.println("Fechar tampa"); //função motor
  
  for(int pos = 90; pos >= 0; pos--) {
    s.write(pos);
    delay(15);
  }
  
  delay(3000);
}

int estadoTampa() {
  if(s.read() == 0)
    return 0;

  else
    return 1;
}

float capacidadeEmCm(){
  long sec = capacidade.timing();
  float sensorCapacidade;
  sensorCapacidade = capacidade.convert(sec, Ultrasonic::CM);
  return sensorCapacidade;
}

void estadoCapacidade(){
  if(capacidadeEmCm() < 10)
    analogWrite(LED, HIGH);
  else
    analogWrite(LED, LOW);
}
