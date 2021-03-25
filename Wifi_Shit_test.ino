#include <ESP8266WiFi.h>

//Stepper Parts Begin
int stepCounter, steps=1000;

int enableM= 16, stepPinM=5, directionM=4;
//Stepper Parts end

const char* ssid = "Millivanilli";//type your ssid
const char* password = "UMFKJ2009";//type your password

int ledPin = 2; // GPIO2 of ESP8266
WiFiServer server(80);//Service Port

void setup() {

  
//Stepper Parts Begin
pinMode(enableM,OUTPUT);
pinMode(stepPinM,OUTPUT);
pinMode(directionM,OUTPUT);

digitalWrite(enableM,LOW);
//Stepper Parts End

  
Serial.begin(115200);
delay(10);

pinMode(ledPin, OUTPUT);
digitalWrite(ledPin, LOW);

// Connect to WiFi network
Serial.println();
Serial.println();
Serial.print("Connecting to ");
Serial.println(ssid);

WiFi.begin(ssid, password);

while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected");

// Start the server
server.begin();
Serial.println("Server started");

// Print the IP address
Serial.print("Use this URL to connect: ");
Serial.print("http://");
Serial.print(WiFi.localIP());
Serial.println("/");
}

void loop() {
// Check if a client has connected
WiFiClient client = server.available();
if (!client) {
return;
}

// Wait until the client sends some data
Serial.println("new client");
while(!client.available()){
delay(1);
}

// Read the first line of the request
String request = client.readStringUntil('\r');
Serial.println(request);
client.flush();

// Match the request

//**Do the shit you want to**
int value = LOW;
bool helpbool=false;
// im Uhrzeigersinn drehen


if (request.indexOf("/LED=ON") != -1) 
{
      //vvv old Test vvv
    //digitalWrite(ledPin, HIGH);
if(helpbool == false){
  helpbool=true; 
  digitalWrite(directionM,HIGH); // im Uhrzeigersinn drehen
  for(stepCounter = 0; stepCounter < steps; stepCounter++)
  {
    digitalWrite(stepPinM,HIGH);
    delay(1);
    digitalWrite(stepPinM,LOW);
    delay(1);
  }

  value = HIGH;
  
  Serial.println(helpbool);  
} 
}
//gegen Uhrzeiger drehen


if (request.indexOf("/LED=OFF") != -1)
{
        //vvv old Test vvv
      //digitalWrite(ledPin, LOW);
  if(helpbool!=true){
  digitalWrite(directionM,LOW); // gegen den Uhrzeigersinn

  for(stepCounter = 0; stepCounter < steps; stepCounter++)
  {
    digitalWrite(stepPinM,HIGH);
    delay(1);
    digitalWrite(stepPinM,LOW);
    delay(1);
  }

  value = LOW;
  helpbool=false;
  Serial.println(helpbool);
}
}





//Set ledPin according to the request
//digitalWrite(ledPin, value);

// Return the response
client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println(""); //  do not forget this one
client.println("<!DOCTYPE HTML>");
client.println("<html>");

client.print("Led pin is now: ");

if(value == HIGH) {
client.print("On");  
} else {
client.print("Off");
}
//####################################
//############hier pls buttons und slider #############
client.println("<br><br>");
client.println("Click <a href=\"/LED=ON\">here</a> turn the LED on pin 2 ON<br>");
client.println("Click <a href=\"/LED=OFF\">here</a> turn the LED on pin 2 OFF<br>");
client.println("</html>");
//############################################
delay(1);
Serial.println("Client disconnected");
Serial.println("");
}
