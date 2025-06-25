#pragma once
#include "cocos2d.h"
#include "CardSprite.h"
#include "LevelConfig.h"

// ��Ϸ��ͼ�࣬������ʾ��Ϸ����ʹ����û�����
class GameView : public cocos2d::Node {
public:
    // ������Ϸ��ͼ��ʹ�ùؿ����ó�ʼ�������ش����� GameView ����
    static GameView* createFromLevelConfig(const LevelConfig& config);
    //���õ�����������ƵĻص�����
    void setOnPlayfieldCardClicked(std::function<void(CardSprite*)> cb);
    // ���õ����ѡ�������ƵĻص�����
    void setOnStackClicked(std::function<void()> cb);
    //���õ��������ť�Ļص�����
    void setOnUndoClicked(std::function<void()> cb);
    // ���µ���
    void updateBaseCard(CardSprite* newCard);
    // �Ƴ���ǰ����
    void removeBaseCard();
    // ��ӿ��Ƶ�������
    void addCardToPlayfield(CardSprite* card);
    // ��ӿ��Ƶ����ö�
    void addCardToStack(CardSprite* card);
    // ���µ������ݣ����� CardModel ����
    void updateBaseCardByModel(const CardModel& model);

    // ��ȡ��ǰ����
    CardSprite* getBaseCard();
    // ��ȡ�����������п���
    std::vector<CardSprite*>& getPlayfieldCards();
    // ��ȡ���öѵ����п���
    std::vector<CardSprite*>& getStackCards();

private:
    //����ָ��
    CardSprite* _baseCard = nullptr;
    // �����������п���
    std::vector<CardSprite*> _playfieldCards;
    //��ѡ���������п���
    std::vector<CardSprite*> _stackCards;
    //���������Ƶ���¼��ص�
    std::function<void(CardSprite*)> _onPlayfieldCardClicked;
    // ��ѡ��������¼��ص�
    std::function<void()> _onStackClicked;
    // ������ť����¼��ص�
    std::function<void()> _onUndoClicked;
    // �󶨿��Ƶ���¼�
    void bindCardClickEvent(CardSprite* card);
};
