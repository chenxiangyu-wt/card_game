#include "GameView.h"

USING_NS_CC;

GameView* GameView::createFromLevelConfig(const LevelConfig& config) {
    auto view = new GameView();
    if (view && view->init()) {
        view->autorelease();

        for (auto& cardData : config.playfieldCards) {
            auto card = CardSprite::createCard(CardModel(cardData.face, (CardSuit)cardData.suit));
            card->setPosition(cardData.position);
            view->addChild(card);
            view->_playfieldCards.push_back(card);
            view->bindCardClickEvent(card);
        }

        view->_baseCard = CardSprite::createCard(CardModel(config.baseCard.face, (CardSuit)config.baseCard.suit));
        view->_baseCard->setPosition(config.baseCard.position);
        view->addChild(view->_baseCard);

        float y = 200;
        for (auto& s : config.stackCards) {
            auto card = CardSprite::createCard(CardModel(s.face, (CardSuit)s.suit));
            card->setPosition(Vec2(900, y));
            view->addChild(card);
            view->_stackCards.push_back(card);
            y += 40;
        }

        auto undoLabel = Label::createWithSystemFont("Undo", "Arial", 32);
        auto undoItem = MenuItemLabel::create(undoLabel, [=](Ref*) {
            if (view->_onUndoClicked) view->_onUndoClicked();
            });
        auto visibleSize = Director::getInstance()->getVisibleSize();
        undoItem->setPosition(Vec2(60, visibleSize.height / 2));
        auto menu = Menu::create(undoItem, nullptr);
        menu->setPosition(Vec2::ZERO);
        view->addChild(menu, 100);

        auto stackListener = EventListenerTouchOneByOne::create();
        stackListener->setSwallowTouches(true);
        stackListener->onTouchBegan = [=](Touch* t, Event*) {
            Rect area(850, 150, 150, 300);
            if (area.containsPoint(t->getLocation()) && view->_onStackClicked) {
                view->_onStackClicked();
                return true;
            }
            return false;
            };
        view->_eventDispatcher->addEventListenerWithSceneGraphPriority(stackListener, view);

        return view;
    }
    delete view;
    return nullptr;
}

void GameView::setOnPlayfieldCardClicked(std::function<void(CardSprite*)> cb) {
    _onPlayfieldCardClicked = cb;
}
void GameView::setOnStackClicked(std::function<void()> cb) {
    _onStackClicked = cb;
}
void GameView::setOnUndoClicked(std::function<void()> cb) {
    _onUndoClicked = cb;
}

void GameView::bindCardClickEvent(CardSprite* card) {
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [=](Touch* t, Event*) {
        if (card->getBoundingBox().containsPoint(t->getLocation())) {
            if (_onPlayfieldCardClicked) _onPlayfieldCardClicked(card);
            return true;
        }
        return false;
        };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, card);
}

void GameView::updateBaseCard(CardSprite* newCard) {
    if (_baseCard) removeBaseCard();
    _baseCard = newCard;
    _baseCard->setPosition(Vec2(540, 300));
    this->addChild(_baseCard);
}
void GameView::removeBaseCard() {
    if (_baseCard) {
        _baseCard->removeFromParent();
        _baseCard = nullptr;
    }
}
void GameView::addCardToPlayfield(CardSprite* card) {
    _playfieldCards.push_back(card);
    bindCardClickEvent(card);
    this->addChild(card);
}
void GameView::addCardToStack(CardSprite* card) {
    _stackCards.push_back(card);
    this->addChild(card);
}

CardSprite* GameView::getBaseCard() { return _baseCard; }
std::vector<CardSprite*>& GameView::getPlayfieldCards() { return _playfieldCards; }
std::vector<CardSprite*>& GameView::getStackCards() { return _stackCards; }

void GameView::updateBaseCardByModel(const CardModel& model) {
    removeBaseCard();
    _baseCard = CardSprite::createCard(model);
    _baseCard->setPosition(Vec2(540, 300));
    this->addChild(_baseCard);
}


