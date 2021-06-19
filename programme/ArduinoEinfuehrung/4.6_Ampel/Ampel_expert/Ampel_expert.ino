#define ROT   13
#define GELB  12
#define GRUEN 11

const int gruen_zeit = 4000,
          gelb_zeit = 600,
          rot_zeit = 5000,
          gelb_rot_zeit = 600;

void setup()
{
    pinMode(GRUEN, OUTPUT);
    pinMode(GELB, OUTPUT);
    pinMode(ROT, OUTPUT);
}

void loop()
{
    digitalWrite(GRUEN, HIGH); // Grün an
    delay(gruen_zeit);         // warte 4s
    digitalWrite(GRUEN, LOW);  // Grün aus
    digitalWrite(GELB, HIGH);  // Gelb an
    delay(gelb_zeit);          // warte 0,6s
    digitalWrite(GELB, LOW);   // Gelb aus
    digitalWrite(ROT, HIGH);   // Rot an
    delay(rot_zeit);           // warte 5s
    digitalWrite(GELB, HIGH);  // Gelb an
    delay(gelb_rot_zeit);      // warte 0,6s
    digitalWrite(ROT, LOW);    // Rot aus
    digitalWrite(GELB, LOW);   // Gelb aus
}
