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
}


void dot(){
  Led1On;
  delay(200);
  Led1Off;  
}

void dash(){
  Led1On;
  delay(600);
  Led1Off; 
}

void S(){
  dash();
  delay(200);
  dash();
  delay(200);
  dash();
}

void O(){
  dot();
  delay(200);
  dot();
  delay(200);
  dot();
}

void loop () {
  S();
  delay(600);
  O();
  delay(600);
  S();
  delay(1400);
  delay(2000); 
}
