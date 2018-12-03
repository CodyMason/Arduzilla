
// CAMERA FUNCTIONS //
void moveCamera() {
  if (arduboy.pressed(LEFT_BUTTON)) {
    cam_x -= 0.25;
  }
  if (arduboy.pressed(RIGHT_BUTTON)) {
    cam_x += 0.25;
  }
  if (arduboy.pressed(UP_BUTTON)) {
    cam_y -= 0.25;
  }
  if (arduboy.pressed(DOWN_BUTTON)) {
    cam_y += 0.25;
  }
}

void getCameraOffset() {
  if (arduboy.pressed(LEFT_BUTTON)) {
    cam_x_off = CAM_OFFSET;
  }
  if (arduboy.pressed(RIGHT_BUTTON)) {
    cam_x_off = -CAM_OFFSET;
  }
  if (arduboy.pressed(UP_BUTTON)) {
    cam_y_off = CAM_OFFSET;
  }
  if (arduboy.pressed(DOWN_BUTTON)) {
    cam_y_off = -CAM_OFFSET;
  }

  if (dirPressed() == false) {
    //cam_x_off = 0;
    cam_y_off = 0;
  }
}

void cameraFollow(float tx, float ty) {
  //cam_x = -tx+52.0;
  //cam_y = -ty+32.0;
  cam_x = lerp(cam_x, -tx+52 + cam_x_off, 0.1);
  cam_y = lerp(cam_y, -ty+32 + cam_y_off, 0.1);
}

void limitCamera() {
  cam_x = minf(cam_x, 0);
  cam_x = maxf(cam_x, -(WORLD_WIDTH*TILE_SIZE)+WIDTH);
  cam_y = minf(cam_y, 0);
  cam_y = maxf(cam_y, -(WORLD_HEIGHT*TILE_SIZE)+HEIGHT);
}
