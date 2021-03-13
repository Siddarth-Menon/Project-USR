#include <Wire.h>
#include <ESP8266WiFi.h>
char r[7];
String apiKey = "4ZG8QNAXNYH1PTCR";     //  Enter your Write API key from ThingSpeak

const char *ssid =  "SID";     // replace with your wifi ssid and wpa2 key
const char *pass =  "jello_green";
const char* server = "api.thingspeak.com";

WiFiClient client;

int  ppm,m, k=6;
int i,j,ppm1, m1,u,temp;
char sensorData[7],c;
void setup() {
 Serial.begin(9600); /* begin serial for debug */
 Wire.begin(D1, D2); /* join i2c bus with SDA=D1 and SCL=D2 of NodeMCU */

 
       Serial.println("Connecting to ");
       Serial.println(ssid);
 
 
       WiFi.begin(ssid, pass);
 
      while (WiFi.status() != WL_CONNECTED) 
     {
            delay(500);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");
      
}

void loop() {
 Wire.beginTransmission(8); /* begin with device address 8 */
 Wire.write("Hello");  /* sends hello string */
 Wire.endTransmission();    /* stop transmitting */

 Wire.requestFrom(8, 4); 
 while(Wire.available()){
    char c = Wire.read();
    r[i]=c;
    i++;
    if(i==4)
    {
      i=0;
      } 
 }
  
  temp=r[0];
  ppm=r[1];
 ppm=ppm*10;
  u=r[2];
  m=r[3];
  m=m*10;
  
  String stringOne =  String(temp, DEC);
  String stringTwo =  String(ppm, DEC);
   String stringThree =  String(u, DEC);
  String stringFour =  String(m, DEC);
  Serial.print(stringOne);
  Serial.print(stringTwo);
   Serial.print(stringThree);
  Serial.print(stringFour);
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////

                         if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {  
                            
                             String postStr = apiKey;
                             postStr +="&field1=";
                             postStr += stringOne;
                             postStr +="&field2=";
                             postStr += stringTwo;
                             postStr +="&field3=";
                             postStr += stringThree;
                             postStr +="&field4=";
                             postStr += stringFour;
                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                             Serial.print("Temperature: ");
                             Serial.print(stringOne);
                             Serial.print(" GAS ppm ");
                             Serial.print(stringTwo);
                             Serial.print("distance: ");
                             Serial.print(stringThree);
                             Serial.print(" metal ");
                             Serial.print(stringFour);
                             Serial.println("%. Send to Thingspeak.");
                        }
          client.stop();
 
          Serial.println("Waiting...");
          
 delay(12000);
 delay(3000);
}
