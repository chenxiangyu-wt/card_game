#include "GameScene.h"
#include "LevelConfigLoader.h"

USING_NS_CC;
//创建游戏场景
Scene* GameScene::createScene() {
    auto scene = Scene::create();
    auto layer = GameScene::create();
    scene->addChild(layer);
    return scene;
}
//游戏场景初始化，加载关卡配置并创建游戏视图和控制器
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


