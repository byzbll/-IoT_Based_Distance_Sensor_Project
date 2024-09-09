#include <ESP8266WiFi.h>
#include <MQTTClient.h>
#include <FirebaseArduino.h>  

const char *ssid = "******";                 
const char *password = "*******"; 
   
#define FIREBASE_HOST "*******"     // veritabanının linki
#define FIREBASE_AUTH "*******"     // veritabanı secret key

WiFiClient wifi_istemci;
MQTTClient mqtt_istemci;

void setup() 
{
  Serial.begin(9600);                            
  delay(1000);
  Serial.println("Wifi agina baglaniliyor");

  WiFi.mode(WIFI_STA);                          
  WiFi.begin(ssid, password);                    

  while (WiFi.status() != WL_CONNECTED) 
  { 
    delay(500);                                 
    Serial.print(".");                          
  }

  Serial.println("");                           
  Serial.println("Bağlantı sağlandı...");       

  Serial.print("Alınan IP addresi: ");          
  Serial.println(WiFi.localIP());              
 
  mqtt_istemci.begin("****.shiftr.io", wifi_istemci); 
  mqtt_istemci.onMessage(mesaj_geldi);      

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); // firabase i başlat
}

void loop() 
{
  mqtt_istemci.loop();              
  if (!mqtt_istemci.connected()) 
    baglan();

  delay(1000);

}
void baglan()
{
 
  while (!mqtt_istemci.connect("*****", "*****", "*****")) // xxx= client adı, yyy=proje adı, zzz= token
  {
    Serial.print(".");
    delay(1000);
  }
  
  mqtt_istemci.subscribe("******");   //abone olunacak konu
}

void mesaj_geldi(String &konu, String &veri)    // gelen veriyi oku
{
  Serial.println(konu + ": "+ veri);
  int mesafeInt = veri.toInt();
  
  
  Firebase.setInt("mesafe", mesafeInt);
 
  if (Firebase.failed()) {
      Serial.print("yazdirma hatasi:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
}
