#ifndef HEADLIST_H
#define HEADLIST_H

#include "list.h"

template <typename T>
class HeadList :public List<T>
{
protected:
    TNode<T>* pHead;
public:
    HeadList() :List<T>()
    {
        pHead = new TNode<T>(T(), -1);
        pHead->pNext = pFirst;
        pPrev=pHead;
        pStop = nullptr;
    }
    HeadList(const HeadList<T>& hlist);
    ~HeadList();
    virtual void PushFront(const T& val, const int& key);
    virtual void PopFront();
    virtual const HeadList& operator=(const HeadList<T>& list);
};

template <typename T>
HeadList<T>::HeadList(const HeadList<T>& hlist):List<T>(hlist)
{
    pHead = new TNode<T>(T(), -1);
    pHead->pNext = pFirst;
    pCurr = pFirst;
    pPrev = pHead;
}
template <typename T>
HeadList<T>::~HeadList()
{
    delete pHead;
    pHead = nullptr;
}
template <typename T>
void HeadList<T>::PushFront(const T& val, const int& key)
{
    List<T>::PushFront(val,key);
    pHead->pNext = pFirst;
    pPrev = pHead;
}

 template <typename T>
 void HeadList<T>::PopFront()
 {
     List<T>::PopFront();
     pHead->pNext = pFirst;
     pPrev = pHead;
 }

 template <typename T>
 const HeadList<T>& HeadList<T>::operator=(const HeadList<T>& hlist)
 {
     List<T>::operator=(hlist);
     pHead = new TNode<T>(T(), -1);
     pHead->pNext = pFirst;
     pCurr = pFirst;
     pPrev = pHead;
     return *this;
 }
#endif // !HEADLIST_H
