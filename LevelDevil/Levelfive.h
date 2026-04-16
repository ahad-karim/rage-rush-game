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

int obstacleHeightLevel5 = 60;
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
    objLevel5[noOfObjLevel5++] = {0,  0, 150, 50, 2, 0, true, false, false, 0, 0, -200, 0,   0, -60,   0, -60};

    // Starting safe platform
    objLevel5[noOfObjLevel5++] = {0,    20, 100,  20, 2, 0, true, false, false, 0, 0, -200, 0,   0,  20,   0,  20};

    // Orb sitting on the starting platform
    objLevel5[noOfObjLevel5++] = {50,   55,  30,  30, 7, 0, true, false, false, 0, 0, -200, 0,  50,  55,  50,  55};

    // Elevator 1 – oscillates between y=20 and y=110
    objLevel5[noOfObjLevel5++] = {300,  60, 100,  20, 2, 0, true, false, true,  3, 1, -200, 0, 300,  60, 300, 160};

    // Static landing ledge
    objLevel5[noOfObjLevel5++] = {500, 100, 100,  20, 2, 0, true, false, false, 0, 0, -200, 0, 500, 100, 500, 100};

    // Elevator 2 – oscillates between y=20 and y=100
    objLevel5[noOfObjLevel5++] = {700,  60, 100,  20, 2, 0, true, false, true,  4, 1, -200, 0, 700,  60, 700, 160};

    // Static landing ledge 2
    objLevel5[noOfObjLevel5++] = {900,  90, 100,  20, 2, 0, true, false, false, 0, 0, -200, 0, 900,  90, 900,  90};

    // Ground spikes between platforms
    objLevel5[noOfObjLevel5++] = {200,  60,  50,  20, 0, 0, true, true,  false, 0, 0, -200, 0, 200,  60, 200,  60};
    objLevel5[noOfObjLevel5++] = {425,  60,  50,  20, 0, 0, true, true,  false, 0, 0, -200, 0, 425,  60, 425,  60};
    objLevel5[noOfObjLevel5++] = {625,  60,  50,  20, 0, 0, true, true,  false, 0, 0, -200, 0, 625,  60, 625,  60};
    objLevel5[noOfObjLevel5++] = {825,  60,  50,  20, 0, 0, true, true,  false, 0, 0, -200, 0, 825,  60, 825,  60};

  } else if (subLevelCount5 == 2) {
    // -------------------------------------------------------------------------
    // SUBLEVEL 2 – Horizontal Sliding Platforms
    // Walk to x >= 1000 to advance to sublevel 3
    // -------------------------------------------------------------------------

    // Ground base
	  objLevel5[noOfObjLevel5++] = { 0, 0, 150, 50, 2, 0, true, false, false, 0, 0, -200, 0, 0, -60, 0, -60 };

 

    // Horizontal slider 1 – oscillates between x=150 and x=400
    objLevel5[noOfObjLevel5++] = {150, 140, 100, 20, 2, 0, true, false, true, 3, 0, -200, 0, 150, 140, 400, 140};

    // Orb on the perch
    objLevel5[noOfObjLevel5++] = {160, 220, 30, 30, 7, 0, true, false, false, 0, 0, -200, 0, 160, 220, 160, 220};

    // Horizontal slider 2 – oscillates between x=300 and x=650
    objLevel5[noOfObjLevel5++] = {300, 140, 100, 20, 2, 0, true, false, true, 4, 0, -200, 0, 300, 140, 650, 140};

    // Static platform at far right
    objLevel5[noOfObjLevel5++] = {800, 120, 100, 20, 2, 0, true, false, false, 0, 0, -200, 0, 800, 120, 800, 120};

    // Spikes on ground
    objLevel5[noOfObjLevel5++] = {150,  60, 60, 20, 0, 0, true, true, false, 0, 0, -200, 0, 125,  60, 150,  60};
    objLevel5[noOfObjLevel5++] = {350,  60, 60, 20, 0, 0, true, true, false, 0, 0, -200, 0, 280,  60, 350,  60};
    objLevel5[noOfObjLevel5++] = {750,  60, 60, 20, 0, 0, true, true, false, 0, 0, -200, 0, 570,  60, 750,  60};
    objLevel5[noOfObjLevel5++] = {900,  60, 60, 20, 0, 0, true, true, false, 0, 0, -200, 0, 700,  60, 900,  60};

  } else if (subLevelCount5 == 3) {
    // -------------------------------------------------------------------------
    // SUBLEVEL 3 – Mixed heights + fast platforms + sawblade
    // Walk to x >= 1000 to advance to sublevel 4
    // -------------------------------------------------------------------------

    // Ground base
    objLevel5[noOfObjLevel5++] = {0, 0, 1080, 80, 2, 0, true, false, false, 0, 0, -200, 0, 0, 0, 0, 0};


    // Orb just above starting platform
    objLevel5[noOfObjLevel5++] = {30, 80, 30, 30, 7, 0, true, false, false, 0, 0, -200, 0, 30, 80, 30, 80};

    // Fast Y-elevator – oscillates between y=20 and y=120
    objLevel5[noOfObjLevel5++] = {160, 60, 100, 20, 2, 0, true, false, true, 5, 1, -200, 0, 160, 60, 160, 120};

    // Wide horizontal slider – oscillates between x=320 and x=620
    objLevel5[noOfObjLevel5++] = {320, 90, 100, 20, 2, 0, true, false, true, 3, 0, -200, 0, 320, 90, 620, 90};

    // Y-elevator 2 – oscillates between y=20 and y=90
    objLevel5[noOfObjLevel5++] = {680, 20, 100, 20, 2, 0, true, false, true, 4, 1, -200, 0, 680, 20, 680, 90};

    // Final landing ledge (wide enough to walk off the right edge)
    objLevel5[noOfObjLevel5++] = {840, 100, 100, 20, 2, 0, true, false, false, 0, 0, -200, 0, 840, 100, 840, 100};

    // Sawblade patrolling the ground
    objLevel5[noOfObjLevel5++] = {110, 60, 45, 45, 3, 0, true, true, true, 5, 0, -200, 0, 110, 60, 820, 60};

    // Spikes
    objLevel5[noOfObjLevel5++] = {110, 60, 50, 20, 0, 0, true, true, false, 0, 0, -200, 0, 110, 60, 110, 60};
    objLevel5[noOfObjLevel5++] = {270, 60, 50, 20, 0, 0, true, true, false, 0, 0, -200, 0, 270, 60, 270, 60};
    objLevel5[noOfObjLevel5++] = {630, 60, 50, 20, 0, 0, true, true, false, 0, 0, -200, 0, 630, 60, 630, 60};

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
    objLevel5[noOfObjLevel5++] = {150, 120, 100, 20, 2, 0, true, false, true, 3, 0, -200, 0, 150, 120, 600, 120};

    // Y-elevator – oscillates between y=20 and y=100
    objLevel5[noOfObjLevel5++] = {585, 60, 110, 20, 2, 0, true, false, true, 4, 1, -200, 0, 585, 60, 585, 100};

    // Final platform (hero stands here to reach the door)
    objLevel5[noOfObjLevel5++] = {800, 100, 100, 20, 2, 0, true, false, false, 0, 0, -200, 0, 800, 100, 800, 100};

    // Exit door – hero must walk into this to complete Level 5
	objLevel5[noOfObjLevel5++] = { 1000, 60, 100, 100, 1, 0,
		true, false, false, 0, 0, 0,
		0, 1000, 60, 1000, 60 };

    // Sawblade 1: sweeps low across the ground gap
    objLevel5[noOfObjLevel5++] = {180, 120, 40, 45, 3, 0, true, true, true, 6, 0, -200, 0, 180, 120, 180, 120};

    // Sawblade 2: sweeps at mid-height (opposite direction)
    objLevel5[noOfObjLevel5++] = {830, 70, 45, 45, 3, 0, true, true, true, 5, 0, -200, 0, 830, 70, 830, 70};

    // Ground spikes
    objLevel5[noOfObjLevel5++] = {120, 60, 50, 20, 0, 0, true, true, false, 0, 0, -200, 0, 120, 60, 120, 60};
    objLevel5[noOfObjLevel5++] = {300, 60, 50, 20, 0, 0, true, true, false, 0, 0, -200, 0, 300, 60, 300, 60};
    objLevel5[noOfObjLevel5++] = {520, 60, 50, 20, 0, 0, true, true, false, 0, 0, -200, 0, 520, 60, 520, 60};
    objLevel5[noOfObjLevel5++] = {750, 60, 50, 20, 0, 0, true, true, false, 0, 0, -200, 0, 750, 60, 750, 60};
  }
}

#endif
