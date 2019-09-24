//Include Servo library
#include <Servo.h>

//Setup global veriables for Servo and theta
Servo pitch;
Servo yaw;
int phi = 75;
int theta = 0;

int step_size = 3; //degrees per increment
int xres = 15; //x resolution
int yres = 15; //y resolution


void setup() {
  pitch.attach(9);
  yaw.attach(10);

  long baudRate = 9600;
  Serial.begin(baudRate);

  pitch.write(phi);
  yaw.write(theta);
  delay(2000);
}

void loop() {
  sweep_2d(xres, yres);
}

void increment_pitch(int deg) {
  phi -= deg;
  pitch.write(phi);
  delay(deg * 25);
}

void increment_yaw(int deg) {
  theta += deg;
  yaw.write(theta);
  delay(deg * 25);
}

void sweep_1d(int increments) {
  int dist = 0;

  for (int i = 0; i < increments; i += 1) {
    dist = analogRead(A0);
    Serial.println(dist);
    delay(300);
    increment_yaw(step_size);
  }

  theta = 0;
  yaw.write(theta);
  delay(500);
}

void sweep_2d(int xincrements, int yincrements) {
  for (int j = 0; j < yincrements; j += 1) {
    sweep_1d(xincrements);
    increment_pitch(step_size);
    delay(200);
  }

  phi = 75;
  pitch.write(phi);
}
