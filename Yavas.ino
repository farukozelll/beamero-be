// Reprap 1.4 Shield pin tanımlamaları
#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56

int stepSize = 200;
int stepDelay = 2000;

void setup() {
  // Pinleri çıkış olarak ayarla
  pinMode(X_STEP_PIN, OUTPUT);
  pinMode(X_DIR_PIN, OUTPUT);
  pinMode(X_ENABLE_PIN, OUTPUT);
  
  pinMode(Y_STEP_PIN, OUTPUT);
  pinMode(Y_DIR_PIN, OUTPUT);
  pinMode(Y_ENABLE_PIN, OUTPUT);
}

void loop() {
  // X ve Y motorlarını etkinleştir
  digitalWrite(X_ENABLE_PIN, LOW);
  digitalWrite(Y_ENABLE_PIN, LOW);

  // X ve Y eksenlerini hareket ettir
  for (int i = 0; i < stepSize; i++) {
    digitalWrite(X_DIR_PIN, HIGH);
    digitalWrite(X_STEP_PIN, HIGH);
    delayMicroseconds(stepDelay);
    digitalWrite(X_STEP_PIN, LOW);
    delayMicroseconds(stepDelay);
    
    digitalWrite(Y_DIR_PIN, HIGH);
    digitalWrite(Y_STEP_PIN, HIGH);
    delayMicroseconds(stepDelay);
    digitalWrite(Y_STEP_PIN, LOW);
    delayMicroseconds(stepDelay);
  }

  delay(1000); // 1 saniye bekle

  // Yavaş başla, hızlan
  for (int i = 0; i < 2000; i++) {
    if (i < 1000) {
      stepDelay = 2000 - (i * 2);
    } else {
      stepDelay = (i - 1000) * 2;
    }

    // X ve Y eksenlerini hareket ettir
    for (int j = 0; j < stepSize; j++) {
      digitalWrite(X_DIR_PIN, HIGH);
      digitalWrite(X_STEP_PIN, HIGH);
      delayMicroseconds(stepDelay);
      digitalWrite(X_STEP_PIN, LOW);
      delayMicroseconds(stepDelay);

      digitalWrite(Y_DIR_PIN, HIGH);
      digitalWrite(Y_STEP_PIN, HIGH);
      delayMicroseconds(stepDelay);
      digitalWrite(Y_STEP_PIN, LOW);
      delayMicroseconds(stepDelay);
    }
  }
}
