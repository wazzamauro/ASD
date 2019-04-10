//
// Created by Mauro Nicolì on 2019-04-05.
//

#ifndef STRUTTURE_DATI_GRAPH_H
#define STRUTTURE_DATI_GRAPH_H


template<class W, class N>
class Arch_ {
public:
    N node_first;
    N nodo_second;
    W Weigth;
};


template<class I, class W, class N>
class Graph {
public:
    typedef I Item;
    typedef W Weigth;
    typedef N Node;

    typedef Arch_<Weigth, Node> Arch;
    typedef Vector_list<Node *> ListNodes;
    typedef typename Vector_list<Node *>::position PositionListNodes;
    typedef Vector_list<Arch> ListArches;

    virtual bool empty() const = 0;

    virtual void insNode(Node&) = 0;

    virtual void insArch(Node, Node, Weigth) = 0;

    virtual void deleteNode(Node) = 0;

    virtual void deleteArch(Node, Node) = 0;

    //	virtual bool existNodo(Node) = 0;

    //	virtual bool existArco(Arch) = 0;

    virtual ListNodes Neighbor(Node) const = 0;

    virtual ListNodes list_nodes() const = 0;

    virtual Item readItem(Node) const = 0;

    virtual void writeItem(Node, Item) = 0;

    virtual Weigth readWeigth(Node, Node) const = 0;

    virtual void writeWeigth(Node, Node, Weigth) = 0;

    virtual int numNodes() = 0;

    virtual int numArches() = 0;

    //virtual ~Graph() {};

};


#endif //STRUTTURE_DATI_GRAPH_H
