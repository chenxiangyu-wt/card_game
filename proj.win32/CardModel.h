#pragma once

//定义卡牌花色枚举
enum class CardSuit {
    CLUB, DIAMOND, HEART, SPADE
};

//卡牌模型结构体，包含牌面和花色
struct CardModel {
    int face;  // 1 - 13 (A - K)
    //花色，0 - 3 分别代表梅花、方块、红心、黑桃
    CardSuit suit;
    // 构造函数，初始化卡牌模型
    CardModel(int f, CardSuit s) : face(f), suit(s) {}
};
