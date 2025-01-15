/*
  Ch32v003-f4p6

  - blinks D4 -> LED on board 
*/
//---txpin PD5  -->pin 8
//---led pc1 -->pin 5

/*
 * // Analog (Ax) pin number array
const uint32_t analogInputPin[] = {
  1,    // A0/PA2 ///--pin3
  0,    // A1/PA1   //---pin1
  6,    // A2/PC4  ///---pin 7
  12,   // A3/PD2
  13,   // A4/PD3
  15,   // A5/PD5
  16,   // A6/PD6
  14    // A7/PD4 
};
 */
#define sw1 PA1
#define sw2 PA2
void setup() 
{
 AFIO->PCFR1 = AFIO->PCFR1 & 0xFFFF7FFF; //Sets PA1 & PA2 as I/O by clearing bit 15
 // Serial.begin(115200);

 // Serial.println("Hello");
pinMode(sw1, INPUT_PULLUP);//---PA2 PIN3
pinMode(sw2, INPUT_PULLUP);//

  pinMode(PD6, OUTPUT); //---PIN1 OK  
 // pinMode(PA2, OUTPUT);//---PA2 PIN3
   pinMode(PC1, OUTPUT);//---PIN5 OK
  pinMode(PC2, OUTPUT);//---PIN6 OK
   pinMode(PC4, OUTPUT);//---PIN7 OK
 
  digitalWrite(PD6, LOW);
  //digitalWrite(PA2, LOW);
  digitalWrite(PC1, LOW);
  digitalWrite(PC2, LOW);
  digitalWrite(PC4, LOW);
  }

void prog1()
{   digitalWrite(PD6, HIGH);
    digitalWrite(PA2, HIGH);
    digitalWrite(PC1, LOW);
    digitalWrite(PC2, HIGH);
    digitalWrite(PC4, HIGH);
    delay(300);
  
  digitalWrite(PD6, LOW);
  digitalWrite(PA2, LOW);
  digitalWrite(PC1, HIGH);
  digitalWrite(PC2, LOW);
  digitalWrite(PC4, LOW);
  delay(300);
  //if(digitalRead(sw1))digitalWrite(PC1, HIGH);
  // else digitalWrite(PC1, LOW);

  
}
#define dyp2 5 ///---3
void prog2()
{  unsigned char  a;
  a=0; 
  while(a<dyp2)
  { digitalWrite(PA2, HIGH);   
    delay(70);
    digitalWrite(PA2, LOW);
    if(++a<dyp2)delay(70);
  }
  a=0;
  while(a<dyp2)
  { digitalWrite(PC1, HIGH);   
    delay(70);
    digitalWrite(PC1, LOW);
    if(++a<dyp2)delay(70);
  }
   
}
void loop() 
{
  //int val=analogRead(A2);//---pin7  ok
  //int val=analogRead(A1);//---pin1  don't work
  //int val=analogRead(A0);//---pin3  dont't work
  
  //Serial.println("Blink");
  //Serial.println(val);
 
  //prog2();
  if(digitalRead(sw1)==LOW)digitalWrite(PC1, HIGH);
   else digitalWrite(PC1, LOW);

   if(digitalRead(sw2)==LOW)digitalWrite(PC2, HIGH);
   else digitalWrite(PC2, LOW);
  
}
