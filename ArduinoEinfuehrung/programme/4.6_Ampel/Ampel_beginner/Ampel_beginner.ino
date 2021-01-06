/**
 * Rot  Pin 13
 * Gelb Pin 12
 * Grün Pin 11
 */

void setup()
{
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
}

void loop()
{
    digitalWrite(11, HIGH); // Grün an
    delay(4000);            // warte 4s
    digitalWrite(11, LOW);  // Grün aus
    digitalWrite(12, HIGH); // Gelb an
    delay(600);             // warte 0,6s
    digitalWrite(12, LOW);  // Gelb aus
    digitalWrite(13, HIGH); // Rot an
    delay(5000);            // warte 5s
    digitalWrite(12, HIGH); // Gelb an
    delay(600);             // warte 0,6s
    digitalWrite(13, LOW);  // Rot aus
    digitalWrite(12, LOW);  // Gelb aus
}
