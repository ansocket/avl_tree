#pragma once

#include <cstdint>
#include <iostream>
class Node
{
private:
    int key;
    unsigned int height;
    Node* left;
    Node* right;
    void* data;


public:
    
    Node(int key){
        this->key = key;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 1;
    }
    int get_key()
    {
        return this->key;
    }
    unsigned int get_height()
    {
        return this->height;
    }
    void set_height(unsigned int height)
    {
        this->height = height;
    }
    Node* get_left()
    {
        return this->left;
    }
    Node* get_right()
    {
        return this->right;
    }
    void set_left(Node* node)
    {
        this->left = node;
    }
    void set_right(Node* node)
    {
        this->right = node;
    }
    int get_bfactor()
    {
        int res = 0;
        if(this->right){
            res = this->right->height;
        }
        if(this->left)
        {
            res -= this->left->height;
        }
        return res;
    }   
    void fixheight()
    {
        unsigned int hl = 0;
        unsigned int hr = 0;
        if(this->right)
        {
            hr = this->right->height;
        }
        if(this->left)
        {
            hl = this->left->height;
        }
        if(hl > hr)
        {
            this->height = hl + 1;
        }
        else
        {
            this->height = hr + 1;
        }
    }    
};

class AVL_Tree
{
    Node* root;

    Node* rotateleft(Node* q); // левый поворот вокруг q
    Node* rotateright(Node* p); // правый поворот вокруг p
    Node* prv_balance(Node* p);
    Node* prv_insert(Node* p, int key);
    Node* prv_findmin(Node* p);
    Node* prv_removemin(Node* p); // удаление узла с минимальным ключом из дерева p
    Node* prv_remove(Node* p, int key);
    void prv_traverse_nlr(Node* p)
    {
        if(p)
        {
            std::cout << p->get_key() << " ";
            prv_traverse_nlr(p->get_left());
            prv_traverse_nlr(p->get_right());
        }
        
    }
public:
    AVL_Tree()
    {
        this->root = nullptr;
    }
    void insert(int key)
    {
        this->root = prv_insert(this->root,key);
    }
    void remove(int key)
    {
        this->root = prv_remove(this->root,key);
    }
    void traverse()
    {
        prv_traverse_nlr(this->root);
    }
};
