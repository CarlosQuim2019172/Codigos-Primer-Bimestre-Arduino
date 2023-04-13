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
#define L1 2
#define L2 3
#define L3 4
#define L4 5
#define L5 6
#define L6 7
#define L7 8
#define L8 9
#define L9 10
#define L10 11
#define PMO(pin) pinMode(pin,OUTPUT)
int i;

void setup() {
  PMO(2);
  PMO(3);
  PMO(4);
  PMO(5);
  PMO(6);
  PMO(7);
  PMO(8);
  PMO(9);
  PMO(10);
  PMO(11);
}

void loop() {

  for(i=2;i<11;i++){
    digitalWrite(i,HIGH);
    delay(50);
    digitalWrite(i,LOW);
    delay(50);
  }

  for(i=11;i>2;i--){
    digitalWrite(i,HIGH);
    delay(50);
    digitalWrite(i,LOW);
    delay(50);
  }  
}
