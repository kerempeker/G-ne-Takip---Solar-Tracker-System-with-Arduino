# Gunes-Takip--Solar-Tracker-System-with-Arduino
Arduino ile portatif güneş takip sistemi, Solar tracker system with Arduino.

Ders geçme projesi olarak farklı örnekleri de bulunan Arduino ile Güneş Takip Sistemi'ni Türkçe kaynakların az olması nedeniyle bu projeyi her kesime hitap etmesi adına temel hatları ile sizlerle paylaşmak istedim. Umarım kaynak çeşitliliği açısından yararlı olur.

I made Solar Tracker System with Arduino and I am now preparing this Git for I would like to increase information on the Internet with this source. And I hope this source can help your projects.

Bu projede proje gövdesi haricinde:
-4 tane LDR sensör 
-Arduino Uno  
-mini Solar Panel
-10 K ohm Resistor
-L780S Voltaj regülatörü
-100nF Seramik kapasitör
-1uF/50V Elektrolit Kapasitör kullandım.
-12 V 2A Power Supply kullandım.

I used except for the project body in this project:
-4 LDR sensors
-Arduino Uno
-mini Solar Panel
-10K ohm Resistor
-L780S Voltage regulator
-100nF Ceramic capacitor
-1uF/50V Electrolyte Capacitor.
-12 V 2A Power Supply.
--------------------------------------------------
Öncelikle LDR sensörlerin işleyişinden kısaca bahsetmek istiyorum. LDR sensörler, bulundukları ortamdaki ışık şiddetine göre değişen dirençlerdir. Işık azaldıkça LDR sensör'ün direnci artar, ışık arttıkça azalır. Bu direnç, ışığa duyarlı çeşitli projelerde kullanılabilir.

Firstly, I would like to talk about the mechanism of the LDR sensor. LDR sensor is a resistor. This resistor's value is associated with light intensity. When the light intensity is high, the LDR sensor's resistance value is going to decrease.  When the light intensity is low, the LDR sensor's resistance value is going to increase.

Arduino, açık kaynaklı bir mikrodenetleyici platformudur. Arduino kullanarak çeşitli sensörlerden gelen verileri okuyabilir ve işleyebilir, motor ledi gibi ekipmanların kontrol edilmesi gibi elektronik uygulamalar yapabilirsiniz.

Arduino is an open source microcontroller platform. Using Arduino, you can read and process data from various sensors, and make electronic applications such as controlling equipment such as motor led.

Güneş paneli, üzerinde güneş enerjisini soğurmaya yarayan birçok güneş hücresi bulunduran bir enerji kaynağıdır. //wikipedia
A solar panel is an energy source that contains many solar cells that absorb solar energy. //wikipedia

Servo Motorlar, istenilen pozisyonu alması ve yeni bir komut gelmediği sürece bulunduğu pozisyonu değiştirmemesi amacıyla tasarlanmıştır(robotistan). Normal motorlar ile servo motorlar arasındaki fark, hareketi kontrollü yapan bir düzenek olmasıdır.

Servo Motors are designed to take the desired position and not change its position unless a new command comes. The difference between normal motors and servo motors is that there is a mechanism that makes the movement controlled.
--------------------------------------------------
Projeyi kodlarken temel mantığı şu şekilde belirlendi, solar panel'in dört köşesine LDR sensör yerleştirdim. Sistem, üstteki iki sensör ile alttaki iki sensör'ün ortalamasını alarak ışığın yönünü belirleyecek. LDR sensörlerden gelen verilere göre altta bulunan sağ-sol servo motor ve arkasında bulunan yukarı-aşağı servo motor ile güneş panelinin hareketi sağlandı. Devrede iki servo motor olduğundan dolayı dışardan güç aldım (12V 2A power supply). Dışardan güç aldığım için voltaj regulatorü, seramik ve elektrolit kapasitör kullandım.

Projenin gövdesi, evimde bulunan 3d baskıdan çıkardığım robot kolunu modifiye ederek oluşturdum. Tabi bununla alakalı çeşitli 3d modellerini ve CNC modellerini internette bulabilirsiniz (Makaleyi ilerde model ekleyerek güncelleyeceğim).


While coding the project, the basic logic was determined as follows, I placed LDR sensors on the four corners of the solar panel. The system will determine the direction of the light by averaging the top two sensors and the bottom two sensors. According to the data from the LDR sensors, the movement of the solar panel was provided with the right-left servo motor at the bottom and the up-down servo motor behind it. I used a voltage regulator, ceramic and electrolytic capacitor since I got power from the adaptor.

I created the body of the project by modifying the robot arm that I took out of 3d printing in my house. Of course, you can find various 3d models and CNC models related to this on the internet (I will update the article by adding models in the future).

--------------------------------------------------
İlgili devre şemasını aşağıda görebilirsiniz,
You can see circuit schematic in the picture,

<img width="948" alt="Screenshot 2022-02-04 at 21 12 59" src="https://user-images.githubusercontent.com/69105430/152581399-4a556f02-e9a1-4c11-b9bb-4ad3d57dd7fc.png">

--------------------------------------------------
NOTE : Projeyi yapmaya uğraşırken birçok farklı model denedim. Sunumunu yaptığım modelden önceki fotoğrafını aşağıda görebilirsiniz. 4 ldr sensörünü bu şekilde birleştiren modeller de vardı fakat ben o tür modellerden istediğim verimi alamadığım için tekrardan resimde gösterilen dört köşeye LDR sensörlerini yerleştirip etrafını siyah elektrik bantıyla sadece yörüngesindeki ışığa odaklı hale getirdim. 

I tried many different models while trying to build the project. You can see the photo before the model I presented below. Some models combined 4 LDR sensors in this way, but when I tried these designs in my models I couldn't get efficient performance. This is cause I changed LDR's positions. I placed the LDR sensors in the four corners shown in the picture again and focused them only on the light in their orbit with black electrical tape.

![WhatsApp Image 2022-02-04 at 9 23 43 PM](https://user-images.githubusercontent.com/69105430/152583038-ca314edb-b6b5-4216-a840-578a65f17c69.jpeg)


--------------------------------------------------
Nasıl Geliştirilebilir?
-4 sensörden okunan veriler ayrı ayrı işlenerek sistem daha efektif çalışabilir.
-Kodda da özellikle bıraktığım A5 analog pinine Güneş Paneli(depolama bileşeni ile) bağlanırsa sisteme eklenecek bir led ekran ile solar sistemde ne kadar enerji olduğu görülebilir.
-Gövde tasarımında LDR sensörlerin daha efektif çalışması için değişiklikler yapılabilir.

How Can It Be Improved?
The system can work more effectively by processing the data read from 4 sensors separately.
-If the Solar Panel (with storage component) is connected to the A5 analog pin, which I added in one part in the code, it can be seen how much energy is in the solar system with an LED screen to be added to the system.
-Changes can be made in the body design for the more effective operation of LDR sensors.
--------------------------------------------------
Okuduğunuz için çok teşekkür ederim. Başka sorularınız varsa, lütfen benimle iletişime geçmekten çekinmeyin. Ayrıca Nasıl Geliştirilebilir? bölümü başta olmak üzere önerileriniz benim için çok kıymetli.

Thank you very much for reading. Should you have any further questions, please do not hesitate to contact me. Also, your suggestions are very valuable to me specially on How Can It Be Improved? section and other sections.
