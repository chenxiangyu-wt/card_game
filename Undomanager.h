#pragma once
#include "UndoModel.h"
#include <stack>

// UndoManager 类，负责管理撤销记录
class UndoManager {
public:
    // 添加一条撤销记录
    void push(const UndoRecord& record);
    // 检查是否有可撤销的记录，返回判断结果
    bool canUndo() const;
    // 弹出最近的撤销记录，返回该记录
    UndoRecord pop();
    // 清空所有撤销记录
    void clear();


private:
    // 撤销记录栈
    std::stack<UndoRecord> _records;
};
