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
#include <LiquidCrystal.h>
#define TRIG 9
#define ECHO 8                                                  
#define BUZ 10

int gente = 0; //número de personas
long d; //Variable de distancia en cm

int medicion_Ultrasonico();
int aforo();
int contador(int valor);

LiquidCrystal lcd_quim(2,3,4,5,6,7);

byte customChar[] = {
  B01110,
  B01110,
  B01110,
  B00100,
  B11111,
  B00100,
  B01010,
  B10001
};

void setup() {
  Serial.begin(9600);
  lcd_quim.begin(16,2);
  lcd_quim.createChar(0, customChar);
  lcd_quim.home();
  pinMode(BUZ, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT); //PIN de Entrada
  digitalWrite(TRIG, LOW); //Incializamos el TRIGGER en 0   
}

void loop() {
  medicion_Ultrasonico();
  aforo();
  contador(gente);
}

int medicion_Ultrasonico(){
  long t; //Variable de tiempo en llegar al ECHO
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10); //Pulso de 10us
  digitalWrite(TRIG, LOW);
  
  t = pulseIn(ECHO, HIGH); //obtenemos el ancho del pulso
  d = t/58; //convertimos el tiempo en una distancia en cm
  return d;
}

int aforo(){
  if(d >= 6 && d <=10){
    if(gente>=0 && gente<16){
      gente = gente + 1;
    }
    delay(500);
    Serial.println(gente);
  }
  return gente;  
}

int contador(int valor){
  if(valor <=16){
  lcd_quim.setCursor(0,0);
  lcd_quim.print("Aforo:");
  }
  
  if(valor == 16){
  lcd_quim.setCursor(7,0);
  lcd_quim.print(valor);
  lcd_quim.setCursor(0,2);
  lcd_quim.write(byte(0));
  tone(BUZ,260);
  delay(1000);
  noTone(BUZ);
  }  
}
