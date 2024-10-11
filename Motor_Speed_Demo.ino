// C++ code
// Nathan Fikes

//Establishing Globals.

//LED controlling Pins.
int LED_RED = 7;
int LED_YELLOW = 4;
int LED_GREEN = 2;

//Motor Controlling Pins on H-Bridge.
int PIN_1A = 13;
int PIN_2A = 12;
int PWM_PIN = 11;

//Program Slowness
int DELAY_MS = 50;

void setup()
{
  // Set the BAUD here for the channel you want to communicate on.
  Serial.begin(115200);
  
  //When setting things up, be sure to add completion strings
  //to print into the serial monitor.
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  Serial.print("LED's Ready\n");

  pinMode(PIN_1A, OUTPUT);
  pinMode(PIN_1A, OUTPUT);
  pinMode(PWM_PIN, OUTPUT);
  Serial.print("Motor Ready\n");
}

void light_decider(int speed_percentage)
{
  if (speed_percentage < 30)
  {
  	digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_GREEN, LOW);
  } 
  else if (speed_percentage < 70)
  {
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_GREEN, LOW);
  }
  else
  {
  	digitalWrite(LED_RED, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_GREEN, HIGH);
  }
}

void motor_speed(int speed_percentage)
{
  light_decider(abs(speed_percentage));
  
  if (0 > speed_percentage)
  {
  	digitalWrite(PIN_1A, LOW);
  	digitalWrite(PIN_2A, HIGH);
  }
  else
  {
  	digitalWrite(PIN_1A, HIGH);
  	digitalWrite(PIN_2A, LOW);
  }
  analogWrite(PWM_PIN, round(2.55*abs(speed_percentage)));
}

void loop()
{
  for (int j = 0; j < 100; j++)
  {
    motor_speed(j);
    delay(DELAY_MS);
  }
  for (int i = 100; i > 0; i--)
  {
    motor_speed(i);
    delay(DELAY_MS);
  }

  delay(500);

  for (int k = 0; k > -100; k--)
  {
    motor_speed(k);
    delay(DELAY_MS);
  }
  for (int w = -100; w < 0; w++)
  {
    motor_speed(w);
    delay(DELAY_MS);
  }

  delay(500);
}