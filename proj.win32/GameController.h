#pragma once
#include "GameView.h"
#include "UndoManager.h"
#include "LevelConfig.h"

// GameController 类，负责处理游戏逻辑和用户交互
class GameController {
public:
	// 绑定游戏视图
	void bind(GameView* view);
	// 开始新关卡
	void startLevel(const LevelConfig& config);
	// 处理主牌区卡牌点击事件
	void onPlayfieldCardClicked(CardSprite* card);
	// 处理备用堆卡牌点击事件
	void onStackCardClicked();
	// 撤销上一步操作
	void undoLastMove();

private:
	// 游戏视图指针
	GameView* _view = nullptr;
	//撤销管理器实例
	UndoManager _undoManager;
	//检查是否游戏结束
	void checkGameResult();
	// 检查是否可以匹配任意卡牌，返回判断结果
	bool canMatchAnyCardWith(int baseFace);
};
