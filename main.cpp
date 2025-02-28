#include <iostream>
#include "AVL_Tree.hpp"
#include <cstring>
#include <random>
using namespace std;


AVL_Tree *tree;

unsigned int count;
bool new_line_flag = false;
static void cb(Node* node)
{
    if(new_line_flag)
    {
        cout << "\r\n";
        count = tree->get_height();
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
int main(int argc, char** argv)
{

    tree = new AVL_Tree();
    int number = 0;
    int max = 0;
    srand(time(NULL));
    number = 10;
    max = rand() % 1000;

    for(int i = 1; i < argc; i++)
    {
        if(memcmp(argv[i],"-",1) == 0)
        {
            if(strcmp(argv[i],"--help") == 0)
            {
                cout << "AVL Tree app." << endl;
                cout << "Usage:" << endl;
                cout << "    --help: this message" << endl;
                cout << "    --number <uint> : number of nodes. Default 10" << endl;
                cout << "    --max <uint> : max of random keys. Default 1000" << endl;
                return 0;
            }
            if(strcmp(argv[i],"--number") == 0)
            {
                if(argc > i)
                {
                    number = atoi(argv[i+1]);
                }
                else
                {
                    return -1;
                }
                
            }
            else if(strcmp(argv[i],"--max") == 0)
            {
                if(argc > i)
                {
                    max = atoi(argv[i + 1]);
                }
                else
                {
                    return -1;
                }
            }
            else 
            {
                cout << "Wrong argument. Try --help" << endl;
                return 0;
            }
        }
    }
    tree->set_callback(cb);
    
    for(int i = 0; i < number ; i++)
    {
        tree->insert(rand() % max);
    }
    count = tree->get_height();
    tree->traverse();
    delete tree;
    cout << "\r\n";
    return 0;
}

