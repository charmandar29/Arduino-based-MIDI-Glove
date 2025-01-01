// Define pins for the LDRs
const int ldrPin1 = A0;  // LDR 1 connected to analog pin A0
const int ldrPin2 = A1;  // LDR 2 connected to analog pin A1
const int ldrPin3 = A2;  // LDR 3 connected to analog pin A2
const int ldrPin4 = A3;  // LDR 4 connected to analog pin A3

// Variables to store the analog values
int ldrValue1 = 0;
int ldrValue2 = 0;
int ldrValue3 = 0;
int ldrValue4 = 0;

// Variables to store the MIDI note values (0-127)
int midiNote1 = 60;  // MIDI note for LDR 1 (Middle C)
int midiNote2 = 62;  // MIDI note for LDR 2 (D)
int midiNote3 = 64;  // MIDI note for LDR 3 (E)
int midiNote4 = 67;  // MIDI note for LDR 4 (G)

// Thresholds for turning notes on and off (adjust as needed)
int noteOnThreshold = 512;   // Light intensity to turn the note ON
int noteOffThreshold = 500;  // Light intensity to turn the note OFF

// State variables to track if the note is currently on or off
bool note1On = false;
bool note2On = false;
bool note3On = false;
bool note4On = false;

void setup() {
  // Start serial communication at MIDI baud rate (31250 bps)
  Serial.begin(115200);
}

void loop() {
  // Read the analog values from the LDRs
  ldrValue1 = analogRead(ldrPin1);
  ldrValue2 = analogRead(ldrPin2);
  ldrValue3 = analogRead(ldrPin3);
  ldrValue4 = analogRead(ldrPin4);

  // Process LDR 1
  if (ldrValue1 > noteOnThreshold && !note1On) {
    sendMIDINoteOn(midiNote1, 127);  // Send MIDI Note On with full velocity (127)
    note1On = true;  // Mark note as ON
  } else if (ldrValue1 < noteOffThreshold && note1On) {
    sendMIDINoteOff(midiNote1, 0);  // Send MIDI Note Off
    note1On = false;  // Mark note as OFF
  }

  // Process LDR 2
  if (ldrValue2 > noteOnThreshold && !note2On) {
    sendMIDINoteOn(midiNote2, 127);
    note2On = true;
  } else if (ldrValue2 < noteOffThreshold && note2On) {
    sendMIDINoteOff(midiNote2, 0);
    note2On = false;
  }

  // Process LDR 3
  if (ldrValue3 > noteOnThreshold && !note3On) {
    sendMIDINoteOn(midiNote3, 127);
    note3On = true;
  } else if (ldrValue3 < noteOffThreshold && note3On) {
    sendMIDINoteOff(midiNote3, 0);
    note3On = false;
  }

  // Process LDR 4
  if (ldrValue4 > noteOnThreshold && !note4On) {
    sendMIDINoteOn(midiNote4, 127);
    note4On = true;
  } else if (ldrValue4 < noteOffThreshold && note4On) {
    sendMIDINoteOff(midiNote4, 0);
    note4On = false;
  }

  // Small delay for stability
  delay(10);
}

// Function to send a MIDI Note On message
void sendMIDINoteOn(byte note, byte velocity) {
  Serial.write(0x90);    // MIDI Note On message, Channel 1 (0x90)
  Serial.write(note);    // Note to play (e.g., 60 is middle C)
  Serial.write(velocity);  // Velocity (0-127)
}

// Function to send a MIDI Note Off message
void sendMIDINoteOff(byte note, byte velocity) {
  Serial.write(0x80);    // MIDI Note Off message, Channel 1 (0x80)
  Serial.write(note);    // Note to stop (e.g., 60 is middle C)
  Serial.write(velocity);  // Velocity (0 to turn off)
}
