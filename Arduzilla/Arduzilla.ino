#include <Arduboy2.h>

Arduboy2 arduboy;
Sprites sprites;

#include "images.h"
#include "vars.h"

//////////////////////////// MAIN LOOP START ///////////////////////////////

void setup() {
  arduboy.boot();

  setSmallBuildingsHP();
}

void loop() {
  // Update
  if(!arduboy.nextFrame())
    return;

  // RGB LED CONTROL
  resetLED();

  // UPDATE CAMERA
  getCameraOffset();
  cameraFollow(dino_x, dino_y);
  limitCamera();

  updateDino();
  updateBuildings();

  // Draw
  arduboy.clear();
    arduboy.fillScreen();
    drawWorldMap();
    drawBuildings();
    drawDino();
    drawScore();
  arduboy.display();
}
