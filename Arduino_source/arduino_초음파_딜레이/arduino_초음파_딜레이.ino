int trigPin = 9; //초음파 발신핀 설정
int echoPin = 8; //초음파 수신핀 설정
int relay1 = 3; //디스플레이 릴레이핀 설정
int relay2 = 6; //전구 릴레이핀 설정
int count = 0; //count초기값을 0으로 설정

void setup()
{
  Serial.begin(9600); //시리얼모니터 사용준비
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
  float duration, distance; //자료형 float 변수 duration, distance 설정
  digitalWrite(trigPin, HIGH); //초음파 발신핀 켜기
  delay(10); //딜레이 0.1초
  digitalWrite(trigPin, LOW); //초음파 발신핀 끄기
  duration = pulseIn(echoPin, HIGH);
  distance = ((float)(340 * duration) / 10000) / 2;

  Serial.println(distance);

  if (distance > 20 && distance < 70) {
    digitalWrite(relay1, HIGH);
    delay(3000);
    digitalWrite(relay2, HIGH);
    count = 0;
  } else {
    count++;
    if (count < 20)
      delay(1000);
    if (count > 20)
      digitalWrite(relay1, LOW);
    if (count > 10)
      digitalWrite(relay2, LOW);
  }
}
