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
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define TRIG 2
#define ECHO 3                                                  
#define BUZ 9
#define LEDR 4
#define LEDA 5
#define LEDV 6
#define LEDB 7

long d; //Variable de distancia en cm

int medicion_Ultrasonico();
int distancia(int valor);

LiquidCrystal_I2C lcd_quim(0x27,16,2); 

void setup() {
  Serial.begin(9600);
  lcd_quim.init(); 
  lcd_quim.backlight();
  pinMode(LEDR,OUTPUT);
  pinMode(LEDA,OUTPUT);
  pinMode(LEDV,OUTPUT);
  pinMode(LEDB,OUTPUT);
  pinMode(BUZ, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT); //PIN de Entrada
  digitalWrite(TRIG, LOW); //Incializamos el TRIGGER en 0 

}

void loop() {
   distancia(d);
   medicion_Ultrasonico();
}

int medicion_Ultrasonico(){
  long t; //Variable de tiempo en llegar al ECHO
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10); //Pulso de 10us
  digitalWrite(TRIG, LOW);
  
  t = pulseIn(ECHO, HIGH); //obtenemos el ancho del pulso
  d = t/58; //convertimos el tiempo en una distancia en cm
  Serial.println(d);
  return d;
}

int distancia(int valor){
  if(valor > 45){
      lcd_quim.setCursor(0,0);
      lcd_quim.print("Fuera de        ");
      lcd_quim.setCursor(0,1);
      lcd_quim.print("Alcance         ");
      digitalWrite(LEDB, HIGH);
      digitalWrite(LEDA, LOW);
      digitalWrite(LEDR, LOW);
      digitalWrite(LEDV, LOW); 
  }
  
  if(valor >= 30 && valor < 45){
      lcd_quim.setCursor(0,0);
      lcd_quim.print("Persona/Objeto  ");
      lcd_quim.setCursor(0,1);
      lcd_quim.print("Acercandose     ");
      digitalWrite(LEDV, HIGH);
      digitalWrite(LEDA, LOW);
      digitalWrite(LEDR, LOW);
      digitalWrite(LEDB, HIGH);
  }
  
  if(valor >= 15 && valor < 30){
      lcd_quim.setCursor(0,0);
      lcd_quim.print("Cuidado!!!      ");
      lcd_quim.setCursor(0,1);
      lcd_quim.print("Espacio Privado ");
      digitalWrite(LEDA, HIGH);
      digitalWrite(LEDB, HIGH);
      digitalWrite(LEDR, LOW);
      digitalWrite(LEDV, HIGH);
      tone(BUZ,800,5000);
      delay(100);
      noTone(BUZ);
  }

  if(valor >= 5 && valor < 15){
      lcd_quim.setCursor(0,0);
      lcd_quim.print("Invadiendo!!!   ");
      lcd_quim.setCursor(0,1);
      lcd_quim.print("Espacio Privado ");
      digitalWrite(LEDR, HIGH);
      digitalWrite(LEDA, HIGH);
      digitalWrite(LEDB, HIGH);
      digitalWrite(LEDV, HIGH);
      tone(BUZ,200,10000);
      delay(100);
      noTone(BUZ);
  }
}
