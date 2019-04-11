//
// Created by Mauro Nicolì on 2019-04-02.
//

#ifndef STRUTTURE_DATI_BTREE_H
#define STRUTTURE_DATI_BTREE_H

#include "../../list/vector_list.h"

using namespace std;

template<class T>
class BTree;


template<class T>
class NodeBTree {
public:
    friend class BTree<T>;

    NodeBTree<T>() {
        this->_parent = nullptr;
        this->_left = nullptr;
        this->_right = nullptr;
    };

    NodeBTree<T>(const NodeBTree<T> &n) {
        this->_item = n._item;
        this->_parent = n._parent;
        this->_left = n._left;
        this->_right = n._right;
    }

private:

    T _item;

    NodeBTree<T> *_parent;

    NodeBTree<T> *_left;

    NodeBTree<T> *_right;

};


template<class T>
class BTree {

public:

    typedef T item;
    typedef NodeBTree<T> *node;

    BTree();

    BTree(const BTree &);

    ~BTree();

    bool empty() const;

    node root() const;

    node parent(node) const;

    node left(node) const;

    node right(node) const;

    bool left_empty(node) const;

    bool right_empty(node) const;

    void costr(const BTree &, const BTree &);

    void erase(node);

    T read(node) const;

    void write(node, item);

    void ins_root(item);

    void ins_left(node);

    void ins_right(node);

    bool leaf(node);

    void print(node);

    void ins_sub_tree(node, BTree<T> &);

    BTree<T> operator=(BTree<T> &);

    bool operator==(BTree<T> &);

    // Scrivere un programma ricorsivo che cancella da un albero binario di nodi con valore intero tutte le foglie di valore pari.
    void rimuovi_foglie_pari(node);

    // Dati due alberi binari A e B, e due nodi u e v, con u appartenente ad A e v appartenente a B, implementare la funzione mutation che scambia i sottoalberi con radice u e v.
    void mutation(BTree<T> &, node, BTree<T> &, node);

    // Dato un nodo, restituire il livello a cui appartiene.
    int level(node);

    // Restituisce la profondità massima dalla radice
    int depth();

    // support recursive function to calculate depth from node
    int depth_from_node(node);

    // Restituisce il numero di nodi nell' albero.
    int size();

    //support recursive function to calculate how many nodes are in subtree node
    int size_from_node(node);

    int diametro(node);

    void pre_print(node);

    void in_print(node);

    void post_print(node);

    void path_from_root(node);

    void path_node_to_node(node, node);


private:

    node _root;

    //support recursive function to copy from node to node (recursively)
    void copy(node, node) const;

    //support recursive function to compare from node to node (recursively)
    bool compare(node, node) const;

    // lowest common ancestor of first and second node, serched from third node(eg root)
    node prima_sotto_radice(node, node, node);

};

template<class T>
BTree<T>::BTree() {
    _root = nullptr;
}

template<class T>
BTree<T>::BTree(const BTree &t) {
    _root = new NodeBTree<T>;
    copy(t._root, _root);
}

template<class T>
BTree<T>::~BTree() {
    erase(_root);
}

template<class T>
bool BTree<T>::empty() const {
    return (_root == nullptr);
}

template<class T>
typename BTree<T>::node BTree<T>::root() const {
    return _root;
}

template<class T>
typename BTree<T>::node BTree<T>::parent(node n) const {
    return n->_parent;
}

template<class T>
typename BTree<T>::node BTree<T>::left(node n) const {
    if (!left_empty(n)) {
        return n->_left;
    }
    return nullptr;
}

template<class T>
typename BTree<T>::node BTree<T>::right(node n) const {
    if (!right_empty(n)) {
        return n->_right;
    }
    return nullptr;
}

template<class T>
bool BTree<T>::left_empty(node n) const {
    return (n->_left == nullptr);
}

template<class T>
bool BTree<T>::right_empty(node n) const {
    return (n->_right == nullptr);
}

template<class T>
void BTree<T>::erase(node n) {
    if (n->_parent != nullptr) {
        if (!left_empty(n)) {
            erase(n->_left);
        }
        if (!right_empty(n)) {
            erase(n->_right);
        }

        if (n->_parent->_left == n) {
            n->_parent->_left = nullptr;
        }
        if (n->_parent->_right == n) {
            n->_parent->_right = nullptr;
        }
        delete n;

        if (n == _root) {
            _root = nullptr;
        }
    }
}

