//
// Created by Mauro Nicolì on 2019-03-19.
//

#ifndef STRUTTURE_DATI_N_TREE_LIST_FIGLI_H
#define STRUTTURE_DATI_N_TREE_LIST_FIGLI_H

#include "../../list/linked_list.h"

using namespace std;

template<class T>
class NTreeLF;

template<class T>
class NodeTree {
    friend class NTreeLF<T>;

public:
    // NodeTree();

    //NodeTree((const T &));
/*
    ~NodeTree(){
        delete this;
    }
*/
    T getValue();

    void setValue(const T &);


private:
    T value;
    NodeTree<T> *_next;
};

template<class T>
class NTreeLF {

public:

    NTreeLF();

    NTreeLF(const NTreeLF<T> &);

    ~NTreeLF();

    bool empty() const;

    void insRadice(const NodeTree<T> &);

    NodeTree<T> radice() const;

    NodeTree<T> padre(const NodeTree<T> &) const;

    bool foglia(const NodeTree<T> &);

    NodeTree<T> primoFiglio(const NodeTree<T> &);

    bool ultimoFratello(const NodeTree<T> &);

    NodeTree<T> succFratello(const NodeTree<T> &);

    void insPrimoSottoAlbero(const NodeTree<T> &, NTreeLF<T> &);

    void insSottoAlbero(const NodeTree<T> &, NTreeLF<T> &);

    void cancSottoAlbero(NodeTree<T> &);

    int size() {
        return _size;
    };

    //friend ostream &operator<<(ostream &os, const NTreeLF<T> &);
    friend ostream &operator<<(ostream &os, const NTreeLF<T> &a) {
        for (int i = 0; i < a._size; i++) {
            cout << "[ " << a.tree[i].getValue() << " ]";
            NodeTree<T> *temp = a.tree[i]._next;
            while (temp != NULL) {
                cout << "[ " << temp->getValue() << " ]";
                temp = temp->_next;
            }
            cout << endl;
        }
        return os;
    }


private:

    //NodeTree<T> *_root;

    int dimension;

    int _size;

    void changeDimendion(const NodeTree<T> *, int, int);

    void removeRec(NodeTree<T> &, NodeTree<T> &);

    NodeTree<T> *tree;

};


template<class T>
T NodeTree<T>::getValue() {
    return value;
}

template<class T>
void NodeTree<T>::setValue(const T &v) {
    value = v;
}

template<class T>
NTreeLF<T>::NTreeLF() {
    this->_size = 0;
    this->dimension = 10;
    this->tree = new NodeTree<T>[dimension];
}

template<class T>
NTreeLF<T>::NTreeLF(const NTreeLF<T> &t) {

}

template<class T>
NTreeLF<T>::~NTreeLF() {
    //delete tree;
}

template<class T>
bool NTreeLF<T>::empty() const {
    return (_size == 0);
}

template<class T>
void NTreeLF<T>::insRadice(const NodeTree<T> &r) {
    tree[0]._next = NULL;
    tree[0].value = r.value;
    _size = 1;
}

template<class T>
NodeTree<T> NTreeLF<T>::radice() const {
    return tree[0];
}

template<class T>
NodeTree<T> NTreeLF<T>::padre(const NodeTree<T> &n) const {
    for (int i = 0; i < _size; i++) {
        if (tree[i].value == n.value) {
            return tree[i];
        } else {
            NodeTree<T> *temp = tree[i]._next;
            while (temp != NULL) {
                if (temp->value == n.value) {
                    return tree[i];
                } else {
                    temp = temp->_next;
                }
            }
        }
    }
    return tree[0];
}

template<class T>
bool NTreeLF<T>::foglia(const NodeTree<T> &n) {
    for (int i = 0; i < _size; i++) {
        if (tree[i].value == n.value) {
            if (tree[i]._next == NULL) {
                return true;
            }
        }
    }
    return false;
}

template<class T>
NodeTree<T> NTreeLF<T>::primoFiglio(const NodeTree<T> &n) {
    NodeTree<T> *temp = new NodeTree<T>;
    for (int i = 0; i < _size; i++) {
        temp = tree[i]._next;
        if ((n.value == tree[i].value) && (temp != NULL)) {
            return *temp;
        }
    }
}

