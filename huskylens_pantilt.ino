# Make sure you have the libraries or ur gonna be sad and shit won't work.

<Servo.h>
<HuskyLens.h>

Servo panServo;
Servo tiltServo;
HuskyLens husky;

int panPin = 9;
int tiltPin = 10;
int servoSpeed = 2;

void setup() {
  panServo.attach(panPin);
  tiltServo.attach(tiltPin);
  husky.begin();
}

void loop() {
  husky.update();
  int x = husky.getObjectX();
  int y = husky.getObjectY();
  int w = husky.getObjectWidth();
  int h = husky.getObjectHeight();

  int panTarget = map(x + w / 2, 0, 320, 0, 180);
  int tiltTarget = map(y + h / 2, 0, 240, 0, 180);

  int panPos = panServo.read();
  int tiltPos = tiltServo.read();

  if (abs(panPos - panTarget) > servoSpeed) {
    if (panPos > panTarget) {
      panPos -= servoSpeed;
    } else {
      panPos += servoSpeed;
    }
    panServo.write(panPos);
  }

  if (abs(tiltPos - tiltTarget) > servoSpeed) {
    if (tiltPos > tiltTarget) {
      tiltPos -= servoSpeed;
    } else {
      tiltPos += servoSpeed;
    }
    tiltServo.write(tiltPos);
  }

  delay(50);
}
