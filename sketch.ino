
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int voltagePin = 34;
const int currentPin = 35;

float voltage = 0;
float current = 0;
float power = 0;
float energy = 0;

unsigned long previousTime = 0;
unsigned long previousDisplayTime = 0;

int displayPage = 0;

void setup() {
  Serial.begin(115200);

  Wire.begin(21, 22);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Smart Energy");
  lcd.setCursor(0, 1);
  lcd.print("Monitor Starting");

  delay(2000);
  lcd.clear();
}

void loop() {
  int voltageRaw = analogRead(voltagePin);
  int currentRaw = analogRead(currentPin);

  voltage = (voltageRaw / 4095.0) * 250.0;
  current = (currentRaw / 4095.0) * 10.0;

  power = voltage * current;

  unsigned long currentTime = millis();

  if (previousTime > 0) {
    float elapsedHours =
      (currentTime - previousTime) / 3600000.0;

    energy += power * elapsedHours;
  }

  previousTime = currentTime;

  // Switch LCD page every 2 seconds
  if (currentTime - previousDisplayTime >= 2000) {
    previousDisplayTime = currentTime;
    displayPage = !displayPage;

    lcd.clear();

    if (displayPage == 0) {
      lcd.setCursor(0, 0);
      lcd.print("V:");
      lcd.print(voltage, 1);
      lcd.print("V I:");
      lcd.print(current, 1);
      lcd.print("A");

      lcd.setCursor(0, 1);
      lcd.print("Power:");
      lcd.print(power, 1);
      lcd.print("W");
    }
    else {
      lcd.setCursor(0, 0);
      lcd.print("Energy:");

      lcd.setCursor(0, 1);
      lcd.print(energy, 4);
      lcd.print(" Wh");
    }
  }

  // Serial Monitor output
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.print(" V | Current: ");
  Serial.print(current);
  Serial.print(" A | Power: ");
  Serial.print(power);
  Serial.print(" W | Energy: ");
  Serial.print(energy);
  Serial.println(" Wh");

  delay(1000);
}
