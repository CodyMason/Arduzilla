
// MISC FUNCTIONS //

int getNumberLength(int num) {
  int len = 1;
  while(num /= 10)
    len++;
  return len;
}

void printEachDigit(int num) {
  if (num >= 10)
    printEachDigit(num / 10);

  int digit = num % 10;
  arduboy.println(digit);
}

void drawEachDigit(int num, int x, int y) {
  if (num >= 10)
    drawEachDigit(num / 10, x-5, y);

  int digit = num % 10;
  sprites.drawExternalMask(x, y, numbers_img, numbers_mask, digit, digit);
}

void resetLED() {
  arduboy.setRGBled(0, 0, 0);
}

bool dirPressed() {
  if (arduboy.pressed(LEFT_BUTTON) || arduboy.pressed(RIGHT_BUTTON) ||
      arduboy.pressed(UP_BUTTON)   || arduboy.pressed(DOWN_BUTTON)) {
    return true;
  }
  return false;
}

void limitXAtWorldBounds(float &x, float &dx, int w) {
  float world_right = WORLD_WIDTH*TILE_SIZE;
  if (x <= 0.0) {
    x = 0.0;
    dx = 0.0;
  } else if (x+w >= world_right) {
    x = world_right-w;
    dx = 0.0;
  }
}

void limitYAtWorldBounds(float &y, float &dy, int h) {
  float world_bottom = WORLD_HEIGHT*TILE_SIZE;
  if (y <= 0.0) {
    y = 0.0;
    dy = 0.0;
  } else if (y+h >= world_bottom) {
    y = world_bottom-h;
    dy = 0.0;
  }
}

float minf(float a, float b) {
  return (a < b) ? a : b;
}

float maxf(float a, float b) {
  return (a > b) ? a : b;
}

float lerp(float s, float e, float p) {
  return (s + p*(e - s));
}
