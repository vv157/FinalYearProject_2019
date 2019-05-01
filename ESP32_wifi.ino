/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/

// Load Wi-Fi library
#include <WiFi.h>
#include <Servo.h>
// Creating servo Objectto control servo
Servo servo2;
Servo servo1;

//Network credentials
const char* ssid     = "ASUS";
const char* password = "Krishna2017";

// Setting web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String output26_startState = "off";
String output27_stopState = "off";
String output26_start = "off";
String output27_stop = "off";
String output23_fast  = "off";
String output22_slow  = "off";
String output21_random  = "off";
String output19_arrow_left  = "off";
String output18_arrow_center  = "off";
String output_arrow_right = "off";
// Assign output variables to GPIO pins
const int servo2_pwm = 15; 
//Variable to inizialize position variable
int pos = 0;
bool start_state = false;
int count = 0;
// Setting pins for motors
static const int motor1Pin1 = 33; 
static const int motor1Pin2 = 25; 
static const int enable1Pin = 32; 
static const int motor1Pin3 = 27; 
static const int motor1Pin4 = 13; 
static const int enable1Pin2 = 26;
static const int freq = 30000;
static const int pwmChannel = 0;
static const int pwmChannel2 = 1;
static const int resolution = 8;
int dutyCycle1 = 250;



