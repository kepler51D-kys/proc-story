#pragma once
#include "../data/vectors.hpp"
#include "item.hpp"
#include <vector>

typedef enum {
    body_left_hand = 1,
    body_right_hand = 2,
    body_left_arm = 4,
    body_right_arm = 8,
    body_left_leg = 16,
    body_right_leg = 32,
    body_left_foot = 64,
    body_right_foot = 128,
    body_torso = 256,
    body_head = 512,
} bodyPart;

typedef struct {
    v3 position;
    float health;
    std::vector<clothing> clothesPerBodyPart;
} player;