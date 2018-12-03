
void gainPoints(int amt) {
  score += amt;
}

void drawScoreBox(int x, int y) {
  arduboy.fillRect(x, y, 30, 10);
  arduboy.drawFastVLine(x+1, y, 8, BLACK);
  arduboy.drawFastHLine(x+2, y+7, 28, BLACK);
  arduboy.drawFastHLine(x+2, y+8, 28, BLACK);
  arduboy.drawPixel(x+2, y, BLACK);
  arduboy.drawPixel(x+29, y, BLACK);
  arduboy.drawPixel(x+2, y+6, BLACK);
  arduboy.drawPixel(x+29, y+6, BLACK);
}

void drawZeros(int n, int x, int y) {
  for (int i=0; i<n; i++) {
    sprites.drawExternalMask(x+(i*5), y, numbers_img, numbers_mask, 0, 0);
  }
}

void drawScoreNumber(int x, int y) {
  int score_length = getNumberLength(score);
  //int num_of_zeros = (score_length < 5) ? 5 - score_length : 0;

  //drawZeros(num_of_zeros, x-20, y);
  drawEachDigit(score, x, y);
}

void drawScore() {
  drawScoreBox(98, 0);
  drawScoreNumber(122, 1);
}
