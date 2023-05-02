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

int medidas; //Variable de distancia en cm
int i,a;
int medicion_Ultrasonico();
void distancia();

LiquidCrystal_I2C lcd_quim(0x27,16,2); 

byte customChar[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

void setup() {
  Serial.begin(9600);
  lcd_quim.init();  
  lcd_quim.backlight();
  lcd_quim.createChar(0, customChar);
  lcd_quim.home();
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT); //PIN de Entrada
  digitalWrite(TRIG, LOW); //Incializamos el TRIGGER en 0 

}

void loop() {
   distancia();
}

int medicion_Ultrasonico(){
  long d; //Variable de distancia en cm
  long t; //Variable de tiempo en llegar al ECHO
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10); //Pulso de 10us
  digitalWrite(TRIG, LOW);
  
  t = pulseIn(ECHO, HIGH); //obtenemos el ancho del pulso
  d = t/58; //convertimos el tiempo en una distancia en cm
  Serial.println(d);
  return d;
}

void distancia(){
  medidas = medicion_Ultrasonico();
  if(medidas > 70){
    lcd_quim.clear();
  }
  switch(medidas){
    case 50:
      lcd_quim.setCursor(7,0);
      lcd_quim.print("50    ");
      lcd_quim.setCursor(0,1);
      lcd_quim.print("     LIBRES     ");
      i = 0;
      a = 13;
      for(i == 0; i <=2; i++){
        lcd_quim.setCursor(i,0);
        lcd_quim.write(byte(0));
        lcd_quim.setCursor(3,0);
        lcd_quim.print("    ");
      }
      for(a == 13; a <=15; a++){
        lcd_quim.setCursor(a,0);
        lcd_quim.write(byte(0));
      }
    break;

    case 30:
      lcd_quim.setCursor(7,0);
      lcd_quim.print("30  ");
      lcd_quim.setCursor(0,1);
      lcd_quim.print("    CUIDADO!     ");
      i = 0;
      a = 11;
      for(i == 0; i <=4; i++){
        lcd_quim.setCursor(i,0);
        lcd_quim.write(byte(0));
        lcd_quim.setCursor(5,0);
        lcd_quim.print("  ");
      }
      for(a == 11; a <=15; a++){
        lcd_quim.setCursor(a,0);
        lcd_quim.write(byte(0));
      }
    break;

    case 10:
      lcd_quim.setCursor(7,0);
      lcd_quim.print("10");
      lcd_quim.setCursor(0,1);
      lcd_quim.print("     ALTO!!     ");
      i = 0;
      a = 9;
      for(i == 0; i <=6; i++){
        lcd_quim.setCursor(i,0);
        lcd_quim.write(byte(0));
      }
      for(a == 9; a <=15; a++){
        lcd_quim.setCursor(a,0);
        lcd_quim.write(byte(0));
      }
    break;
  }
}
