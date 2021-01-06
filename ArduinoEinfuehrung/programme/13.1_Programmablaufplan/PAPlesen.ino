int x = 10;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    if (x < 100)
    {
        Serial.println(x);
        x += 2;
    }
}
