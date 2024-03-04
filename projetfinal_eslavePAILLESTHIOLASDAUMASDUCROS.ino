#include <Wire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup()
{
  Wire.begin(4); // Rejoindre le bus à l'adresse #4
  Wire.onReceive(action); // Preparer une fonction spécifique a la reception de donnee
  Serial.begin(9600); // Demarrer la liaison serie avec le PC
}

void loop()
{
  delay(100);
}

// Fonction qui s execute si quelque chose est present sur l interface
void action()
{
  int x = Wire.read(); // recevoir un chiffre
  if (x == 0)
  {
    lcd.begin(16, 2); // définition d'un écran avec 16 colonnes et 2 lignes
    lcd.setCursor(0, 0); // placement du cusueur sur la (colonne 1 , ligne 1)
    lcd.write("*"); // écriture du message pour indiquer à la voiture d'avancer
    delay(3000);
  }
  if (x == 1)
  {
    lcd.begin(16, 2); // définition d'un écran avec 16 colonnes et 2 lignes
    lcd.setCursor(0, 0); // placement du cusueur sur la (colonne 1 , ligne 1)
    lcd.write("**"); // écriture du message pour indiquer à la voiture d'avancer
    delay(3000);
  }
  if (x == 2)
  {
    lcd.begin(16, 2); // définition d'un écran avec 16 colonnes et 2 lignes
    lcd.setCursor(0, 0); // placement du cusueur sur la (colonne 1 , ligne 1)
    lcd.write("***"); // écriture du message pour indiquer à la voiture d'avancer
    delay(3000);
  }
  if (x == 3)
  {
    lcd.begin(16, 2); // définition d'un écran avec 16 colonnes et 2 lignes
    lcd.setCursor(0, 0); // placement du cusueur sur la (colonne 1 , ligne 1)
    lcd.write("****"); // écriture du message pour indiquer à la voiture d'avancer
    delay(3000);
  }
  if (x == 4)
  {
    lcd.begin(16, 2); // définition d'un écran avec 16 colonnes et 2 lignes
    lcd.setCursor(0, 0); // placement du cusueur sur la (colonne 1 , ligne 1)
    lcd.write("Bienvenue ! :) "); // écriture du message pour indiquer à la voiture d'avancer
    delay(3000);
  }
  if (x == 5)
  {
    lcd.begin(16, 2); // définition d'un écran avec 16 colonnes et 2 lignes
    lcd.setCursor(0, 1); // placement du cusueur sur la (colonne 1 , ligne 1)
    lcd.write("DEGAGE"); // écriture du message pour indiquer à la voiture d'avancer
    delay(3000);
  }
    if (x == 6)
  {
    lcd.clear();
  }
}
