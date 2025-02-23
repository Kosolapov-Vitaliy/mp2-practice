#include "list.h"

void main()
{
    List<int> a;
    a.PushBack(2, 4);
    List<int> s;
    s = a;
    std::cout << "Readdy";
}