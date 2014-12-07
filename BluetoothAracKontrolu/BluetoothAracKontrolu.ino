const int sagileri = 9;
const int saggeri = 8;
const int solileri = 6;
const int solgeri = 7;
const int solenable = 11;
const int sagenable = 10;

void ileri(){
  digitalWrite(sagileri,HIGH);
  digitalWrite(saggeri,LOW);
  digitalWrite(solileri, HIGH);
  digitalWrite(solgeri,LOW);
}


void geri(){
  digitalWrite(sagileri,LOW);
  digitalWrite(saggeri,HIGH);
  digitalWrite(solileri, LOW);
  digitalWrite(solgeri,HIGH);
}


void sol(){
  digitalWrite(sagileri,LOW);
  digitalWrite(saggeri,HIGH);
  digitalWrite(solileri, HIGH);
  digitalWrite(solgeri,LOW);
}


void sag(){
  digitalWrite(sagileri,HIGH);
  digitalWrite(saggeri,LOW);
  digitalWrite(solileri, LOW);
  digitalWrite(solgeri,HIGH);
}




void dur()
{
digitalWrite(sagileri, HIGH);
digitalWrite(saggeri, HIGH);
digitalWrite(solileri, HIGH);
digitalWrite(solgeri, HIGH);
}

void setup(){
pinMode(sagileri,OUTPUT);
pinMode(saggeri,OUTPUT);
pinMode(solileri,OUTPUT);
pinMode(solgeri,OUTPUT);
pinMode(sagenable,OUTPUT);
pinMode(solenable,OUTPUT);

Serial.begin(9600);
}
char gelen;
void loop(){
 if (Serial.available() > 0) {
   gelen = Serial.read();
   
   
 }
   
   switch(gelen){
     case 'a':
        sol();
        delay(300);
        break;
     case 'd':
        sag();
        delay(300);
        break;
     case 'w':
         ileri();
         delay(300);
         break;
     case 's':
         geri();
         delay(300);
         break;
     default:
         dur();
         break;
   }
   gelen = 'x';
   
}

