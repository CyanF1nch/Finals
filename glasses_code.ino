const int irSensorPin = A0; // Pin connected to the IR sensor output
const int buzzerPin = 13;    // Pin connected to the Buzzer
const int threshold = 400;    // Set your threshold value here

void setup() {
  pinMode(buzzerPin, OUTPUT); // Set buzzer pin as output
  pinMode(irSensorPin, INPUT); // Set IR sensor pin as input
}

void loop() {
  int sensorValue = analogRead(irSensorPin); // Read the value from the IR sensor

  if (sensorValue < threshold) { // If the sensor detects eyes closing
    delay(3000); // Wait for 3 seconds
    // Check again to confirm eyes are still closed
    sensorValue = analogRead(irSensorPin);
    if (sensorValue < threshold) {
      digitalWrite(buzzerPin, HIGH); // Activate the buzzer
    }
  } else {
    digitalWrite(buzzerPin, LOW); // Deactivate the buzzer
  }

  delay(100); // Small delay for stability
}