#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>

template <typename T>
class List
{
private:
    struct TNode
    {
        TNode* pNext;
        T data;
        int key;
        TNode() :data(0),key(0) pNext(nullptr) {}
        TNode(const T& x, const int& y) : data(x), key(y), pNext(nullptr) {}
    };
    TNode* pFirst;
    TNode* pCurr;
    TNode* pPrev;
    TNode* pLast;
    TNode* pStop;
public:
    List() : pFirst(nullptr), pCurr(nullptr), pPrev(nullptr), pLast(nullptr), pStop(nullptr) {};
    List(const List<T>& list);
    ~List();
    void DelList();
    const List& operator=(const List<T>& list);
    bool operator==(const List<T>& list) const;
    int GetSZ();
    void PushFront(const T& val, const int& key);
    void PushBack(const T& val, const int& key);
    void PopBack();
    void PopFront();
    bool IsEmpty() const;
    T SearchKey(const int& key);
    bool CheckKey(const int& key);
    T GetFirst() { return pFirst->data; };
};


template <typename T>
List<T>::List(const List<T>& list) : pFirst(nullptr), pCurr(nullptr), pPrev(nullptr), pLast(nullptr), pStop(nullptr)
{
    if (list.pFirst == nullptr)
        return;
    pFirst = new TNode{ *list.pFirst };
    pCurr = pFirst;
    while (pCurr->pNext != nullptr)
    {
        pCurr->pNext = new TNode{ *pCurr->pNext };
        pCurr = pCurr->pNext;
    }
    pLast = pCurr;
    pStop = pLast;
    pCurr = pFirst;
}

template <typename T>
void List<T>::DelList()
{
    pCurr = pFirst;
    TNode* tmp;
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
    if (this != &list)
    {
        this->DelList();
        pFirst = new TNode{ *list.pFirst };
        TNode* pNew = pFirst;
        while (pNew->pNext != nullptr)
        {
            
            pNew->pNext = new TNode{ *pNew->pNext };
            pNew = pNew->pNext;
            if (pNew->pNext == list.pCurr)
            {
                pPrev = pNew;
            }
        }
        pCurr = pPrev->pNext;
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
    TNode* curr=pFirst;
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
    TNode* curr1 = pFirst;
    TNode* curr2 = list.pFirst;
    if (curr1 != nullptr && curr2 != nullptr)
    {
        while (curr1 != nullptr || curr2 != nullptr)
        {
            if (curr1 == nullptr || curr2 == nullptr)
            {
                return 0;
            }
            if (curr1->data != curr2->data)
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
    TNode* node = new TNode(val,key);
    if (pFirst == nullptr)
    {
        pFirst = node;
        pCurr = node;
        pLast = node;
        pStop = node;
        return;
    }
    TNode* curr = pFirst;
    while (curr != pStop)
        curr = curr->pNext;
    curr->pNext = node;
    pLast = node;
    pStop = pLast;
}

template<typename T>
void List<T>::PushFront(const T& val, const int& key)
{
    TNode* node = new TNode(val,key);
    if (pFirst == nullptr)
    {
        pFirst = node;
        pCurr = node;
        pLast = node;
        pStop = node;
        return;
    }
    TNode* tmp = pFirst;
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
        delete pFirst;
        pFirst = nullptr;
        pCurr = nullptr;
        pLast = nullptr;
        pStop = nullptr;
        return;
    }
    TNode* curr = pFirst->pNext;
    TNode* prevcurr = pFirst;
    while (curr->pNext != nullptr)
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
    TNode* tmp = pFirst->pNext;
    if (pCurr == pFirst)
        pCurr = pFirst->pNext;
    if (pPrev == pFirst)
        pPrev = nullptr;
    if (pLast == pFirst)
    {
        pLast = nullptr;
        pStop = pLast;
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
T List<T>::SearchKey(const int& key)
{
    TNode* curr = pFirst;
    if (curr->key == key)
        return curr->data;
    while (curr != pStop)
    {
        curr = curr->pNext;
        if (curr->key == key)
            return curr->data;
    }
    throw std::exception("Have not key");
}

template <typename T>
bool List<T>::CheckKey(const int& key)
{
    TNode* curr = pFirst;
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
#endif // !LIST_H