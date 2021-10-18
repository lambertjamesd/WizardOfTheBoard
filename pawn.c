
#include "board.h"
#include "pieces.h"
#include "constants.h"

void pawnLegalMove(u32 ourIndex, const u8* piecesActive, const Pos2* piecePositions, u8* legalSpots) {
  const Pos2* ourPosition = &(piecePositions[ourIndex]);

  // If our pawn is at the end of the board, we aren't going to be able to move it
  if (ourPosition->y >= (BOARD_HEIGHT - 1)) {
    return;
  }

  if (isSpaceOccupied(ourPosition->x, ourPosition->y + 1) > -1) {
    return;
  }

  // If we've made it this far, then we can mark our desired spot as legal
  legalSpots[ourPosition->x + ((ourPosition->y + 1) * BOARD_WIDTH)] = 1;


  // The starting row
  if (ourPosition->y == 1) {
    if (isSpaceOccupied(ourPosition->x, ourPosition->y + 2) <= -1) {
      legalSpots[ourPosition->x + ((ourPosition->y + 2) * BOARD_WIDTH)] = 1;
    }
  }

  
}

Vtx pawn_verts[] = {
  { 67, 70, 0, 0, 0, 0, 43, 43, 43, 255 },
  { 67, 70, 35, 0, 0, 0, 189, 189, 189, 255 },
  { 45, 45, 43, 0, 0, 0, 115, 115, 115, 255 },
  { 16, 18, 181, 0, 0, 0, 110, 110, 110, 255 },
  { 38, 37, 205, 0, 0, 0, 189, 189, 189, 255 },
  { 36, 35, 247, 0, 0, 0, 151, 151, 151, 255 },
  { 27, 28, 57, 0, 0, 0, 199, 199, 199, 255 },
  { 0, 100, 0, 0, 0, 0, 40, 40, 40, 255 },
  { -67, 70, 0, 0, 0, 0, 43, 43, 43, 255 },
  { 0, 100, 35, 0, 0, 0, 192, 192, 192, 255 },
  { -67, 70, 35, 0, 0, 0, 189, 189, 189, 255 },
  { 0, 67, 43, 0, 0, 0, 115, 115, 115, 255 },
  { -45, 45, 43, 0, 0, 0, 115, 115, 115, 255 },
  { 0, 24, 181, 0, 0, 0, 121, 121, 121, 255 },
  { -16, 18, 181, 0, 0, 0, 110, 110, 110, 255 },
  { 0, 58, 205, 0, 0, 0, 189, 189, 189, 255 },
  { -38, 37, 205, 0, 0, 0, 189, 189, 189, 255 },
  { 0, 58, 247, 0, 0, 0, 157, 157, 157, 255 },
  { -36, 35, 247, 0, 0, 0, 151, 151, 151, 255 },
  { -27, 28, 57, 0, 0, 0, 199, 199, 199, 255 },
  { 0, 40, 57, 0, 0, 0, 197, 197, 197, 255 },
  { 0, 13, 274, 0, 0, 0, 255, 255, 255, 255 },
  { 100, 0, 0, 0, 0, 0, 43, 43, 43, 255 },
  { 67, -70, 0, 0, 0, 0, 43, 43, 43, 255 },
  { 100, 0, 35, 0, 0, 0, 195, 195, 195, 255 },
  { 67, -70, 35, 0, 0, 0, 189, 189, 189, 255 },
  { 69, 0, 43, 0, 0, 0, 115, 115, 115, 255 },
  { 45, -45, 43, 0, 0, 0, 115, 115, 115, 255 },
  { 25, 0, 181, 0, 0, 0, 110, 110, 110, 255 },
  { 16, -18, 181, 0, 0, 0, 110, 110, 110, 255 },
  { 55, 0, 205, 0, 0, 0, 189, 189, 189, 255 },
  { 38, -37, 205, 0, 0, 0, 189, 189, 189, 255 },
  { 55, 0, 245, 0, 0, 0, 178, 178, 178, 255 },
  { 36, -35, 247, 0, 0, 0, 151, 151, 151, 255 },
  { 27, -28, 57, 0, 0, 0, 199, 199, 199, 255 },
  { 42, 0, 57, 0, 0, 0, 199, 199, 199, 255 },
  { 13, 0, 273, 0, 0, 0, 255, 255, 255, 255 },
  { 0, 0, 0, 0, 0, 0, 50, 50, 50, 255 },
  { 0, -100, 0, 0, 0, 0, 40, 40, 40, 255 },
  { -100, 0, 0, 0, 0, 0, 43, 43, 43, 255 },
  { -67, -70, 0, 0, 0, 0, 43, 43, 43, 255 },
  { 0, -100, 35, 0, 0, 0, 192, 192, 192, 255 },
  { -100, 0, 35, 0, 0, 0, 195, 195, 195, 255 },
  { -67, -70, 35, 0, 0, 0, 189, 189, 189, 255 },
  { 0, 0, 43, 0, 0, 0, 255, 255, 255, 255 },
  { 0, -67, 43, 0, 0, 0, 115, 115, 115, 255 },
  { -69, 0, 43, 0, 0, 0, 115, 115, 115, 255 },
  { -45, -45, 43, 0, 0, 0, 115, 115, 115, 255 },
  { 0, -24, 181, 0, 0, 0, 121, 121, 121, 255 },
  { -25, 0, 181, 0, 0, 0, 110, 110, 110, 255 },
  { -16, -18, 181, 0, 0, 0, 110, 110, 110, 255 },
  { 0, -58, 205, 0, 0, 0, 189, 189, 189, 255 },
  { -55, 0, 205, 0, 0, 0, 189, 189, 189, 255 },
  { -38, -37, 205, 0, 0, 0, 189, 189, 189, 255 },
  { 0, -58, 247, 0, 0, 0, 157, 157, 157, 255 },
  { -55, 0, 245, 0, 0, 0, 178, 178, 178, 255 },
  { -36, -35, 247, 0, 0, 0, 151, 151, 151, 255 },
  { -27, -28, 57, 0, 0, 0, 199, 199, 199, 255 },
  { 0, -40, 57, 0, 0, 0, 197, 197, 197, 255 },
  { -42, 0, 57, 0, 0, 0, 199, 199, 199, 255 },
  { -13, 0, 273, 0, 0, 0, 255, 255, 255, 255 },
  { 0, -13, 274, 0, 0, 0, 255, 255, 255, 255 },
  { 0, 0, 274, 0, 0, 0, 255, 255, 255, 255 },
};


