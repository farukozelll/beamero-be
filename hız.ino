// Reprap 1.4 Shield pin tanımlamaları
#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56

int stepSize = 1000;
int currentSpeed = 1000;
int targetSpeed = 5000;
int acceleration = 1000;

void setup() {
  // Pinleri çıkış olarak ayarla
  pinMode(X_STEP_PIN, OUTPUT);
  pinMode(X_DIR_PIN, OUTPUT);
  pinMode(X_ENABLE_PIN, OUTPUT);
  
  pinMode(Y_STEP_PIN, OUTPUT);
  pinMode(Y_DIR_PIN, OUTPUT);
  pinMode(Y_ENABLE_PIN, OUTPUT);
  
  // Motorları etkisiz hale getir
  digitalWrite(X_ENABLE_PIN, HIGH);
  digitalWrite(Y_ENABLE_PIN, HIGH);
}

void loop() {
  // X ve Y motorlarını hareket ettir
  move(X_STEP_PIN, X_DIR_PIN, currentSpeed, acceleration, stepSize);
  move(Y_STEP_PIN, Y_DIR_PIN, currentSpeed, acceleration, stepSize);

  delay(1000); // 1 saniye bekle
}

void move(int stepPin, int dirPin, int &currentSpeed, int acceleration, int steps) {
  // Motoru etkinleştir
  digitalWrite(X_ENABLE_PIN, LOW);

  // Belirtilen sayıda adım at
  int remainingSteps = steps;
  while (remainingSteps > 0) {
    // Adım at
    digitalWrite(dirPin, steps > 0 ? HIGH : LOW);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(currentSpeed);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(currentSpeed);

    // Hızı arttır veya azalt
    if (currentSpeed < targetSpeed && (targetSpeed - currentSpeed) > acceleration) {
      currentSpeed += acceleration;
    } else if (currentSpeed > targetSpeed && (currentSpeed - targetSpeed) > acceleration) {
      currentSpeed -= acceleration;
    } else {
      currentSpeed = targetSpeed;
    }

    // Adım sayısını azalt
    if (steps > 0) {
      remainingSteps--;
    } else {
      remainingSteps++;
    }
  }

  // Motoru etkisiz hale getir
  digitalWrite(X_ENABLE_PIN, HIGH);
}
