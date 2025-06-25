#pragma once
#include "CardSprite.h"

// 撤销类型枚举
enum class UndoType {
    MOVE_FROM_PLAYFIELD,  // 从主牌区匹配到 base
    DRAW_FROM_STACK       // 从备用堆抽一张牌到 base
};
// 撤销记录结构体
struct UndoRecord {
    //记录当前撤销的类型
    UndoType type;
    //原卡牌内容
    CardModel model;
    //被移动的卡牌内容（主牌区或备用堆的卡牌）
    CardModel playCardModel;
    //撤销卡牌的空间位置
    cocos2d::Vec2 fromPos;
    // 构造函数，初始化撤销记录
    UndoRecord(UndoType t, const CardModel& m, const CardModel& playM, const cocos2d::Vec2& pos)
        : type(t), model(m), playCardModel(playM), fromPos(pos) {
    }
};
