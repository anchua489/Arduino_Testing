//Austin Chua
//Button class with included button debouncing algorithim 
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
  
  bool pressed() //button will only register a true press if button is pressed for 3 cycles. This is to eliminate noise disruption in the button press
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

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
