#pragma once
#include "../data/vectors.hpp"

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
        clothing Clothing;
        weapon Weapon;
    };
    itemtype type;
} item;

/* 
todo:
- add a way to access all items with the id
- create new ones without recompilation
*/