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
#define PMI(pin) pinMode(pin,INPUT)
#define DR(pin) digitalRead(pin)
#define SW_1 2
#define SW_2 3
bool SW1,SW2;
int i = 1; 
int a = 1;

struct Producto{
  int PrecioU;
  int Stock;
  char Nombre[25];
  char Reserva[30];
  float PrecioL;  
};

Producto cocacola = { 6.50, 10, "Produtco 1 - CocaCola", "5 unidades Ddisponibles",};
Producto doritos = { 5.00, 15, "Produtco 2 - Doritos", "No hay en bodega",};
Producto galletas = { 2.50, 20, "Produtco 3 - Galletas", "25 Unidades Disponibles",};
Producto chocolate = { 3.00, 5, "Produtco 4 - Chocolate", "Disponible en Tienda Majadas",};
 
void setup() {
  Serial.begin(9600);
  PMI(2);
  PMI(3);
  Serial.println("-----------------------------------");
  Serial.println("Bienvenido a mi Maquina Expendedora");
}

void loop() {
  SW1 = DR(2); //acendente
  SW2 = DR(3); //descendente
    
  if(SW1 == HIGH){
    a = 1;
    i++;
    delay(200);
  }
  if(i > 4){
    i = 1;
  }
  
  if(SW2 == HIGH){
    a = 1;
    i--;
    delay(200);
  }
  if(i < 1){
    i = 4;
  }
  

while(a == 1){

switch(i){
  case(1):
    Serial.println("-----------------------------------");
    Serial.println(cocacola.Nombre);
    Serial.print("Precio Unitario: Q "); Serial.println(cocacola.PrecioU);
    Serial.print("Stock: "); Serial.print(cocacola.Stock); Serial.println(" Unidades en Stock");
    Serial.print("Reserva: "); Serial.println(cocacola.Reserva); 
    Serial.print("Precio de Lote: Q "); Serial.println(cocacola.PrecioU*cocacola.Stock);
    a = 2;
    break;

  case(2):
    Serial.println("-----------------------------------");
    Serial.println(doritos.Nombre);
    Serial.print("Precio Unitario: Q "); Serial.println(doritos.PrecioU);
    Serial.print("Stock: "); Serial.print(doritos.Stock); Serial.println(" Unidades en Stock");
    Serial.print("Reserva: "); Serial.println(doritos.Reserva);
    Serial.print("Precio de Lote: Q "); Serial.println(doritos.PrecioU*doritos.Stock);
    a = 2;
    break;

  case(3):
    Serial.println("-----------------------------------");
    Serial.println(galletas.Nombre);
    Serial.print("Precio Unitario: Q "); Serial.println(galletas.PrecioU);
    Serial.print("Stock: "); Serial.print(galletas.Stock); Serial.println(" Unidades en Stock");
    Serial.print("Reserva: ");Serial.println(galletas.Reserva);
    Serial.print("Precio de Lote: Q ");Serial.println(galletas.PrecioU*galletas.Stock);
    a = 2;
    break;

  case(4):
    Serial.println("-----------------------------------");
    Serial.println(chocolate.Nombre);    
    Serial.print("Precio Unitario: Q "); Serial.println(chocolate.PrecioU);
    Serial.print("Stock: "); Serial.print(chocolate.Stock); Serial.println(" Unidades en Stock");
    Serial.print("Reserva: "); Serial.println(chocolate.Reserva);
    Serial.print("Precio de Lote: Q "); Serial.println(chocolate.PrecioU*chocolate.Stock);
    a = 2;
    break;
}}}
