//Arduino motor testing
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


class Motor
{
private:
  int signalPin;
  int pin1;
  int pin2;
  int pin1state;
  int pin2state;

public:
  Motor(int Signal, int pinOne, int pinTwo)
  {
    pin1 = pinOne;
    pin2 = pinTwo;
    signalPin = Signal;
    pin1state = HIGH;
    pin2state = LOW;
  }

  void changeDir()
  {
    if(pin1state == LOW and pin2state == HIGH){
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, LOW);
      pin1state = HIGH;
      pin2state = LOW;
    }
    else{
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, HIGH);
      pin1state = LOW;
      pin2state = HIGH;
    }
  }
};

class Potentiometer
{
private:
  int pinNum;

public:
  Potentiometer(int pin)
  {
    pinNum = pin;
  }

  int getval()
  {
    int avg = 0;
    for(int i = 0; i < 6; ++i){
      avg += analogRead(pinNum);
    }
    return avg/6;
  }
};

void setup() {
  Serial.begin(115200);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  digitalWrite(8,  LOW);
  digitalWrite(9, HIGH);
}

Button b(7);
Motor m(11,8,9);
Potentiometer p(5);

void loop() {
  int potval = p.getval();
  int pwm = map(potval, 0, 1023,0, 255);
  Serial.println(pwm);
  analogWrite(11, pwm); 
  if(b.pressed() == true){
    m.changeDir(); 
  }
}
