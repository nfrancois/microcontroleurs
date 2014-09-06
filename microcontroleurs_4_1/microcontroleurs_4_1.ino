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

int step = 0;

void setup() { 
  pinMode (L1, OUTPUT);
  pinMode (L2, OUTPUT);
  Serial.begin(9600);
}
boolean p1on = false;
boolean p2on = false;


void loop(){
 delay(20);
  Serial.println(step);
  
  switch(step){
    case 0:
      //Serial.println("00");
      Led1Off;
      Led2Off;   
      break;
    case 1:
      //Serial.println("10");
      Led1On;
      Led2Off;       
      break;
    case 2:
     // Serial.println("11");
      Led1On;
      Led2On;    
      break;
    case 3:   
     // Serial.println("01");
      Led1Off;
      Led2On;    
      break;
  }

  if(Pous1On && !p1on){
    if(step==3){
      step = 0;
    } else {
      step++;
    }
    p1on = true;
  } else if(Pous1Off && p1on){
    p1on = false;
  } if(Pous2On && !p2on){
    if(step==0){
      step = 3;
    } else {
      step--;
    }
    p2on = true;
  } else if(Pous2Off && p2on){
    p2on = false;
  } 
}

