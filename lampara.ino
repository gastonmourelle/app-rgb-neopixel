#include <Adafruit_NeoPixel.h>
#include <ESP8266WiFi.h>
#define NUMPIXELS 3
#define pir D2
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, D3, NEO_GRB + NEO_KHZ800);


const char* ssid     = "iPhone";      // SSID
const char* password = "manyamanya";      // Password
const char* host = "*IP*";  // IP serveur - Server IP
const int   port = 8080;            // Port serveur - Server Port
const int   watchdog = 5000;        // Fréquence du watchdog - Watchdog frequency
unsigned long previousMillis = millis();


String codigo;        //Aquí se almacena la respuesta del servidor

String prendido;
String brillo;
String rs;
String gs;
String bs;
String reposo;
//bool setReposo = true;
//int brillo;
//int r;


boolean fin = false;
boolean pregunta = true;

void setup(void)
{
  pixels.begin();
  pinMode(D4, OUTPUT);
  pinMode(pir, INPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    //Serial.print(".");
  }

  //Serial.println("");
  //Serial.println("WiFi connected");
  //Serial.println("IP address: ");
  // Serial.println(WiFi.localIP());

  Serial.begin(9600);
  delay(700);

}
void loop() {
  //pixels.setPixelColor(0, pixels.Color(255, 0, 255));
  pixels.show();

  // pixels.setPixelColor(1, pixels.Color(255, 255, 0));
  // pixels.setPixelColor(2, pixels.Color(0, 255, 255));
  //pixels.setBrightness(45);
  //pixels.show();



  unsigned long currentMillis = millis();

  if ( currentMillis - previousMillis > watchdog ) {
    previousMillis = currentMillis;
    WiFiClient client;

    if (!client.connect(host, port)) {
      Serial.println("Fallo al conectar");
      return;
    }

    String url = "/lampara/datos.php";

    // Enviamos petición al servidor
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n\r\n");
    unsigned long timeout = millis();
    while (client.available() == 0) {
      if (millis() - timeout > 5000) {
        Serial.println(">>> Client Timeout !");
        client.stop();
        return;
      }
    }

    // Leemos la respuesta del servidor
    while (client.available()) {
      char c = client.read();
      codigo += c;
      //Habilitamos la comprobación del código recibido
      fin = true;
      //String line = client.readStringUntil('\r');
      //Serial.print(line);
    }

    //Si está habilitada la comprobación del código entramos en el IF
    if (fin)  {
      // Serial.println(codigo);
      //Analizamos la longitud del código recibido
      int longitud = codigo.length();
      //Buscamos en que posición del string se encuentra nuestra variable
      int posicion = codigo.indexOf("pr=");
      int posicion2 = codigo.indexOf("br=");
      int posicion3 = codigo.indexOf("cr=");
      int posicion4 = codigo.indexOf("cg=");
      int posicion5 = codigo.indexOf("cb=");
      int posicion6 = codigo.indexOf("re=");
      //Borramos lo que haya almacenado en el string nombre
      prendido = "";
      reposo = "";
      brillo = "";
      rs = "";
      gs = "";
      bs = "";
      //Analizamos el código obtenido y almacenamos el nombre en el string nombre
      for (int i = posicion + 3; i < longitud; i ++) {
        if (codigo[i] == ';') i = longitud;
        else prendido += codigo[i];
      }
      for (int i = posicion2 + 3; i < longitud; i ++) {
        if (codigo[i] == ';') i = longitud;
        else brillo += codigo[i];
      }
      for (int i = posicion3 + 3; i < longitud; i ++) {
        if (codigo[i] == ';') i = longitud;
        else rs += codigo[i];
      }
      for (int i = posicion4 + 3; i < longitud; i ++) {
        if (codigo[i] == ';') i = longitud;
        else gs += codigo[i];
      }
      for (int i = posicion5 + 3; i < longitud; i ++) {
        if (codigo[i] == ';') i = longitud;
        else bs += codigo[i];
      }
      for (int i = posicion6 + 3; i < longitud; i ++) {
        if (codigo[i] == ';') i = longitud;
        else reposo += codigo[i];
      }

      //Deshabilitamos el análisis del código
      fin = false;
      //Imprimir el nombre obtenido
      if (digitalRead(pir) == HIGH) {
        Serial.println("DETECTADO");
        delay(250);
      }
      Serial.println("Valor prendido:" + prendido);
      Serial.println("Valor reposo:" + reposo);
      Serial.println("Valor brillo: " + brillo);
      Serial.println("Valor canal R: " + rs);
      Serial.println("Valor canal G: " + gs);
      Serial.println("Valor canal B: " + bs);
      //Cerrar conexión
      Serial.println("Desconectar");
      client.stop();
    }
    //Borrar código y salir de la función//Dirección IP del servidor
    codigo = "";

    if (prendido == "0") {
      for (int i = 0; i < NUMPIXELS; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
      //pixels.setBrightness(0);

      if (reposo == "1" && digitalRead(pir) == HIGH) {
        for (int i = 0; i < 100; i++) {
          for (int j = 0; j < NUMPIXELS; j++) {
            pixels.setPixelColor(j, pixels.Color(i, i, i));
            delay(10);
            pixels.show();
          }}
          delay(3000);
          for (int k = 100; k > 0; k--) {
          for (int p = 0; p < NUMPIXELS; p++) {
            pixels.setPixelColor(p, pixels.Color(k, k, k));
            delay(10);
            pixels.show();
          }}
      }
    }
    else {
      int brilloInt = brillo.toInt();
      int r = rs.toInt();
      int g = gs.toInt();
      int b = bs.toInt();
      //pixels.clear();
      for (int i = 0; i < NUMPIXELS; i++) {
        pixels.setPixelColor(i, pixels.Color(r, g, b));
      }
      pixels.setBrightness(brilloInt);
    }

  }
  delay(800);
}
