#define BLAU_PIN 9
#define GRUEN_PIN 10
#define ROT_PIN 11

int zeit = 1;

void setup()
{
    pinMode(ROT_PIN, OUTPUT);
    pinMode(GRUEN_PIN, OUTPUT);
    pinMode(BLAU_PIN, OUTPUT);
}

void loop()
{

    for (int r = 0; r < 255; r++)
    {
        for (int g = 0; g < 255; g++)
        {
            for (int b = 0; b < 255; b++)
            {
                analogWrite(ROT_PIN, r);
                analogWrite(GRUEN_PIN, g);
                analogWrite(BLAU_PIN, b);
                delay(zeit);
            }
        }
    }
}
