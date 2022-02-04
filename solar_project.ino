//Servo motor kütüphanesi
#include <Servo.h>
#include <LDR.h>
//Değişken tanımları
 
int ldrsagu = 1;                // top-right LDR girişi                         
int ldrsolu = 3;               // top-left LDR  girişi                         
int ldrsaga = 4;               // bottom-right LDR  girişi                    
int ldrsola = 5;               // bottom-left LDR   girişi                 
int solu,sagu,sola,saga ;

//Servoların tanımlanması.
Servo servo_asyuk;
Servo servo_sagsol;

int threshold_value=10;           //Ölçüm hassasiyeti

void setup()
{
  Serial.begin(9600);                                //Terminaldeki data rate'in 9600a ayarlanması
  Serial.println("CLEARDATA");                       //Bir önceki verilerin temizlenmesi
  Serial.println("LABEL,t,voltage,current,power");   //Terminaldeki sütun başlıklarının tanımlanması
  
  servo_updown.attach(2);             //Aşağı yukarı servonun hareketi
  servo_rightleft.attach(3);          //Sağ sol servonun hareketi
}
void loop()
{  
 
    float volt = analogRead(A5)*5.0/1023;   //Solar sistem voltajın A5 analog pinine bağlanarak veri çekilmesi
    float voltage = 2*volt;                //  Volt=(R1/R1+R2)*Voltage / R1=R2=10Ohms  => voltage=2*volt)
    float current = voltage/20;            //  I=voltage/(R1+R2) 
    float power = voltage*current;
    Serial.print("DATA,TIME,"); // 
    Serial.print(voltage);    //Voltaj verisinin terminale gönderilmesi
    Serial.print(",");
    Serial.print(current);    //Akım verisinin terminale gönderilmesi
    Serial.print(",");
    Serial.print(power);  //Güç verisinin terminale gönderilmesi
    Serial.print(",");     
   
    solartracker();
    }

void solartracker(){
  
     //Analog verilerin her LDR sensöründen alınması
     topr= analogRead(ldrsagu);         // sağ üst LDR
     topl= analogRead(ldrsolu);         // sol üst LDR
     botr= analogRead(ldrsaga);         // sağ alt LDR 
     botl= analogRead(ldrsola);         // sol alt LDR

    // ortalama değerlerin hesaplanması
     int avgyuk = (sagu + solu) / 2;     //üst LDR'ler
     int avgas = (saga + sola) / 2;     //alt LDR'ler
     int avgsol = (solu + sola) / 2;    //sol LDR'ler
     int avgsag = (sagu + saga) / 2;   //sağ LDR'ler
   
    //Değerlerin farklarının alınması
     int diffelev = avgyuk - avgas;      
     int diffazi = avgsag - avgsol;    
    
    //Solar tracker'ın sağ sol hareketi
     
      if (abs(diffazi) >= threshold_value){       
       if (diffazi > 0) {                          //Sağ ve sol LDR sensörlerin aldığı değerlerin farkı ölçüm hassasiyeti değerinden büyükse pozisyonu değiştir.
        if (servo_sagsol.read() < 180) {
          servo_sagsol.write((servo_updown.read() + 1));
        }
      }
      if (diffazi <  0) {
        if (servo_sagsol.read() > 0) {
          servo_sagsol.write((servo_updown.read() - 1));
        }
      }
    }
             
      //Solar tracker'in yukarı aşağı hareketi

      if (abs(diffelev) >= threshold_value){     //Sağ ve sol LDR sensörlerin aldığı değerlerin farkı ölçüm hassasiyeti değerinden büyükse pozisyonu değiştir.
       if (diffelev > 0) {
        if (servo_asyuk.read() < 180) {
          servo_asyuk.write((servo_sagsol.read() - 1)); // servonun adımı takip etme hızı, hızını -1 değerini düşürerek azaltabilirsiniz
        }
      }
      if (diffelev <  0) {
        if (servo_asyuk.read() > 0) {
          servo_asyuk.write((servo_sagsol.read() + 1)); // servonun adımı takip etme hızı, servonun hızını +1 değerini düşürerek azaltabilirsiniz
        }
      }
    }       
 }  
