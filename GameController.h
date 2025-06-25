#pragma once
#include "GameView.h"
#include "UndoManager.h"
#include "LevelConfig.h"

// GameController �࣬��������Ϸ�߼����û�����
class GameController {
public:
	// ����Ϸ��ͼ
	void bind(GameView* view);
	// ��ʼ�¹ؿ�
	void startLevel(const LevelConfig& config);
	// �������������Ƶ���¼�
	void onPlayfieldCardClicked(CardSprite* card);
	// �����öѿ��Ƶ���¼�
	void onStackCardClicked();
	// ������һ������
	void undoLastMove();

private:
	// ��Ϸ��ͼָ��
	GameView* _view = nullptr;
	//����������ʵ��
	UndoManager _undoManager;
	//����Ƿ���Ϸ����
	void checkGameResult();
	// ����Ƿ����ƥ�����⿨�ƣ������жϽ��
	bool canMatchAnyCardWith(int baseFace);
};
