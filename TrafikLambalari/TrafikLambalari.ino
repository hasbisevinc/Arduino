/*
    Hasbi Sevinç
    https://twitter.com/hassbi
    hasbi.sevinc@gmail.com
    
    7.12.2014
*/

int kirmizi = 13;
int sari = 12;
int yesil = 11;
void setup()
{
  pinMode(kirmizi, OUTPUT);
  pinMode(sari, OUTPUT);
  pinMode(yesil, OUTPUT);
}
void lambaDegistir(int lamba) // kirmizi = 1, sari = 2, yeşil = 3
{
  digitalWrite(kirmizi, LOW);
  digitalWrite(sari, LOW);
  digitalWrite(yesil, LOW);
  switch(lamba){
    case 1:
    digitalWrite(kirmizi, HIGH);
    break;
    case 2:
    digitalWrite(sari, HIGH);
    break;
    case 3:
    digitalWrite(yesil, HIGH);
    break;
  }
}
void loop()
{
  lambaDegistir(1);
  delay(5000);
  lambaDegistir(2);
  delay(500);
  lambaDegistir(3);
  delay(3000);
  lambaDegistir(2);
  delay(1000);
}
