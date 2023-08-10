// C++ code
//

#define sensorldr A0
#define sensorpir 3
#define led_g 6
#define led_v 5


int leituraldr;
int leiturapir;
float brilho;
int c;
int soma;

void setup() {
  
  Serial.begin(9600);
  pinMode(led_g, OUTPUT);
  pinMode(sensorldr, INPUT);
  pinMode(led_v, OUTPUT);
  pinMode(sensorpir, INPUT);
 
}

void loop() {
  
  leiturapir = digitalRead(sensorpir);

  for(int c = 0; c < 10; c++){
    
    soma = 0;
    leituraldr = analogRead(sensorldr);      
    soma = soma + leituraldr;
    soma = soma / 10;    
    
  } //Pra fazer uma média, ao invés de ficar tirando medida e jogando na luz toda hora, talvez faça média maiores dependendo da implementação.

  brilho = map(soma, 0, 1024, 0, 255);
  
  if(soma <= 30 ){
    analogWrite(led_g, 0);    
  }
  if(soma > 30 && soma <= 40){
    analogWrite(led_g, 20);   
  }  

  if(soma > 40 && soma <= 50){
    analogWrite(led_g, 40);   
  }  

  if(soma > 50 && soma <= 60){
    analogWrite(led_g, 60);   
  } 

  if(soma > 60 && soma <= 75){
    analogWrite(led_g, 80);   
  } 

  if(soma > 75){
    analogWrite(led_g, 255);   
  }  
  
  Serial.print("Leitura Média = ");
  Serial.println(soma);

  Serial.print("Brilho = ");
  Serial.print(brilho);
  Serial.println("% ");
  
  Serial.print("Leitura PIR = ");
  Serial.println(leiturapir);
  
  if(leiturapir == 1){
    digitalWrite(led_v, HIGH);
  }else{
    digitalWrite(led_v, LOW);
   }
  
  delay(5000);
}
