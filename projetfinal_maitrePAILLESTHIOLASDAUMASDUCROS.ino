#include <Wire.h>
#include <Keypad.h> // inclusion de la librairie pour clavier matriciel 
#include <LiquidCrystal.h>

// −−− Déclaration des constantes −−−

//−−− Constantes utilisées avec le clavier 4x4

const byte LIGNES = 4; // 4 lignes
const byte COLONNES = 4; //4 colonnes
int code [4];
int resultat[4];
int variable = 0;

// −−− constantes des broches −−−

const int C4 = 2; //declaration constante de broche
const int C3 = 3; //declaration constante de broche
const int C2 = 4; //declaration constante de broche
const int C1 = 5; //declaration constante de broche
const int L4 = 6; //declaration constante de broche
const int L3 = 7; //declaration constante de broche
const int L2 = 8; //declaration constante de broche
const int L1 = 9; //declaration constante de broche
const int led = 11;

// −−− Déclaration des variables globales −−−
//−−− Définition des touches

char touches[LIGNES ][ COLONNES] =
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// tableaux de lignes et colonnes

byte BrochesLignes[LIGNES] = {L1, L2, L3, L4}; //connexions utilisées pour les broches de lignes du clavier
byte BrochesColonnes[COLONNES] = {C1, C2, C3, C4}; //connexions utilisées pour les broches de colonnes du clavier
char touche;

Keypad clavier = Keypad( makeKeymap(touches) , BrochesLignes , BrochesColonnes , LIGNES, COLONNES );

// les broches de lignes sont automatiquement configurées en ENTREE avec pullup interne activé
// les broches de colonnes sont automatiquement configurées en SORTIE

void setup() {
  Wire.begin();

  Serial.begin(9600);

  pinMode(led, OUTPUT);
  digitalWrite (led, LOW);

  for (int i = 0; i < 4; i++) { //code à entrer pour déverouiller
    resultat[i] = 2 * i;
  }

  for (int i = 0; i < 4; i++) { //code entré sur le clavier initialisé a 0
    code[i] = 0;
  }

  for (int i = 0; i < 4; i++) {
    Serial.println (resultat[i]);
  }
}


void loop() {

  switch (variable)
  {
    case 0:
      touche = clavier.getKey() ; // lecture de la touche appuyée
      if (touche != NO_KEY)
      {
        chiffre();
        variable = 1;
        Wire.beginTransmission(4);
        Wire.write(0);
        Wire.endTransmission();
      }
      break;


    case 1:
      touche = clavier.getKey() ; // lecture de la touche appuyée
      if (touche != NO_KEY)
      {
        chiffre();
        variable = 2;

        Wire.beginTransmission(4);
        Wire.write(1);
        Wire.endTransmission();
      }
      break;


    case 2:
      touche = clavier.getKey() ; // lecture de la touche appuyée
      if (touche != NO_KEY)
      {
        chiffre();
        variable = 3;

        Wire.beginTransmission(4);
        Wire.write(2);
        Wire.endTransmission();
      }
      break;


    case 3:
      touche = clavier.getKey() ; // lecture de la touche appuyée
      if (touche != NO_KEY)
      {
        chiffre();
        Wire.beginTransmission(4);
        Wire.write(3);
        Wire.endTransmission();

        if ((resultat[0] == code[0]) && (resultat[1] == code[1]) && (resultat[2] == code[2]) && (resultat[3] == code[3])) {
          Serial.println("open");
          Wire.beginTransmission(4);
          Wire.write(4);
          Wire.endTransmission();
          delay(3000);
          Wire.beginTransmission(4);
          Wire.write(6);
          Wire.endTransmission();
        }
        else {
          Serial.println("closed");
          Wire.beginTransmission(4);
          Wire.write(5);
          Wire.endTransmission();
          delay(3000);
          Wire.beginTransmission(4);
          Wire.write(6);
          Wire.endTransmission();
        }
        for (int i = 0; i < 4; i++) { //code à entrer
          code[i] = 0;
        }
        for (int i = 0; i < 4; i++) {
          Serial.println (code[i]);
        }
        delay(2000);
        variable = 0;
      }
      break;

  }

}

void chiffre() {
  // si une touche a été frappée −− gestion de la touche appuyée
  if (touche == '1') //Exemple si on appui sur # une action sinon la même action pour les autres touches
  {
    code[variable] = 1;
    for (int i = 0; i < 4; i++) {
      Serial.println (code[i]);
    }
  }
  if (touche == '2') //Exemple si on appui sur # une action sinon la même action pour les autres touches
  {
    code[variable] = 2;
    for (int i = 0; i < 4; i++) {
      Serial.println (code[i]);
    }
  }
  if (touche == '3') //Exemple si on appui sur # une action sinon la même action pour les autres touches
  {
    code[variable] = 3;
    for (int i = 0; i < 4; i++) {
      Serial.println (code[i]);
    }
  }
  if (touche == '4') //Exemple si on appui sur # une action sinon la même action pour les autres touches
  {
    code[variable] = 4;
    for (int i = 0; i < 4; i++) {
      Serial.println (code[i]);
    }
  }
  if (touche == '5') //Exemple si on appui sur # une action sinon la même action pour les autres touches
  {
    code[variable] = 5;
    for (int i = 0; i < 4; i++) {
      Serial.println (code[i]);
    }
  }
  if (touche == '6') //Exemple si on appui sur # une action sinon la même action pour les autres touches
  {
    code[variable] = 6;
    for (int i = 0; i < 4; i++) {
      Serial.println (code[i]);
    }
  }
  if (touche == '7') //Exemple si on appui sur # une action sinon la même action pour les autres touches
  {
    code[variable] = 7;
    for (int i = 0; i < 4; i++) {
      Serial.println (code[i]);
    }
  }
  if (touche == '8') //Exemple si on appui sur # une action sinon la même action pour les autres touches
  {
    code[variable] = 8;
    for (int i = 0; i < 4; i++) {
      Serial.println (code[i]);
    }
  }
  if (touche == '9') //Exemple si on appui sur # une action sinon la même action pour les autres touches
  {
    code[variable] = 9;
    for (int i = 0; i < 4; i++) {
      Serial.println (code[i]);
    }
  }
  if (touche == '0') //Exemple si on appui sur # une action sinon la même action pour les autres touches
  {
    code[variable] = 0;
    for (int i = 0; i < 4; i++) {
      Serial.println (code[i]);
    }
  }

  else
    delay(300); // pause entre 2 appuis et anti rebonds
  // fin gestion de la touche appuyée
}
