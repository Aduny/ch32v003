/*
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
    delay(100);                      // wait for a second
    digitalWrite(PC1, LOW);   // turn the LED off by making the voltage LOW
    delay(100);                      // wait for a second
}
