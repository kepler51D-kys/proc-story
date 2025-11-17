#pragma once
#include "../data/vectors.hpp"

typedef enum {
    bodyPart_left_hand = 1,
    bodyPart_right_hand = 2,
    bodyPart_left_arm = 4,
    bodyPart_right_arm = 8,
    bodyPart_left_leg = 16,
    bodyPart_right_leg = 32,
    bodyPart_left_foot = 64,
    bodyPart_right_foot = 128,
    bodyPart_torso = 256,
    bodyPart_head = 512,
} bodyPart;

typedef struct {
    i32 dmg;
    i32 weight;
    i32 condition;

    u32 iconID;
    u32 modelID;
} weapon;

typedef struct {
    u16 positionOnBody;
    i32 insulation;
    i32 protection;
    i32 weight;
    i32 condition;

    u32 iconID;
    u32 modelID;
} clothing;

typedef enum {
    itemtype_clothing,
    itemtype_weapon,
} itemtype;

typedef struct {
    union {
        clothing;
        weapon;
    };
    itemtype type;
} item;

/* 
todo:
- add a way to access all items with the id
- create new ones without recompilation
*/