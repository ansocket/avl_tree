#include <iostream>
#include "AVL_Tree.hpp"
#include <cstring>
#include <random>
using namespace std;

AVL_Tree tree;

int count;
bool new_line_flag = false;
static void cb(Node* node)
{
    if(new_line_flag)
    {
        cout << "\r\n";
        count = tree.get_height();
        new_line_flag = false;
        
    }
    while(count > node->get_height() - 1)
    {
        cout << "\t";
        count--;
    }
    cout << node->get_key() << "\t";

    if(node->get_height() == 1)
    { 
        new_line_flag = true;
    }
    else
    {
        count--;
    }
    
}
int main()
{
    srand(time(NULL));
    tree.set_callback(cb);
    int number = rand() % 1000;
    for(int i = 0; i < number ; i++)
    {
        tree.insert(rand() % 10000);
    }
    count = tree.get_height();
    tree.traverse();
    cout << "\r\n";
    return 0;
}

