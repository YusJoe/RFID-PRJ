#include <SPI.h>
#include <RFID.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>


#define SS_PIN 10
#define RST_PIN 9
LiquidCrystal_I2C lcd(0x3F, 16, 2);

RFID rfid(SS_PIN,RST_PIN);
int serNum[5];         
int cards1[][5] = {      
  {212,254,111,167,226}
  };
  int cards2[][5] = {   
   {3,42,60,129,148}
  };
  int cards3[][5] = {
   {128,64,223,213,202}
  };
bool access = false;

int alarm = 0;
SoftwareSerial SIM900A(2,3);

int randNumber;
  int a;
char str[10];
int buffer_password[10];
char pindah;
char tes[30];
uint8_t pwMode=0;
uint8_t pwPos=0;


void setup(){
    Serial.begin(9600);
    lcd.begin();
    SPI.begin();
    rfid.init();
    randomSeed(analogRead(0));
  SIM900A.begin(9600);     
  Serial.begin(9600);    
  Serial.println ("SIM900A Ready");
  delay(100);
  Serial.println (" Ketik 's' dan 'r' untuk Mengirim SMS");
}

void loop(){
  if(rfid.isCard()){
    
        if(rfid.readCardSerial()){
            Serial.print(rfid.serNum[0]);
            Serial.print(" ");
            Serial.print(rfid.serNum[1]);
            Serial.print(" ");
            Serial.print(rfid.serNum[2]);
            Serial.print(" ");
            Serial.print(rfid.serNum[3]);
            Serial.print(" ");
            Serial.print(rfid.serNum[4]);
            Serial.println("");

            for(int x = 0; x < sizeof(cards1); x++){
              for(int i = 0; i < sizeof(rfid.serNum); i++ ){
                  if(rfid.serNum[i] != cards1[x][i]) {
                      access = false;
                      break;
                  } else {
                      access = true;
                  }
              }
              if(access) break;
            }
             for(int x = 0; x < sizeof(cards2); x++){
              for(int i = 0; i < sizeof(rfid.serNum); i++ ){
                  if(rfid.serNum[i] != cards2[x][i]) {
                      access = false;
                      break;
                  } else {
                      access = true;
                  }
              }
              if(access) break;
            }   
             for(int x = 0; x < sizeof(cards3); x++){
              for(int i = 0; i < sizeof(rfid.serNum); i++ ){
                  if(rfid.serNum[i] != cards3[x][i]) {
                      access = false;
                      break;
                  } else {
                      access = true;
                  }
              }
              if(access) break;
            }      
        }
        
       if(access){
          Serial.println("Welcome!");
          lcd.setCursor (0,0);
          lcd.print(F(" CARD ACCEPTED "));
          lcd.setCursor (0,1);
          lcd.print("ID:");
          lcd.print(rfid.serNum[0]); lcd.print(rfid.serNum[1]);
          lcd.print(rfid.serNum[2]); lcd.print(rfid.serNum[3]);
          lcd.print(rfid.serNum[4]);
          ACCEPT ();
           }
           
      
      else {
           alarm = alarm+1;
           Serial.println("Not Allowed"); 
           lcd.setCursor (0,0);
           lcd.print(F("  CARD DENIED   "));
           lcd.setCursor (0,1);
           lcd.print("ID:");
           lcd.print(rfid.serNum[0]); lcd.print(rfid.serNum[1]);
           lcd.print(rfid.serNum[2]); lcd.print(rfid.serNum[3]);
           lcd.print(rfid.serNum[4]);
           RIJECT ();    
       }        
    }
 if (cards1 == a)
   switch(rfid.isCard())
    {
    case 'a':
      
      SendMessage1();
      break;
    }
    rfid.halt();
}


void ACCEPT () {
           lcd.setCursor (0,0);
           lcd.print(F(" PLEASE WELCOME "));
           lcd.setCursor (0,1);
           lcd.print(F(" Auto Lock...  "));
           for(int i=3; i>0; i--){
            lcd.setCursor (15,1); lcd.print(i);
            delay (1000);
           }
           pwMode =0;
           lcd.clear();}

void RIJECT () {
           pwMode =0;
           lcd.clear();  
}
void SendMessage1()
{
    for(a=0;a<6;a++)
{
  randNumber = random(9);
  Serial.print(randNumber);  
  buffer_password[pindah]=randNumber;
  Serial.println(buffer_password[pindah]);
  pindah++;
  if (pindah>5) pindah=0;
  
}
 Serial.print("\n");
  Serial.println ("SIM900A Mengirim SMS");
  SIM900A.println("AT+CMGF=1");
  delay(1000);
  Serial.println ("Set SMS Number");
  SIM900A.println("AT+CMGS=\"+6283852864068\"\r");
  delay(1000);
  sprintf(tes,"Masukkan password %d%d%d%d%d%d", buffer_password[0],buffer_password[1],buffer_password[2],buffer_password[3],buffer_password[4],buffer_password[5]);
  Serial.print(tes);
  SIM900A.println(tes);
  SIM900A.println((char)26);
  delay(1000);
  Serial.println ("\nSMS Selesai dikirim");
}
void SendMessage2()
{
    for(a=0;a<6;a++)
{
  randNumber = random(9);
  Serial.print(randNumber);  
  buffer_password[pindah]=randNumber;
  Serial.println(buffer_password[pindah]);
  pindah++;
  if (pindah>4) pindah=0;
  
}
 Serial.print("\n");
  Serial.println ("SIM900A Mengirim SMS");
  SIM900A.println("AT+CMGF=1");
  delay(1000);
  Serial.println ("Set SMS Number");
  SIM900A.println("AT+CMGS=\"+6285607184299\"\r");
  delay(1000);
  sprintf(tes,"Masukkan password %d%d%d%d%d%d", buffer_password[0],buffer_password[1],buffer_password[2],buffer_password[3],buffer_password[4],buffer_password[5]);
  Serial.print(tes);
  SIM900A.println(tes);/
  SIM900A.println((char)26);
  delay(1000);
  Serial.println ("\nSMS Selesai dikirim");
}
void SendMessage3()
{
    for(a=0;a<6;a++)
{
  randNumber = random(9);
  Serial.print(randNumber);  
  buffer_password[pindah]=randNumber;
  Serial.println(buffer_password[pindah]);
  pindah++;
  if (pindah>4) pindah=0;
  
}
 Serial.print("\n");
  Serial.println ("SIM900A Mengirim SMS");
  SIM900A.println("AT+CMGF=1");
  delay(1000);
  Serial.println ("Set SMS Number");
  SIM900A.println("AT+CMGS=\"+6285736779859\"\r");
  delay(1000);
  sprintf(tes,"Masukkan password %d%d%d%d%d%d", buffer_password[0],buffer_password[1],buffer_password[2],buffer_password[3],buffer_password[4],buffer_password[5]);
  Serial.print(tes);
  SIM900A.println(tes);// The SMS text you want to send
  SIM900A.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
  Serial.println ("\nSMS Selesai dikirim");
}

