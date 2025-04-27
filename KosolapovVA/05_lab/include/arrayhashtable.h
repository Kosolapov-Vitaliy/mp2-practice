#pragma once
#ifndef ARRAYHASHTABLE_H
#define ARRAYHASHTABLE_H

#include "hashtable.h"

template <typename TKey, typename TData>
class ArrayHashTable : public HashTable<TKey, TData>
{
private:
    TabRecord<TKey, TData>** recs;
    TabRecord<TKey, TData>* pMark;
    int freePos;
    int hashStep;
    int HashFunc_2(int pos) { return (pos + hashStep) % max_sz; };
public:
    ArrayHashTable(int mxs, int hStep);
    ArrayHashTable(const ArrayHashTable<TKey, TData>& aht);
    ~ArrayHashTable();
    TabRecord<TKey, TData>* Find(TKey key);
    void Insert(TabRecord<TKey, TData>* rec);
    void Remove(TKey key);
    void Next();
    bool IsTabEnd();
    bool Reset();
};

template <typename TKey, typename TData>
ArrayHashTable<TKey, TData>::ArrayHashTable(int mxs, int hStep) :
    HashTable<TKey, TData>(mxs), hashStep(hStep), freePos(0)
{
    recs = new TabRecord<TKey, TData>* [mxs];
    pMark = new TabRecord<TKey, TData>(TKey(), nullptr);
    for (int i = 0; i < mxs; i++)
    {
        recs[i] = nullptr;
    }
}

template <typename TKey, typename TData>
ArrayHashTable<TKey, TData>::ArrayHashTable
(const ArrayHashTable<TKey, TData>& aht) :
    ArrayHashTable<TKey, TData>(aht.max_sz, aht.hashStep)
{
    count = aht.count;
    for (int i = 0; i < max_sz; i++)
    {
        if (aht.recs[i] == nullptr) { continue; }
        recs[i] = new TabRecord<TKey, TData>(aht.recs[i]->key, aht.recs[i]->data);
    }
}

template <typename TKey, typename TData>
ArrayHashTable<TKey, TData>::~ArrayHashTable()
{
    for (int i = 0; i < max_sz; i++)
    {
        if (recs[i] == pMark) { continue; }
        delete recs[i];
    }
    delete[] recs;
    delete pMark;
}

template <typename TKey, typename TData>
TabRecord<TKey, TData>* ArrayHashTable<TKey, TData>::Find(TKey key)
{
    TabRecord<TKey, TData>* res = nullptr;
    curr_pos = HashFunc(key);
    for (int i = 0; i < max_sz; i++)
    {
        if (recs[curr_pos] == nullptr)
            break;
        else if (recs[curr_pos]->key == key)
        {
            res = recs[curr_pos];
            break;
        }
        else
            curr_pos = HashFunc_2(curr_pos);
    }
    return res;
}

template <typename TKey, typename TData>
void ArrayHashTable<TKey, TData>::Insert(TabRecord<TKey, TData>* rec)
{
    if (IsFull())
        throw std::exception("Error: table is full");
    curr_pos = HashFunc(rec->key);
    count++;
    for (int i = 0; i < max_sz; i++)
    {
        if (recs[curr_pos] == nullptr)
        {
            recs[curr_pos] = rec;
            return;
        }
        else if (recs[curr_pos] == pMark)
        {
            recs[curr_pos] = rec;
            return;
        }
        else
        {
            curr_pos = HashFunc_2(curr_pos);
        }
    }
}

template <typename TKey, typename TData>
void ArrayHashTable<TKey, TData>::Remove(TKey key)
{
    TabRecord<TKey, TData>* rec = Find(key);
    if (rec == nullptr)
        throw std::exception("Error: the key not found in this table");
    delete rec;
    recs[curr_pos] = pMark;
    count--;
}

template <typename TKey, typename TData>
void ArrayHashTable<TKey, TData>::Next()
{
    curr_pos++;
    while (curr_pos != max_sz &&
        (recs[curr_pos] == nullptr ||recs[curr_pos]->key == pMark->key))
    {
        curr_pos++;
    }
}

template <typename TKey, typename TData>
bool ArrayHashTable<TKey, TData>::Reset()
{
    curr_pos = -1;
    Next();
    return 0;
}

template <typename TKey, typename TData>
bool ArrayHashTable<TKey, TData>::IsTabEnd()
{
    if (curr_pos == -1)
        return 1;
    return curr_pos == max_sz;
}
#endif // !ARRAYHASHTABLE_H
