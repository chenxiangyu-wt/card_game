#include "GameScene.h"
#include "LevelConfigLoader.h"

USING_NS_CC;
//������Ϸ����
Scene* GameScene::createScene() {
    auto scene = Scene::create();
    auto layer = GameScene::create();
    scene->addChild(layer);
    return scene;
}
//��Ϸ������ʼ�������عؿ����ò�������Ϸ��ͼ�Ϳ�����
bool GameScene::init() {
    if (!Layer::init()) return false;

    auto config = LevelConfigLoader::loadFromFile("level_1.json");

    _gameView = GameView::createFromLevelConfig(config);
    this->addChild(_gameView);

    _gameController = new GameController();
    _gameController->bind(_gameView);
    _gameController->startLevel(config);

    return true;
}


