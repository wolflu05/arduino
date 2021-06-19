void setup()
{
    Serial.begin(9600);
    randomSeed(analogRead(A1));

    int x = random(1, 4);

    if (x == 1)
    {
        Serial.println("Schere");
    }
    if (x == 2)
    {
        Serial.println("Stein");
    }
    if (x == 3)
    {
        Serial.println("Papier");
    }
}

void loop()
{
}
