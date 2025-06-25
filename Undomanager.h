#pragma once
#include "UndoModel.h"
#include <stack>

// UndoManager �࣬�����������¼
class UndoManager {
public:
    // ���һ��������¼
    void push(const UndoRecord& record);
    // ����Ƿ��пɳ����ļ�¼�������жϽ��
    bool canUndo() const;
    // ��������ĳ�����¼�����ظü�¼
    UndoRecord pop();
    // ������г�����¼
    void clear();


private:
    // ������¼ջ
    std::stack<UndoRecord> _records;
};
