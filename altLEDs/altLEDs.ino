//Program to light up three various LEDs with a button
//Austin Chua
class Button
{
private:
  int pinNum;
  int buttonState;
  int debounce;
  bool dbRun;
public:
  Button(int pin)
  {
    pinNum = pin;
    buttonState = HIGH;
    debounce = 0;
    dbRun = true;
    pinMode(pinNum, INPUT_PULLUP);
  }
  
  bool pressed()
  {
    int newState = digitalRead(pinNum);
    if(buttonState == LOW and newState == HIGH){
        debounce = 0;
        dbRun = true;
      }
    if(dbRun == true){
      if(buttonState == HIGH and newState == LOW){
        buttonState = LOW;
        debounce++;
      }
      if(buttonState == LOW and newState == LOW){
        if(debounce == 3){
          debounce = 0;
          dbRun = false;
          return true;
        }
        else{
          debounce++;
        }
      } 
    }
    return false;
  }
};

class LED
{
private:
  int pinNum;
public:
  LED(int pin)
  {
    pinNum = pin;
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

void setup() {
  Serial.begin(115200);
  pinMode(13, INPUT_PULLUP);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

Button button(13);
LED redLED(2);
LED yellowLED(3);
LED greenLED(4);
LED leds[3] = {redLED, yellowLED, greenLED};
int count = 0;

void loop() {
  leds[count].turnON();
  bool pressed = button.pressed();
  if(pressed == true){
    leds[count].turnOFF();
    ++count;
    Serial.println("pressed");
    if(count > 2){
      count = 0;
    }
    leds[count].turnON();
  }
}
