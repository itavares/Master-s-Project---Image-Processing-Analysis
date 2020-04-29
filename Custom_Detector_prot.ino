//TODO : set up debug functionality
//TODO : add button to change frequency instead of serial command
//TODO : fix circuitry, make it more compact.
//TODO : record changes to a file (add functionality such as a button to record current state and save it).


// Pin Definitions - RED LED
#define LEDR_1_PIN_VIN  5
#define LEDR_2_PIN_VIN  4
#define LEDR_3_PIN_VIN  9

// Pin Definitions - BLUE LED
#define LEDB_1_PIN_VIN  6
#define LEDB_2_PIN_VIN  7
#define LEDB_3_PIN_VIN  8


// Pin Definitions - GREEN LED
#define LEDG_1_PIN_VIN  10
#define LEDG_2_PIN_VIN  11
#define LEDG_3_PIN_VIN  12

#define TRIMMER_PIN_SIG A3 //potentiometer

#define TRUE 1
#define FALSE 0

int readValue; //variable to read the Potentiometer
int writeValue; // variable to write to LED

int ledState = LOW;  //inital state

unsigned long previousMillis = 0; //last time LED was updated
long interval = 25;   //rate of blinking (ms)

char menuOption  = 0;
char colorOption = 0;

int debug;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");

//define pin for RED LED
    pinMode(LEDR_1_PIN_VIN, OUTPUT);
    pinMode(LEDR_2_PIN_VIN, OUTPUT);
    pinMode(LEDR_3_PIN_VIN, OUTPUT);

//define pin for BLUE LED
    pinMode(LEDB_1_PIN_VIN, OUTPUT);
    pinMode(LEDB_2_PIN_VIN, OUTPUT);
    pinMode(LEDB_3_PIN_VIN, OUTPUT);

   //define pin for GREE LED
    pinMode(LEDG_1_PIN_VIN, OUTPUT);
    pinMode(LEDG_2_PIN_VIN, OUTPUT);
    pinMode(LEDG_3_PIN_VIN, OUTPUT);

// define pin for POTENTIOMETER
    pinMode(TRIMMER_PIN_SIG, INPUT);

   // menuOption = serial_menu();

    debug = TRUE;  //TRUE : use serial input ;  FALSE : run with 50ms default

    if (debug)
      colorOption = color_menu();
     // menuOption = serial_menu();
      menuOption = '1';

       //colorOption = color_menu(); //have errors. test with frequency 1 only for now
      
       delay(2000);
       Serial.println(colorOption);
        Serial.println(menuOption);

      

}

