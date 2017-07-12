//Digital IC Tester for 74xx Series IC
//By Projjal Gupta

#include <LiquidCrystal.h>
#include <String.h>

LiquidCrystal lcd(A4,A5,10,11,12,13);//(RS,EN,4,5,6,7) on LCD Module

//Initializing Input and Output pins
int ip1 = 2;
int ip2 = 3;
int ip3 = 4;
int ip4 = 5;
int ip5 = 6;
int ip6 = 7;
int ip7 = 8;
int ip8 = 9;

int op1 = A0;
int op2 = A1;
int op3 = A2;
int op4 = A3;

String icType = "";
String icNum = "";
int Rled = 0;
int Gled = 1;

void setup() {
  //LCD Initialization
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" IC 74xx Tester ");
  lcd.setCursor(0, 1);
  lcd.print("   By Projjal   ");
  
  // Initializing the type of pin activity
  pinMode(ip1,OUTPUT); 
  pinMode(ip2,OUTPUT);
  pinMode(ip3,OUTPUT);
  pinMode(ip4,OUTPUT);
  pinMode(ip5,OUTPUT);
  pinMode(ip6,OUTPUT);
  pinMode(ip7,OUTPUT);
  pinMode(ip8,OUTPUT);
  
  pinMode(op1,INPUT);//IC pin 3
  pinMode(op2,INPUT);//IC pin 6
  pinMode(op3,INPUT);//IC pin 8
  pinMode(op4,INPUT);//IC pin 11

  //Setup Output LEDs
  pinMode(Rled,OUTPUT);
  pinMode(Gled,OUTPUT);

  //Setup pins as Input pairs
  digitalWrite(ip1, LOW);//IC pin 1
  digitalWrite(ip2, LOW);//IC pin 2
  
  digitalWrite(ip3, LOW);//IC pin 4
  digitalWrite(ip4, HIGH);//IC pin 5

  digitalWrite(ip5, HIGH);//IC pin 9
  digitalWrite(ip6, LOW);//IC pin 10

  digitalWrite(ip7, HIGH);//IC pin 12
  digitalWrite(ip8, HIGH);//IC pin 13

  digitalWrite(Rled, HIGH);
  digitalWrite(Gled, HIGH);
  
  delay(3000);
  
  digitalWrite(Rled, LOW);
  digitalWrite(Gled, LOW);
}


void TypeTest() { //Function to find the type of IC

  //Read the output of the Gates
  int a = digitalRead(op1);
  int b = digitalRead(op2);
  int c = digitalRead(op3);
  int d = digitalRead(op4);
  int ToP = ((8*a)+(4*b)+(2*c)+d);

  //Gate Detection
  if (ToP==1){
    icType = "AND";
    icNum = "7408/09" ;
  } else if (ToP==7){
    icType = "OR"; 
    icNum = "7432" ;
  } else if (ToP==14){
    icType = "NAND"; 
    icNum = "7400/01/03";
  } else if (ToP==8){
    icType = "NOR";  
    icNum = "7402";
  } else if (ToP==6){
    icType = "XOR"; 
    icNum = "7486";
  } else if (ToP==9){
    icType = "XNOR"; 
    icNum = "74266/810" ;
  } else if (ToP==0){
    icType = "none";
    icNum = "error" ; 
  } else {
    icType = "fault";
    icNum = "error";  
  }
}

void printType(String temptype,String tempnum){ //Print the output on the LCD screen
  
if (temptype=="none"){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(" ERROR ALERT !! ");
    lcd.setCursor(0,1);
    lcd.print(" No IC Detected ");
    loopred(); 
} else if (temptype=="fault"){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(" ERROR ALERT !! ");
    lcd.setCursor(0,1);
    lcd.print("  IC is Faulty!  ");
    red(); 
  } else {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("   IC "+tempnum+"   ");
    lcd.setCursor(0,1);
    lcd.print("  Gate - "+temptype+"  ");
    green();  
  }
}

void red() { // Red Led Switching
  digitalWrite(Rled, HIGH);
  digitalWrite(Gled, LOW);
}

void green() { // Green LED switching
  digitalWrite(Gled, HIGH);
  digitalWrite(Rled, LOW);
}

void loopred() { //Red LED Blinking alert
  while (true) {
    red();
    delay(1000);
    digitalWrite(Rled, LOW);
    delay(1000);
  }
}

void loop() { //Main Function that continuously loops
  
  TypeTest();
  printType(icType,icNum);
}
