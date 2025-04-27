#pragma once
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "table.h"
#include <functional>

template <typename TKey, typename TData>
class HashTable :public Table<TKey, TData>
{
protected:
    int HashFunc(const TKey key);
public:
    HashTable(int mxs) :Table<TKey, TData>(mxs) {};
};

template <typename TKey, typename TData>
int HashTable<TKey, TData>::HashFunc(const TKey key)
{
    std::hash<TKey> hasher;
    return hasher(key) % max_sz;
}
#endif // !HASHTABLE_H
