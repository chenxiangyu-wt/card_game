#pragma once
#include "cocos2d.h"

//����ģ�ͽṹ�壬��������ͻ�ɫ������λ����Ϣ
struct CardConfig {
    // ����ֵ��1~13
    int face;  // 1~13
    // ��ɫ��0~3 �ֱ����÷�������顢���ġ�����
    int suit;  // 0~3
    //����λ�ã��������ƶ�
    cocos2d::Vec2 position;
};

// LevelConfig �ṹ�壬�����ؿ��������ƶ���Ϣ
struct LevelConfig {
    // �������Ŀ�������
    std::vector<CardConfig> playfieldCards;
    // ���öѵĿ�������
    std::vector<CardConfig> stackCards;
    //����
    CardConfig baseCard;
};
