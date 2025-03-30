#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
template <typename T>
struct TNode
{
    TNode* pNext;
    T data;
    int key;
    TNode() :data(0), key(0) pNext(nullptr) {}
    TNode(const T& x, const int& y) : data(x), key(y), pNext(nullptr) {}
    TNode(const TNode& nd):data(nd.data), key(nd.key), pNext(nd.pNext){}
    TNode(const TNode* nd):data(nd.data), key(nd.key), pNext(nd.pNext) {}
};

template <typename T>
class List
{
private:
protected:
    TNode<T>* pFirst;
    TNode<T>* pCurr;
    TNode<T>* pPrev;
    TNode<T>* pLast;
    TNode<T>* pStop;
public:
    List(): pFirst(nullptr), pCurr(nullptr), pPrev(nullptr), pLast(nullptr), pStop(nullptr) {};
    List(const List<T>& list);
    ~List();
    virtual void DelList();
    virtual const List& operator=(const List<T>& list);
    bool operator==(const List<T>& list) const;
    int GetSZ() const;
    virtual void PushFront(const T& val, const int& key);
    virtual void PushBack(const T& val, const int& key);
    virtual void PopBack();
    virtual void PopFront();
    bool IsEmpty() const;
    TNode<T>* SearchKey(const int& key);
    T GetFirst() const { return pFirst->data; };
    T GetCurr() const { return pCurr->data; };
    void PushAfterKey(const T& val, const int& key, int ch_key);
    void PushBeforeKey(const T& val, const int& key, int ch_key);
    void Remove(const int& key);
    virtual void Next();
    void Reset() { pCurr = pFirst; pPrev = pStop; };
    bool Is_End() { return (pCurr == pStop); };
    void PushAfterCurr(const T& val, const int& key);
    void PushBeforeCurr(const T& val, const int& key);
    void PopAftterCurr();
    void PopBeforeCurr();
    
};


template <typename T>
List<T>::List(const List<T>& list) : pFirst(nullptr), pCurr(nullptr), pPrev(nullptr), pLast(nullptr),pStop(nullptr)
{
    if (list.pFirst == nullptr)
        return;
    pFirst = new TNode<T>(*list.pFirst );
    TNode<T>* pNew = pFirst;
    pCurr = pFirst;
    while (pNew->pNext != list.pStop)
    {        
        pNew->pNext = new TNode<T>(*pNew->pNext);
        pNew = pNew->pNext;
    }
    pLast = pNew;
    if (list.pStop != nullptr)
    {
        pStop = new TNode<T>(*list.pStop);
    }
    pLast->pNext = pStop;
}

template <typename T>
void List<T>::DelList()
{
    if (pFirst == nullptr)
    {
        return;
    }
    pCurr = pFirst;
    TNode<T>* tmp;
    while (pCurr->pNext != pStop)
    {
        tmp = pCurr->pNext;
        delete pCurr;
        pCurr = tmp;
    }
    tmp = pCurr->pNext;
    delete pCurr;
    pCurr = nullptr;;
    pFirst = nullptr;
    pPrev = nullptr;
    pLast = nullptr;
    pStop = nullptr;
}

template <typename T>
List<T>::~List()
{
    DelList();
}

template <typename T>
const List<T>& List<T>::operator=(const List<T>& list)
{
    if (list.pFirst == nullptr)
    {
        return List<T>();
    }
    if (this != &list)
    {
        this->DelList();
        /*
        List<T> res = new List<T>(list);
        return res;
        */     
        pFirst = new TNode<T>(*list.pFirst);
        TNode<T>* pNew = pFirst;
        while (pNew->pNext != list.pStop)
        {            
            pNew->pNext = new TNode<T>(*pNew->pNext);
            pNew = pNew->pNext;
        }
        pLast = pNew;
        pLast->pNext = pStop;
    }
    return *this;

}

template <typename T>
int List<T>::GetSZ() const
{ 
    if (pFirst == nullptr)
        return 0;
    int i = 1;
    TNode<T>* curr=pFirst;
    while (curr != pLast)
    {
        curr = curr->pNext;
        i++;
    }
    return i;
} 

template <typename T>
bool List<T>::operator==(const List<T>& list) const
{
    TNode<T>* curr1 = pFirst;
    TNode<T>* curr2 = list.pFirst;
    if (GetSZ()!=list.GetSZ())
        return 0;
    if (curr1 != nullptr && curr2 != nullptr)
    {
        while (curr1->pNext != pStop || curr2->pNext != list.pStop)
        {
            if (curr1->data != curr2->data|| curr1->key != curr2->key)
                return 0;
            curr1 = curr1->pNext;
            curr2 = curr2->pNext;
        }
    }
    return 1;

}

template <typename T>
void List<T>::PushBack(const T& val, const int& key)
{
    if (pFirst == nullptr)
    {
        PushFront(val, key);
        return;
    }
    TNode<T>* node = new TNode<T>(val, key);
    pLast->pNext = node;
    pLast = node;
    pLast->pNext=pStop;
    Reset();
}

template<typename T>
void List<T>::PushFront(const T& val, const int& key)
{
    TNode<T>* node = new TNode<T>(val,key);
    if (pFirst == nullptr)
    {
        pFirst = node;
        pCurr = node;
        pLast = node;
        pLast->pNext = pStop;
        return;
    }
    TNode<T>* tmp = pFirst;
    pFirst = node;
    pFirst->pNext = tmp;
    Reset();
}

