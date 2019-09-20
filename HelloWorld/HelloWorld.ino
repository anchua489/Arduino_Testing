//First Arduino program
class LED
{
private:
  int pinNum;
  
public:
  LED(int pin)
  {
    pinNum = pin;
    pinMode(pin, OUTPUT);
    digitalWrite(pinNum, LOW);
  }

  void turnON()
  {
    digitalWrite(pinNum, HIGH);
  }

  void turnOFF()
  {
    digitalWrite(pinNum, LOW);
  }
};

class Button
{
private:
  int pinNum;
  int buttonState;
public:
  Button(int pin)
  {
    pinNum = pin;
    pinMode(pinNum, INPUT_PULLUP);
  }

  int getState()
  {
    buttonState = digitalRead(pinNum);
    return buttonState;
  }
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  pinMode(13, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Hello World");
  LED redLED(2);
  Button button(13);
  int buttonState = button.getState();
  if(buttonState == HIGH){
    redLED.turnOFF();
  }
  else{
    redLED.turnON();
   }
}
