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
  pinMode (P1, INPUT);
  pinMode (P2, INPUT);

  Serial.begin(9600);

  Led1Off;
  Led2Off;

}

/*
 mesure de la durée du signal à 1 avec pulseIn()
 si durée differente de 0
 mesure de la durée du signal à 0 avec pulseIn()
 ici on a les deux durées, 
 donc on peut calculer le rapport cyclique et gérer les LEDs en conséquence
 sinon
 absence de signal, LEDs en conséquence
 */

void loop(){
  Serial.println("start");
  unsigned long highDelay = pulseIn(P1, LOW);
  
  if(highDelay>0){
    unsigned long lowDelay = pulseIn(P1, HIGH);
    int score = highDelay*100/(highDelay+lowDelay);
    Serial.println(score);
    if(score <= 40){
      Led1On;
      Led2Off;
    } 
    else if(score >= 60){
      Led1Off;
      Led2On;
    } 
    else {
      Led1Off;
      Led2Off;
    }     
  } 
  else {
    Led1Off;
    Led2Off;  
  }



}



