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
#define TRIG 2
#define ECHO 4
#define BUZ 3

int medicion_Ultrasonico();
void aforo();

int personas, gente;

LiquidCrystal lcd_quim(5, 6, 7, 8, 9, 10);

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

byte customChar1[] = {
  B01110,
  B01110,
  B01110,
  B10101,
  B01110,
  B00100,
  B01010,
  B10001
};

byte explosion[] = {
  B00100,
  B10101,
  B01110,
  B11111,
  B01110,
  B10101,
  B00100,
  B00000
};

byte barra[] = {
  B00100,
  B01110,
  B10101,
  B01110,
  B10101,
  B01110,
  B10101,
  B00100
};

void setup() {
  Serial.begin(9600);
  lcd_quim.begin(16, 2);
  lcd_quim.createChar(0, customChar);
  lcd_quim.createChar(1, customChar1);
  lcd_quim.createChar(2, explosion);
  lcd_quim.createChar(3, barra);
  lcd_quim.home();
  pinMode(BUZ, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);     //PIN de Entrada
  digitalWrite(TRIG, LOW);  //Incializamos el TRIGGER en 0
}

void loop() {
  aforo();
}

int medicion_Ultrasonico() {
  long d;  //Variable de distancia en cm
  long t;  //Variable de tiempo en llegar al ECHO
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);  //Pulso de 10us
  digitalWrite(TRIG, LOW);

  t = pulseIn(ECHO, HIGH);  //obtenemos el ancho del pulso
  d = t / 58;               //convertimos el tiempo en una distancia en cm
  return d;
}

void aforo() {
  personas = medicion_Ultrasonico();

  if (personas >= 6 && personas <= 10) {
    gente = gente + 1;
    delay(500);
    Serial.println(gente);
  }

  if (gente <= 16) {
    lcd_quim.setCursor(0, 0);
    lcd_quim.print("Aforo:");
    lcd_quim.setCursor(7, 0);
    lcd_quim.print(gente);
  }

  if (gente >= 16) {
    lcd_quim.clear();
    lcd_quim.setCursor(0, 0);
    lcd_quim.print("    El AFORO    ");
    lcd_quim.setCursor(0, 1);
    lcd_quim.print("    COMPLETO    ");
    lcd_quim.setCursor(0, 2);
    // personas con brazos abajo
    lcd_quim.write(byte(0));
    lcd_quim.setCursor(15, 2);
    lcd_quim.write(byte(0));
    delay(500);
    // personas con brazos arriba
    lcd_quim.setCursor(0, 2);
    lcd_quim.write(byte(1));
    lcd_quim.setCursor(15, 2);
    lcd_quim.write(byte(1));

    // barras
    lcd_quim.setCursor(13, 1);
    lcd_quim.write(byte(3));
    lcd_quim.setCursor(2, 1);
    lcd_quim.write(byte(3));
    delay(500);
    lcd_quim.setCursor(13, 0);
    lcd_quim.write(byte(3));
    lcd_quim.setCursor(2, 0);
    lcd_quim.write(byte(3));

    delay(500);
    // explocion
    lcd_quim.setCursor(13, 0);
    lcd_quim.write(byte(2));
    lcd_quim.setCursor(13, 1);
    lcd_quim.print(" ");
    lcd_quim.setCursor(2, 0);
    lcd_quim.write(byte(2));
    lcd_quim.setCursor(2, 1);
    lcd_quim.print(" ");

    tone(BUZ, 260);
    delay(500);
    noTone(BUZ);
  }
}
