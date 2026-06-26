#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

WebServer server(80); // servidor HTTP porta 80
//terminais dos leds
const int ledR = 18; //conferir ligação na placa
const int ledG = 19;
const int ledB = 21;
//canais PWM do ESP32
const int canalR = 0;
const int canalG = 1;
const int canalB = 2;
//Resolução e frequencia PWM
const int resolucao = 8; //0~255 
const int frequencia = 5000;

void paginaWeb(); //protótipo de função
void mudaLed();
void setup() {
  Serial.begin(115200);
//LedC do ESP32
  ledcSetup(canalR, frequencia, resolucao);
  ledcSetup(canalG, frequencia, resolucao);
  ledcSetup(canalB, frequencia, resolucao);
  ledcAttachPin(ledR, canalR);
  ledcAttachPin(ledG, canalG);
  ledcAttachPin(ledB, canalB);
//WiFi
  Serial.println("Iniciando AP WiFi...");
  WiFi.softAP("ESP_Ronaldo", "12345678"); //cria a rede
  Serial.print("Pronto. IP: ");
  Serial.println(WiFi.softAPIP()); //informa o IP
//Servidor HTTP
  Serial.println("Iniciando Servirdor HTTP...");
  server.on("/",HTTP_GET, paginaWeb); // cria rota http://192.168.4.1/
  server.on("/set", HTTP_GET, mudaLed);
  server.begin(); //inicia o servidor http
  Serial.println("Servidor online em http://192.168.4.1/");
}
void loop() {
  server.handleClient();
}
const char paginaHtml[] PROGMEM = R"rowliteral(
COLE AQUI O HTML
)rowliteral";

void paginaWeb(){
  server.send(200, "text/html", paginaHtml);
}

void mudaLed(){
    // http://192.168.4.1/set?cor=b&valor=128 exemplo de requisição

    String cor = server.arg("cor");
    int valor = server.arg("valor").toInt();
    if(cor == "r"){
      //grava valor no led vermelho
      ledcWrite(canalR, valor);
    }
    if(cor == "g"){
      //grava valor no led verde
      ledcWrite(canalG, valor);
    }
    if(cor == "b"){
      //grava valor no led azul
      ledcWrite(canalB, valor);
    }
    server.send(200, "text", "OK");
}
