//Joystick testing
const int JoyStickpin = 3;
const int Xpin = 1;
const int Ypin = 0;

class JoyStick
{
private:
  int X;
  int Y;
  int buttonState;
  int pin;
  int Xpin;
  int Ypin;
  
public:
  JoyStick(int pinNum, int XpinNum, int YpinNum)
  {
    pin = pinNum;
    Xpin = XpinNum;
    Ypin = YpinNum;
    X = analogRead(Xpin);
    Y = analogRead(Ypin);
    buttonState = HIGH;
  }

  int getX()
  {
    int X1 = analogRead(Xpin);
    int X2 = analogRead(Xpin);
    int X3 = analogRead(Xpin);
    int X4 = analogRead(Xpin);
    int Xavg = (X1 + X2 + X3 + X4)/4;
    X = Xavg;
    return X;
  }

  int getY()
  {
    int Y1 = analogRead(Ypin);
    int Y2 = analogRead(Ypin);
    int Y3 = analogRead(Ypin);
    int Y4 = analogRead(Ypin);
    int Yavg = (Y1 + Y2 + Y3 + Y4)/4;
    Y = Yavg;
    return Y;
  }

  bool pressed()
  {
    int newState = digitalRead(pin);
    buttonState = newState;
    if(buttonState == LOW){
      return true;
    }
    return false;
  }
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(JoyStickpin, INPUT_PULLUP);
  //digitalWrite(JoyStickpin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  JoyStick j(JoyStickpin, Xpin, Ypin);
  //Serial.print("X-axis");
  //Serial.println(j.getX());
  Serial.print("Y-axis");
  Serial.println(j.getY());
}
