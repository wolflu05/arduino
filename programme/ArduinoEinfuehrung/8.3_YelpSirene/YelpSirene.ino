int min = 700,
    max = 950;

void setup()
{
}

void loop()
{
    for (int i = min; i < max; i++)
    {
        tone(11, i);
        delay(1);
    }
    for (int i = max; i > min; i--)
    {
        tone(11, i);
        delay(1);
    }
}
