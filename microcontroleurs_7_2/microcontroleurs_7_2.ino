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


void nomove(){
  Led1Off;
  Led2Off;
}

void progress(){
  Led1Off;
  Led2On;
}

void back(int val){
  Led1On;
  //Led2Off;
  analogWrite(L2, 1023-val);  
}


void setup() { 
  pinMode (L1, OUTPUT);
  pinMode (L2, OUTPUT);

  nomove();
  
}

void loop(){
    
   int val = analogRead(A1);
   if(val > 512){
     back(val);
   } else {
     progress();
   }
}
