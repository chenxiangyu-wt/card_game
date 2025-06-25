#pragma once
#include "CardSprite.h"

// ��������ö��
enum class UndoType {
    MOVE_FROM_PLAYFIELD,  // ��������ƥ�䵽 base
    DRAW_FROM_STACK       // �ӱ��öѳ�һ���Ƶ� base
};
// ������¼�ṹ��
struct UndoRecord {
    //��¼��ǰ����������
    UndoType type;
    //ԭ��������
    CardModel model;
    //���ƶ��Ŀ������ݣ����������öѵĿ��ƣ�
    CardModel playCardModel;
    //�������ƵĿռ�λ��
    cocos2d::Vec2 fromPos;
    // ���캯������ʼ��������¼
    UndoRecord(UndoType t, const CardModel& m, const CardModel& playM, const cocos2d::Vec2& pos)
        : type(t), model(m), playCardModel(playM), fromPos(pos) {
    }
};