template<class T>
bool NTreeLF<T>::ultimoFratello(const NodeTree<T> &n) {
    if (n.value == tree[0].value) {
        return true;
    }
    for (int i = 0; i < _size; i++) {
        if (tree[i]._next != NULL) {
            NodeTree<T> *ultimo = tree[i]._next;
            while (ultimo != NULL) {
                if (ultimo->value == n.value) {
                    if (ultimo->_next == NULL) {
                        return true;
                    }
                }
                ultimo = ultimo->_next;
            }
        }
    }
    return false;
}

template<class T>
NodeTree<T> NTreeLF<T>::succFratello(const NodeTree<T> &n) {
    NodeTree<T> *temp = new NodeTree<T>;
    for (int i = 0; i < _size; i++) {
        temp = tree[i]._next;
        while (temp != NULL) {
            if (n.value == temp->value) {
                return *temp->_next;
            } else {
                temp = temp->_next;
            }

        }
    }
    return n;

}

template<class T>
void NTreeLF<T>::insPrimoSottoAlbero(const NodeTree<T> &u, NTreeLF<T> &t) {
    while (dimension <= this->_size + t._size) {
        changeDimendion(tree, dimension, dimension * 2);
        dimension = dimension * 2;
    }
    NodeTree<T> *new_node = new NodeTree<T>;
    for (int j = 0; j < _size; j++) {
        if (tree[j].value == u.value) {
            new_node->_next = tree[j]._next;
            tree[j]._next = new_node;
            new_node->value = t.radice().value;
        }
    }
    for (int i = 0; i < t._size; i++) {
        tree[_size] = t.tree[i];
        _size++;

        NodeTree<T> *par_temp = t.tree[i]._next;
        NodeTree<T> *this_temp = tree[_size]._next;

        while (par_temp != NULL) {
            this_temp = new NodeTree<T>;
            this_temp->value = par_temp->value;

            par_temp = par_temp->_next;
            this_temp = this_temp->_next;
        }
    }
}

template<class T>
void NTreeLF<T>::insSottoAlbero(const NodeTree<T> &u, NTreeLF<T> &t) {
    while (dimension <= this->_size + t._size) {
        changeimendion(this->tree, dimension, dimension * 2);
        dimension = dimension * 2;
    }
    for (int j = 0; j < _size; j++) {
        NodeTree<T> *temp = tree[j]._next;
        while (temp != NULL) {
            if (temp->value == u.value) {
                NodeTree<T> *new_node = new NodeTree<T>;
                new_node->_next = temp->_next;
                temp->_next = new_node;
                new_node->value = t.radice().value;
            }
            temp = temp->_next;
        }
    }
    for (int i = 0; i < t._size; i++) {
        tree[_size] = t.tree[i];
        _size++;

        NodeTree<T> *par_temp = t.tree[i]._next;
        NodeTree<T> *this_temp = tree[_size]._next;

        while (par_temp != NULL) {
            this_temp = new NodeTree<T>;
            this_temp->value = par_temp->value;

            par_temp = par_temp->_next;
            this_temp = this_temp->_next;
        }
    }

}

template<class T>
void NTreeLF<T>::cancSottoAlbero(NodeTree<T> &u) {
    NodeTree<T> padre = u;
    removeRec(u, padre);
}

template<class T>
void NTreeLF<T>::removeRec(NodeTree<T> &u, NodeTree<T> &p) {
    cout << "u: " << u.getValue() << endl;
    cout << "p: " << p.getValue() << endl;
/*
    if (!foglia(u)) {

        NodeTree<T> pfiglio = primoFiglio(u);
        while (!foglia(pfiglio)){
            NodeTree<T> succFra = succFratello(pfiglio);
            removeRec(succFra, p);
        }
        removeRec(pfiglio, p);

    } else {
        delete[] u;
        _size--;
    }
*/
}

template<class T>
void NTreeLF<T>::changeDimendion(const NodeTree<T> *tree, int vecchia_dim, int nuova_dim) {
    NodeTree<T> *temp = new NodeTree<T>[nuova_dim];
    int num;
    if (vecchia_dim < nuova_dim) {
        num = vecchia_dim;
    } else {
        num = nuova_dim;
    }
    for (int i = 0; i < num; i++) {
        temp[i] = tree[i];
    }
    delete[] tree;
    tree = temp;

}

#endif //STRUTTURE_DATI_N_TREE_LIST_FIGLI_H
