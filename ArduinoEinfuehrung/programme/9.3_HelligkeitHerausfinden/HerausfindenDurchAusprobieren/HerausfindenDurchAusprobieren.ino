void setup()
{
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
    digitalWrite(10, HIGH); // Referenzwert
    analogWrite(11, 127);
}

void loop()
{
}
