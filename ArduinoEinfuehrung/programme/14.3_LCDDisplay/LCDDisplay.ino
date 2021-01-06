#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C Lcd(0x3f, 16, 2);

void setup()
{
    Lcd.init();
    Lcd.backlight();
}

void loop()
{
    Lcd.clear();
    Lcd.setCursor(3, 0);
    Lcd.print("Zeit:");
    Lcd.print(millis());
    delay(100);
}