void setup() {
  Serial.begin(115200);
  // Initialize pins
  servo2.attach(16);
  servo1.attach(17);
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  pinMode(motor1Pin3, OUTPUT);
  pinMode(motor1Pin4, OUTPUT);
  pinMode(enable1Pin2, OUTPUT);
  ledcSetup(pwmChannel, freq, resolution);
  ledcSetup(pwmChannel2, freq, resolution);
  ledcAttachPin(enable1Pin, pwmChannel);
  ledcAttachPin(enable1Pin2, pwmChannel2); 
  

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // turns the GPIOs on and off
            if (header.indexOf("GET /start/on") >= 0) {
              
              output26_startState = "on";
//              put function
              servo1_motion();
              servo2_motion();
              start_state = true;
//            motor_control_on();
      
              

            } else if (header.indexOf("GET /start/off") >= 0) {
              Serial.println("GPIO 26 off");
              
//              put function
              output26_startState = "on";
//            put function
//              motor_control_off();
//              start_state = false;
//              while(start_state)
//              {
//                servo1_motion();
//                servo2_motion();
//              }
//              digitalWrite(output26_start, LOW);
            } else if (header.indexOf("GET /slow/on") >= 0) {
              
//              digitalWrite(output27_stop, HIGH);
            } else if (header.indexOf("GET /27/off") >= 0) {
              Serial.println("GPIO 27 off");
              output27_stopState = "off";
//              digitalWrite(output27_stop, LOW);
            }
            
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
        
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; margin: 0; display: inline; text-align: center;}");
            client.println("body{background-color: darkgray; margin: 0;}");
            client.println(".title_page{color:white; width: 100%; background-color: black;margin: 0; padding: 5%;}");
            client.println(".button { background-color: #4CAF50; border: none;border-radius: 4px; color: white; padding: 2% 2%; width: 30%;  box-shadow: 1px 1px 2px 2px rgba(0,0,0,0.7);");
            client.println("text-decoration: none; font-size: 100%; margin: 0px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555; }");
            client.println(".positioning_area_cell_1{ height: 100%; background-color: none; color: white; diaplay: table-cell; vertical-align: middle;}");
            client.println(".positioning_area_cell_2{  background-color: none; color: white;display: table-cell;vertical-align:middle;}");
            client.println(".positioning_area_row {display: table-row; padding: 1%; margin:10%; }");
            client.println(".circle{width:50px; height: 50px; border-radius: 50px; background-color: gray; border: 1px solid white; position: relative; left:107%; margin: 30%;box-shadow: 1px 1px 10px 2px rgba(0,0,0,0.7);}");
            client.println(".positioning_table{ height: 100px; width: 100%; background-color: none; color: white;display: table; margin-bottom: 10%; margin-top: 10%;}</style></head>");
            
            // Web Page Heading
            client.println("<body><h1 class=\"title_page\">Final Year Project</h1>");
            if(output26_startState=="off")
            {
            
              client.println("<div class=\"positioning_table\">"
                               "<div class= \"positioning_area_cell_1\">"
                                    "<div class=\"positioning_area_row\">"
                                       "<div class=\"circle\"></div>"  
                                    "</div>"
                                    "<div class=\"positioning_area_row\">"
                                        "<div class=\"circle\"></div>" 
                                    "</div>"
                                    "<div class=\"positioning_area_row\">"
                                        "<div class=\"circle\"></div>" 
                                    "</div>"
                                "</div>"
                                "<div class=\"positioning_area_cell_2\">"
                                    "<div class=\"positioning_area_row\">"
                                        "<div class=\"circle\"></div>" 
                                    "</div>"
                                    "<div class=\"positioning_area_row\">"
                                        "<div class=\"circle\"></div>" 
                                    "</div>"
                                    "<div class=\"positioning_area_row\">"
                                        "<div class=\"circle\"></div>" 
                                    "</div>"   
                                "</div>"
                                "<div class=\"positioning_area_cell_2\">"
                                    "<div class=\"positioning_area_row\">"
                                        "<div class=\"circle\"></div>" 
                                    "</div>"
                                    "<div class=\"positioning_area_row\">"
                                        "<div class=\"circle\"></div>" 
                                    "</div>"
                                    "<div class=\"positioning_area_row\">"
                                        "<div class=\"circle\"></div>" 
                                    "</div>"
                                "</div>"
                            "</div>" 
                               
                               "</div>"
                          "</div>");
                client.println(
                                 "<p>"
                                    "<a href=\"/start/on\">"
                                          "<button class=\"button button2\">START</button>"
                                    "</a>"
                                 "</p>"
                            
                                 "<p>"
                                    "<a href=\"/start/off\">"
                                          "<button class=\"button button2\">STOP</button>"
                                    "</a>"
                                 "</p>"
                         
                     
                                 "<p>"
                                    "<a href=\"/fast/on\">"
                                          "<button class=\"button button2\">FAST</button>"
                                    "</a>"
                                 "</p>"
  
                                 "<p>"
                                    "<a href=\"/slow/on\">"
                                          "<button class=\"button button2\">SLOW</button>"
                                    "</a>"
                                 "</p>"
                                    );
                client.println("<p>"
                               "<a href=\"/random/on\">"
                                    "<button class=\"button button2\">RANDOM</button>"
                               "</a>"
                             "</p>");
              
            }else if(output26_startState=="on")
            {
              client.println("<div class=\"positioning_table\">"
                               "<div class= \"positioning_area_cell_1\">"
                                    "<div class=\"positioning_area_row\">"
                                       "<div class=\"circle\"></div>"  
                                    "</div>"
                                    "<div class=\"positioning_area_row\">"
                                        "<div class=\"circle\"></div>" 
                                    "</div>"
                                    "<div class=\"positioning_area_row\">"
                                        "<div class=\"circle\"></div>" 
                                    "</div>"
                                "</div>"
                                "<div class=\"positioning_area_cell_2\">"
                                    "<div class=\"positioning_area_row\">"
                                        "<div class=\"circle\"></div>" 
                                    "</div>"
                                    "<div class=\"positioning_area_row\">"
                                        "<div class=\"circle\"></div>" 
                                    "</div>"
                                    "<div class=\"positioning_area_row\">"
                                        "<div class=\"circle\"></div>" 
                                    "</div>"   
                                "</div>"
                                "<div class=\"positioning_area_cell_2\">"
                                    "<div class=\"positioning_area_row\">"
                                        "<div class=\"circle\"></div>" 
                                    "</div>"
                                    "<div class=\"positioning_area_row\">"
                                        "<div class=\"circle\"></div>" 
                                    "</div>"
                                    "<div class=\"positioning_area_row\">"
                                        "<div class=\"circle\"></div>" 
                                    "</div>"
                                "</div>"
                            "</div>" 
                               
                               "</div>"
                          "</div>");
                client.println(
                                 "<p>"
                                    "<a href=\"/start/on\">"
                                          "<button class=\"button button2 \">START</button>"
                                    "</a>"
                                 "</p>"
                            
                                 "<p>"
                                    "<a href=\"/start/off\">"
                                          "<button class=\"button button2\">STOP</button>"
                                    "</a>"
                                 "</p>"
                         
                     
                                 "<p>"
                                    "<a href=\"/fast/on\">"
                                          "<button class=\"button button2\">FAST</button>"
                                    "</a>"
                                 "</p>"
  
                                 "<p>"
                                    "<a href=\"/slow/on\">"
                                          "<button class=\"button button2\">SLOW</button>"
                                    "</a>"
                                 "</p>"
                                    );
                client.println("<p>"
                               "<a href=\"/random/on\">"
                                    "<button class=\"button button2\">RANDOM</button>"
                               "</a>"
                             "</p>");
            }
           
            
            
            // Display current state, and ON/OFF buttons for GPIO 26  
