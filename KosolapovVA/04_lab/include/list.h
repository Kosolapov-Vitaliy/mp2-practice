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
};

template <typename T>
class List
{
private:
    TNode<T>* pStop;
protected:
    TNode<T>* pFirst;
    TNode<T>* pCurr;
    TNode<T>* pPrev;
    TNode<T>* pLast;
public:
    List(): pFirst(nullptr), pCurr(nullptr), pPrev(nullptr), pLast(nullptr), pStop(nullptr) {};
    List(const List<T>& list);
    ~List();
    virtual void DelList();
    virtual const List& operator=(const List<T>& list);
    bool operator==(const List<T>& list) const;
    int GetSZ();
    virtual void PushFront(const T& val, const int& key);
    virtual void PushBack(const T& val, const int& key);
    virtual void PopBack();
    virtual void PopFront();
    bool IsEmpty() const;
    void SearchKey(const int& key);
    bool CheckKey(const int& key);
    T GetFirst() { return pFirst->data; };
    T GetCurr() { return pCurr->data; };
    int CurrKey() { return pCurr->key; };
    void PushAfterKey(const T& val, const int& key, int ch_key);
    void PushBeforeKey(const T& val, const int& key, int ch_key);
    void PopAftterKey(int ch_key);
    void PopBeforeKey(int ch_key);

    virtual void Next();
    void Reset() { pCurr = pFirst; pPrev = nullptr; };
    void PushAfterCurr(const T& val, const int& key);
    void PushBeforeCurr(const T& val, const int& key);
    void PopAftterCurr();
    void PopBeforeCurr();
    
};


template <typename T>
List<T>::List(const List<T>& list) : pFirst(nullptr), pCurr(nullptr), pPrev(nullptr), pLast(nullptr), pStop(nullptr)
{
    if (list.pFirst == nullptr)
        return;
    pFirst = new TNode<T>{ *list.pFirst };
    TNode<T>* pNew = pFirst;
    TNode<T>* pCheck = list.pFirst;
    if (list.pFirst == list.pCurr)
        pCurr = pFirst;
    if (list.pFirst == list.pPrev)
        pPrev = pFirst;
    while (pCheck != list.pStop)
    {        
        if (pNew->pNext == list.pCurr)
        {
            pPrev = pNew;
        }        
        pNew->pNext = new TNode<T>{ *pNew->pNext };
        if (pNew == pPrev)
        {
            pCurr = pNew->pNext;
        }
        pNew = pNew->pNext;
        pCheck = pCheck->pNext;
    }
    pLast = pNew;
    pStop = pLast;
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
    while (pCurr != pStop)
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
        pFirst = new TNode<T>{ *list.pFirst };
        TNode<T>* pNew = pFirst;
        TNode<T>* pCheck = list.pFirst;
        if (list.pFirst == list.pCurr)
            pCurr = pFirst;
        if (list.pFirst == list.pPrev)
            pPrev = pFirst;
        while (pCheck != list.pStop)
        {
            if (pNew->pNext == list.pCurr)
            {
                pPrev = pNew;
            }
            pNew->pNext = new TNode<T>{ *pNew->pNext };
            if (pNew == pPrev)
            {
                pCurr = pNew->pNext;
            }
            pNew = pNew->pNext;
            pCheck = pCheck->pNext;
        }
        pLast = pNew;
        pStop = pLast;
    }
    return *this;

}

