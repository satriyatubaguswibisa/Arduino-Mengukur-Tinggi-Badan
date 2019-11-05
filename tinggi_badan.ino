//  --------------------------------------

#define PIN_TRIG 13 //definisi PIN_TRIG 13
#define PIN_ECHO 12 //definisi PIN_TRIG 12

const double JARAK_DASAR = 200; // Diperoleh Saat gelas disingkirkan


void setup() 
{  
  Serial.begin (9600);        // set kecepatan transmisi data ke 96000
  pinMode(PIN_TRIG, OUTPUT);  // pilih mode PIN_TRIG sebagai OUTPUT
  pinMode(PIN_ECHO, INPUT);   // pilih mode PIN_ECHO sebagai INPUT
}

void loop() {
  
  // Berikan isyarat HIGH pada pin trig 10 mikrodetik
  digitalWrite(PIN_TRIG, HIGH);   // mengatur PIN_TRIG menyala
  delayMicroseconds(10);          // Tunda 10 mikrodetik
  digitalWrite(PIN_TRIG, LOW);    // mengatur PIN_TRIG mati

  // Baca hasilnya di pin echo
  double selang = pulseIn(PIN_ECHO, HIGH); //tipe data double selang = pulsein akan menunggu rentang waktu echopin dari LOW menjadi HIGH

  // Hitung jarak yang diperoleh
  double tinggi = JARAK_DASAR - 0.0343 * ( selang/2 );

    Serial.print("Tinggi Badan = ");  
    Serial.print(tinggi);   // mengirim data ASCII tinggi
    Serial.println(" cm");  // mengirim data ASCII (" cm")
    delay (1000);           // Tunda 1 detik
}
