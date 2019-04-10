//
// Created by Mauro Nicolì on 2019-03-31.
//

#ifndef STRUTTURE_DATI_TREE_H
#define STRUTTURE_DATI_TREE_H
#ifndef TREE_H
#define TREE_H

template<class I, class N>
class Tree {
public:
    typedef I item;
    typedef N node;

    virtual bool empty() const = 0;

    virtual void insRoot(item) = 0;

    virtual node root() const = 0;

    virtual node parent(node) const = 0;

    virtual bool leaf(node) const = 0;

    virtual node firstChild(node) const = 0;

    virtual bool lastSibling(node) const = 0;

    virtual node nextSibling(node) const = 0;

    virtual void insFirstSubTree(node, Tree &) = 0;

    virtual void insSubTree(node, Tree &) = 0;

    virtual void removeSubTree(node) = 0;

    virtual void writeNode(node, item) = 0;

    virtual item readNode(node) const = 0;

    void in_print(node);

    void pre_print(node);

    void post_print(node);


};

template<class I, class N>
void Tree<I, N>::in_print(node n) {

}

template<class I, class N>
void Tree<I, N>::pre_print(node n) {

}

template<class I, class N>
void Tree<I, N>::post_print(node n) {

}

#endif
#endif //STRUTTURE_DATI_TREE_H
