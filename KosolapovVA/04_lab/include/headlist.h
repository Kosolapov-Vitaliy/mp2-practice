#ifndef HEADLIST_H
#define HEADLIST_H

#include "list.h"

template <typename T>
class HeadList :public List<T>
{
private:
    TNode<T>* pHead;
public:
    HeadList() :List<T>()
    {
        pHead = new TNode<T>(0, -1);
        pHead->pNext = pFirst;
        pPrev = pHead;
    }
    HeadList(const HeadList<T>& hlist);
    ~HeadList();
    virtual void PushFront(const T& val, const int& key);
    virtual void PushBack(const T& val, const int& key);
};
template <typename T>
HeadList<T>::HeadList(const HeadList<T>& hlist):List<T>(hlist)
{
    pHead = new TNode<T>(0, -1);
    pHead->pNext = pFirst;
    if (pCurr == pFirst)
        pPrev = pHead;
}
template <typename T>
HeadList<T>::~HeadList()
{
    delete pHead;
}
template <typename T>
void HeadList<T>::PushFront(const T& val, const int& key)
{
    List<T>::PushFront(val,key);
    pHead->pNext = pFirst;
    pPrev = pHead;
}

template <typename T>
void HeadList<T>::PushBack(const T& val, const int& key)
{
    List<T>::PushBack(val, key);
    pHead->pNext = pFirst;
    pPrev = pHead;
}


#endif // !HEADLIST_H
