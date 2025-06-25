#include "LevelConfigLoader.h"
#include "json/document.h"
#include "json/filereadstream.h"
#include "platform/CCFileUtils.h"

USING_NS_CC;
using namespace rapidjson;

LevelConfig LevelConfigLoader::loadFromFile(const std::string& filename) {
    LevelConfig config;

    std::string content = FileUtils::getInstance()->getStringFromFile(filename);
    Document doc;
    doc.Parse(content.c_str());

    // Playfield
    const auto& pfArray = doc["Playfield"];
    for (SizeType i = 0; i < pfArray.Size(); ++i) {
        auto item = pfArray[i].GetObject();
        CardConfig card;
        card.face = item["CardFace"].GetInt();
        card.suit = item["CardSuit"].GetInt();
        card.position.x = item["Position"]["x"].GetFloat();
        card.position.y = item["Position"]["y"].GetFloat();
        config.playfieldCards.push_back(card);
    }

    // Stack
    const auto& stackArray = doc["Stack"];
    for (SizeType i = 0; i < stackArray.Size(); ++i) {
        auto item = stackArray[i].GetObject();
        CardConfig card;
        card.face = item["CardFace"].GetInt();
        card.suit = item["CardSuit"].GetInt();
        card.position = Vec2::ZERO;  // 不需要位置
        config.stackCards.push_back(card);
    }

    // BaseCard
    auto base = doc["BaseCard"].GetObject();
    config.baseCard.face = base["CardFace"].GetInt();
    config.baseCard.suit = base["CardSuit"].GetInt();
    config.baseCard.position = Vec2(540, 300);  // 固定位置

    return config;
}
