// inserting into a list
#include <iostream>
#include <list>
#include <vector>
#include <memory>

int main()
{
    std::list<int>* myl = new std::list<int>;
    std::shared_ptr<std::list<int>> mylist = std::shared_ptr<std::list<int>>(myl);
    std::list<int>::iterator it;

    // set some initial values:
    // for (int i = 1; i <= 5; ++i)
        // mylist->push_back(i); // 1 2 3 4 5

    it = mylist->end();
    // ++it; // it points now to number 2           ^

    mylist->insert(it, 10); // 1 10 2 3 4 5

    // "it" still points to number 2                      ^
    mylist->insert(it, 2, 20); // 1 10 20 20 2 3 4 5

    --it; // it points now to the second 20            ^

    std::vector<int> myvector(2, 30);
    mylist->insert(it, myvector.begin(), myvector.end());
    // 1 10 20 30 30 20 2 3 4 5
    //               ^
    std::cout << "mylist contains:";
    for (it = mylist->begin(); it != mylist->end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    return 0;
}