#pragma once

//���忨�ƻ�ɫö��
enum class CardSuit {
    CLUB, DIAMOND, HEART, SPADE
};

//����ģ�ͽṹ�壬��������ͻ�ɫ
struct CardModel {
    int face;  // 1 - 13 (A - K)
    //��ɫ��0 - 3 �ֱ����÷�������顢���ġ�����
    CardSuit suit;
    // ���캯������ʼ������ģ��
    CardModel(int f, CardSuit s) : face(f), suit(s) {}
};
