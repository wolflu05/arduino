int s;

void setup()
{
    Serial.begin(9600);
    randomSeed(analogRead(A1));
}

void loop()
{
    s = random(1, 7);
    Serial.println(s);
    delay(1000);
}
