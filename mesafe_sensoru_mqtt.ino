#include <ESP8266WiFi.h>
#include <MQTTClient.h>

const char *ssid = "******";                 
const char *password = "*****";                  

WiFiClient wifi_istemci;
MQTTClient mqtt_istemci;

#define TRIG_PIN D1
#define ECHO_PIN D2

void setup() 
{
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
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
 
  mqtt_istemci.begin("******.shiftr.io", wifi_istemci);
}

void loop() 
{
  mqtt_istemci.loop();         
  
  if (!mqtt_istemci.connected())        
    baglan();                

  long duration, distance;
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;
    
  mqtt_istemci.publish("******", String(distance)); // publish edilecek konu
  delay(3000); 
                
}

void baglan()
{
 
  while (!mqtt_istemci.connect("******", "******", "*******")) // xxx=client adı, yyy=proje adı, zzz= token
  {
    Serial.print(".");
    delay(1000);
  }
}
