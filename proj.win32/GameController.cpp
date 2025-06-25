#include "GameController.h"

void GameController::bind(GameView* view) {
    _view = view;
    _view->setOnPlayfieldCardClicked([=](CardSprite* c) { onPlayfieldCardClicked(c); });
    _view->setOnStackClicked([=]() { onStackCardClicked(); });
    _view->setOnUndoClicked([=]() { undoLastMove(); });
}


void GameController::onPlayfieldCardClicked(CardSprite* card) {
    auto base = _view->getBaseCard();
    if (!base) return;

    if (abs(card->getModel().face - base->getModel().face) == 1) {
        UndoRecord record(UndoType::MOVE_FROM_PLAYFIELD, base->getModel(), card->getModel(), card->getPosition());
        _undoManager.push(record);

        auto moveTo = cocos2d::MoveTo::create(0.3f, base->getPosition());
        auto callback = cocos2d::CallFunc::create([=]() {
            _view->removeBaseCard();

            _view->updateBaseCardByModel(card->getModel());

            auto& list = _view->getPlayfieldCards();
            list.erase(std::remove(list.begin(), list.end(), card), list.end());

            card->removeFromParent();

            checkGameResult();
            });
        card->runAction(cocos2d::Sequence::create(moveTo, callback, nullptr));
    }
}

void GameController::onStackCardClicked() {
    auto& stack = _view->getStackCards();
    if (stack.empty()) return;

    auto card = stack.back();
    stack.pop_back();

    UndoRecord record{
        UndoType::DRAW_FROM_STACK,
        _view->getBaseCard()->getModel(),
        card->getModel(),
        card->getPosition()
    };
    _undoManager.push(record);

    auto moveTo = cocos2d::MoveTo::create(0.3f, _view->getBaseCard()->getPosition());
    auto callback = cocos2d::CallFunc::create([=]() {
        _view->removeBaseCard();
        _view->updateBaseCardByModel(card->getModel()); // 不使用 card 节点本体
        card->removeFromParent();                       // 从场景中移除
        checkGameResult();
        });

    card->runAction(cocos2d::Sequence::create(moveTo, callback, nullptr));
}


void GameController::undoLastMove() {
    if (!_undoManager.canUndo()) return;
    auto r = _undoManager.pop();
    _view->removeBaseCard();

    if (r.type == UndoType::MOVE_FROM_PLAYFIELD) {
        auto restored = CardSprite::createCard(r.playCardModel);
        restored->setPosition(r.fromPos);
        _view->addCardToPlayfield(restored);
        _view->updateBaseCard(CardSprite::createCard(r.model));
    }
    else if (r.type == UndoType::DRAW_FROM_STACK) {
        auto restored = CardSprite::createCard(r.playCardModel);
        restored->setPosition(r.fromPos);
        _view->addCardToStack(restored);
        _view->updateBaseCard(CardSprite::createCard(r.model));
    }

    checkGameResult();
}

bool GameController::canMatchAnyCardWith(int baseFace) {
    for (auto c : _view->getPlayfieldCards()) {
        if (abs(c->getModel().face - baseFace) == 1) return true;
    }
    return false;
}

void GameController::checkGameResult() {
    if (_view->getPlayfieldCards().empty()) {
        cocos2d::MessageBox("You win!", "Game");
        return;
    }
    if (!canMatchAnyCardWith(_view->getBaseCard()->getModel().face) && _view->getStackCards().empty()) {
        cocos2d::MessageBox("You lose!", "Game");
    }
}
void GameController::startLevel(const LevelConfig& config) {
    _undoManager.clear();          // 清空撤回记录
    checkGameResult();            // 初始状态判断是否立即胜负
}

