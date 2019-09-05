float encA;
float encB;

//Motor Pins in heading direction
int EN_A_RIGHTMOTOR = 13;      //Enable pin for right motor
int IN1_RIGHTMOTOR = 12;       //control pin for right motor
int IN2_RIGHTMOTOR = 11;       //control pin for right motor

int EN_B_LEFTMOTOR = 10;      //Enable pin for left motor
int IN3_EN_B_LEFTMOTOR = 9;        //control pin for left motor
int IN4_EN_B_LEFTMOTOR = 8;        //control pin for left motor


//EncoderA pins
int VCC_RIGHTMOTOR = 5;
int OUT_A_RIGHTMOTOR = 6;
int OUT_B_RIGHTMOTOR = 7;

//EncoderB pins
int VCC_LEFTMOTOR = 2;
int OUT_A_LEFTMOTOR = 3;
int OUT_B_LEFTMOTOR = 4;

//Initializing variables to store data
int motor_speedL;
int motor_speedR;
// Set speeds accordingly 0-min, 255-max
int maxspeed = 0; //Max is 255
int stopspeed = 0;





void setup ( ) {
  Serial.begin (9600); //Starting the serial communication at 9600 baud rate
  //Initializing the motor pins as output

  //Right Motor
  pinMode(EN_A_RIGHTMOTOR, OUTPUT);
  pinMode(IN1_RIGHTMOTOR, OUTPUT);
  pinMode(IN2_RIGHTMOTOR, OUTPUT);
  //Left Motor
  pinMode(EN_B_LEFTMOTOR, OUTPUT);
  pinMode(IN3_EN_B_LEFTMOTOR, OUTPUT);
  pinMode(IN4_EN_B_LEFTMOTOR, OUTPUT);

  //Right Encoder
  pinMode(VCC_RIGHTMOTOR, OUTPUT);
  pinMode(OUT_A_RIGHTMOTOR, INPUT);
  pinMode(OUT_B_RIGHTMOTOR, INPUT);

  //Left Encoder
  pinMode(VCC_LEFTMOTOR, OUTPUT);
  pinMode(OUT_A_LEFTMOTOR, INPUT);
  pinMode(OUT_B_LEFTMOTOR, INPUT);


  //Setting Direction of motors according to L298N motor controller
  // Left Motor
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Right motor
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  //Enable encoders
  digitalWrite(VCC_RIGHTMOTOR, HIGH);
  digitalWrite(VCC_LEFTMOTOR, HIGH);
}

void loop()
{
    motor_speedL = maxspeed;
    //motor_speedR = maxspeed;
    analogWrite(EN_A, motor_speedL);
    encA = digitalRead(outA);
    encB = digitalRead(outB);
    Serial.print(encA);
    Serial.print(' ');
    Serial.println(encB);
    //analogWrite(EN_B, motor_speedR);
    delay(10);

    //motor_speedL = stopspeed;
    //motor_speedR = stopspeed;
    //analogWrite(EN_A, motor_speedL);
    //analogWrite(EN_B, motor_speedR);
    //delay(100000);
    }
