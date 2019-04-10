//
// Created by Mauro Nicolì on 2019-03-31.
//
#ifndef TREELINK_H
#define TREELINK_H

#include <iostream>
#include "../../stack/stack.h"

template<class I>
class TreeLink;

template<class I>
class TreeNodeLink {
    friend class TreeLink<I>;

private:
    TreeNodeLink<I> *_parent = nullptr;
    TreeNodeLink<I> *_firstChild = nullptr;
    TreeNodeLink<I> *_nextSibling = nullptr;
    I _item;
};


template<class I>
class TreeLink {
public:

    typedef I item;
    typedef TreeNodeLink<I> *node;

    TreeLink();

    TreeLink(const TreeLink &t);

    ~TreeLink();

    bool empty() const;

    void insRoot(item);

    node root() const;

    node parent(node) const;

    bool leaf(node) const;

    node firstChild(node) const;

    bool lastSibling(node) const;

    node nextSibling(node) const;

    void insFirstSubTree(node, TreeLink &);

    void insSubTree(node, TreeLink &);

    void removeSubTree(node);

    void insFirst(node, item);

    void insNext(node, item);

    void writeNode(node, item);

    item readNode(node) const;

    void print(node n) const;

    bool operator==(const TreeLink &);

    TreeLink operator=(const TreeLink &);

    void pre_print(node);

    void in_print(node);

    void post_print(node);

private:

    node _root;

    //support recursive function to copy from node to node (recursively)
    void copy(node, node) const;

    //support recursive function to compare from node to node (recursively)
    bool compare(node, node) const;

};

template<class I>
TreeLink<I>::TreeLink() {
    _root = nullptr;
}

template<class I>
TreeLink<I>::TreeLink(const TreeLink &t) {
    if (!t.empty()) {
        this->_root = new TreeNodeLink<I>;
        copy(t._root, this->_root);
    }
}

template<class I>
TreeLink<I>::~TreeLink() {
    _root = nullptr;
}

template<class I>
bool TreeLink<I>::operator==(const TreeLink &t) {
    bool check = false;
    if (this->_root->_item != t._root->_item) {
        check = false;
    } else {
        check = compare(t._root, this->_root);
    }
    return check;
}

template<class I>
TreeLink<I> TreeLink<I>::operator=(const TreeLink &t) {
    if (!t.empty()) {
        this->_root = new TreeNodeLink<I>;
        copy(t._root, this->_root);
    }
}

template<class I>
void TreeLink<I>::copy(node from, node to) const {
    to->_item = from->_item;
    node from_child;
    node to_child;
    if (!leaf(from)) {
        from_child = firstChild(from);
        do {
            node t = new TreeNodeLink<I>;
            if (to->_firstChild != nullptr) {
                node cursor = to->_firstChild;
                while (!lastSibling(cursor)) {
                    cursor = nextSibling(cursor);
                }
                cursor->_nextSibling = t;
            } else {
                to->_firstChild = t;
            }
            t->_item = from_child->_item;
            t->_parent = to;
            from_child = nextSibling(from_child);

        } while (!lastSibling(from_child));


        from_child = firstChild(from);
        to_child = firstChild(to);
        while (!lastSibling(from_child)) {
            copy(from_child, to_child);
            from_child = nextSibling(from_child);
            to_child = nextSibling(to_child);
        }
        copy(from_child, to_child);

    }
}

template<class I>
bool TreeLink<I>::compare(node from, node to) const {
    bool check = false;
    if (to->_item != from->_item) {
        return check = false;
    } else {
        node from_child;
        node to_child;
        if (!leaf(from) && (!leaf(to))) {
            from_child = from->_firstChild;
            to_child = to->_firstChild;
            do {
                if (from_child->_item == to_child->_item) {
                    check = true;
                    from_child = nextSibling(from_child);
                    to_child = nextSibling(to_child);
                } else {
                    return check = false;
                }
            } while (!lastSibling(from_child) && !lastSibling(to_child));
            from_child = from->_firstChild;
            to_child = to->_firstChild;
            while (!lastSibling(from_child) && !lastSibling(to_child)) {
                compare(from_child, to_child);
                from_child = nextSibling(from_child);
                to_child = nextSibling(to_child);
            }
        } else {
            check = false;
        }
    }
    return check;
}

template<class I>
bool TreeLink<I>::empty() const {
    return (_root == nullptr);
}

template<class I>
void TreeLink<I>::insRoot(item i) {
    _root = new TreeNodeLink<I>();
    _root->_item = i;
}

template<class I>
void TreeLink<I>::print(node n) const {
    using namespace std;
    node p;
    cout << n->_item << ":";
    if (!leaf(n)) {
        p = firstChild(n);
        while (!lastSibling(p)) {
            cout << " " << p->_item;
            p = nextSibling(p);
        }
        cout << " " << p->_item << endl;
        p = firstChild(n);
        while (!lastSibling(p)) {
            print(p);
            p = nextSibling(p);
        }
        print(p);
    } else {
        cout << endl;
    }
}

