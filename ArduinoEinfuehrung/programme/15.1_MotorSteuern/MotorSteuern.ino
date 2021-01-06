#define ENABLE 5
#define DIR_A 4
#define DIR_B 3

void setup()
{
    pinMode(ENABLE, OUTPUT);
    pinMode(DIR_A, OUTPUT);
    pinMode(DIR_B, OUTPUT);

    // enable driver
    digitalWrite(ENABLE, HIGH);
    digitalWrite(DIR_B, LOW);
}

void loop()
{
    digitalWrite(DIR_A, HIGH);
    delay(2000);
    digitalWrite(DIR_A, LOW);
    delay(2000);
}
