#ifndef RINGLIST_H
#define RINGLIST_H

#include "headlist.h"
template <typename T>
class RingList :public HeadList<T>
{
public:
    RingList() : HeadList<T>() { pStop = pHead; };
    RingList(const RingList<T>& rlist);
    ~RingList();
    virtual void PushFront(const T& val, const int& key);
    virtual void PopFront();
    virtual void PushBack(const T& val, const int& key);
    virtual void PopBack();
    virtual const RingList& operator=(const RingList<T>& list);
    //virtual void PopBeforeCurr();
};

template <typename T>
RingList<T>::RingList(const RingList<T>& rlist) : HeadList<T>(rlist)
{
    if (pLast != nullptr)
    {
        pLast->pNext = pStop;
    }
}
template <typename T>
RingList<T>::~RingList()
{

}
template <typename T>
void RingList<T>::PushFront(const T& val, const int& key)
{
    HeadList<T>::PushFront(val, key);
    pLast->pNext = pStop;
}

template <typename T>
void RingList<T>::PopFront()
{
    HeadList<T>::PopFront();
    if (pLast != nullptr)
        pLast->pNext = pStop;
    
}
template <typename T>
void RingList<T>::PushBack(const T& val, const int& key)
{
    if (pFirst == nullptr)
    {
        PushFront(val, key);
        return;
    }
    HeadList<T>::PushBack(val, key);
    pLast->pNext = pStop;
}

template <typename T>
void RingList<T>::PopBack()
{
    if (pFirst == pLast)
    {
        PopFront();
        return;
    }
    HeadList<T>::PopBack();
    if(pLast!=nullptr)
        pLast->pNext = pStop;

}
template <typename T>
const RingList<T>& RingList<T>::operator=(const RingList<T>& rlist)
{
    HeadList<T>::operator=(rlist);
    if (pLast != nullptr)
        pLast->pNext = pStop;
    return *this;
}

#endif //!RINGLIST_H
