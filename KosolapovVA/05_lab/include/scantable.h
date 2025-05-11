#pragma once
#ifndef SCANTABLE_H
#define SCANTABLE_H

#include "table.h"

template <typename TKey, typename TData>
class ScanTable : public Table<TKey, TData> {
protected:
    TabRecord<TKey, TData>** recs;
public:
    ScanTable(int maxsize);
    ScanTable(const ScanTable<TKey, TData>& st);
    ~ScanTable();
    virtual TabRecord<TKey, TData>* Find(TKey key);
    virtual void Insert(TabRecord<TKey, TData>* tr);
    virtual void Remove(TKey key);
    virtual TabRecord<TKey, TData>* GetCurr() const { return recs[curr_pos]; };
};

template <typename TKey, typename TData>
ScanTable<TKey, TData>::ScanTable(int msz) : Table<TKey, TData>(msz)
{
    recs = new TabRecord<TKey, TData>* [msz];
    for (int i = 0; i < msz; i++) {
        recs[i] = nullptr;
    }
}

template <typename TKey, typename TData>
ScanTable<TKey, TData>::ScanTable(const ScanTable<TKey, TData>& std)
    : ScanTable(std.max_sz)
{
    this->count = std.count;
    for (int i = 0; i < this->count; i++)
    {
        this->recs[i] = new TabRecord<TKey, TData>
            (std.recs[i]->key, std.recs[i]->data);
    }
}

template <typename TKey, typename TData>
ScanTable<TKey, TData>::~ScanTable()
{
    for (int i = 0; i < this->count; i++)
        delete this->recs[i];
    delete[] recs;
}

template <typename TKey, typename TData>
TabRecord<TKey, TData>* ScanTable<TKey, TData>::Find(TKey k)
{
    for (int i = 0; i < count; i++)
    {
        if (recs[i]->key == k)
        {
            curr_pos = i;
            return recs[i];
        }
    }
    return nullptr;
}

template <typename TKey, typename TData>
void ScanTable<TKey, TData>::Remove(TKey key)
{
    TabRecord<TKey, TData>* rec = Find(key);
    if (rec == nullptr)
        throw std::exception("Error: the key not found in this table");
    delete rec;
    recs[curr_pos] = recs[--count];
}
template <typename TKey, typename TData>
void ScanTable<TKey, TData>::Insert(TabRecord<TKey, TData>* trec)
{
    if (IsFull())
        throw std::exception("Error: table is full");
    recs[count++] = trec;
}
#endif // !SCANTABLE_H
