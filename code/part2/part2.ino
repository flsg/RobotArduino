/***
* RobotArduino - Part 2
* Description: How to control robot to go left, right, forward and backward
* Author: Nhan Nguyen
* Email: hello@fablabsaigon.org
* Version: 1.0
***/
#define MOTORA_SPEED_PIN        D1
#define MOTORA_DIRECTION_PIN    D3
#define MOTORB_SPEED_PIN        D2
#define MOTORB_DIRECTION_PIN    D4

void setup() {
    setupRobot();
}

void loop() {
    goForward(800);
    delay(3000);
    goRight(800);
    delay(3000);
    goLeft(800);
    delay(3000);
    goBackward(800);
    delay(3000);
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
