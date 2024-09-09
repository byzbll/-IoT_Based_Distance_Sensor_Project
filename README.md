# -IoT_Based_Distance_Sensor_Project

Proje Tanımı: 
Bu proje, IoT (Internet of Things - Nesnelerin İnterneti) teknolojisi kullanarak görme engelli bireyler için bir engel algılama sistemi geliştirmeyi amaçlamaktadır. Projede kullanılan ultrasonik mesafe sensörü ile kullanıcıya yaklaşan engeller algılanmakta ve mesafe verisi MQTT protokolü üzerinden Firebase bulut veritabanına aktarılmaktadır. Ayrıca, sensörden alınan mesafe verisi, bir mobil uygulama aracılığıyla işlenerek belirli bir eşik değerinin altına düşüldüğünde sesli uyarı verilmesi sağlanmaktadır.

Kullanılan Teknolojiler
* ESP8266: WiFi bağlantısı ve IoT projeleri için kullanılan mikrodenetleyici.
* Ultrasonik Mesafe Sensörü: Engellerin uzaklığını algılamak için kullanılır.
* MQTT Protokolü: Verileri hafif ve güvenilir bir şekilde buluta iletmek için kullanılan haberleşme protokolü.
* Firebase: Mesafe verilerinin depolandığı bulut veritabanı.
* Mobil Uygulama: Kullanıcıyı sesli uyarılarla bilgilendiren uygulama.
  
Proje Kurgusu:
Bu proje, görme engelli bireylerin günlük yaşamlarını kolaylaştırmayı hedeflemektedir. IoT teknolojileri kullanılarak çevredeki engeller algılanmakta ve bu engellerin varlığı hakkında kullanıcıya sesli uyarılar verilmektedir.

Sensör Verisi: Ultrasonik mesafe sensörü, kullanıcının önündeki engelleri algılar ve bu veriyi ESP8266 mikrodenetleyici ile işler.
Veri İletimi: Sensör verisi, MQTT aracılığıyla bulut sunucusuna gönderilir ve aynı zamanda Firebase veritabanına kaydedilir.
Uyarı Mekanizması: Belirli bir mesafe eşik değerinin altına düşüldüğünde, mobil uygulama kullanıcıya sesli bir uyarı gönderir. Bu uyarı, kullanıcının yaklaşan bir engele dikkat etmesini sağlar.

IoT Nedir?
IoT (Nesnelerin İnterneti), fiziksel cihazların internete bağlanarak birbirleriyle ve bulut sistemleriyle veri alışverişi yapmasını sağlayan bir teknolojidir. Bu proje, IoT teknolojisinin bir uygulaması olarak, sensör verilerini kablosuz olarak bulut ortamına aktarıp, bu verilerin mobil cihazlarla işlenmesini sağlamaktadır. Böylece sensörler ve cihazlar, internet üzerinden sürekli bağlantı halinde olup gerçek zamanlı veri paylaşımı gerçekleştirir.

Proje Adımları:
WiFi Bağlantısı: ESP8266, belirtilen WiFi ağına bağlanarak internete erişir.
MQTT Bağlantısı: Mesafe verileri, MQTT kullanılarak bulut sunucusuna aktarılır.
Firebase Entegrasyonu: Veriler Firebase veritabanında saklanır.
Mobil Uygulama ile Uyarı: Veriler belirli bir eşik değerin altına düştüğünde, mobil uygulamaya uyarı gönderilir.

Kodlar:
Bu proje iki ana kod dosyasından oluşur:

mesafe_sensoru_firebase.ino: Bu kod, sensörden gelen mesafe verisini MQTT aracılığıyla alır ve Firebase veritabanına gönderir.
mesafe_sensoru_mqtt.ino: Bu kod, sensör verilerini toplar ve MQTT aracılığıyla buluta gönderir.

Ek Dosyalar:
Projeyi daha iyi anlamak için eklediğim 3 sayfalık PowerPoint sunusu, IoT teknolojisinin kullanımını ve projenin temel işleyişini vurgulamaktadır.
