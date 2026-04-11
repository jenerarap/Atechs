#define BLYNK_PRINT Serial

#include <WiFi.h>

// ----------- Blynk Credentials -----------
#define BLYNK_TEMPLATE_ID   "Your_Template_ID"
#define BLYNK_TEMPLATE_NAME "Your_Device_Name"
#define BLYNK_AUTH_TOKEN    "Your_Auth_Token"

#include <BlynkSimpleEsp32.h>
// ----------- WiFi Credentials -----------
char ssid[] = "Your_WiFi_Name";
char pass[] = "Your_WiFi_Password";

// ----------- Hardware -----------
#define LED_PIN 2  

// ----------- Blynk Virtual Pin -----------
BLYNK_WRITE(V0)
{
  int ledState = param.asInt();   // 1 = ON, 0 = OFF
  digitalWrite(LED_PIN, ledState);
}

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();
}
