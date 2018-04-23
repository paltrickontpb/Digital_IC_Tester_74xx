#include <LiquidCrystal.h>

#include <Keypad.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int n = 0;

void setup(){
   Serial.begin(9600);
   lcd.begin(16,2);
   lcd.setCursor(0, 0);
   lcd.print("Enter IC Number");
  
}
  
void loop(){
  char key = keypad.getKey();
  
  if (key){
    if (key == '#'){
      
    }
    else if (key == '*'){
      for (int i=0; i<16; i++){
        lcd.setCursor(i, 1);
        lcd.print(" ");
        n=0;
      }
    } else {
      lcd.setCursor(n, 1);
      lcd.print(key);
      n++;
    }
  }
}
