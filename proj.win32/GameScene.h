#pragma once
#include "cocos2d.h"
#include "GameView.h"
#include "GameController.h"

//游戏场景类，负责创建和管理游戏视图和控制器
class GameScene : public cocos2d::Layer {
public:
    //创建游戏场景
    static cocos2d::Scene* createScene();
    //游戏场景初始化，加载关卡配置并创建游戏视图和控制器
    virtual bool init();
    CREATE_FUNC(GameScene);

private:
    //游戏视图和控制器指针
    GameView* _gameView = nullptr;
    GameController* _gameController = nullptr;
};
