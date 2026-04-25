#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); //endereço I2C, nCaracteres, nLinhas

const int led = 23;
const int btn = 25;
const int ldr = 34;

void setup() {
  pinMode(btn, INPUT_PULLUP); //estado sempre em HIGH
  pinMode(led, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0); 
  lcd.print("Iniciando");
  for(int i=1; i<=5;i++){
    lcd.print(".");
    delay(200);
  }
}
void loop() {
  lcd.setCursor(0,1);
  while(digitalRead(btn) == LOW){
   lcd.print("."); 
  }
  lcd.clear();
  int sensor = analogRead(ldr);
  lcd.setCursor(0,0);
  lcd.print(sensor);
  delay(500); //enquanto isso o botão não funciona.
  lcd.clear();
  digitalWrite(led, HIGH);
}
