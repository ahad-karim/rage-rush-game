#ifndef LEVELFIVE_H
#define LEVELFIVE_H

#include "GameData.h"
#include "Images.h"

// Type 0=Spike, 1=Door, 2=Platform, 3=Sawblade, 4=Fake Platform,
//       5=Ghost, 6=Fake Door, 7=Orb
//
// Struct layout (positional init):
// { x, y, width, height, type, state, isVisible, willKill, willMove,
//   speed, mode, trigX, trigY, innitialX, innitialY, finX, finY }
//
// Level 5 sublevel advancement:
//   Sublevels 1-3: walk to x >= 1000 (right edge) to advance to next sublevel
//   Sublevel 4:    touch the door at far right to advance to the next level

int obstacleHeightLevel5 = 20;
int noOfObjLevel5;
int subLevelCount5 = 1;
GameObject objLevel5[100];

void subLevelDefining5() {
  noOfObjLevel5 = 0;

  if (subLevelCount5 == 1) {
    // -------------------------------------------------------------------------
    // SUBLEVEL 1 – Vertical Elevators + Orb introduction
    // Walk to x >= 1000 to advance to sublevel 2
    // -------------------------------------------------------------------------

    // Ground base (static)
    objLevel5[noOfObjLevel5++] = {0,   -60, 1080, 80, 2, 0, true, false, false, 0, 0, -200, 0,   0, -60,   0, -60};

    // Starting safe platform
    objLevel5[noOfObjLevel5++] = {0,    20, 130,  20, 2, 0, true, false, false, 0, 0, -200, 0,   0,  20,   0,  20};

    // Orb sitting on the starting platform
    objLevel5[noOfObjLevel5++] = {50,   55,  30,  30, 7, 0, true, false, false, 0, 0, -200, 0,  50,  55,  50,  55};

    // Elevator 1 – oscillates between y=20 and y=110
    objLevel5[noOfObjLevel5++] = {210,  20, 120,  20, 2, 0, true, false, true,  3, 1, -200, 0, 210,  20, 210, 110};

    // Static landing ledge
    objLevel5[noOfObjLevel5++] = {390, 100, 100,  20, 2, 0, true, false, false, 0, 0, -200, 0, 390, 100, 390, 100};

    // Elevator 2 – oscillates between y=20 and y=100
    objLevel5[noOfObjLevel5++] = {560,  20, 120,  20, 2, 0, true, false, true,  4, 1, -200, 0, 560,  20, 560, 100};

    // Static landing ledge 2
    objLevel5[noOfObjLevel5++] = {740,  90, 200,  20, 2, 0, true, false, false, 0, 0, -200, 0, 740,  90, 740,  90};

    // Ground spikes between platforms
    objLevel5[noOfObjLevel5++] = {140,  20,  60,  20, 0, 0, true, true,  false, 0, 0, -200, 0, 140,  20, 140,  20};
    objLevel5[noOfObjLevel5++] = {340,  20,  60,  20, 0, 0, true, true,  false, 0, 0, -200, 0, 340,  20, 340,  20};
    objLevel5[noOfObjLevel5++] = {500,  20,  50,  20, 0, 0, true, true,  false, 0, 0, -200, 0, 500,  20, 500,  20};
    objLevel5[noOfObjLevel5++] = {690,  20,  50,  20, 0, 0, true, true,  false, 0, 0, -200, 0, 690,  20, 690,  20};

  } else if (subLevelCount5 == 2) {
    // -------------------------------------------------------------------------
    // SUBLEVEL 2 – Horizontal Sliding Platforms
    // Walk to x >= 1000 to advance to sublevel 3
    // -------------------------------------------------------------------------

    // Ground base
    objLevel5[noOfObjLevel5++] = {0, -60, 1080, 80, 2, 0, true, false, false, 0, 0, -200, 0, 0, -60, 0, -60};

    // Starting safe platform
    objLevel5[noOfObjLevel5++] = {0, 20, 120, 20, 2, 0, true, false, false, 0, 0, -200, 0, 0, 20, 0, 20};

    // Horizontal slider 1 – oscillates between x=150 and x=400
    objLevel5[noOfObjLevel5++] = {150, 20, 120, 20, 2, 0, true, false, true, 3, 0, -200, 0, 150, 20, 400, 20};

    // Static perch
    objLevel5[noOfObjLevel5++] = {420, 70, 80, 20, 2, 0, true, false, false, 0, 0, -200, 0, 420, 70, 420, 70};

    // Orb on the perch
    objLevel5[noOfObjLevel5++] = {440, 90, 30, 30, 7, 0, true, false, false, 0, 0, -200, 0, 440, 90, 440, 90};

    // Horizontal slider 2 – oscillates between x=300 and x=650
    objLevel5[noOfObjLevel5++] = {300, 110, 130, 20, 2, 0, true, false, true, 4, 0, -200, 0, 300, 110, 650, 110};

    // Static platform at far right
    objLevel5[noOfObjLevel5++] = {800, 80, 200, 20, 2, 0, true, false, false, 0, 0, -200, 0, 800, 80, 800, 80};

    // Spikes on ground
    objLevel5[noOfObjLevel5++] = {125,  20, 20, 20, 0, 0, true, true, false, 0, 0, -200, 0, 125,  20, 125,  20};
    objLevel5[noOfObjLevel5++] = {280,  20, 20, 20, 0, 0, true, true, false, 0, 0, -200, 0, 280,  20, 280,  20};
    objLevel5[noOfObjLevel5++] = {570,  20, 60, 20, 0, 0, true, true, false, 0, 0, -200, 0, 570,  20, 570,  20};
    objLevel5[noOfObjLevel5++] = {700,  20, 90, 20, 0, 0, true, true, false, 0, 0, -200, 0, 700,  20, 700,  20};

  } else if (subLevelCount5 == 3) {
    // -------------------------------------------------------------------------
    // SUBLEVEL 3 – Mixed heights + fast platforms + sawblade
    // Walk to x >= 1000 to advance to sublevel 4
    // -------------------------------------------------------------------------

    // Ground base
    objLevel5[noOfObjLevel5++] = {0, -60, 1080, 80, 2, 0, true, false, false, 0, 0, -200, 0, 0, -60, 0, -60};

    // Starting platform
    objLevel5[noOfObjLevel5++] = {0, 20, 100, 20, 2, 0, true, false, false, 0, 0, -200, 0, 0, 20, 0, 20};

    // Orb just above starting platform
    objLevel5[noOfObjLevel5++] = {30, 80, 30, 30, 7, 0, true, false, false, 0, 0, -200, 0, 30, 80, 30, 80};

    // Fast Y-elevator – oscillates between y=20 and y=120
    objLevel5[noOfObjLevel5++] = {160, 20, 100, 20, 2, 0, true, false, true, 5, 1, -200, 0, 160, 20, 160, 120};

    // Wide horizontal slider – oscillates between x=320 and x=620
    objLevel5[noOfObjLevel5++] = {320, 90, 120, 20, 2, 0, true, false, true, 3, 0, -200, 0, 320, 90, 620, 90};

    // Y-elevator 2 – oscillates between y=20 and y=90
    objLevel5[noOfObjLevel5++] = {680, 20, 100, 20, 2, 0, true, false, true, 4, 1, -200, 0, 680, 20, 680, 90};

    // Final landing ledge (wide enough to walk off the right edge)
    objLevel5[noOfObjLevel5++] = {840, 100, 200, 20, 2, 0, true, false, false, 0, 0, -200, 0, 840, 100, 840, 100};

    // Sawblade patrolling the ground
    objLevel5[noOfObjLevel5++] = {110, 20, 45, 45, 3, 0, true, true, true, 5, 0, -200, 0, 110, 20, 820, 20};

    // Spikes
    objLevel5[noOfObjLevel5++] = {110, 20, 40, 20, 0, 0, true, true, false, 0, 0, -200, 0, 110, 20, 110, 20};
    objLevel5[noOfObjLevel5++] = {270, 20, 40, 20, 0, 0, true, true, false, 0, 0, -200, 0, 270, 20, 270, 20};
    objLevel5[noOfObjLevel5++] = {630, 20, 40, 20, 0, 0, true, true, false, 0, 0, -200, 0, 630, 20, 630, 20};

  } else if (subLevelCount5 == 4) {
    // -------------------------------------------------------------------------
    // SUBLEVEL 4 – Finale: platforms + dual sawblades
    // Touch the door at the far right to complete Level 5 and advance
    // -------------------------------------------------------------------------

    // Ground base
    objLevel5[noOfObjLevel5++] = {0, -60, 1080, 80, 2, 0, true, false, false, 0, 0, -200, 0, 0, -60, 0, -60};

    // Starting platform
    objLevel5[noOfObjLevel5++] = {0, 20, 120, 20, 2, 0, true, false, false, 0, 0, -200, 0, 0, 20, 0, 20};

    // Orb on starting platform (shield powerup)
    objLevel5[noOfObjLevel5++] = {45, 55, 30, 30, 7, 0, true, false, false, 0, 0, -200, 0, 45, 55, 45, 55};

    // Long horizontal slider – oscillates between x=150 and x=600
    objLevel5[noOfObjLevel5++] = {150, 20, 140, 20, 2, 0, true, false, true, 3, 0, -200, 0, 150, 20, 600, 20};

    // Y-elevator – oscillates between y=20 and y=100
    objLevel5[noOfObjLevel5++] = {640, 20, 110, 20, 2, 0, true, false, true, 4, 1, -200, 0, 640, 20, 640, 100};

    // Final platform (hero stands here to reach the door)
    objLevel5[noOfObjLevel5++] = {800, 100, 180, 20, 2, 0, true, false, false, 0, 0, -200, 0, 800, 100, 800, 100};

    // Exit door – hero must walk into this to complete Level 5
    objLevel5[noOfObjLevel5++] = {950, 100, 50, 60, 1, 0, true, false, false, 0, 0, -200, 0, 950, 100, 950, 100};

    // Sawblade 1: sweeps low across the ground gap
    objLevel5[noOfObjLevel5++] = {140, 20, 45, 45, 3, 0, true, true, true, 6, 0, -200, 0, 140, 20, 790, 20};

    // Sawblade 2: sweeps at mid-height (opposite direction)
    objLevel5[noOfObjLevel5++] = {790, 70, 45, 45, 3, 0, true, true, true, 5, 0, -200, 0, 790, 70, 140, 70};

    // Ground spikes
    objLevel5[noOfObjLevel5++] = {120, 20, 20, 20, 0, 0, true, true, false, 0, 0, -200, 0, 120, 20, 120, 20};
    objLevel5[noOfObjLevel5++] = {300, 20, 60, 20, 0, 0, true, true, false, 0, 0, -200, 0, 300, 20, 300, 20};
    objLevel5[noOfObjLevel5++] = {520, 20, 60, 20, 0, 0, true, true, false, 0, 0, -200, 0, 520, 20, 520, 20};
    objLevel5[noOfObjLevel5++] = {750, 20, 40, 20, 0, 0, true, true, false, 0, 0, -200, 0, 750, 20, 750, 20};
  }
}

#endif
