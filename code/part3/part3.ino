/***
* RobotArduino - Part 3
* Description: How to automate robot using line following sensors
* Author: Nhan Nguyen
* Email: hello@fablabsaigon.org
* Version: 1.0
***/
//#define DEBUG

#define MOTORA_SPEED_PIN        D1
#define MOTORA_DIRECTION_PIN    D3
#define MOTORB_SPEED_PIN        D2
#define MOTORB_DIRECTION_PIN    D4

#define LINE_SENSOR_LEFT        D6
#define LINE_SENSOR_CENTER      D7
#define LINE_SENSOR_RIGHT       D8
#define TIMER                   100  // 10ms

long currentTime = 0;
long lastTimeCheck = 0;

void setup() {
    #ifdef DEBUG
    Serial.begin(115200);
    Serial.println("RobotKit");
    #endif
    // setup robot
    setupRobot();

    // setup line following sensor
    setupLineSensor();
}

void loop() {
  checkLineSensor();
}

/***
* Function: setupLineSensor()
* Arguments: None
* Return: None
* Description: Setup line following sensor for first time use
***/
void setupLineSensor() {
    pinMode(LINE_SENSOR_CENTER, INPUT);
    pinMode(LINE_SENSOR_LEFT, INPUT);
    pinMode(LINE_SENSOR_RIGHT, INPUT);
}

/***
* Function: checkLineSensor()
* Arguments: None
* Return: None
* Description: Control robot using line following sensor
***/
void checkLineSensor() {
    uint8_t sensorCenter, sensorLeft, sensorRight;

    currentTime = millis();
    if((currentTime - lastTimeCheck) >= TIMER) {
        sensorCenter = digitalRead(LINE_SENSOR_CENTER);
        sensorLeft = digitalRead(LINE_SENSOR_LEFT);
        sensorRight = digitalRead(LINE_SENSOR_RIGHT);
        #ifdef DEBUG
        Serial.print(sensorCenter);
        Serial.print(", ");
        Serial.print(sensorLeft);
        Serial.print(", ");
        Serial.println(sensorRight);
        #endif
        if(sensorCenter == HIGH && sensorLeft == LOW && sensorRight == LOW) {
            goForward(800);
        } else if (sensorCenter == HIGH && sensorLeft == HIGH && sensorRight == LOW) {
            goLeft(800);
        } else if (sensorCenter == HIGH && sensorLeft == LOW && sensorRight == HIGH) {
            goRight(800);
        } else {
            stop(); // Hum, does this case happen?
        }
        lastTimeCheck = currentTime;
    }
}

/***
* Function: setupRobot()
* Arguments: None
* Return: None
* Description: Setup robot at first
***/
void setupRobot() {
    // setup motor A pins
    pinMode(MOTORA_SPEED_PIN, OUTPUT);
    pinMode(MOTORA_DIRECTION_PIN, OUTPUT);

    // setup motor B pins
    pinMode(MOTORB_SPEED_PIN, OUTPUT);
    pinMode(MOTORB_DIRECTION_PIN, OUTPUT);

    // stop robot at first
    stop();
}

/***
* Function: goForward()
* Arguments: targetSpeed (how fast the robot can run)
* Return: None
* Description: Make robot go forward
***/
void goForward(int targetSpeed) {
    if(targetSpeed >=0 and targetSpeed <= 1023) {
        digitalWrite(MOTORA_DIRECTION_PIN, 0);
        analogWrite(MOTORA_SPEED_PIN, targetSpeed);
        digitalWrite(MOTORB_DIRECTION_PIN, 0);
        analogWrite(MOTORB_SPEED_PIN, targetSpeed);
    }
}

/***
* Function: goBackward()
* Arguments: targetSpeed (how fast the robot can run)
* Return: None
* Description: Make robot go backward
***/
void goBackward(int targetSpeed) {
    if(targetSpeed >=0 and targetSpeed <= 1023) {
        digitalWrite(MOTORA_DIRECTION_PIN, 1);
        analogWrite(MOTORA_SPEED_PIN, targetSpeed);
        digitalWrite(MOTORB_DIRECTION_PIN, 1);
        analogWrite(MOTORB_SPEED_PIN, targetSpeed);
    }
}

/***
* Function: goLeft()
* Arguments: targetSpeed (how fast the robot can run)
* Return: None
* Description: Make robot go left
***/
void goLeft(int targetSpeed) {
    if(targetSpeed >=0 and targetSpeed <= 1023) {
        digitalWrite(MOTORA_DIRECTION_PIN, 0);
        analogWrite(MOTORA_SPEED_PIN, targetSpeed);
        digitalWrite(MOTORB_DIRECTION_PIN, 1);
        analogWrite(MOTORB_SPEED_PIN, targetSpeed);
    }
}

/***
* Function: goRight()
* Arguments: targetSpeed (how fast the robot can run)
* Return: None
* Description: Make robot go right
***/
void goRight(int targetSpeed) {
    if(targetSpeed >=0 and targetSpeed <= 1023) {
        digitalWrite(MOTORA_DIRECTION_PIN, 1);
        analogWrite(MOTORA_SPEED_PIN, targetSpeed);
        digitalWrite(MOTORB_DIRECTION_PIN, 0);
        analogWrite(MOTORB_SPEED_PIN, targetSpeed);
    }
}

/***
* Function: stop()
* Arguments: None
* Return: None
* Description: Stop robot 
***/
void stop() {
    analogWrite(MOTORA_SPEED_PIN, 0);
    analogWrite(MOTORB_SPEED_PIN, 0);
}
