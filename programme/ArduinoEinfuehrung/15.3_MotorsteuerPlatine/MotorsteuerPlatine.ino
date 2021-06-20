// Motor 1
#define M_1 10
#define IN_1 9
#define IN_2 8

// Motor 2
#define M_2 5
#define IN_3 7
#define IN_4 6

void setup()
{
  pinMode(M_1, OUTPUT); // Definire alle PINS als OUTPUT
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(M_2, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT);
}

void loop()
{
  digitalWrite(IN_1, HIGH); // Richtung 1
  digitalWrite(IN_2, LOW);
  analogWrite(M_1, 200); // Geschwindigkeit M1 200 (max. 255)

  digitalWrite(IN_3, HIGH);
  digitalWrite(IN_4, LOW);
  analogWrite(M_2, 200); // Geschwindigkeit M2 200 (max. 255)

  delay(2000); // Warte 2s

  digitalWrite(IN_1, LOW); // Richtungswechsel M1
  digitalWrite(IN_2, HIGH);
  digitalWrite(IN_3, LOW); // Richtungswechsel M2
  digitalWrite(IN_4, HIGH);

  delay(2000); // Warte 2s

  digitalWrite(IN_1, LOW); // M1 aus
  digitalWrite(IN_2, LOW);
  digitalWrite(IN_3, LOW); // M2 aus
  digitalWrite(IN_4, LOW);

  delay(2000); // Warte 2s ohne das ein Motor dreht
}
