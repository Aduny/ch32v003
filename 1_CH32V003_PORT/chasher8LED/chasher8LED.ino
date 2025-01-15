//https://elchika.com/article/6cc9dfbb-8b30-4b67-8df5-758912282437/
const uint8_t PIN_LED_ARRAY[] = { PC1, PC2, PC3, PC4, PC5, PC6, PC7, PD2 };
const size_t PIN_LED_ARRAY_COUNT = (sizeof(PIN_LED_ARRAY) / sizeof(PIN_LED_ARRAY[0]));

void setup() {
  // put your setup code here, to run once:
  for (size_t i = 0; i < PIN_LED_ARRAY_COUNT; i++) {
    pinMode(PIN_LED_ARRAY[i], OUTPUT);
    digitalWrite(PIN_LED_ARRAY[i], LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  static int cnt = 0;

  for (size_t i = 0; i < PIN_LED_ARRAY_COUNT; i++) {
    if (i == cnt) {
      digitalWrite(PIN_LED_ARRAY[i], HIGH);
    } else {
      digitalWrite(PIN_LED_ARRAY[i], LOW);
    }
  }

  cnt = (cnt + 1) % PIN_LED_ARRAY_COUNT;

  delay(50);
}
