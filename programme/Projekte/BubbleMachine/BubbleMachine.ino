//-----Include Libaries
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Rotary.h>
#include <EEPROM.h>
#include <VarSpeedServo.h>

#include "Menu.h"

//-----Define Pins
#define EXTRA_PIN 9
#define SERVO_PIN 10
#define ENCODER_CLK_PIN 2
#define ENCODER_DT_PIN 3
#define ENCODER_SW_PIN 4
#define M_ENABLE1_PIN 5
#define M_IN1_PIN 6
#define M_IN2_PIN 7
#define M_ENABLE2_PIN 11
#define M_IN3_PIN 8
#define M_IN4_PIN 12

// EEPROM Addresses
#define EEPROM_CHECK 0
#define EEPROM_SERVO_SPEED 2
#define EEPROM_SERVO_ANGLE 4
#define EEPROM_MOTOR_DELAY 6
#define EEPROM_MOTOR1_SPEED 8
#define EEPROM_MOTOR2_SPEED 10
#define EEPROM_MOTOR_DElAY2 12
#define EEPROM_SERVO_DELAY 14
#define EEPROM_SERVO_SPEED2 16

//-----Define Constants
#define EEPROM_CHECK_NUMBER 43
#define SERVO_DEFAULT_ANGLE 10

//-----Define Vars

//-----Create class instances
LiquidCrystal_I2C lcd(0x3F, 16, 2);
Menu menu1(lcd);
Rotary rotary = Rotary(ENCODER_DT_PIN, ENCODER_CLK_PIN);
VarSpeedServo servo1;

//-----Util Functions
int readIntFromEEPROM(int address)
{
    return (EEPROM.read(address) << 8) + EEPROM.read(address + 1);
}

void updateIntIntoEEPROM(int address, int number)
{
    if (readIntFromEEPROM(address) != number)
    {
        EEPROM.write(address, number >> 8);
        EEPROM.write(address + 1, number & 0xFF);
    }
}

//-----Functions
void main_loop()
{
    unsigned char result = rotary.process();

    if (result)
    {
        if (result == DIR_CW) // left
        {
            menu1.go(1);
        }
        else // right
        {
            menu1.go(-1);
        }
    }

    if (!digitalRead(ENCODER_SW_PIN))
    {
        menu1.select();

        // debounce button
        while (!digitalRead(ENCODER_SW_PIN))
        {
        }
    }
}

void setup_eeprom()
{
    if (EEPROM.read(EEPROM_CHECK) != EEPROM_CHECK_NUMBER)
    {
        EEPROM.write(EEPROM_CHECK, EEPROM_CHECK_NUMBER);
        updateIntIntoEEPROM(EEPROM_SERVO_SPEED, 20);
        updateIntIntoEEPROM(EEPROM_SERVO_ANGLE, 70);
        updateIntIntoEEPROM(EEPROM_MOTOR_DELAY, 1000);
        updateIntIntoEEPROM(EEPROM_MOTOR1_SPEED, 200);
        updateIntIntoEEPROM(EEPROM_MOTOR2_SPEED, 200);
        updateIntIntoEEPROM(EEPROM_MOTOR_DElAY2, 2000);
        updateIntIntoEEPROM(EEPROM_SERVO_DELAY, 1000);
        updateIntIntoEEPROM(EEPROM_SERVO_SPEED2, 20);
    }
}

void motors_off()
{
    digitalWrite(M_ENABLE1_PIN, LOW);
    digitalWrite(M_ENABLE2_PIN, LOW);
    digitalWrite(M_IN1_PIN, LOW);
    digitalWrite(M_IN2_PIN, LOW);
    digitalWrite(M_IN3_PIN, LOW);
    digitalWrite(M_IN4_PIN, LOW);
}

void print_step(int step, int maxStep, String name)
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Step " + (String)step + " of " + (String)maxStep);
    lcd.setCursor(0, 1);
    lcd.print(name);
}

//-----Event handlers
void handle_start()
{
    print_step(1, 5, "Load soap bubble");
    servo1.write(readIntFromEEPROM(EEPROM_SERVO_ANGLE) + SERVO_DEFAULT_ANGLE, readIntFromEEPROM(EEPROM_SERVO_SPEED), true);

    delay(readIntFromEEPROM(EEPROM_MOTOR_DELAY));

    print_step(2, 5, "Start rotors");
    digitalWrite(M_IN1_PIN, LOW);
    digitalWrite(M_IN2_PIN, HIGH);
    analogWrite(M_ENABLE1_PIN, readIntFromEEPROM(EEPROM_MOTOR1_SPEED));
    digitalWrite(M_IN3_PIN, LOW);
    digitalWrite(M_IN4_PIN, HIGH);
    analogWrite(M_ENABLE2_PIN, readIntFromEEPROM(EEPROM_MOTOR2_SPEED));

    delay(readIntFromEEPROM(EEPROM_MOTOR_DElAY2));

    print_step(3, 5, "Pause");
    motors_off();

    delay(readIntFromEEPROM(EEPROM_SERVO_DELAY));

    print_step(4, 5, "Go home position");

    servo1.write(SERVO_DEFAULT_ANGLE, readIntFromEEPROM(EEPROM_SERVO_SPEED2), true);

    print_step(5, 5, "Finish");

    delay(1000);

    menu1.go_back();
}