void loop() {
  // put your main code here, to run repeatedly:

//check menu option

if(debug == 1){

  
if(menuOption == '1' ){

     unsigned long currentMillis = millis(); //get current time
        interval = 25; //set to 25ms (20hz)
        readValue = analogRead(TRIMMER_PIN_SIG); //Read value from potentiometer
        writeValue = ( 255./1023.) * readValue ; 
        
    switch (colorOption){
      case 'r':
       
        analogWrite(LEDR_1_PIN_VIN, writeValue);
        analogWrite(LEDR_2_PIN_VIN, writeValue);
        analogWrite(LEDR_3_PIN_VIN, writeValue);        
        if (currentMillis - previousMillis >= interval) {
            // save the last time you blinked the LED
            previousMillis = currentMillis;
            
            if (ledState == LOW) {
              ledState = HIGH;
            } else {
              ledState = LOW;
            }
            digitalWrite(LEDR_1_PIN_VIN, ledState);
            digitalWrite(LEDR_2_PIN_VIN, ledState);
            digitalWrite(LEDR_3_PIN_VIN, ledState);
             }
        
              Serial.print("Write Value: ");
              Serial.println(writeValue);
        break;
         case 'b':
       
        analogWrite(LEDB_1_PIN_VIN, writeValue);
        analogWrite(LEDB_2_PIN_VIN, writeValue);
        analogWrite(LEDB_3_PIN_VIN, writeValue);        
        if (currentMillis - previousMillis >= interval) {
            // save the last time you blinked the LED
            previousMillis = currentMillis;
            
            if (ledState == LOW) {
              ledState = HIGH;
            } else {
              ledState = LOW;
            }
            digitalWrite(LEDB_1_PIN_VIN, ledState);
            digitalWrite(LEDB_2_PIN_VIN, ledState);
            digitalWrite(LEDB_3_PIN_VIN, ledState);
             }
        
              Serial.print("Write Value: ");
              Serial.println(writeValue);
              break;

case 'g':
       
        analogWrite(LEDG_1_PIN_VIN, writeValue);
        analogWrite(LEDG_2_PIN_VIN, writeValue);
        analogWrite(LEDG_3_PIN_VIN, writeValue);        
        if (currentMillis - previousMillis >= interval) {
            // save the last time you blinked the LED
            previousMillis = currentMillis;
            
            if (ledState == LOW) {
              ledState = HIGH;
            } else {
              ledState = LOW;
            }
            digitalWrite(LEDG_1_PIN_VIN, ledState);
            digitalWrite(LEDG_2_PIN_VIN, ledState);
            digitalWrite(LEDG_3_PIN_VIN, ledState);
             }
        
              Serial.print("Write Value: ");
              Serial.println(writeValue);
              break;

        default:
            Serial.println("switch over");
            break;
    }
//    unsigned long currentMillis = millis(); //get current time
//    interval = 25; //set to 25ms (20hz)
//    readValue = analogRead(TRIMMER_PIN_SIG); //Read value from potentiometer
//    writeValue = ( 255./1023.) * readValue ; 
//    analogWrite(LEDR_1_PIN_VIN, writeValue);
//    analogWrite(LEDR_2_PIN_VIN, writeValue);
//    analogWrite(LEDR_3_PIN_VIN, writeValue);
//
//    analogWrite(LEDB_1_PIN_VIN, writeValue);
//    analogWrite(LEDB_2_PIN_VIN, writeValue);
//    analogWrite(LEDB_3_PIN_VIN, writeValue);
//    
//    if (currentMillis - previousMillis >= interval) {
//        // save the last time you blinked the LED
//        previousMillis = currentMillis;
//        
//        if (ledState == LOW) {
//          ledState = HIGH;
//        } else {
//          ledState = LOW;
//        }
//        digitalWrite(LEDR_1_PIN_VIN, ledState);
//        digitalWrite(LEDR_2_PIN_VIN, ledState);
//        digitalWrite(LEDR_3_PIN_VIN, ledState);
//
//
//        digitalWrite(LEDB_1_PIN_VIN, ledState);
//        digitalWrite(LEDB_2_PIN_VIN, ledState);
//        digitalWrite(LEDB_3_PIN_VIN, ledState);
//    
//    }
//        
//    Serial.print("Write Value: ");
//    Serial.println(writeValue);
//    
    

  }

// ========================================================MENU2========================================================
  else if(menuOption == '2'){
    
    
    unsigned long currentMillis = millis(); //get current time
    interval = 50; //set to 25ms (20hz)
    readValue = analogRead(TRIMMER_PIN_SIG); //Read value from potentiometer
    writeValue = ( 255./1023.) * readValue ; 
    analogWrite(LEDR_1_PIN_VIN, writeValue);
    analogWrite(LEDR_2_PIN_VIN, writeValue);
    analogWrite(LEDR_3_PIN_VIN, writeValue);
    
    if (currentMillis - previousMillis >= interval) {
        // save the last time you blinked the LED
        previousMillis = currentMillis;
        
        if (ledState == LOW) {
          ledState = HIGH;
        } else {
          ledState = LOW;
        }
        digitalWrite(LEDR_1_PIN_VIN, ledState);
        digitalWrite(LEDR_2_PIN_VIN, ledState);
        digitalWrite(LEDR_3_PIN_VIN, ledState);
    
    }
        
    Serial.print("Write Value: ");
    Serial.println(writeValue);
    
    

  }

   else if(menuOption == '3'){
    
    
    unsigned long currentMillis = millis(); //get current time
    interval = 100; //set to 25ms (20hz)
    readValue = analogRead(TRIMMER_PIN_SIG); //Read value from potentiometer
    writeValue = ( 255./1023.) * readValue ; 
    analogWrite(LEDR_1_PIN_VIN, writeValue);
    analogWrite(LEDR_2_PIN_VIN, writeValue);
    analogWrite(LEDR_3_PIN_VIN, writeValue);
    
    if (currentMillis - previousMillis >= interval) {
        // save the last time you blinked the LED
        previousMillis = currentMillis;
        
        if (ledState == LOW) {
          ledState = HIGH;
        } else {
          ledState = LOW;
        }
        digitalWrite(LEDR_1_PIN_VIN, ledState);
        digitalWrite(LEDR_2_PIN_VIN, ledState);
        digitalWrite(LEDR_3_PIN_VIN, ledState);
    
    }
        
    Serial.print("Write Value: ");
    Serial.println(writeValue);
    
    

  }

   else if(menuOption == '4'){
    
    unsigned long currentMillis = millis(); //get current time
    interval = 200; //set to 25ms (20hz)
    readValue = analogRead(TRIMMER_PIN_SIG); //Read value from potentiometer
    writeValue = ( 255./1023.) * readValue ; 
    analogWrite(LEDR_1_PIN_VIN, writeValue);
    analogWrite(LEDR_2_PIN_VIN, writeValue);
    analogWrite(LEDR_3_PIN_VIN, writeValue);
    
    if (currentMillis - previousMillis >= interval) {
        // save the last time you blinked the LED
        previousMillis = currentMillis;


        //TODO: make this more efficient 
        if (ledState == LOW) {
          ledState = HIGH;
        } else {
          ledState = LOW;
        }
        digitalWrite(LEDR_1_PIN_VIN, ledState);
        digitalWrite(LEDR_2_PIN_VIN, ledState);
        digitalWrite(LEDR_3_PIN_VIN, ledState);
    
    }
        
    Serial.print("Write Value: ");
    Serial.println(writeValue);
    
    

  }
  
  } //debug
  //==================================================================================DEFAULT DEBUG=======================================================
  else if (debug == 0)
  {

    unsigned long currentMillis = millis(); //get current time
    interval = 100; //set to 25ms (20hz)
    readValue = analogRead(TRIMMER_PIN_SIG); //Read value from potentiometer
    writeValue = ( 255./1023.) * readValue ; 
    analogWrite(LEDR_1_PIN_VIN, writeValue);
    analogWrite(LEDR_2_PIN_VIN, writeValue);
    analogWrite(LEDR_3_PIN_VIN, writeValue);
    
    if (currentMillis - previousMillis >= interval) {
        // save the last time you blinked the LED
        previousMillis = currentMillis;


        //TODO: make this more efficient 
        if (ledState == LOW) {
          ledState = HIGH;
        } else {
          ledState = LOW;
        }
        digitalWrite(LEDR_1_PIN_VIN, ledState);
        digitalWrite(LEDR_2_PIN_VIN, ledState);
        digitalWrite(LEDR_3_PIN_VIN, ledState);
    
    }
        
    Serial.print("Write Value: ");
    Serial.println(writeValue);
    
    
  }
  
}


