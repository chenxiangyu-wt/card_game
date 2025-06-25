#include "UndoManager.h"

void UndoManager::push(const UndoRecord& record) {
    _records.push(record);
}

bool UndoManager::canUndo() const {
    return !_records.empty();
}

UndoRecord UndoManager::pop() {
    UndoRecord record = _records.top();
    _records.pop();
    return record;
}
void UndoManager::clear() {
    while (!_records.empty()) _records.pop();
}

