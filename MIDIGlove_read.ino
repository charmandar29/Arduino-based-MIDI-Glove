// Define pins for the LDRs
const int ldrPin1 = A0;  // LDR 1 connected to analog pin A0
const int ldrPin2 = A1;  // LDR 2 connected to analog pin A1
const int ldrPin3 = A2;  // LDR 3 connected to analog pin A2
const int ldrPin4 = A3;  // LDR 4 connected to analog pin A3
// Variables to store the inverted LDR values
int LdrValue1 = 0;
int LdrValue2 = 0;
int LdrValue3 = 0;
int LdrValue4 = 0;

// Variables to store the analog values
int ldrValue1 = 0;
int ldrValue2 = 0;
int ldrValue3 = 0;
int ldrValue4 = 0;



void setup() {
  // Start serial communication at MIDI baud rate (115200 bps)
  Serial.begin(115200);
}

void loop() {
  // Read the analog values from the LDRs
  ldrValue1 = analogRead(ldrPin1);
  ldrValue2 = analogRead(ldrPin2);
  ldrValue3 = analogRead(ldrPin3);
  ldrValue4 = analogRead(ldrPin4);

 // Invert the values: Higher light intensity should give lower values
  LdrValue1 = map(ldrValue1, 0, 1023, 1023, 0);
  LdrValue2 = map(ldrValue2, 0, 1023, 1023, 0);
  LdrValue3 = map(ldrValue3, 0, 1023, 1023, 0);
  LdrValue4 = map(ldrValue4, 0, 1023, 1023, 0);

  // Print the inverted values to the Serial Monitor
  Serial.print("Inverted LDR 1 Value: ");
  Serial.println(LdrValue1);
  
  Serial.print("Inverted LDR 2 Value: ");
  Serial.println(LdrValue2);

  Serial.print("Inverted LDR 3 Value: ");
  Serial.println(LdrValue3);
  
  Serial.print("Inverted LDR 4 Value: ");
  Serial.println(LdrValue4);


 
 
  // Small delay for stability
  delay(100);
}
