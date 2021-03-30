#include <LiquidCrystal.h>                              //LCD ekran için LiquidCyristal.h kütüphanesi kullanıldı.

int nemdeger = 0;                                       //Nem değerini başta 0 olarak tanımlandı.
int sensor = A0;                                        //Toprak nem sensörünün A0 pinini Arduino'nun A0 pinine bağlandı.
int kirmiziled = 8;                                     //Kırmızı led Arduino'nun 8. pinine bağlandı.
int yesilled = 9;                                       //Yeşil Led Arduino'nun 9. pinine bağlandı.
int maviled = 10;                                       //Mavi Led Arduino'nun 10. pinine bağlandı.

int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;   //LCD'nin pin değişkenlerini tanımlandı

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);              //LCD'nin pin bağlantılarını ayarlandı.

void setup() {
  pinMode(sensor, INPUT);                               //Toprak nem sensörü'nden girdi alacağımız için giriş olarak kullanıldı.
  pinMode(kirmiziled, OUTPUT);                          //Kırmızı Led'ten çıktı alacağımız için çıkış olarak kullanıldı.
  pinMode(yesilled, OUTPUT);                            //Yeşil Led'ten çıktı alacağımız için çıkış olarak kullanıldı.
  pinMode(maviled, OUTPUT);                             //Mavi Led'ten çıktı alacağımız için çıkış olarak kullanıldı.
  lcd.begin(16, 2);                                     //LCD ekranın boyutunu belirlendi.
}
void loop() {
  nemdeger = analogRead(A0);                            //Toprak nem sensöründen analog okuma yapılıyor.
  nemdeger = map(nemdeger, 1023,0,0,100);               //0 ile 1023 arasında olan analog değerleri map komutu ile 0 ile 100 arasındaki değerlere çevrildi.


  if (nemdeger > 60) {                                  //Eğer nem değeri 80'in üzerindeyse
    lcd.clear();                                        //LCD'deki eski yazılar temizlenir.
    lcd.setCursor(0, 0);                                //LCD'nin 1. satır 1. sütunundan yazmaya başlıyoruz.
    lcd.print("Deger:");                                //LCD'nin 1. satır ve 1. sütununa Deger: yazılır.
    lcd.print(nemdeger);                                //nemdeger'i LCD'ye yazdırıyoruz.
    lcd.print(" % ");
    lcd.setCursor(0, 1);                                //LCD'nin 2. satır 1. sütunundan yazmaya başlıyoruz.
    lcd.print("Toprak: Islak");                          //LCD'nin 2. satır 1. sütununa toprağın durumunu yazdırıyoruz.
    digitalWrite(kirmiziled, HIGH);                     //Değer 80 üzerindeyse kırmızı led 1 saniye boyunca yanar.
    delay(1000);
  } else {
    digitalWrite(kirmiziled, LOW);                      //Değer 80 altındaysa kırmızı led 1 saniye boyunca söner.
    delay(1000);
  }

  if (nemdeger > 41 && nemdeger <= 59) {                //Eğer nem değeri 51 ile 79 arasındaysa
    lcd.clear();                                        //LCD'deki eski yazılar temizlenir.
    lcd.setCursor(0, 0);                                //LCD'nin 1. satır 1. sütunundan yazmaya başlıyoruz.
    lcd.print("Deger:");                                //LCD'nin 1. satır ve 1. sütununa Deger: yazılır.
    lcd.print(nemdeger);                                //nemdeger'i LCD'ye yazdırıyoruz.
    lcd.println(" % ");
    lcd.setCursor(0, 1);                                //LCD'nin 2. satır 1. sütunundan yazmaya başlıyoruz.
    lcd.print("Toprak: Nemli");                         //LCD'nin 2. satır 1. sütununa toprağın durumunu yazdırıyoruz.
    digitalWrite(yesilled, HIGH);                       //Değer 51 ile 79 arasındaysa yeşil led 1 saniye boyunca yanar.
    delay(1000);
  } else {
    digitalWrite(yesilled, LOW);                        //Değer 51 ile 79 arasındaysa yeşil led 1 saniye boyunca söner.
    delay(1000);
  }

  if (40 > nemdeger) {                                  //Eğer nem değeri 50'nin altındaysa
    lcd.clear();                                        //LCD'deki eski yazılar temizlenir.
    lcd.setCursor(0, 0);                                //LCD'nin 1. satır 1. sütunundan yazmaya başlıyoruz.
    lcd.print("Deger:");                                //LCD'nin 1. satır ve 1. sütununa Deger: yazılır.
    lcd.print(nemdeger);                                //nemdeger'i LCD'ye yazdırıyoruz.
    lcd.println(" % ");
    lcd.setCursor(0, 1);                                //LCD'nin 2. satır 1. sütunundan yazmaya başlıyoruz.
    lcd.print("Toprak: Kuru");                           //LCD'nin 2. satır 1. sütununa toprağın durumunu yazdırıyoruz.
    digitalWrite(maviled, HIGH);                        //Değer 50'nin altındaysa mavih led 1 saniye boyunca yanar.
    delay(1000);
  } else {
    digitalWrite(maviled, LOW);                         //Değer 50'nin altındaysa mavih led 1 saniye boyunca söner.
    delay(1000);
  }
}