template<class T>
T BTree<T>::read(node n) const {
    if (n != nullptr) {
        return n->_item;
    }
    return 0;
}

template<class T>
void BTree<T>::write(node n, item i) {
    n->_item = i;
}

template<class T>
void BTree<T>::ins_root(item i) {
    if (_root == nullptr) {
        _root = new NodeBTree<T>();
        _root->_item = i;
        _root->_parent = _root;
    }
}

template<class T>
void BTree<T>::ins_left(node n) {
    n->_left = new NodeBTree<T>;
    n->_left->_parent = n;
}

template<class T>
void BTree<T>::ins_right(node n) {
    n->_right = new NodeBTree<T>;
    n->_right->_parent = n;
}

template<class T>
bool BTree<T>::leaf(node n) {
    if (n != nullptr) {
        return ((n->_right == nullptr) && (n->_left == nullptr));
    }
    return false;
}

template<class T>
void BTree<T>::print(node n) {
    if (n != nullptr) {
        cout << n->_item;
        cout << " : ";
        if (!left_empty(n)) {
            cout << n->_left->_item;
        }
        cout << "  ";
        if (!right_empty(n)) {
            cout << n->_right->_item;
        }
        cout << endl;
        if (!left_empty(n)) {
            print(n->_left);
        }
        if (!right_empty(n)) {
            print(n->_right);
        }
    } else {
        cout << "~";
    }
}

template<class T>
void BTree<T>::ins_sub_tree(node n, BTree<T> &t) {
    BTree<T> new_t = t;
    copy(new_t._root, n);
}

template<class T>
void BTree<T>::copy(node from, node to) const {
    if (from != nullptr) {
        to->_item = from->_item;
        if (!left_empty(from)) {
            to->_left = new NodeBTree<T>;
            to->_left->_parent = to;
            to->_item = from->_item;
        }
        if (!right_empty(from)) {
            to->_right = new NodeBTree<T>;
            to->_right->_parent = to;
            to->_item = from->_item;
        }
        copy(from->_left, to->_left);
        copy(from->_right, to->_right);
    }
}

template<class T>
bool BTree<T>::compare(node from, node to) const {
    bool check = false;
    if (from != nullptr && to != nullptr) {
        if (to->_item != from->_item) {
            return check = false;
        } else {
            check = true;
            if (!left_empty(from) && !left_empty(to)) {
                compare(left(from), left(to));
            } else {
                return check = false;
            }
            if (!right_empty(from) && !right_empty(to)) {
                compare(right(from), right(to));
            } else {
                return check = false;
            }
        }
    }
    return check;
}

template<class T>
BTree<T> BTree<T>::operator=(BTree<T> &t) {
    _root = new NodeBTree<T>;
    copy(t._root, _root);
}

template<class T>
bool BTree<T>::operator==(BTree<T> &t) {
    return compare(_root, t._root);
}


template<class T>
void BTree<T>::rimuovi_foglie_pari(node n) {}

template<class T>
void BTree<T>::mutation(BTree<T> &A, node a, BTree<T> &B, node b) {
    if (!A.empty() && !B.empty()) {

        if (a != nullptr && b != nullptr) {

            BTree<T> *temp_b = new BTree<T>;
            temp_b->_root = new NodeBTree<T>;
            copy(b, temp_b->_root);

            BTree<T> *temp_a = new BTree<T>;
            temp_a->_root = new NodeBTree<T>;
            copy(a, temp_a->_root);

            NodeBTree<T> *ap = a->_parent;

            if (a == A._root) {
                A.erase(a);
                A._root = new NodeBTree<T>;
            } else if (ap->_left == a) {
                A.erase(a);
                A.ins_left(ap);
            } else {
                A.erase(a);
                A.ins_right(ap);
            }

            NodeBTree<T> *bp = b->_parent;

            if (b == B._root) {
                B.erase(b);
                B._root = new NodeBTree<T>;
            } else if (bp->_left == b) {
                B.erase(b);
                B.ins_left(bp);
            } else {
                B.erase(b);
                B.ins_right(bp);
            }
            copy(temp_b->_root, a);
            copy(temp_a->_root, b);
        }
    }
}

template<class T>
int BTree<T>::level(node n) {
    int l = 0;
    if (n != nullptr) {
        if (n != _root) {
            l = level(n->_parent) + 1;
        }
    }
    return l;
}

