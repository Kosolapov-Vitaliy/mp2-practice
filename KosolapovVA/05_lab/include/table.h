#pragma once
#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <string>
#include "tab_rec.h"

template <typename TKey, typename TData>
class Table
{
protected:
    int max_sz;
    int curr_pos;
    int count;
public:
    Table(int maxsz);
    virtual TabRecord<TKey, TData>* Find(TKey key) = 0;
    virtual void Insert(TabRecord<TKey, TData>* tr) = 0;
    virtual void Remove(TKey key) = 0;

    //virtual TabRecord<TKey, TData>* GetCurr() const = 0;
    bool IsEmpty() const { return count == 0; }
    bool IsFull() const { return count == max_sz; }
    virtual bool Reset();
    virtual bool IsTabEnd();
    virtual void Next();
};

template <typename TKey, typename TData>
Table<TKey, TData>::Table(int maxsz) :curr_pos(0), count(0), max_sz(maxsz)
{
    if (maxsz < 0)
        throw std::exception("Error: maxsz must be greater 0");
}

template <typename TKey, typename TData>
bool Table<TKey, TData>::Reset()
{
    if (curr_pos == -1 && count == 0)
        return 1;
    curr_pos = 0;
    return 0;
}

template <typename TKey, typename TData>
bool Table<TKey, TData>::IsTabEnd()
{
    if (curr_pos == -1)
        return 1;
    return curr_pos==count;
}

template <typename TKey, typename TData>
void Table<TKey, TData>::Next()
{
    if (IsTabEnd())
        return throw std::exception("Error: table is ended");
    curr_pos ++;
}
#endif // !TABLE_H
