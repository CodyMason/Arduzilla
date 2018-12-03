
// BUILDING FUNCTIONS //

void setSmallBuildingsHP() {
  for(int i=0; i<SMALL_BUILDING_COUNT; i++) {
    small_buildings_hp[i] = 3;
  }
}

bool smallBuildingAttacked(int x, int y) {
  int offset = 2;
  Rect building_rect {x+(int)cam_x-offset, y+(int)cam_y-offset, 8+(offset*2), 8+(offset*2)};
  Point fire_point;
  fire_point.y = (int)dino_y+(int)cam_y+6;
  
  switch(dino_dir) {
    case 0:
      // check collision point right of dinosaur
      fire_point.x = (int)dino_x+(int)cam_x+32;
      
      if (arduboy.collide(fire_point, building_rect)) {
        return true;
      }
      break;
      
    case 2:
      // check collision point left of dionsaur
      fire_point.x = (int)dino_x+(int)cam_x-4;
      
      if (arduboy.collide(fire_point, building_rect)) {
        return true;
      }
      break;
  }
  return false;
}

void damageSmallBuilding(int index) {
  if (small_buildings_hp[index] > 0) {
    if (arduboy.everyXFrames(30)) {
      small_buildings_hp[index]--;
      if (small_buildings_hp[index] == 0) {
        destroyBuilding(10);
      }
    }
  }
}

void destroyBuilding(int points) {
  arduboy.setRGBled(120, 0, 0);
  gainPoints(points);
}

void updateBuildings() {
  // UPDATE SMALL BUILDINGS
  for(int i=0; i<SMALL_BUILDING_COUNT; i++) {
    int x = small_buildings_pos[i][0];
    int y = small_buildings_pos[i][1];

    if (dino_attacking) {
      if (smallBuildingAttacked((int)(x*TILE_SIZE), (int)(y*TILE_SIZE))) {
        damageSmallBuilding(i);
      }
    }
    
  }
}

void drawBuildings() {
  for(int i=0; i<SMALL_BUILDING_COUNT; i++) {
    int x = small_buildings_pos[i][0];
    int y = small_buildings_pos[i][1];
    //arduboy.println(small_buildings_pos[0][0]);
    //arduboy.println(small_buildings_pos[0][1]);
    if (small_buildings_hp[i] > 0) {
      arduboy.drawBitmap((x*TILE_SIZE) + cam_x, (y*TILE_SIZE) + cam_y, building_small_img, 8, 8, BLACK);
    } else {
      arduboy.drawBitmap((x*TILE_SIZE) + cam_x, (y*TILE_SIZE) + cam_y, building_small_wreck_img, 8, 8, BLACK);
    }
  }
}
