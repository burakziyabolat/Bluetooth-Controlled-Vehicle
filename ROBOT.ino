//#include <SoftwareSerial.h>
//#include <TimerOne.h>

//#define echoPin 13
//#define trigPin 12
//#define buzzerPin 10

const int motorIN1  = 3;  // L298N'in IN1 Girişi       SOL İLERİ YÖN IN1=LOW,  IN2=HIGH
const int motorIN2  = 5; // L298N'in IN2 Girişi        SAĞ İLERİ YÖN IN3=LOW,  IN4=HIGH
const int motorIN3  = 6;  // L298N'in IN3 Girişi       SOL GERİ YÖN  IN1=HIGH, IN2=LOW
const int motorIN4  = 9;  // L298N'in IN4 Girişi       SAĞ GERİ YÖN  IN3=HIGH, IN4=LOW

//int maximumRange = 400;
//int minimumRange = 1;
//long maximumFreq = 1000000;
//long minimumFreq = 100000;

//long warning = 0;
char state; //Bluetooth cihazından gelecek sinyalin değişkeni


void setup() {
  // Pinlerimizi belirleyelim
  pinMode(motorIN1, OUTPUT);
  pinMode(motorIN2, OUTPUT);
  pinMode(motorIN3, OUTPUT);
  pinMode(motorIN4, OUTPUT);

  // PARK SENSÖRÜ İÇİN PİN TANIMLAMALARI
  //pinMode(trigPin, OUTPUT);
  //pinMode(echoPin, INPUT);
  //pinMode(buzzerPin, OUTPUT);

  //Timer1.initialize(maximumFreq);
  //Timer1.stop();

  // 9600 baud hızında bir seri port açalım
  Serial.begin(9600);

  Serial.println("Hello, world?");
}

void loop() {
  
  //Gelen veri 'A' ise araba ileri gider.
  if (state == 'A') {

    digitalWrite(motorIN1, LOW);
    digitalWrite(motorIN2, HIGH);
    digitalWrite(motorIN3, LOW);
    digitalWrite(motorIN4, HIGH);
  }


  //Gelen veri 'C' ise araba ileri sağ(çapraz) gider.
  else if (state == 'C') {
    digitalWrite(motorIN1, LOW);
    digitalWrite(motorIN2, HIGH);
    digitalWrite(motorIN3, LOW);
    digitalWrite(motorIN4, LOW);

  }

  //Gelen veri 'D' ise araba ileri sol(çapraz) gider.
  else if (state == 'D') {
    digitalWrite(motorIN1, LOW);
    digitalWrite(motorIN2, LOW);
    digitalWrite(motorIN3, LOW);
    digitalWrite(motorIN4, HIGH);

  }

  //Gelen veri 'E' ise araba sağa gider.
  else if (state == 'E') {
    digitalWrite(motorIN1, LOW);
    digitalWrite(motorIN2, HIGH);
    digitalWrite(motorIN3, HIGH);
    digitalWrite(motorIN4, LOW);
  }

  //Gelen veri 'F' ise araba sola gider
  else if (state == 'F') {
    digitalWrite(motorIN1, HIGH);
    digitalWrite(motorIN2, LOW);
    digitalWrite(motorIN3, LOW);
    digitalWrite(motorIN4, HIGH);
  }

  //Gelen veri 'G' ise araba geri sağ(çapraz) gider
  else if (state == 'G') {
    digitalWrite(motorIN1, LOW);
    digitalWrite(motorIN2, LOW);
    digitalWrite(motorIN3, HIGH);
    digitalWrite(motorIN4, LOW);
  }


  //Gelen veri 'H' ise araba geri sol(çapraz) gider
  else if (state == 'H') {
    digitalWrite(motorIN1, HIGH);
    digitalWrite(motorIN2, LOW);
    digitalWrite(motorIN3, LOW);
    digitalWrite(motorIN4, LOW);
  }

  /************************Stop*****************************/
  //Gelen veri 'S' ise arabayı durdur.
  else if (state == 'S') {
    digitalWrite(motorIN1, LOW);
    digitalWrite(motorIN2, LOW);
    digitalWrite(motorIN3, LOW);
    digitalWrite(motorIN4, LOW);
  }

  //int olcum = mesafe(maximumRange, minimumRange);

 // warning = map(olcum, 0, 50, minimumFreq, maximumFreq);

//
//  if (olcum < 30 && olcum > 1)
//  {
//    Timer1.initialize(warning);
//    //Timer1.setPeriod(warning);
//    //Timer1.pwm(fanPin, (dutyCycle / 100) * 1023);
//    Timer1.pwm(buzzerPin, 512);
//    Serial.print(warning);
//    Serial.print(" ");
//    Serial.println(olcum);
//    //
//    //Timer1.start();
//  }
//  else
//  {
//    Timer1.stop();
//    digitalWrite(buzzerPin, LOW);
//    Serial.println(olcum);
//  }

  //Gelen veri 'B' ise araba geri gider.

//  if (state == 'B' && (olcum < 25 && olcum > 0)) {
//    digitalWrite(motorIN1, LOW);
//    digitalWrite(motorIN2, LOW);
//    digitalWrite(motorIN3, LOW);
//    digitalWrite(motorIN4, LOW);
//    state = 'S';
//  }
  else if (state == 'B') {
    digitalWrite(motorIN1, HIGH);
    digitalWrite(motorIN2, LOW);
    digitalWrite(motorIN3, HIGH);
    digitalWrite(motorIN4, LOW);
  }


  //melodi(olcum * 10);
}

//int melodi(int park)
//{
//  tone(buzzerPin, 440);
//  delay(park);
//  noTone(buzzerPin);
//  delay(park);
//
//}

//int mesafe(int maxrange, int minrange)
//{
//  long duration, distance;
//
//  digitalWrite(trigPin, LOW);
//  delayMicroseconds(2);
//  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trigPin, LOW);
//
//  duration = pulseIn(echoPin, HIGH);
//  distance = duration / 58.2;
//  delay(50);
//
//  if (distance >= maxrange || distance <= minrange)
//    return 0;
//  return distance;
//}

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    state = (char)Serial.read();
    Serial.println(state);
  }
}
