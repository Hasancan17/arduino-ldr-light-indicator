int ldrPin = A0;   // LDR bağlı pin

int leds[10] = {2,3,4,5,6,7,8,9,10,11}; // Bargraph pinleri

void setup()
{
  Serial.begin(9600);

  for(int i=0; i<10; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
}

void loop()
{

  int ldrValue = analogRead(ldrPin); // 0 - 1023 arası

  Serial.println(ldrValue);

  // LDR değerini 0-10 arası seviyeye çeviriyoruz
  int level = map(ldrValue, 0, 1023, 10, 0);

  for(int i=0; i<10; i++)
  {
    if(i < level)
    digitalWrite(leds[i], HIGH);

    else
    digitalWrite(leds[i], LOW);
  }

  delay(100);

}