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
#define LEDR 2
#define LEDG 3
#define LEDB 4
#define PUSH1 5
#define PUSH2 6
#define PMI(pin) pinMode(pin,INPUT)
#define PMO(pin) pinMode(pin,OUTPUT)
int P1,P2;
int i;
 
 void setup() {
  PMO(2);
  PMO(3);
  PMO(4);
  PMI(5);
  PMI(6);
}

void loop() {
  P1 = digitalRead(PUSH1);
  P2 = digitalRead(PUSH2);

  if(P1 == HIGH && P2 == LOW){
    digitalWrite(LEDR,HIGH);
    digitalWrite(LEDG,HIGH);
    digitalWrite(LEDB,LOW);
  }else if(P1 == LOW && P2 == HIGH){
    digitalWrite(LEDR,LOW);
    digitalWrite(LEDG,HIGH);
    digitalWrite(LEDB,HIGH);
  }else if(P1 == LOW && P2 == LOW){
    digitalWrite(LEDR,HIGH); delay(500); digitalWrite(LEDR,LOW);
    digitalWrite(LEDG,HIGH); delay(500); digitalWrite(LEDG,LOW);
    digitalWrite(LEDB,HIGH); delay(500); digitalWrite(LEDB,LOW);
  }
   
  if(P1 == HIGH && P2 == HIGH){
    digitalWrite(LEDR,HIGH); 
    digitalWrite(LEDB,HIGH);
    digitalWrite(LEDG,LOW);
  }
  

}
