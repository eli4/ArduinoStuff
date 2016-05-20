const int exLED = 2;
String morseCode[26];


void setup() {
  pinMode(exLED, OUTPUT);
  Serial.begin(9600);
  morseCode[0] = "SF";
  morseCode[1]= "FSSS";
  morseCode[2]= "FSFS";
  morseCode[3]= "FSS";
  morseCode[4]= "S";
  morseCode[5]= "SSFS";
  morseCode[6]= "FFS"; 
  morseCode[7]= "SSSS";
  morseCode[8]= "SS";
  morseCode[9]= "SFFF";
  morseCode[10]= "FSF";
  morseCode[11]= "SFSS";
  morseCode[12]= "FF";  
  morseCode[13]= "FS";
  morseCode[14]= "FFF";
  morseCode[15]= "SFFS";
  morseCode[16]= "FFSF";
  morseCode[17]= "SFS";
  morseCode[18]= "SSS";  
  morseCode[19]= "F";
  morseCode[20]= "SSF";
  morseCode[21]= "SSSF";
  morseCode[22]= "SFF";
  morseCode[23]= "FSSF";
  morseCode[24]= "FSFF";   
  morseCode[25]= "FFSS";  
}

void loop() {
  int incomingByte = 0;
  //char inputChar = 0;
  if(Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    //inputChar = incomingByte;

    // say what you got:
    Serial.print("I received: ");
    Serial.print(incomingByte);
    //Serial.print(inputChar);
    Serial.print("\n");
    const int space = 32;
    if(incomingByte == space){
      wordEnd();
    }
    int index = incomingByte - 97;
    if(index >= 0 && index < 26){      
      String code = morseCode[incomingByte - 97]; //97 is the ascii code for 'a'
      int i =0;
      while(code[i]){
        if(code[i] == 'F'){
         dash();
       }
        if(code[i] == 'S'){
         dot();
       }
       i++;
     }
     charEnd();
   }
  }
}

void dot(){
      digitalWrite(exLED, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(200);              // wait for a second
      digitalWrite(exLED, LOW);    // turn the LED off by making the voltage LOW
      delay(500);
}

void dash(){
      digitalWrite(exLED, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(1000);              // wait for a second
      digitalWrite(exLED, LOW);    // turn the LED off by making the voltage LOW
      delay(500);
}
void charEnd(){
  delay(1000);
}

void wordEnd(){
  delay(1000);
}

