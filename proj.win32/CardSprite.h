#pragma once
#include "cocos2d.h"
#include "CardModel.h"

//���ƾ����࣬�̳��� cocos2d::Node�������͹����Ƶ���ʾ�ͽ���
class CardSprite : public cocos2d::Node {
public:
    // ����һ���µ� CardSprite ʵ����ʹ��ָ���� CardModel ��ʼ��
    static CardSprite* createCard(CardModel model);
    //����cardmodel����
    CardModel getModel() const;

private:
    // ���캯������ʼ�����ƾ���
    CardSprite() : _model(1, CardSuit::CLUB) {}
    //����ģ��
    CardModel _model;
    // ��ʼ����������ȡ����ģ�Ͳ�������ʾ����
    bool initWithCard(CardModel model);
};