Gfx pawn_commands[] = {
  gsSPVertex(&pawn_verts, 63, 0),
  gsSP2Triangles(0, 22, 37, 0, 37, 7, 0, 0),
  gsSP2Triangles(9, 2, 1, 0, 1, 26, 24, 0),
  gsSP2Triangles(0, 24, 22, 0, 7, 1, 0, 0),
  gsSP2Triangles(2, 44, 26, 0, 44, 2, 11, 0),
  gsSP2Triangles(20, 3, 6, 0, 6, 28, 35, 0),
  gsSP2Triangles(13, 4, 3, 0, 3, 30, 28, 0),
  gsSP2Triangles(15, 5, 4, 0, 4, 32, 30, 0),
  gsSP2Triangles(5, 36, 32, 0, 2, 35, 26, 0),
  gsSP2Triangles(11, 6, 2, 0, 36, 5, 21, 0),
  gsSP2Triangles(17, 21, 5, 0, 36, 21, 62, 0),
  gsSP2Triangles(9, 11, 2, 0, 1, 2, 26, 0),
  gsSP2Triangles(0, 1, 24, 0, 7, 9, 1, 0),
  gsSP2Triangles(20, 13, 3, 0, 6, 3, 28, 0),
  gsSP2Triangles(13, 15, 4, 0, 3, 4, 30, 0),
  gsSP2Triangles(15, 17, 5, 0, 4, 5, 32, 0),
  gsSP2Triangles(2, 6, 35, 0, 11, 20, 6, 0),
  gsSP2Triangles(8, 37, 39, 0, 37, 8, 7, 0),
  gsSP2Triangles(9, 10, 12, 0, 10, 42, 46, 0),
  gsSP2Triangles(8, 39, 42, 0, 7, 8, 10, 0),
  gsSP2Triangles(12, 46, 44, 0, 44, 11, 12, 0),
  gsSP2Triangles(20, 19, 14, 0, 19, 59, 49, 0),
  gsSP2Triangles(13, 14, 16, 0, 14, 49, 52, 0),
  gsSP2Triangles(15, 16, 18, 0, 16, 52, 55, 0),
  gsSP2Triangles(18, 55, 60, 0, 12, 46, 59, 0),
  gsSP2Triangles(11, 12, 19, 0, 60, 21, 18, 0),
  gsSP2Triangles(17, 18, 21, 0, 60, 62, 21, 0),
  gsSP2Triangles(9, 12, 11, 0, 10, 46, 12, 0),
  gsSP2Triangles(8, 42, 10, 0, 7, 10, 9, 0),
  gsSP2Triangles(20, 14, 13, 0, 19, 49, 14, 0),
  gsSP2Triangles(13, 16, 15, 0, 14, 52, 16, 0),
  gsSP2Triangles(15, 18, 17, 0, 16, 55, 18, 0),
  gsSP2Triangles(12, 59, 19, 0, 11, 19, 20, 0),
  gsSP2Triangles(23, 37, 22, 0, 37, 23, 38, 0),
  gsSP2Triangles(41, 25, 27, 0, 25, 24, 26, 0),
  gsSP2Triangles(23, 22, 24, 0, 38, 23, 25, 0),
  gsSP2Triangles(27, 26, 44, 0, 44, 45, 27, 0),
  gsSP2Triangles(58, 34, 29, 0, 34, 35, 28, 0),
  gsSP2Triangles(48, 29, 31, 0, 29, 28, 30, 0),
  gsSP2Triangles(51, 31, 33, 0, 31, 30, 32, 0),
  gsSP2Triangles(33, 32, 36, 0, 27, 26, 35, 0),
  gsSP2Triangles(45, 27, 34, 0, 36, 61, 33, 0),
  gsSP2Triangles(54, 33, 61, 0, 36, 62, 61, 0),
  gsSP2Triangles(41, 27, 45, 0, 25, 26, 27, 0),
  gsSP2Triangles(23, 24, 25, 0, 38, 25, 41, 0),
  gsSP2Triangles(58, 29, 48, 0, 34, 28, 29, 0),
  gsSP2Triangles(48, 31, 51, 0, 29, 30, 31, 0),
  gsSP2Triangles(51, 33, 54, 0, 31, 32, 33, 0),
  gsSP2Triangles(27, 35, 34, 0, 45, 34, 58, 0),
  gsSP2Triangles(40, 39, 37, 0, 37, 38, 40, 0),
  gsSP2Triangles(41, 47, 43, 0, 43, 46, 42, 0),
  gsSP2Triangles(40, 42, 39, 0, 38, 43, 40, 0),
  gsSP2Triangles(47, 44, 46, 0, 44, 47, 45, 0),
  gsSP2Triangles(58, 50, 57, 0, 57, 49, 59, 0),
  gsSP2Triangles(48, 53, 50, 0, 50, 52, 49, 0),
  gsSP2Triangles(51, 56, 53, 0, 53, 55, 52, 0),
  gsSP2Triangles(56, 60, 55, 0, 47, 59, 46, 0),
  gsSP2Triangles(45, 57, 47, 0, 60, 56, 61, 0),
  gsSP2Triangles(54, 61, 56, 0, 60, 61, 62, 0),
  gsSP2Triangles(41, 45, 47, 0, 43, 47, 46, 0),
  gsSP2Triangles(40, 43, 42, 0, 38, 41, 43, 0),
  gsSP2Triangles(58, 48, 50, 0, 57, 50, 49, 0),
  gsSP2Triangles(48, 51, 53, 0, 50, 53, 52, 0),
  gsSP2Triangles(51, 54, 56, 0, 53, 56, 55, 0),
  gsSP2Triangles(47, 57, 59, 0, 45, 58, 57, 0),
  gsSPEndDisplayList()
};