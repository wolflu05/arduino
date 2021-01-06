//#####################################################
//########Def Variables and include Librarys###########
//#####################################################

//-----Options
#define ledIntensity 2

//-----Define Pins
#define sw_clear 3
#define Joystick_sw 2
#define Joystick_x 0
#define Joystick_y 1

//-----Define Vars
boolean led[8][8] = {};

int cur_x = 3;
int cur_y = 3;

int threshold = 150;
volatile unsigned long oldTime = 0, oldTime1 = 0, debounceTime = 20, holdTime = 3000;

//-----Include Librarys
#include "LedControl.h"
#include <EEPROM.h>

//-----Configure LedControl
LedControl lc = LedControl(12, 10, 11, 1);

//#####################################################
//############Def Functions############################
//#####################################################

// set Pixel to chache
void setPixel(int x, int y, boolean state)
{
  led[x][y] = state;
  // write to EEPROM
  EEPROM.update(x * 8 + y, state);
}

// draw chache to display
void draw()
{
  for (int i = 0; i < 8; i++)
  {
    for (int ii = 0; ii < 8; ii++)
    {
      lc.setLed(0, i, ii, led[i][ii]);
    }
  }
}

// clear display
void clear()
{
  for (int i = 0; i < 8; i++)
  {
    for (int ii = 0; ii < 8; ii++)
    {
      setPixel(i, ii, false);
    }
  }
  draw();
}

// set pixel interrupt
void sw_int()
{
  if ((millis() - oldTime) > debounceTime)
  {
    // set pixel
    setPixel(cur_x, cur_y, !led[cur_x][cur_y]);
    draw();
    oldTime = millis();
  }
}

// clear display interrupt
void clear_int()
{
  if ((millis() - oldTime1) > debounceTime)
  {
    clear();
    oldTime = millis();
  }
}

//-----Setup function
void setup()
{

  //-----Set Pinmodes
  pinMode(Joystick_sw, INPUT);
  digitalWrite(Joystick_sw, HIGH);
  attachInterrupt(0, sw_int, LOW);

  pinMode(sw_clear, INPUT);
  digitalWrite(sw_clear, HIGH);
  attachInterrupt(1, clear_int, LOW);

  //-----Start serial connection
  Serial.begin(115200);

  //-----Setup LedControl
  lc.shutdown(0, false);
  lc.setIntensity(0, ledIntensity);
  lc.clearDisplay(0);

  // check if EEPROM is initialized
  boolean initialized = false;
  if (EEPROM[64] == 123)
  {
    initialized = true;
    // read cursor position
    cur_x = EEPROM[65];
    cur_y = EEPROM[66];
  }
  else
  {
    // not initialized, clean EEPROM
    for (int i = 0; i < 64; i++)
    {
      EEPROM.update(i, false);
    }
  }

  for (int i = 0; i < 8; i++)
  {
    for (int ii = 0; ii < 8; ii++)
    {
      if (initialized)
      {
        led[i][ii] = EEPROM[i * 8 + ii];
      }
      else
      {
        led[i][ii] = false;
      }
    }
  }

  EEPROM.update(64, 123);

  draw();
}

//-----Loop function
void loop()
{
  int jx = analogRead(Joystick_x);
  int jy = analogRead(Joystick_y);

  if (jx > 510 + threshold)
  {
    // Right
    cur_x = (cur_x + 1) % 8;
  }
  if (jx < 510 - threshold)
  {
    // Left
    cur_x = (cur_x + 7) % 8;
  }
  if (jy > 510 + threshold)
  {
    // Up
    cur_y = (cur_y + 1) % 8;
  }
  if (jy < 510 - threshold)
  {
    // Down
    cur_y = (cur_y + 7) % 8;
  }

  // read cursor position
  EEPROM.update(65, cur_x);
  EEPROM.update(66, cur_y);

  lc.setLed(0, cur_x, cur_y, true);
  delay(200);
  lc.setLed(0, cur_x, cur_y, false);
  delay(200);

  draw();
}
