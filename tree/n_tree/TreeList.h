//
// Created by Mauro Nicolì on 2019-03-31.
//

#ifndef STRUTTURE_DATI_TREELIST_H
#define STRUTTURE_DATI_TREELIST_H

#include "../../list/linked_list.h"
#include "../../stack/stack.h"


template<class I>
class TreeList;

template<class I>
class TreeNodeList {
public:

    friend class TreeList<I>;

private:

    I _item;

    TreeNodeList<I> *_parent = nullptr;

    Linked_list<TreeNodeList<I> *> _children;
};


template<class I>
class TreeList {
public:

    typedef I item;
    typedef TreeNodeList<I> *node;
    typedef typename Linked_list<TreeNodeList<I> *>::position position;


    TreeList();

    TreeList(const TreeList &t);

    ~TreeList();

    bool empty() const;

    void insRoot(item);

    node root() const;

    node parent(node) const;

    bool leaf(node) const;

    node firstChild(node) const;

    bool lastSibling(node) const;

    node nextSibling(node) const;

    void insFirstSubTree(node, TreeList &);

    void insSubTree(node, TreeList &);

    void removeSubTree(node);

    void insFirst(node, item);

    void insNext(node, item);

    void writeNode(node, item);

    item readNode(node) const;

    void print(node) const;

    bool operator==(const TreeList &t);

    TreeList operator=(const TreeList &t);

    int level(node);

    // La profondità di un albero ordinato è il massimo livello delle sue foglie.
    // Implementare la funzione PROFONDITA che calcola la profondità di un albero T.
    int profondita();

    // La largezza di un albero ordinato è il numero massimo di nodi che stanno tutti al medesimo livello.
    // Implementare la funzione LARGHEZZA che calcola la larghezza di un albero T.
    int larghezza();

    void pre_print(node);

    void in_print(node);

    void post_print(node);

    void fill();

    /* Restituisce il numero di foglie presenti nell’albero n-ario T */
    int n_leaf(node);

    /* Restituisce il numero di nodi in T di livello k */
    int n_level(node, int);

    int nodesGreaterThanX(node, int);

    // max valore nell'albero
    I maxTree(node);

    //calcola il numero di nodi con k figli
    int nodiKfigli(node, int);

    // verifico se tutti gli elementi di un albero n-ario sono pari
    bool tutti_pari(node);

    // restituisce i se il valore x e' contenuto nell'albero, 0 altrimenti
    bool findalberon(node, I);

    /* verifica: ogni nodo pari ha solo figli dispari */
    bool paridispari(node);

    void mirrorTree(node);

private:

    node _root;

    //support recursive function to copy from node to node (recursively)
    void copy(node, node) const;

    //support recursive function to compare from node to node (recursively)
    bool compare(node, node) const;

    // support recursive function to calculate depth from node
    int depth(node);

    // support recursive function to calculate width from node
    int width(node);

    void fill_util(node);

};

template<class I>
TreeList<I>::TreeList() {
    _root = nullptr;
}


template<class I>
TreeList<I>::TreeList(const TreeList &t) {
    if (!t.empty()) {
        this->_root = new TreeNodeList<I>;
        copy(t._root, this->_root);
    }
}

template<class I>
TreeList<I>::~TreeList() {
    _root = nullptr;
}

template<class I>
bool TreeList<I>::operator==(const TreeList &t) {
    bool check = false;
    if (this->_root->_item != t._root->_item) {
        check = false;
    } else {
        check = compare(t._root, this->_root);
    }

    return check;
}

template<class I>
TreeList<I> TreeList<I>::operator=(const TreeList &t) {
    if (!t.empty()) {
        this->_root = new TreeNodeList<I>;
        copy(t._root, this->_root);
    }
}

template<class I>
void TreeList<I>::copy(node from, node to) const {
    to->_item = from->_item;
    if (!leaf(from)) {
        position pos_from = from->_children.begin();
        while (!from->_children.end(pos_from)) {
            node new_n = new TreeNodeList<I>;
            new_n->_item = from->_children.read(pos_from)->_item;
            new_n->_parent = to;
            to->_children.push_back(new_n);
            pos_from = from->_children.next(pos_from);
        }
        pos_from = from->_children.begin();
        position pos_to = to->_children.begin();
        while (!from->_children.end(pos_from)) {
            copy(to->_children.read(pos_to), from->_children.read(pos_from));
            pos_from = from->_children.next(pos_from);
            pos_to = to->_children.next(pos_to);
        }
    }
}

