#pragma once
#include "LevelConfig.h"

// LevelConfigLoader �࣬������عؿ�����
class LevelConfigLoader {
public:
    // ����ĳ�ؿ������ã����������ƶѵĳ�ʼ����λ�ö�λ
    static LevelConfig loadFromFile(const std::string& filename);
};
