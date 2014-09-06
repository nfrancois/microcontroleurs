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
boolean p1on = false;
boolean p2on = false;

void setup() { 
  pinMode (L1, OUTPUT);
  pinMode (L2, OUTPUT);
  pinMode(P1, INPUT);
  pinMode(P2, INPUT);
}

void reset(){
  step=0;
  delay(1000);
}

void success(){
  Led1On;
  delay(3000);
  Led1Off;
  step = 0;
}

void buttonState(){
  if(Pous1On && !p1on){
    p1on = true;
  } else if(Pous1Off && p1on){
    p1on = false;
  } if(Pous2On && !p2on){
    p2on = true;
  } else if(Pous2Off && p2on){
    p2on = false;
  } 
}

void lockState(){  switch(step){
    // Etape erreur
    case -1:
      if(!p1on && !p2on){
        step++;
      }
     reset();
    // Appuie sur P1  
    case 0:
      if(p1on && !p2on){
        step++;
      } else if(p1on && p2on){
        step = -1;
      }
      break;
      // Relacher P1
     case 1:
       if(!p1on && !p2on){
         step++;
       } else if(p1on && p2on){
         step = -1;
       }
       break;
      // Appuie P1
      case 2:
        if(p1on && !p2on){
          step++;
        } else if(p1on && p2on){
          step = -1;
        }
        break;
     // Appuie P2
      case 3:
        if(p1on && p2on){
          step++;
        } else if(!p1on && !p2on){
          step = -1;
        }
        break; 
      // Relache P2
      case 4 :
        if(p1on && !p2on){
          step++;
        } else if(!p1on && p2on){
          reset();
        }
        break;
      // Relache P1
      case 5:
       if(!p1on && !p2on){
         step++;
       } else if(p1on && p2on){
         step = -1;
       }     
        break;
      // Win
     default:
       success();
       break;
  }
}


void loop(){
  delay(20);
  buttonState();
  lockState();
}