template<class I>
bool TreeList<I>::compare(node from, node to) const {
    bool check = false;
    if (to->_item != from->_item) {
        return check = false;
    } else {
        position pos_from;
        position pos_to;
        if (!leaf(from) && (!leaf(to))) {
            pos_from = from->_children.begin();
            pos_to = to->_children.begin();
            while (!from->_children.end(pos_from) && !to->_children.end(pos_to)) {
                if (from->_children.read(pos_from)->_item == to->_children.read(pos_to)->_item) {
                    check = true;
                    pos_from = from->_children.next(pos_from);
                    pos_to = to->_children.next(pos_to);
                } else {
                    return check = false;
                }
            }
            pos_from = from->_children.begin();
            pos_to = to->_children.begin();
            while (!from->_children.end(pos_from) && !to->_children.end(pos_to)) {
                compare(to->_children.read(pos_to), from->_children.read(pos_from));
                pos_from = from->_children.next(pos_from);
                pos_to = to->_children.next(pos_to);
            }

        } else {
            check = false;
        }
    }
    return check;
}

template<class I>
bool TreeList<I>::empty() const {
    return (_root == nullptr);
}

template<class I>
void TreeList<I>::insRoot(item i) {
    _root = new TreeNodeList<I>();
    _root->_item = i;
}

template<class I>
void TreeList<I>::print(node n) const {
    using namespace std;
    cout << n->_item << ":";
    if (!leaf(n)) {
        position pos = n->_children.begin();
        while (!n->_children.end(pos)) {
            cout << " " << n->_children.read(pos)->_item;
            pos = n->_children.next(pos);
        }
        cout << endl;
        pos = n->_children.begin();
        while (!n->_children.end(pos)) {
            print(n->_children.read(pos));
            pos = n->_children.next(pos);
        }
    } else {
        cout << endl;
    }
}

template<class I>
typename TreeList<I>::node TreeList<I>::root() const {
    return _root;
}

template<class I>
typename TreeList<I>::node TreeList<I>::parent(node n) const {
    if (n->_parent != nullptr)
        return n->_parent;
}

template<class I>
bool TreeList<I>::leaf(node n) const {
    return (n->_children.empty());
}

template<class I>
typename TreeList<I>::node TreeList<I>::firstChild(node n) const {
    if (!leaf(n)) {
        return n->_children.read(n->_children.begin());
    }
    return nullptr;
}

template<class I>
bool TreeList<I>::lastSibling(node n) const {
    if (n != nullptr) {
        if (n == root() || n->_parent == NULL) {
            return true;
        } else {
            node parent = n->_parent;
            return (n == parent->_children.read(parent->_children.last()));
        }
    }
    return false;
}

template<class I>
typename TreeList<I>::node TreeList<I>::nextSibling(node n) const {
    if (n != nullptr && n != _root) {

        if (!lastSibling(n)) {
            node parent = n->_parent;
            position pos = parent->_children.begin();

            if (parent->_children.read(pos) == n) {

                return parent->_children.read(parent->_children.next(pos));
            }
        }
    }
    return nullptr;
}

template<class I>
void TreeList<I>::insFirstSubTree(node n, TreeList &t) {
    TreeList<I> new_t = t;
    n->_children.push_front(new_t.root());

}

template<class I>
void TreeList<I>::insSubTree(node n, TreeList &t) {
    if (n != _root || n->_parent != nullptr) {

        node parent = n->_parent;
        position pos = parent->_children.begin();
        while (parent->_children.read(pos) != n) {
            pos = parent->_children.next(pos);
        }
        TreeList<I> new_t = t;

        parent->_children.insert(new_t._root, parent->_children.next(pos));

    }
}

template<class I>
void TreeList<I>::insFirst(node n, item el) {
    node newnode = new TreeNodeList<I>;
    newnode->_item = el;
    newnode->_parent = n;
    n->_children.push_front(newnode);
}

template<class I>
void TreeList<I>::insNext(node n, item el) {
    node newnode = new TreeNodeList<I>;
    node parent = n->_parent;

    newnode->_item = el;
    newnode->_parent = n->_parent;

    position pos = parent->_children.begin();
    while (!parent->_children.end(pos)) {
        if (parent->_children.read(pos) == n) {
            parent->_children.insert(newnode, parent->_children.next(pos));
            break;
        }
        pos = parent->_children.next(pos);
    }

}

