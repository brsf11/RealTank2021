#ifndef _REALTANK_H_
#define _REALTANK_H_

#include<stdint.h>

#include"Game.h"
#include"Asset.h"

#define ObjTypeNum 7

#define ObjType.black         0
#define ObjType.wall          1
#define ObjType.box           2
#define ObjType.grass         3
#define ObjType.tank_alliance 4
#define ObjType.tank_hostile  5
#define ObjType.bullet        6

static const uint16_t* AssetTab[ObjTypeNum];

void RealTank_GameInit(void);

#endif