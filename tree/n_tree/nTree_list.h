//
// Created by Mauro Nicolì on 2019-03-28.
//

#ifndef STRUTTURE_DATI_NTREE_LIST_H
#define STRUTTURE_DATI_NTREE_LIST_H

#include "../../list/linked_list.h"
#include "../../queue/queue.h"

using namespace std;

template<class T>
class NTreeL;

template<class T>
class NodeTreeL {

public:

    friend class NTreeL<T>;

    NodeTreeL() {
        _parent = nullptr;
    }

    NodeTreeL(const T &v, NodeTreeL<T> *p) {
        _value = v;
        _parent = p;
    }

    T getvalue() {
        return _value;
    }

    void setValue(const T &v){
        _value = v;
    }

private:

    T _value;

    NodeTreeL<T> *_parent;

    Linked_list<NodeTreeL<T> *> _children;

};


template<class T>
class NTreeL {

    typedef typename Linked_list<NodeTreeL<T> *>::position position;

public:

    //empty constructor
    NTreeL();

    //param constructor
    NTreeL(const T &);

    //copy constructor
    NTreeL(const NTreeL<T> &);

    //destructor
    ~NTreeL();

    bool empty() const;

    void insRadice(const T &);

    void insPrimoFiglio(NodeTreeL<T>&);

    void insSuccFratello(const T &, NodeTreeL<T>);

    NodeTreeL<T> radice() const;

    NodeTreeL<T> padre(const NodeTreeL<T>) const;

    bool foglia(const NodeTreeL<T>) const;

    NodeTreeL<T> primoFiglio(NodeTreeL<T>);

    bool ultimoFratello(NodeTreeL<T>);

    NodeTreeL<T> succFratello(NodeTreeL<T>);

    void insPrimoSottoAlbero(NodeTreeL<T>, NTreeL<T>);

    void insSottoAlbero(NodeTreeL<T>, NTreeL<T>);

    void cancSottoAlbero(NodeTreeL<T>);

    size_t size() const {
        return _size;
    };

    friend ostream &operator<<(ostream &os, const NTreeL<T> &a) {

        return os;
    }

    void print();

private:

    int _size;

    NodeTreeL<T> *_root;

};

template<class T>
NTreeL<T>::NTreeL() {
    _root = nullptr;
    _size = 0;
}

template<class T>
NTreeL<T>::NTreeL(const T &r) {
    _root = nullptr;
    _size = 0;
    insRadice(r);
}

template<class T>
NTreeL<T>::NTreeL(const NTreeL<T> &t) {
}

template<class T>
NTreeL<T>::~NTreeL() {

}

template<class T>
bool NTreeL<T>::empty() const {
    return ((_size == 0) || (_root == nullptr));
}

template<class T>
void NTreeL<T>::insRadice(const T &r) {
    if (empty()) {
        _root = new NodeTreeL<T>(r, nullptr);
        _root->_parent = _root;
        _size = 1;
    }
}

template<class T>
NodeTreeL<T> NTreeL<T>::radice() const {
    return *_root;
}

template<class T>
void NTreeL<T>::insPrimoFiglio(NodeTreeL<T> &n) {
/*
    NodeTreeL<T> *new_node = new NodeTreeL<T>;
    NodeTreeL<T> *pf = new NodeTreeL<T>(p, new_node);

    n._children.push_front(pf);
    _size++;
*/
    NodeTreeL<T> *new_node = new NodeTreeL<T>;
    new_node->_parent = &n;
    n._children.push_front(new_node);
    _size++;
}

template<class T>
void NTreeL<T>::insSuccFratello(const T &s, NodeTreeL<T> n) {
    NodeTreeL<T> *p = padre(n);
    NodeTreeL<T> *new_node = new NodeTreeL<T>;

    NodeTreeL<T> *sf = new NodeTreeL<T>(s, new_node);

    position pos = p->_children.begin();
    while (p->_children.end(pos)) {
        if (p->_children.read(pos) == &n) {
            p->_children.insert(p->_children.next(pos), &sf);
        }
    }
}

template<class T>
NodeTreeL<T> NTreeL<T>::padre(const NodeTreeL<T> n) const {
    return *n._parent;
}

template<class T>
bool NTreeL<T>::foglia(const NodeTreeL<T> n) const {
    return n._children.empty();
}

template<class T>
NodeTreeL<T> NTreeL<T>::primoFiglio(NodeTreeL<T> n) {
    return *n._children.read(n._children.begin());
}

template<class T>
bool NTreeL<T>::ultimoFratello(NodeTreeL<T> n) {
    NodeTreeL<T> *p = padre(n);
    if (p->_children.read(p->_children.last()) == &n) {
        return true;
    }
    return false;
}


template<class T>
NodeTreeL<T> NTreeL<T>::succFratello(NodeTreeL<T> n) {
}

template<class T>
void NTreeL<T>::insPrimoSottoAlbero(NodeTreeL<T> n, NTreeL<T> t) {

}

template<class T>
void NTreeL<T>::insSottoAlbero(NodeTreeL<T> n, NTreeL<T> t) {

}

template<class T>
void NTreeL<T>::cancSottoAlbero(NodeTreeL<T> t) {

}

template<class T>
void NTreeL<T>::print() {
    NodeTreeL<T> temp = this->radice();
    Queue<NodeTreeL<T> *> *to_print = new Queue<NodeTreeL<T> *>;
    while (!foglia(temp)) {
        to_print->push(&temp);
        while (!to_print->empty()) {
            cout << to_print->top()->getvalue();
            to_print->pop();

            //temp = temp._children.begin();

        }
    }
    cout << temp.getvalue();
}

#endif //STRUTTURE_DATI_NTREE_LIST_H
