// ==========================================
// ARDUINO FUNDAMENTALS - MUST-KNOW GUIDE
// ==========================================

// ==========================================
// 1. DATA TYPES
// ==========================================
// byte: 0-255 (1 byte)
byte myByte = 200;

// int: -32768 to 32767 (2 bytes) - MOST COMMON
int myInt = 500;

// long: -2147483648 to 2147483647 (4 bytes)
long myLong = 1000000;

// float: decimal numbers (4 bytes) - NOTE: less precise
float myFloat = 3.14;

// bool: true or false
bool myBool = true;

// char: single character 'A'
char myChar = 'A';

// String: text (uses dynamic memory)
String myString = "Hello Arduino";

// ==========================================
// 2. PIN MODES & CONSTANTS
// ==========================================
// Pin Modes:
//   INPUT        - Read pin state
//   OUTPUT       - Write to pin (HIGH/LOW)
//   INPUT_PULLUP - Input with internal pull-up resistor

// Pin States:
//   HIGH  - 5V (logic 1)
//   LOW   - 0V (logic 0)

// ==========================================
// 3. ESSENTIAL FUNCTIONS
// ==========================================

void setup() {
  // Runs ONCE when Arduino boots
  // Use for initialization
  
  Serial.begin(9600);  // Start serial communication at 9600 baud
  
  // pinMode(pin, mode) - Configure pin as INPUT or OUTPUT
  pinMode(13, OUTPUT);       // Pin 13 as output
  pinMode(2, INPUT);         // Pin 2 as input
  pinMode(3, INPUT_PULLUP);  // Pin 3 with pull-up resistor
}

void loop() {
  // Runs repeatedly (infinitely)
  // Main program logic goes here
}

// ==========================================
// 4. DIGITAL I/O (HIGH/LOW)
// ==========================================

void digitalIOExample() {
  // digitalWrite(pin, value) - Write HIGH or LOW to a digital pin
  digitalWrite(13, HIGH);   // Turn ON (5V)
  digitalWrite(13, LOW);    // Turn OFF (0V)
  
  // digitalRead(pin) - Read HIGH or LOW from a digital pin
  int buttonState = digitalRead(2);
  
  if (buttonState == HIGH) {
    // Button NOT pressed (with INPUT_PULLUP)
  }
  if (buttonState == LOW) {
    // Button IS pressed (with INPUT_PULLUP)
  }
}

// ==========================================
// 5. ANALOG I/O (0-255 or 0-1023)
// ==========================================

void analogIOExample() {
  // analogWrite(pin, value) - PWM output (0-255)
  // PWM pins on UNO: 3, 5, 6, 9, 10, 11
  analogWrite(5, 128);  // 50% brightness/speed
  analogWrite(5, 255);  // 100% brightness/speed
  analogWrite(5, 0);    // 0% (off)
  
  // analogRead(pin) - Read analog value (0-1023)
  // Analog pins on UNO: A0-A5
  int sensorValue = analogRead(A0);  // Returns 0-1023
}

// ==========================================
// 6. TIMING FUNCTIONS
// ==========================================

void timingExample() {
  // delay(milliseconds) - BLOCKS execution
  delay(1000);  // Wait 1000 ms (1 second)
  delay(500);   // Wait 500 ms
  
  // millis() - Returns milliseconds since boot (long)
  // Does NOT block - use for non-blocking delays
  long currentTime = millis();
  
  // Example: Non-blocking delay pattern
  static long lastTime = 0;
  if (millis() - lastTime >= 1000) {  // Every 1000ms
    // Do something
    lastTime = millis();
  }
  
  // delayMicroseconds(microseconds) - Very short delays
  delayMicroseconds(100);  // Wait 100 microseconds
}

// ==========================================
// 7. SERIAL COMMUNICATION (Debug output)
// ==========================================

void serialExample() {
  // Serial.begin(baud) - Start in setup()
  // Common baud rates: 9600, 115200
  
  // Serial.print() - Print without newline
  Serial.print("Value: ");
  Serial.print(42);  // Output: "Value: 42"
  
  // Serial.println() - Print with newline
  Serial.println("Hello");  // Adds newline at end
  Serial.println(123);       // Output: "123\n"
  
  // Serial.write() - Send raw byte/character
  Serial.write(65);  // Sends ASCII 'A'
  
  // Serial.read() - Read one byte (if available)
  if (Serial.available()) {
    byte incoming = Serial.read();
  }
  
  // Serial.available() - Check if data is waiting
  while (Serial.available()) {
    Serial.read();  // Clear buffer
  }
}

// ==========================================
// 8. CONTROL STRUCTURES
// ==========================================

void controlStructuresExample() {
  // if/else if/else
  int temperature = 25;
  if (temperature > 30) {
    Serial.println("Hot");
  } else if (temperature > 20) {
    Serial.println("Warm");
  } else {
    Serial.println("Cold");
  }
  
  // for loop
  for (int i = 0; i < 10; i++) {
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100);
  }
  
  // while loop
  int count = 0;
  while (count < 5) {
    Serial.println(count);
    count++;
  }
  
  // switch/case
  int pin = 5;
  switch (pin) {
    case 5:
      Serial.println("Pin 5");
      break;
    case 6:
      Serial.println("Pin 6");
      break;
    default:
      Serial.println("Other pin");
  }
}

