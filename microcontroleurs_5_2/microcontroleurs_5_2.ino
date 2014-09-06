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

//int S = 0x53;
//int O = 0x4F;

void setup() { 
  pinMode(L1, OUTPUT);
  Serial.begin(9600);
}

void bit_0(){
  Serial.print("0");
  Led1On; 
  delay(3);
}

void bit_1(){
  Serial.print("1");
  Led1Off;
  delay(3);
}

void letter(int val){
  // start bit
  bit_1();
  delay(3);
  // bits
  for(int i=0; i<8; i++){
    if(val & (1 << i)){
      bit_1();
    } else {
      bit_0();
    } 
    delay(3); 
  }
  // stop bit
  bit_0();
  bit_0();
  
  Serial.println("");
}

void loop(){
  letter('S');
  letter('O');
  letter('S');
  delay(1000);  

}

