void setup()
{
    pinMode(3, INPUT_PULLUP);
    pinMode(4, INPUT_PULLUP);
}

void loop()
{
    if (!digitalRead(3))
    {
        tone(11, 440);
    }
    else if (!digitalRead(4))
    {
        tone(11, 740);
    }
    else
    {
        noTone(11);
    }
}
