int x = 30000;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.println(x);
    x++;
}
