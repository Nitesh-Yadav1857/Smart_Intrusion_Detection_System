#define BLYNK_TEMPLATE_ID "TMPL3LzSJdnwe"
#define BLYNK_TEMPLATE_NAME "pir sensor"
#define BLYNK_AUTH_TOKEN "GkWaBHOh3ys91_Sidrtj22cskyrA-P-S"
#define BLYNK_PRINT Serial

#include <BlynkSimpleEsp32.h>

int pir= 14;
int led=13;
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Wokwi-GUEST";
char pass[] = "";


BlynkTimer timer;

void motiondetect(){
  if(digitalRead(14)==HIGH){
    Blynk.virtualWrite(V1,1);
  
    Serial.println("Motion detected!");
    digitalWrite(led, HIGH);

  }
  else{
    Blynk.virtualWrite(V1,0);
    Serial.println("Motion ended!");
   digitalWrite(led, LOW);
  }
}

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(2000L,motiondetect);
  pinMode(14, INPUT);
  pinMode(led,OUTPUT);
}
void loop()
{
  Blynk.run();
  timer.run();
}