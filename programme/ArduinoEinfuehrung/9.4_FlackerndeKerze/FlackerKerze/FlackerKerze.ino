#define LED_PIN 11

void setup()
{
    Serial.begin(9600);
    pinMode(LED_PIN, OUTPUT);
    randomSeed(analogRead(A1));
}

void loop()
{
    int s = random(4, 200);
    int d = random(4, 200);
    analogWrite(LED_PIN, s);
    delay(d);
}
