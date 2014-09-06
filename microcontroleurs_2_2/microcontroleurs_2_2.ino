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


const int MAX = 5;

int counter = 0;

void setup() { 
  pinMode (P1,INPUT); 
  pinMode (P2,INPUT);
  pinMode (L1,OUTPUT);
  pinMode (L2,OUTPUT);
}

void loop () {
  delay(20);  
  if (Pous1On && counter <5) { 
    counter++;
  } else if (Pous2On && counter>0) { 
    counter--;
  }
  if(counter == 0){
    Led1Off;
    Led2On;
  } else if(counter == MAX){
    Led1On;
    Led2Off;
  } else {
    Led1Off;
    Led2Off;  
  }
    
 } 
