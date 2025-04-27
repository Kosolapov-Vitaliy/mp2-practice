#pragma once
#ifndef TAB_REC_H
#define TAB_REC_H
#include <iostream>

template <typename TKey, typename TData>
class TabRecord {
public:
    TKey key;
    TData* data;
    TabRecord(TKey _key, TData* _data) :
        key(_key), data(_data) {};
    TabRecord(const TabRecord<TKey, TData>& tr) :
        key(tr.key), data(tr.data) {};
};
#endif // !TAB_REC_H

