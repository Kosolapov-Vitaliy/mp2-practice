#include "list.h"
#include "headlist.h"

void main()
{
    List<int> a;
    a.PushBack(2, 4);
    List<int> s;
    s = a;
    std::cout << "Readdy";
    HeadList<int> b;
    b.PushBack(10, 4);
    b.PushBack(11, 2);
    b.PushAfterKey(23, 11, 2);
    std::cout << "Readdy";
}