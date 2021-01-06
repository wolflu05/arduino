void setup()
{
    pinMode(4, INPUT_PULLUP);
    pinMode(9, OUTPUT);
}

void loop()
{
    if (digitalRead(4))
    {
        digitalWrite(9, LOW);
    }
    else
    {
        digitalWrite(9, HIGH);
    }
}