template <typename T>
void List<T>::PopBack()
{
    if (IsEmpty())
        throw std::exception("Error");
    if (pFirst==pLast)
    {
        PopFront();
        return;
    }
    TNode<T>* curr = pFirst->pNext;
    TNode<T>* prevcurr = pFirst;
    while (curr->pNext != pStop)
    {
        prevcurr = curr;
        curr = curr->pNext;
    }        
    delete curr;
    pLast = prevcurr;
    pLast->pNext = pStop;
}

template <typename T>
void List<T>::PopFront()
{
    if (IsEmpty())
        throw std::exception("Error");
    TNode<T>* tmp = pFirst->pNext;
    if (pLast == pFirst)
    {
        pLast = pStop;
        pCurr = pStop;
        tmp = pStop;
    }        
    delete pFirst;
    pFirst = tmp;
    Reset();
}

template <typename T>
bool List<T>::IsEmpty() const
{
    return (pFirst == nullptr);
}

template <typename T>
TNode<T>* List<T>::SearchKey(const int& key)
{
    if (IsEmpty())
        return nullptr;
    Reset();
    while (pCurr != pStop)
    {        
        if (pCurr->key == key)
            return pCurr;
        pCurr = pCurr->pNext;
    }
    return nullptr;
}

template <typename T>
void List<T>::Remove(const int& key)
{
    if (IsEmpty())
        throw std::exception("Error");    
    if (SearchKey(key) == nullptr)
        throw std::exception("List havenot this key");
    TNode<T>* tmp = pCurr->pNext;
    delete pCurr;
    pPrev->pNext = tmp;
    Reset();
}
template <typename T>
void List<T>::PushAfterKey(const T& val, const int& key, int ch_key)
{
    if (SearchKey(ch_key) == nullptr)
        throw std::exception("Error: have not this key");
    TNode<T>* curr = pFirst;
    while (curr->key != ch_key)
    {
        curr = curr->pNext;
    }
    if (curr == pLast)
    {
        PushBack(val, key);
        return;
    }
    TNode<T>* node = new TNode<T>(val, key);
    TNode<T>* tmp = curr->pNext;
    curr->pNext = node;
    node->pNext = tmp;
    Reset();
}

template <typename T>
void List<T>::PushBeforeKey(const T& val, const int& key, int ch_key)
{
    if (SearchKey(ch_key) == nullptr)
        throw std::exception("Error: have not this key");
    TNode<T>* curr = pFirst;
    TNode<T>* prev;
    while (curr->key != ch_key)
    {
        prev = curr;
        curr = curr->pNext;
    }
    if(curr==pFirst)
    {
        PushFront(val, key);
        return;
    }
    TNode<T>* node = new TNode<T>(val, key);
    prev->pNext = node;
    node->pNext = curr;
    Reset();
}

template <typename T>
void List<T>::Next()
{
    if (pCurr == pStop)
    {
        //throw std::exception("Error:Last element");
        Reset();
    }        
    pPrev = pCurr;
    pCurr = pCurr->pNext;
}

template <typename T>
void List<T>::PushAfterCurr(const T& val, const int& key)
{
    if (pCurr==nullptr)
        throw std::exception("Error: List is empty");
    TNode<T>* node = new TNode<T>(val, key);
    if (pCurr == pLast)
    {
        TNode<T>* curr = pCurr;
        TNode<T>* prev = pPrev;
        PushBack(val, key);
        pCurr = curr;
        pPrev = prev;
        return;
    }
    TNode<T>* tmp = pCurr->pNext;
    pCurr->pNext = node;
    node->pNext = tmp;
}

template <typename T>
void List<T>::PushBeforeCurr(const T& val, const int& key)
{
    if (pCurr==nullptr)
        throw std::exception("Error: List is empty!");
    TNode<T>* node = new TNode<T>(val, key);
    if (pCurr == pFirst)
    {
        PushFront(val, key);
        pPrev = pCurr;
        pCurr = pCurr->pNext;
        return;
    }
    pPrev->pNext = node;
    node->pNext = pCurr;
    pPrev = node;
}

template <typename T>
void List<T>::PopAftterCurr()
{
    if (IsEmpty())
        throw std::exception("Error: List is empty");
    if (pCurr == pLast)
        return;
    if (pCurr->pNext == pLast)
    {
        TNode<T>* curr = pCurr;
        TNode<T>* prev = pPrev;
        PopBack();
        pCurr = curr;
        pPrev = prev;
        return;
    }
    TNode<T>* tmp = pCurr->pNext->pNext;
    delete pCurr->pNext;
    pCurr->pNext == tmp;
}

template <typename T>
void List<T>::PopBeforeCurr()
{
    if (IsEmpty())
        throw std::exception("Error: List is empty");
    if (pCurr == pFirst)
        return;
    if (pPrev == pFirst)
    {
        TNode<T>* curr = pCurr;
        TNode<T>* prev = pPrev;
        PopFront();
        pCurr = curr;
        pPrev = prev;
        return;
    }
    TNode<T>* tmp = pFirst;
    while (tmp->pNext != pPrev)
        tmp = tmp->pNext;
    delete pPrev;
    pPrev = tmp;
    pPrev->pNext = pCurr;
}

#endif // !LIST_H