template<class T>
int BTree<T>::depth() {
    return depth_from_node(_root);
}

template<class T>
int BTree<T>::size() {
    return size_from_node(_root);
}

template<class T>
int BTree<T>::size_from_node(node n) {
    int count = 1;
    if (n != nullptr) {
        if (!leaf(n)) {
            count += size_from_node(n->_right);
            count += size_from_node(n->_left);
        }
    }
    return count;
}

template<class T>
int BTree<T>::depth_from_node(node n) {
    int count_r = 1;
    int count_l = 1;
    if (n != nullptr) {
        if (!leaf(n)) {
            count_r += depth_from_node(n->_right);
            count_l += depth_from_node(n->_left);
        }
        return max(count_l, count_r);
    }
    return 0;
}

template<class T>
void BTree<T>::pre_print(node n) {
    if (n != nullptr) {
        cout << n->_item << " ";
        if (!left_empty(n)) {
            pre_print(n->_left);
        }
        if (!right_empty(n)) {
            pre_print(n->_right);
        }
    } else {
        cout << "~";
    }
}

template<class T>
void BTree<T>::in_print(node n) {
    if (n != nullptr) {
        if (!left_empty(n)) {
            in_print(n->_left);
        }
        cout << n->_item << " ";
        if (!right_empty(n)) {
            in_print(n->_right);
        }
    } else {
        cout << "~";
    }
}

template<class T>
void BTree<T>::post_print(node n) {
    if (n != nullptr) {
        if (!left_empty(n)) {
            post_print(n->_left);
        }
        if (!right_empty(n)) {
            post_print(n->_right);
        }
        cout << n->_item << " ";
    } else {
        cout << "~";
    }
}

template<class T>
void BTree<T>::costr(const BTree &l, const BTree &r) {
    _root = new NodeBTree<T>;
    _root->_parent = _root;
    if (!l.empty()) {
        _root->_left = new NodeBTree<T>;
        _root->_left = l._root;
    } else {
        _root->_left = nullptr;
    }
    if (!r.empty()) {
        _root->_right = new NodeBTree<T>;
        _root->_right = r._root;
    } else {
        _root->_right = nullptr;
    }

}

template<class T>
int BTree<T>::diametro(node n) {
    if (n == nullptr){
        return 0;
    }
    int depth_l = depth_from_node(n->_left);
    int depth_r = depth_from_node(n->_right);

    int diametero_l = diametro(n->_left);
    int diametero_r = diametro(n->_right);

    return max(depth_l + depth_r, max(diametero_l, diametero_r));
}

template<class T>
typename BTree<T>::node BTree<T>::prima_sotto_radice(node first, node second, node sub_root) {
    if (sub_root != nullptr) {
        if (sub_root == first || sub_root == second) {
            return sub_root;
        } else {
            node f = prima_sotto_radice(first, second, sub_root->_left);
            node s = prima_sotto_radice(first, second, sub_root->_right);
            if (f != nullptr && s != nullptr) {
                return sub_root;
            } else if (f != nullptr) {
                return f;
            } else {
                return s;
            }
        }
    }
}

template<class T>
void BTree<T>::path_from_root(node n) {
    path_node_to_node(_root, n);
}

template<class T>
void BTree<T>::path_node_to_node(node from, node to) {

    node lca = prima_sotto_radice(from, to, _root);
    Vector_list<NodeBTree<T>*> path_from;
    Vector_list<NodeBTree<T>*> path_to;


    while (from != lca){
        path_from.push_back(from);
        from = from->_parent;
    }

    while (to != lca->_parent){
        path_to.push_front(to);
        to = to->_parent;
    }

    while (!path_from.empty()){
        cout << path_from.read(path_from.begin())->_item << " , ";
        path_from.pop_front();
    }

    cout << lca->_item << " , ";

    while (!path_to.empty()){
        cout << path_to.read(path_to.begin())->_item << " , ";
        path_to.pop_front();
    }


}

template<>
void BTree<int>::rimuovi_foglie_pari(node n) {
    if (!leaf(n)) {
        if (n->_left != nullptr) {
            rimuovi_foglie_pari(n->_left);
        }
        if (n->_right != nullptr) {
            rimuovi_foglie_pari(n->_right);
        }
    } else {
        if (n->_item % 2 == 0) {
            erase(n);
        }
    }
}


#endif //STRUTTURE_DATI_BTREE_H
