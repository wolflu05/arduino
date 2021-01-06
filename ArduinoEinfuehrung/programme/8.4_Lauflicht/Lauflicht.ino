int zeit = 200;

void setup()
{
    for (int i = 9; i < 14; i++)
    {
        pinMode(i, OUTPUT);
    }
}

void loop()
{
    for (int i = 9; i < 14; i++)
    {
        digitalWrite(i, HIGH);
        delay(zeit);
        digitalWrite(i, LOW);
        delay(zeit);
    }
}