char serial_menu(){
Serial.println(F("\n Select your frequency for testing: "));
Serial.println(F("(1) LED - 25ms (20hz)"));
Serial.println(F("(2) LED - 50ms (10hz)"));
Serial.println(F("(3) LED - 100ms (5hz)"));
Serial.println(F("(4) LED - 200ms (2hz)"));
Serial.println(F("Click on RESTART Button to restart application"));


while(!Serial.available());

while(Serial.available()){
  char c = Serial.read();
  if(isAlphaNumeric(c)){
    if (c == '1')
      Serial.println(F("Changin Frequency to 20hz "));
    else if (c == '2')
      Serial.println(F("Changin Frequency to 10hz "));
    else if (c == '3')
      Serial.println(F("Changin Frequency to 5hz "));
    else if (c == '4')
      Serial.println(F("Changin Frequency to 2hz "));
     else{
        Serial.println(F("Illegal input!"));
        return 0;
      }  

      return c;
  }
  
}

}

char color_menu(){
  Serial.println(F("\n Select which color to run: "));
  Serial.println(F("(r) RED   "));
  Serial.println(F("(b) BLUE  "));
  Serial.println(F("(g) GREEN "));

  while(!Serial.available());
  
  while(Serial.available()){
  char cc = Serial.read();
  if(isAlphaNumeric(cc)){
    if (cc == 'r')
      Serial.println(F("Changin color to RED "));
    else if (cc == 'b')
      Serial.println(F("Changin color to BLUE "));
    else if (cc == 'g')
      Serial.println(F("Changin color to GREEN "));
     else{
        Serial.println(F("Illegal input!"));
        return 0;
      }  

      return cc;
  }
  
}
  
}



//Serial Control (Menu)
