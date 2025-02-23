#include <iostream>
#include "AVL_Tree.hpp"
using namespace std;

AVL_Tree tree;

int main()
{
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(5);
    tree.insert(4);
    tree.insert(7);
    tree.insert(6);
    tree.traverse();
    return 0;
}

