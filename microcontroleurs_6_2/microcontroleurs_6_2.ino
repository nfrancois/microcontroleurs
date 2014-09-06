#define P1 2 
#define Pous1On (digitalRead (P1)==0) 
#define Pous1Off (digitalRead (P1)==1)

#define P2 3 
#define Pous2On (digitalRead (P2)==0) 
#define Pous2Off (digitalRead (P2)==1)

#define L1 4 
#define Led1On digitalWrite (L1,1); 
#define Led1Off digitalWrite (L1,0);

#define L2 5 
#define Led2On digitalWrite (L2,1); 
#define Led2Off digitalWrite (L2,0);


enum STATE {INIT, WAIT, FILL};

unsigned long startTime;
unsigned long fillingTime = -1;

unsigned long lastPush;

STATE state;

void setup() { 
  pinMode (L1, OUTPUT);
  pinMode (P1, INPUT);
  pinMode (P2, INPUT);
  
  state = WAIT;
}

void loop(){
  switch(state){
    case INIT:
      if(Pous1Off){
        fillingTime = millis()  - startTime;
        Led1Off;  
        state = WAIT;
        delay(20);    
      } else {
        Led1On;
      }
      break;
    case WAIT:
      if(Pous1On){
        startTime = millis();
        Led1On;  
        state = INIT;  ;
        delay(20);    
      } else if(Pous2On && fillingTime!=-1){
        lastPush = millis();
        Led1On;
        state = FILL;
        delay(20);    
      } else {
        Led1Off;
      }     
      break;
    case FILL:
      if(millis()-lastPush >= fillingTime){
        Led1Off;
        state = WAIT;
      } else {
        Led1On;
      }
      break;

  }
}

