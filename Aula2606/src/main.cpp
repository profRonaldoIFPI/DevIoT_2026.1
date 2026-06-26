#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

WebServer server(80); // servidor HTTP porta 80

void paginaWeb(); //protótipo de função
void mudaLed();
void setup() {
  Serial.begin(115200);
  
  Serial.println("Iniciando AP WiFi...");
  WiFi.softAP("ESP_Ronaldo", "12345678"); //cria a rede
  Serial.print("Pronto. IP: ");
  Serial.println(WiFi.softAPIP()); //informa o IP

  Serial.println("Iniciando Servirdor HTTP...");
  server.on("/",HTTP_GET, paginaWeb); // cria rota http://192.168.4.1/
  server.on("/setLed", HTTP_GET, mudaLed);
  server.begin(); //inicia o servidor http
  Serial.println("Servidor online em http://192.168.4.1/");
}
void loop() {
  server.handleClient();
}
const char paginaHtml[] PROGMEM = R"rowliteral( )rowliteral";
void paginaWeb(){
  server.send(200, "text/html", paginaHtml);
}
