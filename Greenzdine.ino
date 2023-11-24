
int t; //temperature variable
const int ledPin = 13;// Define the LED pin
int tT= 30; // Threshold temperature
long int LM35pin = A0; //analog pin for LM35
volatile int ledState = LOW;
void setup()
{
pinMode(ledPin, OUTPUT);//LED pin as an output
Timer1.initialize(1000);
Timer1.attachInterrupt(T_INT);
Serial.begin(9600);
}

void loop()
{
  
int temperature = analogRead(lm35Pin);// Read the analog value from the LM35 temperature sensor
temperature = (sensorValue * 500.0) / 1023.0; // Convert the analog value to temperature in degrees Celsius
Serial.print("Temperature in C: ");
Serial.print(temperature);

// checking the temp
if (temperature < tT) 
{
setBlinkingInterval(250); //Blink in 250 milliseconds
}
else
{
setBlinkingInterval(500); //Blink in 500 milliseconds
}
}

// interrupt using Timer1 to toggle the LED
void T_INT()
{
if(ledState=LOW)
{
  ledState=HIGH;
}
else
{
  ledState=LOW;
}
}
   digitalWrite(ledPin, ledState);
}

void setBlinkingInterval(unsigned long interval) 
{  
  Timer1.setPeriod(interval*2);  // Set the Timer1 period based on the desired intervalMultiply by 2 to get the correct period
}
