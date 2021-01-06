#define BLAU_PIN 9
#define GRUEN_PIN 10
#define ROT_PIN 11

int zeit = 10;

void setup()
{
    pinMode(ROT_PIN, OUTPUT);
    pinMode(GRUEN_PIN, OUTPUT);
    pinMode(BLAU_PIN, OUTPUT);
}

void loop()
{

    for (int i = 0; i < 255; i++)
    {
        analogWrite(ROT_PIN, 255 - i);
        analogWrite(GRUEN_PIN, i);

        delay(zeit);
    }

    for (int i = 0; i < 255; i++)
    {
        analogWrite(GRUEN_PIN, 255 - i);
        analogWrite(BLAU_PIN, i);

        delay(zeit);
    }

    for (int i = 0; i < 255; i++)
    {
        analogWrite(BLAU_PIN, 255 - i);
        analogWrite(ROT_PIN, i);

        delay(zeit);
    }
}
