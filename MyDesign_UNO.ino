/*
int ledPin = 5;
int buttonApin = 9;
bool lightON = false;

byte leds = 0;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);  
}

void loop() 
{
  if (digitalRead(buttonApin) == LOW)
  {
    if (lightON == false){
      digitalWrite(ledPin, HIGH);
      lightON = true;
    }else {
      digitalWrite(ledPin, LOW);
      lightON = false;
    }
    delay(500);
  }
}
*/

int ledPin = 5;
int buttonApin = 9;
bool lightON = false;
bool buttonWasPressed = false;  // NEW: track if button was already pressed

void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);  
}

void loop() 
{
  // Check if button is currently pressed
  if (digitalRead(buttonApin) == LOW)
  {
    // Only toggle if this is a NEW press (wasn't pressed last loop)
    if (buttonWasPressed == false)
    {
      if (lightON == false) {
        digitalWrite(ledPin, HIGH);
        lightON = true;
      } else {
        digitalWrite(ledPin, LOW);
        lightON = false;
      }
      
      buttonWasPressed = true;  // Mark that we've handled this press
    }
  }
  else  // Button is NOT pressed
  {
    buttonWasPressed = false;  // Reset so we can detect the next press
  }
  
  delay(10);  // Small delay to reduce bounce (optional but helpful)
}