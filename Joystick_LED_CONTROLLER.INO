// ============== PIN DEFINITIONS ==============
const int JOY_X = A0;
const int JOY_Y = A1;
const int JOY_SW = A2;     // Switch on A2 (analog pin works as digital)

// LED pins - 3x3 grid
const int ledPins[9] = {
  2, 3, 4,    // Top:    Left, Center, Right
  5, 6, 7,    // Middle: Left, Center, Right
  8, 9, 10    // Bottom: Left, Center, Right
};

const int CLICK_LED = 11;  // Separate pin for click LED

// ============== CALIBRATION ==============
const int CENTER = 512;
const int DEADZONE = 80;
const int THRESHOLD = 150;

// ============== SETUP ==============
void setup() {
  Serial.begin(9600);
  
  pinMode(JOY_X, INPUT);
  pinMode(JOY_Y, INPUT);
  pinMode(JOY_SW, INPUT_PULLUP);  // ← THIS FIXES IT
  
  // 9 grid LEDs
  for (int i = 0; i < 9; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
  
  // Click LED
  pinMode(CLICK_LED, OUTPUT);
  digitalWrite(CLICK_LED, LOW);
}

// ============== MAIN LOOP ==============
void loop() {
  int xRaw = analogRead(JOY_X);
  int yRaw = analogRead(JOY_Y);
  bool clicked = (digitalRead(JOY_SW) == LOW);  // LOW = pressed
  
  int xOffset = xRaw - CENTER;
  int yOffset = yRaw - CENTER;
  
  int row, col;
  
  if (abs(xOffset) < DEADZONE && abs(yOffset) < DEADZONE) {
    row = 1;
    col = 1;
  } else {
    col = (xOffset < -THRESHOLD) ? 0 : (xOffset > THRESHOLD) ? 2 : 1;
    row = (yOffset < -THRESHOLD) ? 0 : (yOffset > THRESHOLD) ? 2 : 1;
  }
  
  int ledIndex = row * 3 + col;
  
  // Turn off all 9 grid LEDs, turn on selected one
  for (int i = 0; i < 9; i++) {
    digitalWrite(ledPins[i], (i == ledIndex) ? HIGH : LOW);
  }
  
  // Click LED - only ON when pressed
  if (clicked) {
    // Option 1: Just click LED on
    digitalWrite(CLICK_LED, HIGH);
    
    // Option 2: All LEDs on when clicked (uncomment below, comment above)
    // for (int i = 0; i < 9; i++) digitalWrite(ledPins[i], HIGH);
  } else {
    digitalWrite(CLICK_LED, LOW);
  }
  
  delay(20);
}
