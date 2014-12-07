/*
    Hasbi Sevinç
    https://twitter.com/hassbi
    hasbi.sevinc@gmail.com
    
    7.12.2014
*/

const int ledler[5] = {11,10,9,6,5}; // ledlerin bagli oldugu pinler
// bu pinler PWM cikisi olmalidir...
// LED pins must be connected to PWM outputs of arduino
void setup(){
  for(int i = 0; i < 5; i ++){
    pinMode (ledler[i], OUTPUT);
    digitalWrite(ledler[i], LOW);
  }
}

const int analogdegerler[100] ={0,5,7,10,12,15,17,20,22,25,28,30,33,35,38,40,43,45,48,51,53,56,58,61,63,66,68,71,73,76,79,81,84,86,89,91,94,96,99,102,104,107,109,112,114,117,119,122,124,127,130,132,135,137,140,142,145,147,150,153,155,158,160,163,165,168,170,173,175,178,181,183,186,188,191,193,196,198,201,204,206,209,211,214,216,219,221,224,226,229,232,234,237,239,242,244,247,249,252,255};
int counter = 0;
void loop(){
  
  for(int i = 0; i < 5; i ++){
    if(counter < (100+i*100) && counter > (0+i*100))
      analogWrite(ledler[i], analogdegerler[counter-i*100]);
    if(counter < (200+i*100) && counter > (99+i*100))
      analogWrite(ledler[i], analogdegerler[(199+i*100)-counter]);
  }

  delay(1);
  counter ++;
  
  if(counter > 600)
    counter =0;
}