template<class I>
void TreeList<I>::removeSubTree(node n) {
    if (!leaf(n)) {
        while (!n->_children.empty()) {
            removeSubTree(n->_children.read(n->_children.begin()));
        }
    }
    node parent = n->_parent;
    position pos = parent->_children.begin();
    while (parent->_children.read(pos) != n) {
        pos = parent->_children.next(pos);
    }
    parent->_children.erase(pos);
}

template<class I>
void TreeList<I>::writeNode(node n, item el) {
    n->_item = el;
}

template<class I>
typename TreeList<I>::item TreeList<I>::readNode(node n) const {
    if (n != nullptr) {
        return n->_item;
    }
}

template<class I>
int TreeList<I>::profondita() {
    return depth(_root);
}

template<class I>
int TreeList<I>::larghezza() {
    return width(_root);
}

template<class I>
int TreeList<I>::depth(node n) {
    int max_d = 0;
    if (!leaf(n)) {
        position pos = n->_children.begin();
        while (!n->_children.end(pos)) {
            max_d = max(max_d, depth(n->_children.read(pos)));
            pos = n->_children.next(pos);
        }
    }
    return max_d + 1;
}

template<class I>
int TreeList<I>::width(node n) {
    int max_w = 0;
    if (!leaf(n)) {
        position pos = n->_children.begin();
        while (!n->_children.end(pos)) {
            max_w = max(n->_children.size() - 1, width(n->_children.read(pos)));
            pos = n->_children.next(pos);
        }
    }
    return max_w + 1;
}

template<class I>
void TreeList<I>::pre_print(node n) {
    if (n != nullptr) {
        cout << n->_item << " ";
        position pos;
        if (!leaf(n)) {
            pos = n->_children.begin();
            while (!n->_children.end(pos)) {
                pre_print(n->_children.read(pos));
                pos = n->_children.next(pos);
            }
        }
    }
}

template<class I>
void TreeList<I>::in_print(node n) {
    /*
    Stack<TreeNodeList<I> *> *stack = new Stack<TreeNodeList<I> *>;

    if (n != nullptr) {
        position pos;
        if (!leaf(n)) {
            pos = n->_children.begin();
            while (!n->_children.end(pos)) {
                in_print(n->_children.read(pos));

                stack->push_no_duplicati(n->_children.read(pos));
                if (pos == n->_children.begin()) {
                    stack->push_no_duplicati(n);
                }
                pos = n->_children.next(pos);
            }
        }

        stack->push_no_duplicati(n->_children.read(n->_children.begin()));
        if (pos == n->_children.begin()) {
            stack->push_no_duplicati(n);
        }
    }
    stack->revert();
    while (!stack->empty()) {
        cout << stack->top()->_item << " ";
        stack->pop();
    }
     */
}

template<class I>
void TreeList<I>::post_print(node n) {
    if (n != nullptr) {
        position pos;
        if (!leaf(n)) {
            pos = n->_children.begin();
            while (!n->_children.end(pos)) {
                post_print(n->_children.read(pos));
                pos = n->_children.next(pos);
            }
        }
        cout << n->_item << " ";
    }
}

template<class I>
void TreeList<I>::fill() {
    cout << "Inserisci il valore della radice: ";
    node curr = root();
    I r;
    cin >> r;
    insRoot(r);
    fill_util(root());
}

template<class I>
void TreeList<I>::fill_util(node n) {
    node nextchild = n;
    cout << "Vuoi inserire figli di " << readNode(n) << "?    (s/n) ";
    char ans;
    cin >> ans;
    if (ans == 'n') {
        return;
    }
    while (ans == 's') {
        ans = 'x';
        cout << "Quanti figli ha " << readNode(n) << "?";
        int n_figli;
        cin >> n_figli;
        if (n_figli <= 1) {
            cout << "Inserisci primo figlio di " << readNode(n) << ": ";
            I p_figlio;
            cin >> p_figlio;
            insFirst(nextchild, p_figlio);
        } else {
            cout << "Inserisci primo figlio di " << readNode(n) << ": ";
            I p_figlio;
            cin >> p_figlio;
            insFirst(nextchild, p_figlio);
            nextchild = firstChild(nextchild);
            for (int i = 0; i < n_figli - 1; i++) {
                cout << "Inserisci fratello di " << p_figlio << ": ";
                I s_fratello;
                cin >> s_fratello;
                p_figlio = s_fratello;
                insNext(nextchild, s_fratello);
                nextchild = nextSibling(nextchild);
            }
        }
        position pos;
        pos = n->_children.begin();
        while (!n->_children.end(pos)) {
            fill_util(n->_children.read(pos));
            pos = n->_children.next(pos);
        }
    }
}

