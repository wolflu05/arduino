int m;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    m = millis();
    Serial.println(m);
}
