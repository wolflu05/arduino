void setup()
{
    Serial.begin(9600);
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
    digitalWrite(10, HIGH);
}

void loop()
{
    int wert = map(analogRead(A0), 0, 1023, 0, 255);
    analogWrite(11, wert);
    Serial.println(wert);
}