template<class I>
int TreeList<I>::n_leaf(node n) {
    int count = 0;
    if (leaf(n)) {
        return 1;
    }
    position pos = n->_children.begin();
    while (!n->_children.end(pos)) {
        count += n_leaf(n->_children.read(pos));
        pos = n->_children.next(pos);
    }
    return count;
}

template<class I>
int TreeList<I>::n_level(node n, int k) {
    int count = 1;
    if (level(_root) == k - 1) {
        return _root->_children.size();
    }
    if (!leaf(n)) {
        position pos = n->_children.begin();
        while (!n->_children.end(pos)) {
            count = n_level(n->_children.read(pos), k);
            if (level(n->_children.read(pos)) == k - 1) {
                count += n->_children.size();
            }
            pos = n->_children.next(pos);
        }
    }
    return count;
}

template<class I>
int TreeList<I>::level(node n) {
    if (n == _root) {
        return 1;
    }
    int count = 1;
    while (n != _root) {
        n = n->_parent;
        count++;
    }
    return count;
}

template<class I>
I TreeList<I>::maxTree(node n) {
    I maxI = n->_item;

    position pos = n->_children.begin();
    while (!n->_children.end(pos)) {
        maxI = max(maxI, maxTree(n->_children.read(pos)));
        pos = n->_children.next(pos);
    }
    return maxI;
}

template<class I>
int TreeList<I>::nodiKfigli(node n, int k) {
    int nodi = 0;
    if (n == nullptr) {
        return 0;
    }
    if (n->_children.size() == k) {
        nodi++;
    }
    position pos = n->_children.begin();
    while (!n->_children.end(pos)) {
        nodi += nodiKfigli(n->_children.read(pos), k);
        pos = n->_children.next(pos);
    }
    return nodi;
}

template<class I>
bool TreeList<I>::tutti_pari(node n) {}

template<>
bool TreeList<int>::tutti_pari(node n) {
    bool flag = false;
    if (n != nullptr) {
        if (n->_item % 2 == 0) {
            flag = true;
        }
        position pos = n->_children.begin();
        while (!n->_children.end(pos) && !(flag == false)) {
            flag = tutti_pari(n->_children.read(pos));
            pos = n->_children.next(pos);
        }
    }
    return flag;
}

template<class I>
bool TreeList<I>::findalberon(node n, I i) {
    bool flag = false;
    if (n != nullptr) {

        if (n->_item == i) {
            flag = true;
        }
        position pos = n->_children.begin();
        while (!n->_children.end(pos) && !flag) {
            flag = findalberon(n->_children.read(pos), i);
            pos = n->_children.next(pos);
        }
    }
    return flag;
}


template<class I>
bool TreeList<I>::paridispari(node n) {
    bool check = false;
    if (n != nullptr) {

        // per ogni nodo pari
        if (n->_item % 2 == 0) {
            position pos = n->_children.begin();
            while (!n->_children.end(pos)) {

                if (n->_children.read(pos)->_item % 2 == 1) {
                    check = true;
                } else {
                    return false;
                }
                pos = n->_children.next(pos);
            }
        }
        // per ogni nodo
        position pos = n->_children.begin();
        while (!n->_children.end(pos)) {
            check = paridispari(n->_children.read(pos)) && check;
            pos = n->_children.next(pos);
        }
    }
    return check;
}


template<class I>
void TreeList<I>::mirrorTree(node n) {
    if (n == nullptr) {
        return;
    }
    position pos = n->_children.begin();
    n->_children.inverti();
    while (!n->_children.end(pos)) {
        mirrorTree(n->_children.read(pos));
        pos = n->_children.next(pos);
    }
}

template<class I>
int TreeList<I>::nodesGreaterThanX(node n, int x) {}

template<>
int TreeList<int>::nodesGreaterThanX(node n, int x) {
    if (n == nullptr) {
        return 0;
    }
    int count = 0;
    if (n->_item > x) {
        count++;
    }
    position pos = n->_children.begin();
    while (!n->_children.end(pos)) {
        count += nodesGreaterThanX(n->_children.read(pos), x);
        pos = n->_children.next(pos);
    }

    return count;
}

#endif //STRUTTURE_DATI_TREELIST_H
