int f = 100;

void setup()
{
    pinMode(3, INPUT_PULLUP);
    pinMode(4, INPUT_PULLUP);
}

void loop()
{
    if (!digitalRead(3))
    {
        f--;
        tone(11, f);
        while (!digitalRead(3))
        {
        }
    }
    else if (!digitalRead(4))
    {
        f++;
        tone(11, f);
        while (!digitalRead(4))
        {
        }
    }
}