//            client.println("<p>GPIO 26 - State " + output26_startState + "</p>");
            // If the output26_startState is off, it displays the ON button       
//            if (output26_startState=="off") {
//              client.println("<p><a href=\"/start/on\"><button class=\"button button2\" style =\"float:left\">START</button></a></p>");
//            } else {
//              client.println("<p><a href=\"/start/off\"><button class=\"button \" style =\"float:left\">START</button></a></p>");
//            } 
               
            // Display current state, and ON/OFF buttons for GPIO 27  
//            client.println("<p>GPIO 27 - State " + output27_stopState + "</p>");
            // If the output27_stopState is off, it displays the ON button       
//            if (output27_stopState=="off") {
//              client.println("<p><a href=\"/27/on\"><button class=\"button button2\">STOP</button></a></p>");
//            } else {
//              client.println("<p><a href=\"/27/off\"><button class=\"button \"  style =\"float:right;margin-left: 3%\">STOP</button></a></p>");
//            }
//            client.println("<p><a href=\"\"></a><button class= \"button button2 \" style =\"float:right;margin-left: 3%;\">SLOW</button></p>");
//            client.println("<p><a href=\"\"></a><button class= \"button  button2\">FAST</button></p>");
//            client.println("</body></html>");
            
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}



void servo2_motion()
{

 
  for(pos = 0; pos <= 180; pos+= 1)
  {
    // tells the servo to go to the position in variable pos
    servo2.write(pos);
    // waits 15ms after the servo reaches the position
    delay(15);
  }
  for(pos = 180; pos >= 0; pos -= 1)
  {
    // tells the servo to go to the position in variable pos
    servo2.write(pos);
    // waits 15ms after the servo reaches the position
    delay(15);
  }

}

void servo1_motion()
{
  for(pos = 0; pos <= 180; pos+= 1)
  {
    // tells the servo to go to the position in variable pos
    servo1.write(pos);
    // waits 15ms after the servo reaches the position
    delay(15);
  }
  for(pos = 180; pos >= 0; pos -= 1)
  {
    // tells the servo to go to the position in variable pos
    servo1.write(pos);
    // waits 15ms after the servo reaches the position
    delay(15);
  }
  
}

void motor_control_on()
{
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor1Pin3, LOW);
  digitalWrite(motor1Pin4, HIGH);
  ledcWrite(pwmChannel, dutyCycle1);
  ledcWrite(pwmChannel2, dutyCycle1);
  delay(1000);
}
void motor_control_off()
{
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor1Pin3, LOW);
  digitalWrite(motor1Pin4, LOW);
  ledcWrite(pwmChannel, dutyCycle1);
  ledcWrite(pwmChannel2, dutyCycle1);
}

