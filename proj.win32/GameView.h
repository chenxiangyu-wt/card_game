#pragma once
#include "cocos2d.h"
#include "CardSprite.h"
#include "LevelConfig.h"

// 游戏视图类，负责显示游戏界面和处理用户交互
class GameView : public cocos2d::Node {
public:
    // 创建游戏视图，使用关卡配置初始化，返回创建的 GameView 对象
    static GameView* createFromLevelConfig(const LevelConfig& config);
    //设置点击主牌区卡牌的回调函数
    void setOnPlayfieldCardClicked(std::function<void(CardSprite*)> cb);
    // 设置点击备选牌区卡牌的回调函数
    void setOnStackClicked(std::function<void()> cb);
    //设置点击撤销按钮的回调函数
    void setOnUndoClicked(std::function<void()> cb);
    // 更新底牌
    void updateBaseCard(CardSprite* newCard);
    // 移除当前底牌
    void removeBaseCard();
    // 添加卡牌到主牌区
    void addCardToPlayfield(CardSprite* card);
    // 添加卡牌到备用堆
    void addCardToStack(CardSprite* card);
    // 更新底牌内容，根据 CardModel 更新
    void updateBaseCardByModel(const CardModel& model);

    // 获取当前底牌
    CardSprite* getBaseCard();
    // 获取主牌区的所有卡牌
    std::vector<CardSprite*>& getPlayfieldCards();
    // 获取备用堆的所有卡牌
    std::vector<CardSprite*>& getStackCards();

private:
    //底牌指针
    CardSprite* _baseCard = nullptr;
    // 主牌区的所有卡牌
    std::vector<CardSprite*> _playfieldCards;
    //备选牌区的所有卡牌
    std::vector<CardSprite*> _stackCards;
    //主牌区卡牌点击事件回调
    std::function<void(CardSprite*)> _onPlayfieldCardClicked;
    // 备选牌区点击事件回调
    std::function<void()> _onStackClicked;
    // 撤销按钮点击事件回调
    std::function<void()> _onUndoClicked;
    // 绑定卡牌点击事件
    void bindCardClickEvent(CardSprite* card);
};
