
// WORLD MAP FUNCTIONS //
void drawWorldMap() {
  for(int y=0; y<WORLD_HEIGHT; y++) {
    for(int x=0; x<WORLD_WIDTH; x++) {
      int tile_index = pgm_read_byte(&world_map[y][x]) -1;
      if (tile_index >= 0) {
        arduboy.drawBitmap(x*TILE_SIZE + cam_x, y*TILE_SIZE + cam_y, tiles[tile_index], TILE_SIZE, TILE_SIZE, BLACK);
      }
    }
  }
}
