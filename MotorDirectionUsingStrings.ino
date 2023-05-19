#define ENA 5
#define in1 4
#define in2 7

//char st1[] = "Start/";
char st2[] = "fr/";
char st3[] = "re";
//char st4[] = "Stop/";

char ch[10];
int speed;
void setup() {
  // put your setup code here, to run once:
  pinMode(ENA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  Serial.begin(9600);
  //Serial.println("verify_1");
}

void loop() {
  // put your main code here, to run repeatedly:
  //while (1)
    //{
        int i=0;
        do
        {
         //Serial.println("verify_2");
         ch[i] = Serial.read();
         i++;
        } while (ch[i-1]!=13);
        ch[i] = '\0';

        digitalWrite(ENA,255);
        if (ch[0]=='s')
        {
            if (ch[1]=='t')
            {
                Serial.println("START");
                digitalWrite(in1,HIGH);
                digitalWrite(in2,LOW);
            }
            else if (ch[1]=='s')
            {
                Serial.println("STOP");
                digitalWrite(in1,LOW);
                digitalWrite(in2,LOW);
            }
            
        }
        else if (strcmp(ch,st2)==0)
        {
                Serial.println("FORWARD");
                digitalWrite(in1,HIGH);
                digitalWrite(in2,LOW);
        }
        
        else if (strcmp(ch,st3)==0)
        {
                Serial.println("REVERSE");
                digitalWrite(in1,LOW);
                digitalWrite(in2,HIGH);
        }
   // }
}
