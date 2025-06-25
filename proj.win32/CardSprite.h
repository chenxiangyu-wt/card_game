#pragma once
#include "cocos2d.h"
#include "CardModel.h"

//卡牌精灵类，继承自 cocos2d::Node，创建和管理卡牌的显示和交互
class CardSprite : public cocos2d::Node {
public:
    // 创建一个新的 CardSprite 实例，使用指定的 CardModel 初始化
    static CardSprite* createCard(CardModel model);
    //返回cardmodel变量
    CardModel getModel() const;

private:
    // 构造函数，初始化卡牌精灵
    CardSprite() : _model(1, CardSuit::CLUB) {}
    //卡牌模型
    CardModel _model;
    // 初始化函数，读取卡牌模型并设置显示内容
    bool initWithCard(CardModel model);
};
