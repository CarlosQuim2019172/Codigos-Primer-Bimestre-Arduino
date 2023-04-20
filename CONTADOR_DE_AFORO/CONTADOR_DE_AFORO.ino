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

#define TRIG 10 //PIN digital 10 para el TRIGGER 
#define ECHO 11 //PIN digital 11 para el ECHO

long d; //Variable de distancia en cm
int gente;

void medicion_Ultrasonico();
void aforo();
int contador(int valor);
void pines();
  
void setup() {
  Serial.begin(9600);
  pines();
}

void loop() {
  medicion_Ultrasonico();
  aforo();
  contador(gente);
}
void pines(){
  for(int i = 2; i <=11; i++){
    pinMode(i,OUTPUT);
  }
  pinMode(ECHO, INPUT); //PIN de Entrada
  digitalWrite(TRIG, LOW); //Incializamos el TRIGGER en 0
  digitalWrite(2,HIGH);
}
void medicion_Ultrasonico(){
  long t; //Variable de tiempo en llegar al ECHO
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10); //Pulso de 10us
  digitalWrite(TRIG, LOW);
  
  t = pulseIn(ECHO, HIGH); //obtenemos el ancho del pulso
  d = t/58; //convertimos el tiempo en una distancia en cm
  return d;
}

void aforo(){
  if(d >= 6 && d <=10){
    gente = gente + 1;
    delay(500);
    Serial.println(gente);
  }
  return gente;  
}

int contador(int valor){
  switch(valor){
    case (0):
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);
      digitalWrite(7,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);
    break;

    case(1):
      digitalWrite(2,HIGH);
      digitalWrite(3,LOW);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      break;
      
    case(2):
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(6,HIGH);
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW);
      digitalWrite(9,HIGH);
      break;
      
    case(3):
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      digitalWrite(9,HIGH);
      break;
      
    case(4):
      digitalWrite(2,HIGH);
      digitalWrite(3,LOW);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
      digitalWrite(9,HIGH);
      break;
      
    case(5):
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
      digitalWrite(9,HIGH);
      break;
      
    case(6):
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);
      digitalWrite(7,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(9,HIGH);
      break;
      
    case(7):
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      break;
      
    case(8):
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);
      digitalWrite(7,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(9,HIGH);
      break;

    case(9):
      digitalWrite(2,LOW);   
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
      digitalWrite(9,HIGH);
      break;

  }
}