void handle_load()
{
    print_step(1, 4, "Servo up");

    while (!digitalRead(ENCODER_SW_PIN))
    {
    }

    servo1.write(80, 100, true);

    print_step(2, 4, "Click to go down");

    // wait for click on encoder
    while (digitalRead(ENCODER_SW_PIN))
    {
    }

    print_step(3, 4, "Servo down");

    servo1.write(SERVO_DEFAULT_ANGLE, 100, true);

    print_step(4, 4, "Finish");

    delay(1000);

    menu1.go_back();
}

void handle_about()
{
    lcd.clear();
    lcd.print("     LATOM      ");
    lcd.setCursor(0, 1);
    lcd.print(" Bubble machine ");
}

void empty_event_handler() {}

void handle_change_sv(int value) { updateIntIntoEEPROM(EEPROM_SERVO_SPEED, value); }
void handle_change_sa(int value) { updateIntIntoEEPROM(EEPROM_SERVO_ANGLE, value); }
void handle_change_mt(int value) { updateIntIntoEEPROM(EEPROM_MOTOR_DELAY, value); }
void handle_change_m1v(int value) { updateIntIntoEEPROM(EEPROM_MOTOR1_SPEED, value); }
void handle_change_m2v(int value) { updateIntIntoEEPROM(EEPROM_MOTOR2_SPEED, value); }
void handle_change_mt2(int value) { updateIntIntoEEPROM(EEPROM_MOTOR_DElAY2, value); }
void handle_change_st(int value) { updateIntIntoEEPROM(EEPROM_SERVO_DELAY, value); }
void handle_change_sv2(int value) { updateIntIntoEEPROM(EEPROM_SERVO_SPEED2, value); }

//-----Setup function
void setup()
{
    //-----Start serial connection
    Serial.begin(115200);

    //-----Set Pinmodes
    pinMode(ENCODER_SW_PIN, INPUT_PULLUP);

    pinMode(M_ENABLE1_PIN, OUTPUT);
    pinMode(M_IN1_PIN, OUTPUT);
    pinMode(M_IN2_PIN, OUTPUT);
    pinMode(M_ENABLE2_PIN, OUTPUT);
    pinMode(M_IN3_PIN, OUTPUT);
    pinMode(M_IN4_PIN, OUTPUT);

    // init motor
    motors_off();

    // init lcd
    lcd.init();
    lcd.backlight();

    // init servo
    servo1.attach(SERVO_PIN);
    servo1.write(SERVO_DEFAULT_ANGLE, 255, true);

    // init eeprom
    setup_eeprom();

    // config menu
    menu1.register_option("Start", handle_start);
    menu1.register_option("Load", handle_load);
    menu1.register_option("About", handle_about);
    menu1.register_option("Servo  - speed", empty_event_handler, "S(v)", handle_change_sv, readIntFromEEPROM(EEPROM_SERVO_SPEED));
    menu1.register_option("Servo  - angle", empty_event_handler, "S(a)", handle_change_sa, readIntFromEEPROM(EEPROM_SERVO_ANGLE));
    menu1.register_option("Motor  - delay", empty_event_handler, "M(t)", handle_change_mt, readIntFromEEPROM(EEPROM_MOTOR_DELAY), 100);
    menu1.register_option("Motor1 - speed", empty_event_handler, "M1(v)", handle_change_m1v, readIntFromEEPROM(EEPROM_MOTOR1_SPEED));
    menu1.register_option("Motor2 - speed", empty_event_handler, "M2(v)", handle_change_m2v, readIntFromEEPROM(EEPROM_MOTOR2_SPEED));
    menu1.register_option("Motor  - delay", empty_event_handler, "M(t2)", handle_change_mt2, readIntFromEEPROM(EEPROM_MOTOR_DElAY2), 100);
    menu1.register_option("Servo  - delay", empty_event_handler, "S(t)", handle_change_st, readIntFromEEPROM(EEPROM_SERVO_DELAY), 100);
    menu1.register_option("Servo  - speed", empty_event_handler, "S(v)", handle_change_sv2, readIntFromEEPROM(EEPROM_SERVO_SPEED2));

    menu1.update();
}

//-----Loop function
void loop()
{
    main_loop();
}
