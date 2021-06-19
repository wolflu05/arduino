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
    stop();
}

void loop()
{
    forward();
    delay(2000);
    backward();
    delay(2000);
}

void forward()
{
    stop();
    digitalWrite(DIR_A, HIGH);
    digitalWrite(DIR_B, LOW);
}

void backward()
{
    stop();
    digitalWrite(DIR_A, LOW);
    digitalWrite(DIR_B, HIGH);
}

void stop()
{
    digitalWrite(DIR_A, LOW);
    digitalWrite(DIR_B, LOW);
}
