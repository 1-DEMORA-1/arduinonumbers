const int segmentPins[7] = { 2, 3, 4, 5, 6, 7, 8 };
const byte digitCodes[10][7] = {
  { 1, 1, 1, 1, 1, 1, 0 },  // 0
  { 0, 1, 1, 0, 0, 0, 0 },  // 1
  { 1, 1, 0, 1, 1, 0, 1 },  // 2
  { 1, 1, 1, 1, 0, 0, 1 },  // 3
  { 0, 1, 1, 0, 0, 1, 1 },  // 4
  { 1, 0, 1, 1, 0, 1, 1 },  // 5
  { 1, 0, 1, 1, 1, 1, 1 },  // 6
  { 1, 1, 1, 0, 0, 0, 0 },  // 7
  { 1, 1, 1, 1, 1, 1, 1 },  // 8
  { 1, 1, 1, 1, 0, 1, 1 }   // 9
};
void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  Serial.println("enter true");
}
void loop() {
  if (Serial.available() > 0) {
    char inputChar = Serial.read();
    if (isDigit(inputChar)) {
      int number = inputChar - '0';
      displayDigit(number);
      delay(1000);
      Serial.print(" ");
      Serial.println(number);
    } else {
    }
  }
}
void displayDigit(int digit) {
  if (digit < 0 || digit > 9) return;
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digitCodes[digit][i]);
  }
}