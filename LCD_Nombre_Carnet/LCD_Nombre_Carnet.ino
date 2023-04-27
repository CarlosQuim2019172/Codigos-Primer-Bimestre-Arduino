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

LiquidCrystal lcd_quim(12,11,5,4,3,2);

void setup() {
  lcd_quim.begin(16,2);
}

void loop() {
  delay(1000);
  lcd_quim.setCursor(2,0);
  lcd_quim.print("Carlos Quim");
  lcd_quim.setCursor(4,2);
  lcd_quim.print("2019172");
  delay(1000);
  lcd_quim.clear();
}
