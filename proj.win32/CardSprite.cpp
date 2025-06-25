#include "CardSprite.h"

USING_NS_CC;

CardSprite* CardSprite::createCard(CardModel model) {
    CardSprite* sprite = new (std::nothrow) CardSprite();
    if (sprite && sprite->initWithCard(model)) {
        sprite->autorelease();
        return sprite;
    }
    delete sprite;
    return nullptr;
}
#include "CardSprite.h"
USING_NS_CC;

// 数值转文字：1 -> A, 11 -> J, 12 -> Q, 13 -> K
static std::string getFaceString(int face) {
    switch (face) {
    case 1:  return "A";
    case 11: return "J";
    case 12: return "Q";
    case 13: return "K";
    default: return std::to_string(face);
    }
}

bool CardSprite::initWithCard(CardModel model) {
    if (!Node::init()) return false;

    _model = model;
    const float margin = 20.0f;

    // 背景卡牌
    auto bg = Sprite::create("card_general.png");
    this->addChild(bg);
    this->setContentSize(bg->getContentSize());

    float w = bg->getContentSize().width;
    float h = bg->getContentSize().height;

    // 判断是否红色花色（heart, diamond）
    bool isRed = (model.suit == CardSuit::HEART || model.suit == CardSuit::DIAMOND);
    std::string colorPrefix = isRed ? "red" : "black";
    std::string faceStr = getFaceString(model.face);

    // 小数字左上角
    std::string smallNumFile = "small_" + colorPrefix + "_" + faceStr + ".png";
    auto smallNum = Sprite::create(smallNumFile);
    if (smallNum) {
        smallNum->setAnchorPoint(Vec2(0, 1));
        smallNum->setPosition(Vec2(-w / 2 + margin, h / 2 - margin));
        smallNum->setScale(0.6f);
        this->addChild(smallNum);
    }

    // 花色图标右上角
    std::string suitStr[] = { "club", "diamond", "heart", "spade" };
    std::string suitFile = suitStr[(int)model.suit] + std::string(".png");
    auto suit = Sprite::create(suitFile);
    if (suit) {
        suit->setAnchorPoint(Vec2(1, 1));
        suit->setPosition(Vec2(w / 2 - margin, h / 2 - margin));
        suit->setScale(0.6f);
        this->addChild(suit);
    }

    // 大数字中间
    std::string bigNumFile = "big_" + colorPrefix + "_" + faceStr + ".png";
    auto bigNum = Sprite::create(bigNumFile);
    if (bigNum) {
        bigNum->setPosition(Vec2(0, 0));
        bigNum->setScale(0.9f);
        this->addChild(bigNum);
    }

    return true;
}

CardModel CardSprite::getModel() const {
    return _model;
}