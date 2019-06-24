//
// Created by Mauro Nicolì on 2019-06-23.
//

#ifndef STRUTTURE_DATI_BSTREE_H
#define STRUTTURE_DATI_BSTREE_H

template<class T>
class BSTree;


template<class T>
class NodeBSTree {
    friend class BSTree<T>;

public:

    NodeBSTree<T>() {
        this->_parent = nullptr;
        this->_left = nullptr;
        this->_right = nullptr;
    }

    NodeBSTree<T>(const NodeBSTree<T> &n) {
        this->_item = n._item;
        this->_parent = n._parent;
        this->_left = n._left;
        this->_right = n._right;
    }

private:

    T _item;

    NodeBSTree<T> *_parent;

    NodeBSTree<T> *_left;

    NodeBSTree<T> *_right;
};

template<class T>
class BSTree {

public:

    typedef T item;
    typedef NodeBSTree<T> *node;

    BSTree();

    BSTree(const BSTree &);

    ~BSTree();

    bool empty() const;

    node root() const;

    node parent(node) const;

    node left(node) const;

    node right(node) const;

    // stabilisce se l'albero binario rispetta i vincoli di un BST
   // bool is_bst();

    //inserisce in modo ordinato nel BST il valore passato
    void insert(item);

    // restituisce il minimo
    item min();

    //restituisce il massimo
    item max();

    // verifica se un elemento appartiene al BST
    bool search(item);

    void print(node);


private:

    node _root;

    void ins_left(node n);

    void ins_right(node n);

    //bool is_bst_util(node n);

};

template<class T>
BSTree<T>::BSTree() {
    _root = nullptr;
}

template<class T>
BSTree<T>::BSTree(const BSTree &) {

}

template<class T>
BSTree<T>::~BSTree() {
}

template<class T>
bool BSTree<T>::empty() const {
    return (_root == nullptr);
}

template<class T>
typename BSTree<T>::node BSTree<T>::root() const {
    return _root;
}

template<class T>
typename BSTree<T>::node BSTree<T>::parent(BSTree::node n) const {
    return n->_parent;
}

template<class T>
typename BSTree<T>::node BSTree<T>::left(BSTree::node n) const {
    return n->_left;
}

template<class T>
typename BSTree<T>::node BSTree<T>::right(BSTree::node n) const {
    return n->_right;
}
/*
template<class T>
bool BSTree<T>::is_bst() {
    return is_bst_util(_root);
}
*/
template<class T>
void BSTree<T>::insert(item i) {
    if (empty()) {
        if (_root == nullptr) {
            _root = new NodeBSTree<T>;
            _root->_item = i;
            _root->_parent = _root;
        }
    } else {
        if (!search(i)) {

            node n = _root;
            node p;
            while (n != nullptr) {
                p = n;
                if (i < n->_item) {
                    n = left(n);
                } else {
                    n = right(n);
                }
            }
            if (i < p->_item) {
                ins_left(p);
                p->_left->_item = i;
            } else {
                ins_right(p);
                p->_right->_item = i;
            }
        }
    }
}

template<class T>
typename BSTree<T>::item BSTree<T>::min() {
    node n = _root;
    while (n->_left != nullptr) {
        n = n->_left;
    }
    return n->_item;
}

template<class T>
typename BSTree<T>::item BSTree<T>::max() {
    node n = _root;
    while (n->_right != nullptr) {
        n = n->_right;
    }
    return n->_item;
}

template<class T>
bool BSTree<T>::search(BSTree::item i) {
    if (i == _root->_item) {
        return true;
    } else {
        node n = _root;
        while (n != nullptr) {
            if (i == n->_item) {
                return true;
            } else if (i < n->_item) {
                n = n->_left;
            } else if (i > n->_item) {
                n = n->_right;
            }
        }
    }
    return false;
}

template<class T>
void BSTree<T>::ins_left(node n) {
    n->_left = new NodeBSTree<T>;
    n->_left->_parent = n;
}

template<class T>
void BSTree<T>::ins_right(node n) {
    n->_right = new NodeBSTree<T>;
    n->_right->_parent = n;
}

template<class T>
void BSTree<T>::print(BSTree::node n) {
    if (n != nullptr) {
        cout << n->_item;
        cout << " : ";
        if (n->_left != nullptr) {
            cout << n->_left->_item;
        }
        cout << "  ";
        if (n->_right != nullptr) {
            cout << n->_right->_item;
        }
        cout << endl;
        if (n->_left != nullptr) {
            print(n->_left);
        }
        if (n->_right != nullptr) {
            print(n->_right);
        }
    } else {
        cout << "~";
    }
}
/*
template<class T>
bool BSTree<T>::is_bst_util(node n) {
    if (n != nullptr) {
        if (n->_left != nullptr) {
            if (n->_item > n->_left->_item) {
                is_bst_util(n->_left);
                return true;
            } else {
                return false;
            }
        }
        if (n->_right != nullptr) {
            if (n->_item < n->_right->_item) {
                is_bst_util(n->_right);
                return true;
            } else {
                return false;
            }
        }
    }
}
*/

#endif //STRUTTURE_DATI_BSTREE_H
