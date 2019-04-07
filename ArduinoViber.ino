#include <LiquidCrystal.h>

//Definimos los pines que vamos a usar
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int motor = 6;
int aceptar = 7;
int rechazar = 8;
 
void setup() 
{
  lcd.begin(16, 2);  //Inicializamos la pantalla
  lcd.setCursor(0, 0);  //Situamos el cursor
  
}

void loop() 
{
  lcd.setCursor(0,0);
  show("Ala");
}

int show(char word[]){
  lcd.setCursor();
  lcd.print(word);
  return 0;
}