template<class I>
typename TreeLink<I>::node TreeLink<I>::root() const {
    return _root;
}

template<class I>
typename TreeLink<I>::node TreeLink<I>::parent(node n) const {
    if (n->_parent != nullptr)
        return n->_parent;
}

template<class I>
bool TreeLink<I>::leaf(node n) const {
    return (n->_firstChild == nullptr);
}

template<class I>
typename TreeLink<I>::node TreeLink<I>::firstChild(node n) const {
    if (!leaf(n)) {
        return n->_firstChild;
    }
    return nullptr;
}

template<class I>
bool TreeLink<I>::lastSibling(node n) const {

    return (n->_nextSibling == nullptr);
}

template<class I>
typename TreeLink<I>::node TreeLink<I>::nextSibling(node n) const {
    if (!lastSibling(n)) {
        return n->_nextSibling;
    }
    return nullptr;
}

template<class I>
void TreeLink<I>::insFirstSubTree(node n, TreeLink &t) {
    TreeLink<I> new_t = t;
    if (leaf(n)) {
        n->_firstChild = new_t._root;
        new_t._root->_parent = n;
    } else {
        new_t._root->_nextSibling = n->_firstChild;
        n->_firstChild = new_t._root;
        new_t._root->_parent = n;
    }
}

template<class I>
void TreeLink<I>::insSubTree(node n, TreeLink &t) {
    TreeLink<I> new_t = t;
    if (lastSibling(n)) {
        n->_nextSibling = new_t._root;
        new_t._root->_parent = n;
    } else {
        new_t._root->_nextSibling = n->_nextSibling;
        n->_nextSibling = new_t._root;
        new_t._root->_parent = n->_parent;
    }

}

template<class I>
void TreeLink<I>::insFirst(node n, item el) {
    node newnode = new TreeNodeLink<I>();
    newnode->_item = el;
    newnode->_nextSibling = n->_firstChild;
    newnode->_parent = n;
    n->_firstChild = newnode;
}

template<class I>
void TreeLink<I>::insNext(node n, item el) {
    if (n != nullptr) {
        node newnode = new TreeNodeLink<I>();
        newnode->_item = el;
        newnode->_nextSibling = n->_nextSibling;
        newnode->_parent = n->_parent;
        n->_nextSibling = newnode;
    }
}

template<class I>
void TreeLink<I>::removeSubTree(node n) {
    node p;
    if (!leaf(n)) {
        p = n->_firstChild;
        do {
            removeSubTree(p);
            p = p->_nextSibling;
        } while (!lastSibling(p));
        //removeSubTree(p);
    }
    p = parent(n)->_firstChild;
    if (p == n) {
        parent(n)->_firstChild = p->_nextSibling;
        delete n;
    } else {
        do {
            p = p->_nextSibling;
        } while (!lastSibling(p) || p->_nextSibling != n);

        p->_nextSibling = p->_nextSibling->_nextSibling;
        delete p->_nextSibling;
    }
}

template<class I>
void TreeLink<I>::writeNode(node n, item el) {
    n->_item = el;
}

template<class I>
typename TreeLink<I>::item TreeLink<I>::readNode(node n) const {
    return n->_item;
}

template<class I>
void TreeLink<I>::pre_print(node n) {
    if (n != nullptr) {
        cout << n->_item << " ";
        node p;
        if (!leaf(n)) {
            p = firstChild(n);
            while (!lastSibling(p)) {
                pre_print(p);
                p = nextSibling(p);
            }
            pre_print(p);
        }
    }
}

template<class I>
void TreeLink<I>::in_print(node n) {
    /*
    Stack<TreeNodeLink<I> *> *stack = new Stack<TreeNodeLink<I> *>;
    if (n != nullptr) {
        node p;
        if (!leaf(n)) {
            p = firstChild(n);
            while (!lastSibling(p)) {
                in_print(p);
                stack->push_no_duplicati(p);
                if (p == firstChild(n)) {
                    stack->push_no_duplicati(n);
                }
                p = nextSibling(p);
                in_print(p);
            }

        }


        stack->revert();
        while (!stack->empty()) {
            cout << stack->top()->_item << " ";
            stack->pop();

        }
    }
    */
}

/*


*/


template<class I>
void TreeLink<I>::post_print(node n) {
    if (n != nullptr) {
        node p;
        if (!leaf(n)) {
            p = firstChild(n);
            while (!lastSibling(p)) {
                post_print(p);
                p = nextSibling(p);
            }
            post_print(p);
        }
        cout << n->_item << " ";
    }
}


#endif
