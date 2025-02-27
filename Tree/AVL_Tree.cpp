#include "AVL_Tree.hpp"

Node* AVL_Tree::rotateleft(Node* q) // левый поворот вокруг q
{
    Node* p = q->get_right();
    q->set_right(p->get_left());
    p->set_left(q);
    q->fixheight();
    p->fixheight();
    return p;
}

Node* AVL_Tree::rotateright(Node* p) // правый поворот вокруг p
{
    Node* q = p->get_left();
    p->set_left(q->get_right());
    q->set_right(p);
    p->fixheight();
    q->fixheight();
    return q;
}

Node* AVL_Tree::prv_balance(Node* p)
{
    p->fixheight();
    if(p->get_bfactor() == 2)
    {
        if(p->get_right()->get_bfactor() < 0)
        {
            p->set_right(this->rotateright(p->get_right()));
        }
        return this->rotateleft(p);
    }
    if(p->get_bfactor() == -2)
    {
        if(p->get_left()->get_bfactor() > 0)
        {
            p->set_left(this->rotateleft(p->get_left()));
        }
        return this->rotateright(p);
    }
    return p;
}

Node* AVL_Tree::prv_insert(Node* p, int key)
{
    if(!p) return new Node(key);
    if(key < p->get_key())
    {
        p->set_left(this->prv_insert(p->get_left(),key));
    }
    else
    {
        p->set_right(this->prv_insert(p->get_right(),key));
    }
    return this->prv_balance(p);
}

Node* AVL_Tree::prv_removemin(Node* p) // удаление узла с минимальным ключом из дерева p
{
    if( p->get_left() == nullptr)
        return p->get_right();
    p->set_left(this->prv_removemin(p->get_left()));
    return this->prv_balance(p);
}

Node* AVL_Tree::prv_remove(Node* p, int key)
{
    if(!p) return nullptr;
    if(key < p->get_key())
    {
        p->set_left(this->prv_remove(p->get_left(),key));
    }
    else if(key > p->get_key())
    {
        p->set_right(this->prv_remove(p->get_right(),key));
    }
    else
    {
        Node* q = p->get_left();
        Node* r = p->get_right();
        delete p;
        if(!r) return q;
        Node* min = this->prv_findmin(r);
        min->set_right(this->prv_removemin(r));
        min->set_left(q);
        return this->prv_balance(min);
    }
    return this->prv_balance(p);
}

Node* AVL_Tree::prv_findmin(Node* p)
{
    if(p->get_left())
    {
        return this->prv_findmin(p->get_left());
    }
    else
    {
        return p;
    }
}