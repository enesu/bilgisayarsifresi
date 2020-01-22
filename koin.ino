#include <Keypad.h>

int role = 5;

const byte satir = 4;
const byte sutun = 3;
int i = 0;
char sifre1[4];
char sifre[4] = {'*', '#', '1', '9'};
char tus;
char tus_takimi[satir][sutun] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte satir_pinleri[satir] = {13, 12, 11, 10};
byte sutun_pinleri[satir] = {9, 8, 7, 6};

Keypad keypad_ard = Keypad(makeKeymap(tus_takimi) , satir_pinleri , sutun_pinleri , satir , sutun);

void setup() {
  pinMode(role, OUTPUT);
  Serial.begin(9600);
  Serial.println("Sistem basladi");
     digitalWrite(role, HIGH); // benim kullandığım rölede HIGH yapınca kapalı kalıyor siz de kendi rölenize göre ayarlayabilirsiniz.
}

void loop()
{

  tus = keypad_ard.getKey();
  if (tus)
  {
    sifre1[i++] = tus;
    Serial.println(tus);
    delay(100);
  }

  if (i == 4) {
    delay(200);
    char sifre[4] = {'3', '4', '2', '3'};
    if ((strncmp(sifre1, sifre, 4) == 0))   {
      
      digitalWrite(role, LOW);
      delay(100);
      digitalWrite(role, HIGH);
       Serial.println("dogru sifre");
           
      i = 0;
    }
    else {
     digitalWrite(role, HIGH);
     Serial.println("yanlis sifre");
      i = 0;
    }
  }
}
