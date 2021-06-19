float d = 25;
volatile unsigned long oldTime = 0, oldTime1 = 0, debounceTime = 50;

void log()
{
    Serial.print("Time: ");
    Serial.print(d * 2);
    Serial.print("ms Frequenz: ");
    Serial.print(1 / (d * 2 / 1000));
    Serial.println("Hz");
}

void increase()
{
    if ((millis() - oldTime) > debounceTime)
    {
        d += 0.25;
        log();
        oldTime = millis();
    }
}

void decrease()
{
    if ((millis() - oldTime1) > debounceTime)
    {
        d -= 0.25;
        log();
        oldTime1 = millis();
    }
}

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(115200);
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    pinMode(13, OUTPUT);

    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);

    attachInterrupt(0, decrease, LOW);
    attachInterrupt(1, increase, LOW);

    log();
}

void loop()
{
    digitalWrite(13, HIGH);
    delay(d);
    digitalWrite(13, LOW);
    delay(d);
}
