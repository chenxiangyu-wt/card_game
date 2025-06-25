#pragma once
#include "cocos2d.h"

//卡牌模型结构体，包含牌面和花色。包含位置信息
struct CardConfig {
    // 牌面值，1~13
    int face;  // 1~13
    // 花色，0~3 分别代表梅花、方块、红心、黑桃
    int suit;  // 0~3
    //卡牌位置，用于主牌堆
    cocos2d::Vec2 position;
};

// LevelConfig 结构体，包含关卡的三个牌堆信息
struct LevelConfig {
    // 主牌区的卡牌配置
    std::vector<CardConfig> playfieldCards;
    // 备用堆的卡牌配置
    std::vector<CardConfig> stackCards;
    //底牌
    CardConfig baseCard;
};
