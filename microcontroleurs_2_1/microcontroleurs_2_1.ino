#define L1 4 
#define Led1On digitalWrite (L1,1); 
#define Led1Off digitalWrite (L1,0);

#define L2 5 
#define Led2On digitalWrite (L2,1); 
#define Led2Off digitalWrite (L2,0);

#define P1 2 
#define Pous1On (digitalRead (P1)==0) 
#define Pous1Off (digitalRead (P1)==1)

void setup() { 
  pinMode (P1,INPUT); 
  pinMode (L1,OUTPUT);
  pinMode (L2,OUTPUT);
}

void loop () { 
   if (Pous1On) { 
     Led1On; 
     delay(1000);
     Led2On;
     delay(1000);
     Led1Off; 
     delay(1000);
     Led2Off;         
   } else {
     Led1Off; 
     Led2Off;
   } 
 } 