// ==========================================
// 9. FUNCTIONS (Reusable code blocks)
// ==========================================

// Declare functions before setup() or after loop()

// Function with no parameters, no return
void blink() {
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
}

// Function with parameters, no return
void blinkN(int times, int delayMs) {
  for (int i = 0; i < times; i++) {
    digitalWrite(13, HIGH);
    delay(delayMs);
    digitalWrite(13, LOW);
    delay(delayMs);
  }
}

// Function with parameters and return value
int addNumbers(int a, int b) {
  return a + b;
}

// ==========================================
// 10. ARRAYS & LOOPS
// ==========================================

void arraysExample() {
  // Declare array of 5 integers
  int ledPins[] = {3, 5, 6, 9, 10};
  
  // Access element (0-indexed)
  digitalWrite(ledPins[0], HIGH);  // Pin 3
  
  // Loop through array
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
    delay(100);
  }
}

// ==========================================
// 11. CONSTANTS (Don't change during runtime)
// ==========================================

// Define constants at top of file
#define LED_PIN 13
#define BUTTON_PIN 2
#define DELAY_TIME 500

const int MAX_VALUE = 255;
const float PI = 3.14159;

// In setup/loop, use like variables:
void constantsExample() {
  pinMode(LED_PIN, OUTPUT);
  int buttonState = digitalRead(BUTTON_PIN);
}

// ==========================================
// 12. COMMON PATTERNS
// ==========================================

// Pattern 1: Button with debouncing
void buttonDebounceExample() {
  const int BUTTON_PIN = 2;
  const int DEBOUNCE_DELAY = 50;
  
  static int lastState = HIGH;
  static long lastChange = 0;
  
  int currentState = digitalRead(BUTTON_PIN);
  
  // Check if state changed
  if (currentState != lastState) {
    // Wait for debounce period
    if (millis() - lastChange >= DEBOUNCE_DELAY) {
      lastState = currentState;
      lastChange = millis();
      
      if (currentState == LOW) {
        // Button just pressed
        Serial.println("Button pressed!");
      }
    }
  }
}

// Pattern 2: LED brightness with PWM
void pwmExample() {
  // Fade LED in and out
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(5, brightness);
    delay(10);
  }
  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(5, brightness);
    delay(10);
  }
}

// Pattern 3: Non-blocking timer
void nonBlockingTimerExample() {
  static long lastTime = 0;
  const long INTERVAL = 1000;  // 1 second
  
  if (millis() - lastTime >= INTERVAL) {
    lastTime = millis();
    // Do something every INTERVAL milliseconds
    digitalWrite(13, !digitalRead(13));  // Toggle LED
  }
}

// ==========================================
// 13. USEFUL ARDUINO FUNCTIONS
// ==========================================

void usefulFunctions() {
  // map(value, fromLow, fromHigh, toLow, toHigh)
  // Convert range: e.g., 0-1023 to 0-255
  int sensorValue = analogRead(A0);           // 0-1023
  int mappedValue = map(sensorValue, 0, 1023, 0, 255);
  
  // constrain(value, min, max) - Keep within bounds
  int limited = constrain(mappedValue, 0, 255);
  
  // abs(value) - Absolute value
  int absolute = abs(-42);  // Returns 42
  
  // min/max
  int smaller = min(5, 10);   // Returns 5
  int larger = max(5, 10);    // Returns 10
  
  // random(max) - Random 0 to max-1
  int randomNum = random(100);  // 0-99
  
  // random(min, max) - Random min to max-1
  int randomNum2 = random(10, 20);  // 10-19
  
  // pow(base, exponent)
  float result = pow(2, 8);  // 2^8 = 256
  
  // sqrt(value)
  float root = sqrt(16);  // Returns 4.0
}

// ==========================================
// 14. MEMORY & VARIABLES
// ==========================================

// Global variables (accessible everywhere)
int globalCounter = 0;

void memoryExample() {
  // Local variables (only in this function)
  int localVar = 5;
  
  // static variables (keep value between calls)
  static int callCount = 0;
  callCount++;
}

// ==========================================
// 15. PRACTICE PROJECT: LED BUTTON TOGGLE
// ==========================================

/*
PROJECT: Press button to toggle LED on/off
Hardware: LED on pin 5, Button on pin 2

const int LED_PIN = 5;
const int BUTTON_PIN = 2;

bool ledState = false;
bool lastButtonState = HIGH;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);
  
  // Detect button press (HIGH to LOW)
  if (buttonState == LOW && lastButtonState == HIGH) {
    ledState = !ledState;  // Toggle LED
    digitalWrite(LED_PIN, ledState ? HIGH : LOW);
    Serial.println(ledState ? "LED ON" : "LED OFF");
    delay(50);  // Debounce
  }
  
  lastButtonState = buttonState;
}
*/

// ==========================================
// QUICK REFERENCE - COMMON PIN ASSIGNMENTS
// ==========================================
/*
Arduino UNO Pinout:
- Digital pins: 0-13 (also TX/RX on 0/1)
- Analog pins: A0-A5
- PWM pins (analogWrite): 3, 5, 6, 9, 10, 11

Typical assignments:
- LEDs: 3, 5, 6, 9, 10, 11 (PWM for brightness)
- Buttons: 2-13 (with INPUT_PULLUP)
- Sensors: A0-A5 (analogRead)
- Serial: pins 0(RX), 1(TX) - don't use for I/O
*/
