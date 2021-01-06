void setup()
{
    pinMode(4, INPUT_PULLUP);
    pinMode(9, OUTPUT);
}

void loop()
{
    digitalWrite(9, !digitalRead(4));
}
