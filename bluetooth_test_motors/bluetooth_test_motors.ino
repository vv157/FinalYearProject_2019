#include <SoftwareSerial.h>
#include <Servo.h>

//FINAL YEAR PROJECT

Servo myservo;  // creating object for the two servos
Servo myservo2;

// Servo that will provide with the feeding mechanism
int servoPin = 3; // declaring the pins PWM that control the servos
int servoPin2 = 5;

//Motors that will provide with with the launching mechanism
int motor1Pin1 = 7;  // declaring the pins for the dc motor(right)
int motor1Pin2 = 8; 
int enable1Pin_right_motor = 6; 

int motor1Pin3 = 9; // declaring the pins for the dc motor(left)
int motor1Pin4 = 10; 
int enable1Pin_left_motor = 11;


int speed_of_firing;
int a = 0;
int b = 0;


SoftwareSerial bt(2,4); //(RX,TX) pin declation for serial communication with the bluetooth module
char Incoming_value = 0; //Variable for storing Incoming_value
void setup() 
{
  Serial.begin(9600); 
  bt.begin(9600);             //Sets the data rate in bits per second (baud) for serial data transmission
  pinMode(12, OUTPUT);        //Sets digital pin 12 as output pin
  myservo.attach(servoPin);   // attaches the servo on pin 3 and 5 to the servo objects
  myservo2.attach(servoPin2);                            
  pinMode(motor1Pin1, OUTPUT); //Setting pins of the motors to output
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin_right_motor, OUTPUT);
  pinMode(motor1Pin3, OUTPUT);
  pinMode(motor1Pin4, OUTPUT);
  pinMode(enable1Pin_left_motor, OUTPUT);
  
  digitalWrite(motor1Pin1, HIGH); //
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor1Pin3, LOW);
  digitalWrite(motor1Pin4, HIGH);
}
void loop()
{
  if(bt.available() > 0)  
  {
    Incoming_value = bt.read();      //Read the incoming data and store it into variable Incoming_value
    Serial.print(Incoming_value);    //Print Value of Incoming_value in Serial monitor
    Serial.print("\n");              //New line 
    if(Incoming_value == 's')        //Checks whether value of Incoming_value is equal to s (when the start button is pressd from the app)
    {           
      motors_at_transition();
      delay(100);

     
    }
    
    else if(Incoming_value == 't')       //Checks whether value of Incoming_value is equal to t (when the stop button is pressed from the app)
    {
      motors_off();
      delay(100);
      stop_fire();
    }
    else if(Incoming_value == 'f')       //Checks whether value of Incoming_value is equal to t (when the stop button is pressed from the app)
    {
      speed_of_firing = 0;
      servo_fire(speed_of_firing);
    }  
//    else if(Incoming_value == 'l')       //Checks whether value of Incoming_value is equal to l(when the slow button is pressed from the app)
//    {
//      motors_at_top_speed();
//      delay(100);
//      speed_of_firing = 1000;
//      for(int i; i>3; i++)
//      {
//        servo_fire(speed_of_firing);
//        i++; 
//      }
//    }
//    
//    else if(Incoming_value == 'f')       //Checks whether value of Incoming_value is equal to f (when the fast button is pressed from the app) 
//    {
//      motors_at_top_speed();
//      delay(100);
//      speed_of_firing = -500;
//      for(int i; i>3; i++)
//      {
//        servo_fire(speed_of_firing);
//        i++; 
//      }
//    }
//   
//    else if(Incoming_value == 'r')       //Checks whether value of Incoming_value is equal to r(when the random button is pressed from the app)
//    {
//      motors_at_top_speed();
//      delay(100);
//      speed_of_firing = 0;
//      for(int i; i>3; i++)
//      {
//        servo_fire(speed_of_firing);
//        i++; 
//      }
//    }

    else if(Incoming_value == '1')       //Checks whether value of Incoming_value is equal to 1(when the corrisponding button is pressed from the app)
    {
      position_1();
      delay(100);
      
    }

    else if(Incoming_value == '2')       //Checks whether value of Incoming_value is equal to 2(when the corrisponding button is pressed from the app)
    {
      position_2();
      delay(100);
      
    }

    else if(Incoming_value == '3')       //Checks whether value of Incoming_value is equal to 3(when the corrisponding button is pressed from the app)
    {
      position_3();
      delay(100);
      
    }

    else if(Incoming_value == '4')       //Checks whether value of Incoming_value is equal to 4(when the corrisponding button is pressed from the app)
    {
      position_4();
      delay(100);
      
    }

    else if(Incoming_value == '5')       //Checks whether value of Incoming_value is equal to 5(when the corrisponding button is pressed from the app)
    {
      position_5();
      delay(100);
     
    }

    else if(Incoming_value == '6')       //Checks whether value of Incoming_value is equal to 6(when the corrisponding button is pressed from the app)
    {
      position_6();
      delay(100);
      
    }

    else if(Incoming_value == '7')       //Checks whether value of Incoming_value is equal to 7(when the corrisponding button is pressed from the app)
    {
      position_7();
      delay(100);
      
    }

    else if(Incoming_value == '8')       //Checks whether value of Incoming_value is equal to 8(when the corrisponding button is pressed from the app)
    {
      position_8();
      delay(100);
      
    }
   
    else if(Incoming_value == '9')       //Checks whether value of Incoming_value is equal to 9(when the corrisponding button is pressed from the app)
    {
      position_9();
      delay(100);
      
    }     
    }
  }
                           



void servo_fire(int delta_time)     
{    
  myservo.write(125);//zero position
  delay(1000+delta_time);
  myservo.write(75);// drop position
  delay(1000+delta_time);
  myservo.write(125);//zero position
  delay(1000+delta_time);
  myservo2.write(30);//taking position 
  delay(1000+delta_time);
  myservo2.write(85);//releasing position
  delay(1000+delta_time);
  myservo2.write(30);//taking position 
  delay(1000+delta_time);
}

void stop_fire()
{
  myservo.write(125);//zero position
  delay(1000);
  myservo2.write(15);//taking position
  delay(1000);
  
}

void motors_at_transition()
{
  analogWrite(enable1Pin_right_motor, 240);
  analogWrite(enable1Pin_left_motor, 240);
}

void motors_off()
{
  analogWrite(enable1Pin_right_motor, 0);
  analogWrite(enable1Pin_left_motor, 0);
}

void position_1()
{
  analogWrite(enable1Pin_right_motor, 150);
  analogWrite(enable1Pin_left_motor, 255);
}
void position_2()
{
  analogWrite(enable1Pin_right_motor, 255);
  analogWrite(enable1Pin_left_motor, 255);
}
void position_3()
{
  analogWrite(enable1Pin_right_motor, 255);
  analogWrite(enable1Pin_left_motor, 150);
}
void position_4()
{
  analogWrite(enable1Pin_right_motor, 150);
  analogWrite(enable1Pin_left_motor, 100);
}
void position_5()
{
  analogWrite(enable1Pin_right_motor, 150);
  analogWrite(enable1Pin_left_motor, 150);
}
void position_6()
{
  analogWrite(enable1Pin_right_motor, 100);
  analogWrite(enable1Pin_left_motor, 150);
}
void position_7()
{
  analogWrite(enable1Pin_right_motor, 80);
  analogWrite(enable1Pin_left_motor, 50);
}
void position_8()
{
  analogWrite(enable1Pin_right_motor, 65);
  analogWrite(enable1Pin_left_motor, 65);
}
void position_9()
{
  analogWrite(enable1Pin_right_motor, 60);
  analogWrite(enable1Pin_left_motor, 90);
}
