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

void setup() { 
  pinMode (L1, OUTPUT);
  pinMode (L2, OUTPUT);
}

void loop(){
  
  int val = analogRead(A1);
  
  if(val < 256 - 50){
    Led1Off;
    Led2Off;
  } else if(val < 512 - 50){
    Led1On;
    Led2Off;  
  } else  if(val < 767 - 50){
    Led1Off;
    Led2On;  
  } else {
    Led1On;
    Led2On;  
  }
  
  
}
