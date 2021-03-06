 /* Projeto Nº 08 -> Soundtrack de Star Wars of War
  *  
  * Author: Thiago Santos Tassinari
  * Data: 19/10/2020
  
  * Descrição do Projeto:
  <!---------------------Soundtrack de Star Wars of Wars----------------------------->
  	
    O projeto tem como funcionalidade de utilizar o Piezo Buzzer para reprodução do som
    de Star Wars. O PIR motion detector é utilizado pelo usuário com o mover do objeto
    detectado e começará o som de fundo da música; Ligará os LED's que acionaram a partir
    dos métodos no loop() ao contar as notas musicais.
    
  <---------------------------------------------------------------------------------->

<!-----------------------Componentes necessários------------------------------------->
  
  - Arduino Uno;
  - 2 LED's
  - 2 resistores de 1KOhm;
  - Piezo buzzer;
  - PIR motion detector;
  - Jumpers
  
<------------------------------------------------------------------------------------->  

*/

const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;
 
//Pin conectados
const int buzzerPin = 8;
const int ledPin1 = 12;
const int ledPin2 = 13;
const int pir=7;

int counter = 0;

void setup() {
  
  // Estado de setup dos pinos
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  pinMode(pir, INPUT_PULLUP); 

}

void loop() {
  
  // Verificar se há movimento
  if(digitalRead(pir)==HIGH)
  {
    //Se é detectado movimento, ligue o LED e toque música
    digitalWrite(ledPin2, HIGH);   

    // Toque a segunda seção
    firstSection();         

    //Toque a segunda seção
    secondSection();
    
    //Variação 1
  beep(f, 250);  
  beep(gS, 500);  
  beep(f, 350);  
  beep(a, 125);
  beep(cH, 500);
  beep(a, 375);  
  beep(cH, 125);
  beep(eH, 650);
 
  delay(500);
 
  //Repeat second section
  secondSection();
 
  //Variant 2
  beep(f, 250);  
  beep(gS, 500);  
  beep(f, 375);  
  beep(cH, 125);
  beep(a, 500);  
  beep(f, 375);  
  beep(cH, 125);
  beep(a, 650);  
 
  delay(650);
  
  }
  else
  {
  digitalWrite(ledPin2, LOW);    // Desligue o LED tornando a tensão BAIXA  
  delay(200);
  }
  
}

void beep(int note, int duration)
{
  //Toque tone on buzzerPin
  tone(buzzerPin, note, duration);
 
  //Toca diferentes LEDs dependendo do valor do 'contador'
  if(counter % 2 == 0)
  {
    digitalWrite(ledPin1, HIGH);
    delay(duration);
    digitalWrite(ledPin1, LOW);
  }else
  {
    digitalWrite(ledPin2, HIGH);
    delay(duration);
    digitalWrite(ledPin2, LOW);
  }
  
  noTone(buzzerPin);
  delay(50);
  counter++;
}
 
void firstSection()
{
  beep(a, ]500);
  beep(a, 500);    
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);  
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
 
  delay(500);
 
  beep(eH, 500);
  beep(eH, 500);
  beep(eH, 500);  
  beep(fH, 350);
  beep(cH, 150);
  beep(gS, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
 
  delay(500);
}

void secondSection()
{
  beep(aH, 500);
  beep(a, 300);
  beep(a, 150);
  beep(aH, 500);
  beep(gSH, 325);
  beep(gH, 175);
  beep(fSH, 125);
  beep(fH, 125);    
  beep(fSH, 250);
 
  delay(325);
 
  beep(aS, 250);
  beep(dSH, 500);
  beep(dH, 325);  
  beep(cSH, 175);  
  beep(cH, 125);  
  beep(b, 125);  
  beep(cH, 250);  
 
  delay(350);
}
