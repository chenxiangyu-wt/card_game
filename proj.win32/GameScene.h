#pragma once
#include "cocos2d.h"
#include "GameView.h"
#include "GameController.h"

//��Ϸ�����࣬���𴴽��͹�����Ϸ��ͼ�Ϳ�����
class GameScene : public cocos2d::Layer {
public:
    //������Ϸ����
    static cocos2d::Scene* createScene();
    //��Ϸ������ʼ�������عؿ����ò�������Ϸ��ͼ�Ϳ�����
    virtual bool init();
    CREATE_FUNC(GameScene);

private:
    //��Ϸ��ͼ�Ϳ�����ָ��
    GameView* _gameView = nullptr;
    GameController* _gameController = nullptr;
};
