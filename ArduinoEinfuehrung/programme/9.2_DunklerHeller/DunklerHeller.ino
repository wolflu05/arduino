#define LED_PIN 11

int zeit = 3;

void setup()
{
    pinMode(LED_PIN, OUTPUT);
}

void loop()
{
    for (int i = 0; i < 255; i++)
    {
        analogWrite(LED_PIN, i);
        delay(zeit);
    }
    for (int i = 255; i > 0; i--)
    {
        analogWrite(LED_PIN, i);
        delay(zeit);
    }
}
