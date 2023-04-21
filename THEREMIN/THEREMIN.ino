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
#define TRIG 6
#define ECHO 5                                                   
#define BUZ 3 

const int nota_do = 261;
const int nota_re = 294;
const int nota_mi = 329;
const int nota_fa = 349;
const int nota_sol = 392;
const int nota_la = 440;

long d; //Variable de distancia en cm
int dtime = 700;

int medicion_Ultrasonico();
void melodia();

void setup() {
  Serial.begin(9600);
  pinMode(BUZ, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT); //PIN de Entrada
  digitalWrite(TRIG, LOW); //Incializamos el TRIGGER en 0
}

void loop() {
  medicion_Ultrasonico();
  melodia(d);
}

void melodia(int valor){
  switch(valor){ 
    case 4:
      tone(BUZ,nota_do);
      delay(dtime);
      valor = 0;
    break;

    case 8:
      tone(BUZ,nota_re);
      delay(dtime);
      valor = 0;
    break;

    case 12:
      tone(BUZ,nota_mi);
      delay(dtime);
      valor = 0;
    break;

    case 16:
      tone(BUZ,nota_fa);
      delay(dtime);
      valor = 0;
    break;   

    case 20:
      tone(BUZ,nota_sol);
      delay(dtime);
      valor = 0;
    break;

    case 24:
      tone(BUZ,nota_la);
      delay(dtime);
      valor = 0;
    break;
   
    default:
      noTone(BUZ);
      valor = 0;
    break;
  }
}

int medicion_Ultrasonico(){
  long t; //Variable de tiempo en llegar al ECHO
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10); //Pulso de 10us
  digitalWrite(TRIG, LOW);
  
  t = pulseIn(ECHO, HIGH); //obtenemos el ancho del pulso
  d = t/58; //convertimos el tiempo en una distancia en cm
  delay(100);
  Serial.println(d);
  return d;
}
