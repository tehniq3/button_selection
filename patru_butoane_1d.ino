/*
 * https://forum.arduino.cc/t/changing-modes-using-push-button/413231/14
 * 
 * 1c - ignorata butoanele la initializare
 * 1d - adaugat monitorizare seriala
 */

#define buton1 2
#define buton2 3
#define buton3 4
#define buton4 5

#define LED0 10
#define LED1 6
#define LED2 7
#define LED3 8
#define LED4 9


byte starebuton11 = 0;  // stare actuala buton 1
byte starebuton10 = 0; // stare anterioara buton 1
byte starebuton21 = 0;  // stare actuala buton 2
byte starebuton20 = 0; // stare anterioara buton 2
byte starebuton31 = 0;  // stare actuala buton 3
byte starebuton30 = 0; // stare anterioara buton 3
byte starebuton41 = 0;  // stare actuala buton 4
byte starebuton40 = 0; // stare anterioara buton 4

byte STATUS = 1;  // stare initiala ... ulterior se va emora in EEPROM
byte STATUS0 = 0;

void intarziere(long cattimp) 
{
  long acum = millis();
  long final = acum + cattimp;
  while(millis() < final) 
  {
   citirebutoane();
  }
}

void intarziere0(long cattimp) 
{
  long acum = millis();
  long final = acum + cattimp;
  while(millis() < final) 
  {
   //citirebutoane(); // nu face nimic (folosit la initializare, sa ignore butoanele)
  }
}
void initializare()  
{
  Serial.println("Initializare la pornire sau la schimbare program...");
  digitalWrite(LED0, HIGH);
  intarziere0(10000);
  digitalWrite(LED0, LOW);
  intarziere0(1000);
  Serial.println("Terminare (re)initializare...");
}


void setup() {
  Serial.begin(9600);
  Serial.println(" ");
  Serial.println("Control 4 functii din 4 butoane...");
  Serial.println("Program scris de Nicu FLORICA (niq_ro)");
  Serial.println("---------------------");
  pinMode (LED0, OUTPUT);
  pinMode (LED1, OUTPUT);
  pinMode (LED2, OUTPUT);
  pinMode (LED3, OUTPUT);
  pinMode (LED4, OUTPUT);
  pinMode (buton1, INPUT);
  pinMode (buton2, INPUT);
  pinMode (buton3, INPUT);
  pinMode (buton4, INPUT);  

digitalWrite(buton1, HIGH);
digitalWrite(buton2, HIGH);
digitalWrite(buton3, HIGH);
digitalWrite(buton4, HIGH);

LEDoff();  // toate ledurile stinse 

//initializare();
}

void LEDoff() {
  digitalWrite(LED0, LOW);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
}

void F1() 
{
  digitalWrite(LED0, HIGH);
  intarziere(100);  // in loc de comanda "delay"
  digitalWrite(LED0, LOW);
  intarziere(2000);
  Serial.println("Final de program nr.1, reiau...");
}

void F2() {
  digitalWrite(LED0, HIGH);
  intarziere(100);
  digitalWrite(LED0, LOW);
  intarziere(100);
  digitalWrite(LED0, HIGH);
  intarziere(100);
  digitalWrite(LED0, LOW);
  intarziere(2000);
  Serial.println("Final de program nr.2, reiau...");
}

void F3() 
{
  digitalWrite(LED0, HIGH);
  intarziere(100);
  digitalWrite(LED0, LOW);
  intarziere(100);
  digitalWrite(LED0, HIGH);
  intarziere(100);
  digitalWrite(LED0, LOW);
  intarziere(100);
  digitalWrite(LED0, HIGH);
  intarziere(100);
  digitalWrite(LED0, LOW);
  intarziere(2000);
  Serial.println("Final de program nr.3, reiau...");
}

