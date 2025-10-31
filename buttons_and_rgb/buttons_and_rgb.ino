/*Connect buttons to ground and 742 pins.*/

const int RED_BUTTON_PIN = 7;
const int GREEN_BUTTON_PIN = 4;
const int BLUE_BUTTON_PIN = 2;

const int PIN_RED = 13;
const int PIN_GREEN = 12;
const int PIN_BLUE = 8;

int RED = 0;
int GREEN = 0;
int BLUE = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);

  pinMode(RED_BUTTON_PIN, INPUT_PULLUP);
  pinMode(GREEN_BUTTON_PIN, INPUT_PULLUP);
  pinMode(BLUE_BUTTON_PIN, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
  int redState = digitalRead(RED_BUTTON_PIN);
  int greenState = digitalRead(GREEN_BUTTON_PIN);
  int blueState = digitalRead(BLUE_BUTTON_PIN);


  if(redState == 0) {
    RED = RED + 5;
    Serial.print("Red: ");
    Serial.println(RED);
  }
  if(greenState == 0) {
    GREEN = GREEN + 5;  
    Serial.print("Green: ");
    Serial.println(GREEN);
  }
  if(blueState == 0) {
    BLUE = BLUE + 5;  
    Serial.print("Blue: ");
    Serial.println(BLUE);
  }
  
  delay(200);

  RED = constrain(RED, 0, 255);
  GREEN = constrain(GREEN, 0, 255);
  BLUE = constrain(BLUE, 0, 255);

  analogWrite(PIN_RED, RED);
  analogWrite(PIN_GREEN, GREEN);
  analogWrite(PIN_BLUE, BLUE);
}
