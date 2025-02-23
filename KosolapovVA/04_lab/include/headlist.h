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
        pHead->pNext = get_first();
        set_prev(pHead);
    }
    HeadList(const HeadList<T>& hlist);
    ~HeadList();
    virtual void PushFront(const T& val, const int& key);
    virtual void PushBack(const T& val, const int& key);
    virtual void PopBack();
    virtual void PopFront();
};
template <typename T>
HeadList<T>::HeadList(const HeadList<T>& hlist):List<T>(hlist)
{
    pHead = new TNode<T>(0, -1);
    pHead->pNext = get_first();
    if (get_curr() == get_first())
        set_prev(pHead);
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
    pHead->pNext = get_first();
    set_prev(pHead);
}

template <typename T>
void HeadList<T>::PushBack(const T& val, const int& key)
{
    List<T>::PushBack(val, key);
    pHead->pNext = get_first();
    set_prev(pHead);
}
 template <typename T>
 void HeadList<T>::PopFront()
 {
     List<T>::PopFront();
     pHead->pNext = get_first();
     set_prev(pHead);
 }
  template <typename T>
  void HeadList<T>::PopBack()
  {
      List<T>::PopBack();
      pHead->pNext = get_first();
      set_prev(pHead);
  }
#endif // !HEADLIST_H
