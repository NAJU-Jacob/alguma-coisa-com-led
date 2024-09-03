// Prof acontece o seguinte o nosso circuito físico tivemos probleas com contraste, ficou bem apagado mas da pra ver com um pouco de esforço haha
//ficou assim porquwe era a nossa terceira montagem, espero que o sr. entenda 
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int buttonPin = A0;

const int lm35Pin = A1;

float soma = 0;

bool buttonClicked = false;

void setup() {
  // Inicializa o LCD
  lcd.begin(16, 2);
}

void loop() {
  int buttonState = analogRead(buttonPin);
  
  if (buttonState < 50 && !buttonClicked) {
    buttonClicked = true;

    float tempCelsius = readTemperature();
  
    lcd.clear();
    
    float tempFahrenheit = celsiusToFahrenheit(tempCelsius + soma);
    lcd.print("Temp (F): ");
    lcd.print(tempFahrenheit);
    lcd.print(" F");
  } else if (buttonState >= 50) {
    buttonClicked = false;
  } else {
    float tempCelsius = readTemperature();
    lcd.clear();
    lcd.print("Temp (C): ");
    lcd.print(tempCelsius);
    lcd.print(" C");
  }
  
  delay(100);
}

float readTemperature() {
  int raw = analogRead(lm35Pin);
  float millivolts = (raw / 1023.0) * 5000;
  float tempCelsius = millivolts / 10;
  return tempCelsius;
}

float celsiusToFahrenheit(float tempCelsius) {
  float tempFahrenheit = (tempCelsius * 9/5) + 32;
  return tempFahrenheit;
}
