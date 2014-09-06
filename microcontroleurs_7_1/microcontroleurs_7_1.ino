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

#define L3 6 
#define Led3On digitalWrite (L3,1); 
#define Led3Off digitalWrite (L3,0);

#define L4 7 
#define Led4On digitalWrite (L4,1); 
#define Led4Off digitalWrite (L4,0);


unsigned long start;

void stop(){
  Led1Off;
  Led2Off;
  Led3Off;
  Led4Off;  
}

void setup() { 
  pinMode (L1, OUTPUT);
  pinMode (L2, OUTPUT);
  pinMode (L3, OUTPUT);
  pinMode (L4, OUTPUT);
  pinMode (P1, INPUT);
  pinMode (P2, INPUT);
  
  stop();
  
}

int detect(){
  if(Pous1On){
   return 1;
  } else if(Pous2On) {
    return 2;
  } else {
    return 0;
  }
}

void progress(){
  Led1On;
  Led2Off;
  Led3On;
  Led4Off;
}

void back(){
  Led1Off;
  Led2On;
  Led3Off;
  Led4On;  
}

void turnLeft(){
  Led1Off;
  Led2On;
  Led3On;
  Led4Off;  
}

void turnRigth(){
  Led1On;
  Led2Off;
  Led3Off;
  Led4On;  
}

void loop(){
  int obs = detect();
  if(obs == 0){
    progress();
  } else {
    start = millis();
    while(millis() - start <1000){
      back();
    }
    start = millis();
    while(millis() - start <500){
      if(obs == 1){
        turnRigth();
      } else {
        turnLeft();
      }
    }    
  }
  
}


