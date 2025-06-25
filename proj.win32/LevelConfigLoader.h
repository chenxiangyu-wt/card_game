#pragma once
#include "LevelConfig.h"

// LevelConfigLoader 类，负责加载关卡配置
class LevelConfigLoader {
public:
    // 加载某关卡的配置，进行三个牌堆的初始化和位置定位
    static LevelConfig loadFromFile(const std::string& filename);
};
