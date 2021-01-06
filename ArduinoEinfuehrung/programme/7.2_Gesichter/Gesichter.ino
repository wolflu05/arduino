void setup()
{
    Serial.begin(9600);

    lachen();
    traurig();
}

void loop()
{
}

void lachen()
{
    Serial.println(" sss ");
    Serial.println("-~~~-");
    Serial.println("x   x");
    Serial.println("  o  ");
    Serial.println("|___|");
}

void traurig()
{
    Serial.println(" sss ");
    Serial.println("-~~~-");
    Serial.println("x   x");
    Serial.println(" _o_");
    Serial.println("|   |");
}