void F4() 
{
  digitalWrite(LED0, HIGH);
  intarziere(100); 
  digitalWrite(LED0, LOW);
  intarziere(100);  
  digitalWrite(LED0, HIGH);
  intarziere(100);
  digitalWrite(LED0, LOW);
  intarziere(100);
  digitalWrite(LED0, HIGH);
  intarziere(100);
  digitalWrite(LED0, LOW);
  intarziere(100);
  digitalWrite(LED0, HIGH);
  intarziere(100);
  digitalWrite(LED0, LOW);
  intarziere(2000);
  Serial.println("Final de program nr.4, reiau...");
}


void citirebutoane() 
{
  starebuton11 = digitalRead(buton1);  // se citeste starea actuala a butonului 1
  if (starebuton11 != starebuton10) // daca butonul 1 a fost apasat
   {
    if (starebuton11 == LOW) // si buton 1 a fost eliberat
     {  
      STATUS = 1;
     // LEDoff();
     // digitalWrite(LED1, HIGH);
     Serial.println("Ati apasat butonul nr.1 !");
     } 
    delay(30);
  starebuton10 = starebuton11;  // starea actuala a butonului 1 este memorata
  }

  starebuton21 = digitalRead(buton2);  // se citeste starea actuala a butonului 2
  if (starebuton21 != starebuton20) // daca butonul 1 a fost apasat
   {
    if (starebuton21 == LOW) // si buton 1 a fost eliberat
     {  
      STATUS = 2;
     // LEDoff();
     // digitalWrite(LED2, HIGH);
     Serial.println("Ati apasat butonul nr.2 !");
     } 
    delay(30);
  starebuton20 = starebuton21;  // starea actuala a butonului 2 este memorata
  }

  starebuton31 = digitalRead(buton3);  // se citeste starea actuala a butonului 3
  if (starebuton31 != starebuton30) // daca butonul 3 a fost apasat
   {
    if (starebuton31 == LOW) // si buton 3 a fost eliberat
     {  
      STATUS = 3;
     // LEDoff();
     // digitalWrite(LED3, HIGH);
     Serial.println("Ati apasat butonul nr.3 !");
     } 
    delay(30);
  starebuton30 = starebuton31;  // starea actuala a butonului 3 este memorata
  }

  starebuton41 = digitalRead(buton4);  // se citeste starea actuala a butonului 4
  if (starebuton41 != starebuton40) // daca butonul 1 a fost apasat
   {
    if (starebuton41 == LOW) // si buton 4 a fost eliberat
     {  
      STATUS = 4;
    //  LEDoff();
    //  digitalWrite(LED4, HIGH);
    Serial.println("Ati apasat butonul nr.4 !");
     } 
    delay(30);
  starebuton40 = starebuton41;  // starea actuala a butonului 2 este memorata
  }

} // sfarsit subrutina citire stari butoane


void loop() {

  citirebutoane();


if (STATUS0 != STATUS)
{
  LEDoff();
//  initializare();  
  if (STATUS == 1)
  {
    digitalWrite(LED1, HIGH);
    Serial.println("Se ruleaza programul nr.1 !");
  }
  if (STATUS == 2)
  {
    digitalWrite(LED2, HIGH);
    Serial.println("Se ruleaza programul nr.2 !");
  }
  if (STATUS == 3)
  {
    digitalWrite(LED3, HIGH);
    Serial.println("Se ruleaza programul nr.3 !");
  }
  if (STATUS == 4) 
  {
    digitalWrite(LED4, HIGH);
    Serial.println("Se ruleaza programul nr.4 !");
  }
initializare();  // comentare daca nu se doreste reinitiale la schimbare program
STATUS0 = STATUS;
}

  switch (STATUS) 
  {
  case 1: 
    
    F1();
    break;
    
  case 2:
    F2();
    break;
    
  case 3:
    F3();
    break;

   case 4:
    F4();
    break;
}
//STATUS0 = STATUS;
}  // sfarsit de program principal
