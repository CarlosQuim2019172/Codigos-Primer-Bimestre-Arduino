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
#define PMO(pin) pinMode(pin,OUTPUT)
int i;

void setup() {
for(i=2;i<11;i++){
  PMO(i);
}
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
