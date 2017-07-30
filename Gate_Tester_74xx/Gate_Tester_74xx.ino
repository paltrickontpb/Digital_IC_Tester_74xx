//Digital IC Tester for 74xx Series IC
//By Projjal Gupta & Shreyas

#include <String.h>

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

String datainput = "";

void setup() {

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

  Serial.begin(9600);

}

void normalPin(){
  digitalWrite(ip1, LOW);//IC pin 1
  digitalWrite(ip2, LOW);//IC pin 2
  
  digitalWrite(ip3, LOW);//IC pin 4
  digitalWrite(ip4, HIGH);//IC pin 5

  digitalWrite(ip5, HIGH);//IC pin 9
  digitalWrite(ip6, LOW);//IC pin 10

  digitalWrite(ip7, HIGH);//IC pin 12
  digitalWrite(ip8, HIGH);//IC pin 13
}

void TypeTest(String num) { 
  
  //Read the output of the Gates
  int a = digitalRead(op1);
  int b = digitalRead(op2);
  int c = digitalRead(op3);
  int d = digitalRead(op4);

  if (num == "7408") {
    normalPin();
    if (a==0){
      Serial.println("Gate 1 OK");
    } else {
      Serial.println("Gate 1 Not OK");
    }
    if (b==0){
      Serial.println("Gate 2 OK");
    } else {
      Serial.println("Gate 2 Not OK");
    }
    if (c==0){
      Serial.println("Gate 3 OK");
    } else {
      Serial.println("Gate 3 Not OK");
    }
    if (d==1){
      Serial.println("Gate 4 OK");
    } else {
      Serial.println("Gate 4 Not OK");
    }
  } else if (num == "7432") {
    normalPin();
    if (a==0){
      Serial.println("Gate 1 OK");
    } else {
      Serial.println("Gate 1 Not OK");
    }
    if (b==1){
      Serial.println("Gate 2 OK");
    } else {
      Serial.println("Gate 2 Not OK");
    }
    if (c==1){
      Serial.println("Gate 3 OK");
    } else {
      Serial.println("Gate 3 Not OK");
    }
    if (d==1){
      Serial.println("Gate 4 OK");
    } else {
      Serial.println("Gate 4 Not OK");
    }
  } else if (num == "7400") {
    normalPin();
    if (a==1){
      Serial.println("Gate 1 OK");
    } else {
      Serial.println("Gate 1 Not OK");
    }
    if (b==1){
      Serial.println("Gate 2 OK");
    } else {
      Serial.println("Gate 2 Not OK");
    }
    if (c==1){
      Serial.println("Gate 3 OK");
    } else {
      Serial.println("Gate 3 Not OK");
    }
    if (d==0){
      Serial.println("Gate 4 OK");
    } else {
      Serial.println("Gate 4 Not OK");
    }
  } else if (num == "7486") {
    normalPin();
    if (a==0){
      Serial.println("Gate 1 OK");
    } else {
      Serial.println("Gate 1 Not OK");
    }
    if (b==1){
      Serial.println("Gate 2 OK");
    } else {
      Serial.println("Gate 2 Not OK");
    }
    if (c==1){
      Serial.println("Gate 3 OK");
    } else {
      Serial.println("Gate 3 Not OK");
    }
    if (d==0){
      Serial.println("Gate 4 OK");
    } else {
      Serial.println("Gate 4 Not OK");
    }
  } else {
    Serial.println("Invalid Input");
  }
}
void loop() { //Main Function that continuously loops
  Serial.println("================================================");
  Serial.println("================================================");
  Serial.println("===        DIGITAL IC TESTER CIRCUIT         ===");
  Serial.println("================================================");
  Serial.println("================================================");
  Serial.println("========   BY PROJJAL GUPTA & SHREYAS   ========");
  Serial.println("================================================");
  Serial.println("================================================");
  Serial.println("================================================");
  Serial.println("        TYPE IN THE IC NUMBER FOR TESTING       ");
  Serial.println("================================================");
  Serial.println("");
  Serial.println("");
  Serial.println("IC NUMBER :");

  datainput = Serial.readString();
  TypeTest(datainput);
}
