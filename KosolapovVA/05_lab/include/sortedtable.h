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
    SortedTable(int mxs);
    SortedTable(const SortedTable<TKey, TData>& srt);
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
            return a->key < b->key;
        });
}

template <typename TKey, typename TData>
SortedTable<TKey, TData>::SortedTable(int mxs) :ScanTable<TKey, TData>(mxs)
{
    for (int i = 0; i < max_sz; i++)
    {
        recs[i] = nullptr;
    }
}

template <typename TKey, typename TData>
SortedTable<TKey, TData>::SortedTable(const SortedTable<TKey, TData>& srt) 
    :SortedTable<TKey, TData>(srt.max_sz)
{
    count = srt.count;
    for (int i = 0; i < count; i++)
    {
        recs[i] = new TabRecord<TKey, TData>
            (srt.recs[i]->key, srt.recs[i]->data);
    }
}

template <typename TKey, typename TData>
SortedTable<TKey, TData>::SortedTable(const ScanTable<TKey, TData>& sct)
    : ScanTable<TKey, TData>(sct)
{
    this->sort();
}

template <typename TKey, typename TData>
TabRecord<TKey, TData>* SortedTable<TKey, TData>::Find(TKey _key)
{
    int left = 0, right = count - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (recs[mid]->key == _key)
        {
            curr_pos = mid;
            return recs[mid];
        }
        else if (recs[mid]->key < _key)
            left = mid + 1;
        else 
            right = mid - 1;
    }
    curr_pos = right;
    return nullptr;
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
        recs[i] = recs[i + 1];
    }
    count--;
}
template <typename TKey, typename TData>
void SortedTable<TKey, TData>::Insert(TabRecord<TKey, TData>* tr)
{
    if (count == 0) 
    {
        recs[0] = tr;
        count++;
        return;
    }
    if (IsFull())
        throw std::exception("Error: table is full");
    Find(tr->key);
    if (curr_pos == count) {
        recs[count] = tr;
        count++;
        return;
    }
    curr_pos++;
    for (int i = count; i > curr_pos; i--)
    {
        recs[i] = recs[i-1];
    }
    recs[curr_pos] = tr;
    count++;
}
#endif // !SORTEDTABLE_H
