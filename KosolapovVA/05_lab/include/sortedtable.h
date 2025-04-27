#pragma once
#ifndef SORTEDTABLE_H
#define SORTEDTABLE_H

#include "scantable.h"
#include <algorithm>

template <typename TKey, typename TData>
class SortedTable :public ScanTable<TKey, TData>
{
protected:
    void sort();
public:
    SortedTable(int mxs) :ScanTable<TKey,TData>(mxs) {};
    SortedTable(const SortedTable<TKey, TData>& srt) :ScanTable<TKey, TData>(srt) {};
    SortedTable(const ScanTable<TKey, TData>& sct);
    TabRecord<TKey, TData>* Find(TKey key);
    void Remove(TKey key);
    void Insert(TabRecord<TKey, TData>* rec);
};

template <typename TKey, typename TData>
void SortedTable<TKey, TData>::sort()
{
    std::sort(recs, recs + count, 
        [](TabRecord<TKey, TData>* a, TabRecord<TKey, TData>* b)
        {
            return a.key < b.key;
        });
}

template <typename TKey, typename TData>
SortedTable<TKey, TData>::SortedTable(const ScanTable<TKey, TData>& sct)
    : ScanTable<TKey, TData>(sct)
{
    this->sort();
}

template <typename TKey, typename TData>
TabRecord<TKey, TData>* SortedTable<TKey, TData>::Find(TKey key)
{
    int left = 0, right = count - 1;
    TabRecord<TKey, TData> res = nullptr;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (recs[mid]->key == key)
        {
            left = mid + 1;
            right = mid;
            res = recs[mid];
        }
        else if (recs[mid]->key < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    curr_pos = right;
    return answ;
}

template <typename TKey, typename TData>
void SortedTable<TKey, TData>::Remove(TKey key)
{
    TabRecord<TKey, TData>* rec = Find(key);
    if (rec == nullptr)
        throw std::exception("Error: the key not found in this table");
    delete rec;
    for (int i = curr_pos; i < count; i++)
    {
        recs[i]=recs[i+1]
    }
    count--;
}
template <typename TKey, typename TData>
void SortedTable<TKey, TData>::Insert(TabRecord<TKey, TData>* trec)
{
    if (count == 0) 
    {
        recs[0] = tr;
        count++;
        return;
    }
    if (IsFull())
        throw std::exception("Error: table is full");
    Find(trec->key);
    for (int i = count - 1; i > curr_pos; i--)
    {
        recs[i + 1] = recs[i];
    }
    count++;
    recs[curr_pos] = trec;
}
#endif // !SORTEDTABLE_H
