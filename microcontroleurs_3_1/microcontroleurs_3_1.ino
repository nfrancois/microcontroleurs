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


int l1Counter = 0;
int l2Counter = 0;

boolean p1_pressed = false;
boolean p2_pressed = false;


void setup() { 
  pinMode (P1, INPUT); 
  pinMode (P2, INPUT);
  pinMode (L1, OUTPUT);
  pinMode (L2, OUTPUT);
}

void loop () {
  delay(20);  
  if (l1Counter < l2Counter) { 
    Led1Off;
    Led2On;
  } 
  else if (l1Counter > l2Counter) { 
    Led1On;
    Led2Off;
  } 
  else {
    Led1Off;
    Led2Off;
  }

  if(Pous1On && !p1_pressed){
    p1_pressed = true;
    l1Counter++;
  } else if(Pous1Off && p1_pressed){
    p1_pressed = false;
  } 
  if(Pous2On && !p2_pressed){
    p2_pressed = true;
    l2Counter++;
  } 
  else if(Pous2Off && p2_pressed){
    p2_pressed = false;
  }

} 


