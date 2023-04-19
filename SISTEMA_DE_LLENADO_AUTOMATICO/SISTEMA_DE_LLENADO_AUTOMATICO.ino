/*
Fundación Kinal
Centro Educativo Técnico Labral Kinal 
Electrónica
Grado: Quinto
Sección: A
Curso: Taller de Electrónica Digital y Reparación de Computadoras I
Nombre: Carlos Alexander Quim Chapaz
Carné: 2019172 
*/

#define LEDB 4
#define LEDR 5
#define SENSOR 3 
#define RELE 2
void setup() {
  pinMode(LEDB, OUTPUT);
  pinMode(LEDR, OUTPUT);
  pinMode(RELE, OUTPUT);
  pinMode(SENSOR, INPUT);
}

void loop() {
  if(digitalRead(SENSOR) == HIGH){
    digitalWrite(LEDR,LOW);
    digitalWrite(LEDB,HIGH);
    digitalWrite(RELE,HIGH);
  }

  if(digitalRead(SENSOR) == LOW){
    digitalWrite(LEDR,HIGH);
    digitalWrite(LEDB,LOW);
    digitalWrite(RELE,LOW);
  }
}
