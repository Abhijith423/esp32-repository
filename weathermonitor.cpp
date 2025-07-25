#include <DHT.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#define DHTPIN 15
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
Serial.begin(115200);
dht.begin();

if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
Serial.println(F("SSD1306 allocation failed"));
for(;;);
}

display.clearDisplay();
display.setTextSize(1);
display.setTextColor(SSD1306_WHITE);
}

void loop() {
float temp = dht.readTemperature();
float hum = dht.readHumidity();

display.clearDisplay();
display.setCursor(0, 0);
display.print("Temp: ");
display.print(temp);
display.println(" C");

display.print("Humidity: ");
display.print(hum);
display.println(" %");
display.display();

delay(2000);
}
