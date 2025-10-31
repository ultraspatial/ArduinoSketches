float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


const int PIN_RED   = 5;
const int PIN_GREEN = 6;
const int PIN_BLUE  = 9;

// the setup routine runs once when you press reset:
void setup() {
  pinMode(PIN_RED,   OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE,  OUTPUT);

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin A0:
  int analogValue = analogRead(A0);
  // Rescale to potentiometer's voltage (from 0V to 5V):
  float voltage = floatMap(analogValue, 0, 1023, 0, 5);

  analogWrite(PIN_RED,   analogValue/4);
  analogWrite(PIN_GREEN, analogValue/4);
  analogWrite(PIN_BLUE,  analogValue/4);

  // print out the value you read:
  Serial.print("Analog: ");
  Serial.print(analogValue);
  Serial.print(", Voltage: ");
  Serial.println(voltage);
}