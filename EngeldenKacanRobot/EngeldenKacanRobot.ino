/*
    Hasbi Sevinç
    https://twitter.com/hassbi
    hasbi.sevinc@gmail.com
    
    7.12.2014
*/


const int sagileri = 9;
const int saggeri = 8;
const int solileri = 12;
const int solgeri = 13;
const int solenable = 11;
const int sagenable = 10;
/*
trigPin1 ve echoPin1 = soldaki uzaklık sensörümüz
trigPin2 ve echoPin2 = öndeki uzaklık sensörümüz
trigPin3 ve echoPin3 = sağdaki uzaklık sensörümüz
*/
int trigPin1 = 6;
int echoPin1 = 7;
int trigPin2 = 4;
int echoPin2 = 5;
int trigPin3 = 2;
int echoPin3 = 3;
float uzaklik(int trigPin, int echoPin){
float olcum;
float cm;
digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
olcum = pulseIn(echoPin, HIGH);
cm= olcum /29.1/2;
return cm;
}
void ileri(int hizsag, int hizsol){
analogWrite(sagenable, hizsag);
digitalWrite(sagileri,HIGH);
digitalWrite(saggeri,LOW);
analogWrite(solenable, hizsol);
digitalWrite(solileri, HIGH);
digitalWrite(solgeri,LOW);
}
void geri(int hizsag, int hizsol){
analogWrite(sagenable, hizsag);
digitalWrite(sagileri,LOW);
digitalWrite(saggeri, HIGH);
analogWrite(solenable, hizsol);
digitalWrite(solileri, LOW);
digitalWrite(solgeri, HIGH);
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
35
pinMode(solgeri,OUTPUT);
pinMode(sagenable,OUTPUT);
pinMode(solenable,OUTPUT);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1,INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2,INPUT);
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3,INPUT);
}
void loop(){
while( uzaklik(trigPin2, echoPin2 ) < 10 ){ // önüne engel gelene kadar düz git
ileri(100,100);
}
dur(); // engel geldikten sonra dur
delay(1000); // 1 saniye bekle
if( uzaklik(trigPin1, echoPin1) > 10 ){ // soluna bak
ileri(150,0); // engel yoksa sola dön
delay(500); // 90 derece dönene kadar geçecek süre. Bu süreyi kendinize göre ayarlayın
dur(); // dur
delay(1000);
}else if(uzaklik(trigPin3, echoPin3) > 10 ){ // sol dolu ise sağa bak
ileri(0,150); // engel yoksa sağa dön
delay(500); // 90 derece dönene kadar geçecek süre. Bu süreyi kendinize göre ayarlayın
dur(); // dur
delay(1000);
}else { // sağ ve solda engel varsa geri gidip dönelim
geri(100,100);
delay(1000);
ileri(150,0);
delay(500);
dur();
delay(1000);
}
}
