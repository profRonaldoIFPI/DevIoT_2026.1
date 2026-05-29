#include <Arduino.h>
const int pot = 15;
const int ledR = 5;
const int ledG = 18;
const int ledB = 19;
void setup() {
    Serial.begin(115200);//baudrate
    pinMode(ledR, OUTPUT);
    pinMode(ledG, OUTPUT);
    pinMode(ledB, OUTPUT);  
    pinMode(pot, INPUT);
}
void loop() {
    int entrada = analogRead(pot); // 0 a 4095
    int hue = map(entrada, 0, 4095, 0, 255); // 0 a 360
    Serial.print("Entrada: ");
    Serial.print(entrada);
    Serial.print(" |hue: ");
    Serial.println(hue);
    int red;
    int green;
    int blue;
    if (hue < 85) {
        // 1º terço: vermelho para azul
        green = 0;
        red = 255 - hue * 3; // 255 a 0
        blue = hue * 3; // 0 a 255
    }else if (hue < 170) {
        // 2º terço: azul para verde
        red = 0;
        green = (hue - 85) * 3; // 0 a 255
        blue = 255 - (hue - 85) * 3; // 255 a 0
    }else if (hue < 255) {
        // 3º terço: verde para vermelho
        blue = 0;
        red = (hue - 170) * 3; //0 a 255
        green = 255 - (hue - 170) * 3; //255 a 0
    }
    analogWrite(ledR, red);
    analogWrite(ledG, green);
    analogWrite(ledB, blue);
}
