#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    50

CRGB leds[NUM_LEDS];

int i = 0;
int j = 0;
unsigned int total = 0;
unsigned int total5 = 0;
int arr[100];
int arr5[5];
float avg = 0;
float avg5 = 0;
float mag = 0;
int bar = 0;

void setup() {
  Serial.begin(9600); 
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  memset(arr,0,sizeof(arr));
  memset(leds,CRGB (0,0,0),sizeof(leds));
  FastLED.show();
}

void loop() {
  
  int y1 = analogRead(A0);
//  Serial.println("howdy");
  //Serial.println(y1);

  total5 = total5 - arr5[j] + y1;
  arr5[j] = y1; 
  avg5 = total5/5.0;
  total = total - arr[i] + y1;
  arr[i] = y1;

  avg = total/100.0;
  mag = abs(avg-y1);
 Serial.println(total);
 Serial.println(y1);
  //Serial.println(i);
  Serial.println(avg);
  Serial.println(mag);
  bar = mag*10;
  Serial.println(bar);
  //memset(leds,CRGB (0,0,0),sizeof(leds));
//  for (int k = 0; k <= bar; k++) {
//    leds[k] = CRGB ( 0, 0, 172);
//  }
  

//  for (int l = 299; l > mag*10; l++) {
//    leds[l] = CRGB ( 0, 0, 0);
//  }
  FastLED.show();
  delay(100);
  i = (i == 99) ? 0 : i+1;
  j = (j == 4) ? 0 : j+1;

}
