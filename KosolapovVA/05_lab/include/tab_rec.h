#pragma once
#ifndef TAB_REC_H
#define TAB_REC_H
#include <iostream>

template <typename TKey, typename TData>
class TabRecord {
public:
    TKey key;
    TData* data;
    TabRecord(TKey t_key, TData* t_data) :
        key(t_key), data(t_data) {};
    TabRecord(const TabRecord<TKey, TData>& tr) :
        key(tr.key), data(tr.data) {};
};
#endif // !TAB_REC_H

