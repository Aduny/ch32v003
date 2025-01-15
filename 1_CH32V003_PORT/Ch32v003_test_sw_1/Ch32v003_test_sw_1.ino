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
#define sw1 PC0 
#define sw2 PA2
#define sw3 PA1
#define sw4 PD7

#define led1 PC1
#define led2 PC2
#define led3 PC3
#define led4 PC6
#define adc_pin   A2
u16 adc_time;

#include "inc_prog.h"
#include "inc_blink.h"


//-----------
void setup() 
{
 AFIO->PCFR1 = AFIO->PCFR1 & 0xFFFF7FFF; //Sets PA1 & PA2 as I/O by clearing bit 15
 // Serial.begin(115200);
pinMode(adc_pin,INPUT_ANALOG);
 // Serial.println("Hello");
pinMode(sw1, INPUT_PULLUP);//---PA2 PIN3
pinMode(sw2, INPUT_PULLUP);//
pinMode(sw3, INPUT_PULLUP);//
pinMode(sw4, INPUT_PULLUP);//

   pinMode(led1, OUTPUT); //---PIN1 OK  
   pinMode(led2, OUTPUT);//---PIN5 OK
   pinMode(led3, OUTPUT);//---PIN6 OK
   pinMode(led4, OUTPUT);//---PIN7 OK
 
 off_all_led();
  }

void prog1()  
{   adc_map();
    digitalWrite(led4, LOW);      
    digitalWrite(led1, HIGH);   
    delay(adc_time);
    
    adc_map();
    digitalWrite(led1, LOW);      
    digitalWrite(led2, HIGH);   
    delay(adc_time);

    adc_map();
    digitalWrite(led2, LOW);      
    digitalWrite(led3, HIGH);   
    delay(adc_time);
    
    adc_map();
    digitalWrite(led3, LOW);      
    digitalWrite(led4, HIGH);   
    delay(adc_time);  
}

void prog2()
{   prog1();
    digitalWrite(led4, LOW);    

    adc_map();
    on_all_led();
    delay(adc_time);

    adc_map();
    off_all_led();
    delay(adc_time);
}
void prog6()  
{
    adc_map();       
    digitalWrite(led1, HIGH); 
      
    delay(adc_time);
    adc_map();
    digitalWrite(led2, HIGH);
       
    delay(adc_time);
    adc_map();
    digitalWrite(led3, HIGH);  
     
    delay(adc_time);
    adc_map();
    digitalWrite(led4, HIGH); 
      
    delay(adc_time);
    adc_map();
    off_all_led();
    delay(adc_time);
}


void loop() 
{
   if(digitalRead(sw1)==LOW)prog2();
   else if(digitalRead(sw2)==LOW)prog3();
   else if(digitalRead(sw3)==LOW)prog4();
   else if(digitalRead(sw4)==LOW)prog5();
   else prog1();
   
 /*
  if(digitalRead(sw1)==LOW)digitalWrite(led1, HIGH);
   else digitalWrite(PC1, LOW);

   if(digitalRead(sw2)==LOW)digitalWrite(led2, HIGH);
   else digitalWrite(PC2, LOW);
  */
}