template <typename T>
int List<T>::GetSZ()
{ 
    if (pFirst == nullptr)
        return 0;
    int i = 1;
    TNode<T>* curr=pFirst;
    while (curr != pStop)
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
    if (pCurr->data != list.pCurr->data|| pCurr->key != list.pCurr->key)
        return 0;
    if ((pPrev!=nullptr && list.pPrev!=nullptr) && 
        (pPrev->data != list.pPrev->data || pPrev->key != list.pPrev->key))
        return 0;
    if (curr1 == nullptr && curr2 != nullptr || curr2 == nullptr && curr1 != nullptr)
        return 0;
    if (curr1 != nullptr && curr2 != nullptr)
    {
        while (curr1 != pStop || curr2 != list.pStop)
        {
            if (curr1 == pStop || curr2 == list.pStop)
            {
                return 0;
            }
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
    if (CheckKey(key) == 1)
        throw std::exception("The key is in the list");    
    if (pFirst == nullptr)
    {
        PushFront(val, key);
        return;
    }
    TNode<T>* node = new TNode<T>(val, key);
    pLast->pNext = node;
    pLast = node;
    pStop = pLast;
}

template<typename T>
void List<T>::PushFront(const T& val, const int& key)
{
    if (CheckKey(key) == 1)
        throw std::exception("The key is in the list");
    TNode<T>* node = new TNode<T>(val,key);
    if (pFirst == nullptr)
    {
        pFirst = node;
        pCurr = node;
        pLast = node;
        pStop = node;
        return;
    }
    TNode<T>* tmp = pFirst;
    if (pCurr == pFirst)
        pPrev = node;
    pFirst = node;
    pFirst->pNext = tmp;
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
    while (curr != pStop)
    {
        prevcurr = curr;
        curr = curr->pNext;
    }
    if (pCurr == pLast)
        pCurr = prevcurr;
    delete curr;
    prevcurr->pNext = nullptr;
    pLast = prevcurr;
    pStop = pLast;
}

template <typename T>
void List<T>::PopFront()
{
    if (IsEmpty())
        throw std::exception("Error");
    TNode<T>* tmp = pFirst->pNext;
    if (pCurr == pFirst)
        pCurr = pFirst->pNext;
    if (pPrev == pFirst)
        pPrev = nullptr;
    if (pLast == pFirst)
    {
        pLast = nullptr;
        pCurr = nullptr;
        pStop = pLast;
        tmp = nullptr;
    }        
    delete pFirst;
    pFirst = tmp;
}

template <typename T>
bool List<T>::IsEmpty() const
{
    return (pFirst == nullptr);
}

template <typename T>
void List<T>::SearchKey(const int& key)
{
    if (IsEmpty())
        throw std::exception("Error: List is empty");
    Reset();
    if (pCurr->key == key)
        return;
    while (pCurr != pStop)
    {
        pCurr = pCurr->pNext;
        if (pCurr->key == key)
            return;
    }
    throw std::exception("Have not key");
}

template <typename T>
bool List<T>::CheckKey(const int& key)
{
    if (IsEmpty())
        return 0;
    TNode<T>* curr = pFirst;
    if (curr->key == key)
        return 1;
    while (curr != pStop)
    {
        curr = curr->pNext;
        if (curr->key == key)
            return 1;
    }
    return 0;
}

template <typename T>
void List<T>::PushAfterKey(const T& val, const int& key, int ch_key)
{
    if (CheckKey(ch_key) == 0)
        throw std::exception("Error: have not this key");
    if (CheckKey(key) == 1)
        throw std::exception("The key is in the list");
    TNode<T>* curr = pFirst;
    while (curr->key != ch_key)
    {
        curr = curr->pNext;
    }
    if (curr == pStop)
    {
        PushBack(val, key);
        return;
    }
    TNode<T>* node = new TNode<T>(val, key);
    TNode<T>* tmp = curr->pNext;
    curr->pNext = node;
    node->pNext = tmp;
}

template <typename T>
void List<T>::PushBeforeKey(const T& val, const int& key, int ch_key)
{
    if (CheckKey(ch_key) == 0)
        throw std::exception("Error: have not this key");
    if (CheckKey(key) == 1)
        throw std::exception("The key is in the list");
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
}

template <typename T>
void List<T>::PopAftterKey(int ch_key)
{
    if (CheckKey(ch_key) == 0)
        throw std::exception("Error: have not this key");
    TNode<T>* curr = pFirst;
    while (curr->key != ch_key)
    {
        curr = curr->pNext;
    }
    if (curr == pStop)
        return;
    if (curr->pNext == pStop)
    {
        delete curr->pNext;
        curr->pNext = nullptr;
        pLast = curr;
        pStop = pLast;
        return;
    }
    if(curr->pNext==pCurr)
        pCurr= curr->pNext->pNext;
    if (curr->pNext == pPrev)
        pPrev = curr;
    TNode<T>* tmp = curr->pNext->pNext;
    delete curr->pNext;
    curr->pNext = tmp;
}

template <typename T>
void List<T>::PopBeforeKey(int ch_key)
{
    if (CheckKey(ch_key) == 0)
        throw std::exception("Error: have not this key");
    if (pFirst->key == ch_key)
        return;
    TNode<T>* curr = pFirst->pNext;
    if (pFirst->pNext->key == ch_key)
    {
        if (pFirst == pPrev)
            pPrev = nullptr;
        if (pFirst == pCurr)
            pCurr = curr;
        delete pFirst;
        pFirst = curr;
        return;
    }
    TNode<T>* prevCurr=pFirst;
    TNode<T>* prevPrev;
    while (curr->key != ch_key)
    {
        prevPrev = prevCurr;
        prevCurr = curr;
        curr = curr->pNext;
    }
    if (prevCurr == pCurr)
        pCurr = curr;
    if (prevCurr == pPrev)
        pPrev = prevPrev;
    delete prevCurr;
    prevCurr = nullptr;
    prevPrev->pNext = curr;
}

template <typename T>
void List<T>::Next()
{
    if (pCurr == pStop)
        throw std::exception("Error:Last element");
    pPrev = pCurr;
    pCurr = pCurr->pNext;
}

template <typename T>
void List<T>::PushAfterCurr(const T& val, const int& key)
{
    if (IsEmpty())
        throw std::exception("Error: List is empty");
    if (CheckKey(key))
        throw std::exception("The key is in the list");
    TNode<T>* node = new TNode<T>(val, key);
    if (pCurr == pStop)
    {
        PushBack(val, key);
        return;
    }
    TNode<T>* tmp = pCurr->pNext;
    pCurr->pNext = node;
    node->pNext = tmp;
}

template <typename T>
void List<T>::PushBeforeCurr(const T& val, const int& key)
{
    if (IsEmpty())
        throw std::exception("Error: List is empty");
    if (CheckKey(key))
        throw std::exception("The key is in the list");
    TNode<T>* node = new TNode<T>(val, key);
    if (pCurr == pFirst)
    {
        PushFront(val, key);
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
    if (pCurr == pStop)
        return;
    if (pCurr->pNext == pStop)
    {
        PopBack();
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
        PopFront();
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