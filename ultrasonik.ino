//-----------------------------------------
//  Sensor jarak HC-SR04
//-----------------------------------------

#define PIN_TRIG 13
#define PIN_ECHO 12

void setup()
{
  Serial.begin (9600);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
}
void loop()
{
  // Berikan isyarat HIGH pada pin trig 10 mikrodetik
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10); // Tunda 10 mikrodetik
  digitalWrite(PIN_TRIG, LOW);

  // Baca Hasilnya di pin echo
  double selang = pulseIn(PIN_ECHO, HIGH);
  
  // Hitung jarak yang diperoleh
  double jarak = 0.0343 * ( selang / 2);
  
  if (jarak > 400 || jarak <= 0)
  {
    Serial.println("di luar jangkauan sensor");
    }
  else 
  {
    Serial.print(jarak);
    Serial.println(" cm");
    }
  delay(1000); // Tunda dua detik
}
