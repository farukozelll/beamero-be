// Reprap 1.4 Shield pin tanımlamaları
#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62

int stepSize  =1000;
void setup() {
  // Pinleri çıkış olarak ayarla
  pinMode(X_STEP_PIN, OUTPUT);
  pinMode(X_DIR_PIN, OUTPUT);
  pinMode(X_ENABLE_PIN, OUTPUT);
  
  pinMode(Y_STEP_PIN, OUTPUT);
  pinMode(Y_DIR_PIN, OUTPUT);
  pinMode(Y_ENABLE_PIN, OUTPUT);
  
  pinMode(Z_STEP_PIN, OUTPUT);
  pinMode(Z_DIR_PIN, OUTPUT);
  pinMode(Z_ENABLE_PIN, OUTPUT);
}

void loop() {
  // X, Y ve Z eksenlerini hareket ettir
  digitalWrite(X_ENABLE_PIN, LOW); // X motorunu etkinleştir
  digitalWrite(Y_ENABLE_PIN, LOW); // Y motorunu etkinleştir
  digitalWrite(Z_ENABLE_PIN, LOW); // Z motorunu etkinleştir

  // X eksenini ileri hareket ettir
  digitalWrite(X_DIR_PIN, HIGH); // Sağa hareket
  for (int i = 0; i < stepSize; i++) { // 200 adım yap
    digitalWrite(X_STEP_PIN, HIGH);
    delayMicroseconds(500);
    digitalWrite(X_STEP_PIN, LOW);
    delayMicroseconds(500);
  }

  // Y eksenini ileri hareket ettir
  digitalWrite(Y_DIR_PIN, HIGH); // Sağa hareket
  for (int i = 0; i < stepSize; i++) { // 200 adım yap
    digitalWrite(Y_STEP_PIN, HIGH);
    delayMicroseconds(500);
    digitalWrite(Y_STEP_PIN, LOW);
    delayMicroseconds(500);
  }

  // Z eksenini ileri hareket ettir
  digitalWrite(Z_DIR_PIN, HIGH); // Yüksekliği artır
  for (int i = 0; i < stepSize; i++) { // 200 adım yap
    digitalWrite(Z_STEP_PIN, HIGH);
    delayMicroseconds(500);
    digitalWrite(Z_STEP_PIN, LOW);
    delayMicroseconds(500);
  }

  delay(1000); // 1 saniye bekle

  // X, Y ve Z eksenlerini geri hareket ettir
  digitalWrite(X_DIR_PIN, LOW); // Sola hareket
  for (int i = 0; i < stepSize; i++) { // 200 adım yap
    digitalWrite(X_STEP_PIN, HIGH);
    delayMicroseconds(500);
    digitalWrite(X_STEP_PIN, LOW);
    delayMicroseconds(500);
  }

  digitalWrite(Y_DIR_PIN, LOW); // Sola hareket
  for (int i = 0; i < stepSize; i++) { // 200 adım yap
    digitalWrite(Y_STEP_PIN, HIGH);
    delayMicroseconds(500);
    digitalWrite(Y_STEP_PIN, LOW);
    delayMicroseconds(500);
  }

  digitalWrite(Z_DIR_PIN, LOW); // Yüksekliği azalt
  for (int i = 0; i < stepSize; i++) { // 200 adım yap
    digitalWrite(Z_STEP_PIN, HIGH);
    delayMicroseconds(500);
    digitalWrite(Z_STEP_PIN, LOW);
    delayMicroseconds(500);
  }

  delay(1000);
  }
