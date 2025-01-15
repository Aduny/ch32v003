/*
        _          _ ______ _____ _____ 
       (_)        | |  ____|  __ \_   _|
  _ __  ___  _____| | |__  | |  | || |  
 | '_ \| \ \/ / _ \ |  __| | |  | || |  
 | |_) | |>  <  __/ | |____| |__| || |_ 
 | .__/|_/_/\_\___|_|______|_____/_____|
 | |                                    
 |_|                                    
                             
www.pixeledi.eu | https://links.pixeledi.eu
CH32v003J4M6 LED Blink | V1.0 | 03.2024

CH32v003J4M6

     +---------+
 PD6 |1      8| PD4
 VSS |2      7| PC4
 PA2 |3      6| PC2
 VDD |4      5| PC1 --> LED --> Widerstand 220ohm --> GND
     +---------+

*/
// the setup function runs once when you press reset or power the board
void setup() {
    // initialize digital pin LED_BUILTIN as an output.
    pinMode(PC1, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
    digitalWrite(PC1, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(300);                      // wait for a second
    digitalWrite(PC1, LOW);   // turn the LED off by making the voltage LOW
    delay(300);                      // wait for a second
}
