#define ENA 5
#define in1 4
#define in2 7

char ch;
int speed = 200;
void setup() {
  // put your setup code here, to run once:
  pinMode(ENA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("verify_1");
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(ENA, speed);
  delay(5000);
  while(Serial.available())
  {
    ch = Serial.read();
    switch(ch)
    {
      case'a':
      analogWrite(ENA,0);
      delay(5000);
      Serial.println("0");
      break;

      case'b':
      analogWrite(ENA,50);
      delay(5000);
      Serial.println("50");
      break;

      case'2':
      analogWrite(ENA,70);
      delay(5000);
      Serial.println("70");
      break;

      case'3':
      analogWrite(ENA,90);
      delay(5000);
      Serial.println("90");
      break;

      case'4':
      analogWrite(ENA,110);
      delay(5000);
      Serial.println("110");
      break;


      default:
      Serial.println("verify");
      break;
    }
  }
}
