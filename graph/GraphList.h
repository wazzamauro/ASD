//
// Created by Mauro Nicolì on 2019-04-05.
//

#ifndef STRUTTURE_DATI_GRAPHLIST_H
#define STRUTTURE_DATI_GRAPHLIST_H

#include "Graph.h"
#include "../list/vector_list.h"
#include "../queue/queue.h"
#include "../stack/stack.h"

class NodeG {
public:

    NodeG() {
    }

    NodeG(int i) {
        nodeId = i;
    }

    int getId() const { return nodeId; }

    void setId(int id) { nodeId = id; }

private:
    int nodeId;
};


template<class W>
class InfoArch {
public:
    W Weigth;
    NodeG _to;
};


template<class I, class W>
class InfoNode {
public:
    I Item;
    bool empty;
    Vector_list<InfoArch<W>> arches;
    bool visited;

    InfoNode() {
        empty = true;
    }

    ~InfoNode() {
    }
};


template<class I, class W>
class GraphList : public Graph<I, W, NodeG> {
public:
    typedef I Item;
    typedef W Weigth;
    typedef NodeG Node;
    typedef Arch_<Weigth, Node> Arch;
    typedef Graph<Item, Weigth, Node> Graph_;
    typedef typename Graph_::ListNodes ListNodes;
    typedef typename Graph_::PositionListNodes PositionListNodes;

    GraphList(int);

    GraphList(const GraphList &);

    ~GraphList();

    bool empty() const;

    void insNode(Node &);

    void insArch(Node, Node, Weigth);

    void deleteNode(Node);

    void deleteArch(Node, Node);

    bool existNodo(Node);

    bool existArco(Arch);

    ListNodes Neighbor(Node) const;

    ListNodes list_nodes() const;

    Item readItem(Node) const;

    void writeItem(Node, Item);

    Weigth readWeigth(Node, Node) const;

    void writeWeigth(Node, Node, Weigth);

    int numNodes() {
        return _nodes;
    }

    int numArches() {
        return _arches;
    }

    void print();

    GraphList &operator=(const GraphList &);

    bool operator==(GraphList &);


    //implementare la procedura int inDegree(Node N), per grafi orientati, che restituisce il numero di archi entranti in N
    int inDegree(Node);

    //implementare la procedura int outDegree(Node N), per grafi orientati, che restituisce il numero di archi uscenti da N
    int outDegree(Node);

    //implementare la procedura double meanOutDegree(), per grafi orientati, che restituisce la media del numero di archi uscenti per ogni nodo del grafo
    double meanOutDegree();

    //implementare la procedura findPath(Node S, Node D) che stabilisce se esiste un path dal nodo S al nodo D, e in caso positivo lo stampa a video
    void findPath(Node, Node);

    void BFS(const Node &) const;

    void DFS(const Node &) const;

    void fill();

private:

    InfoNode<I, W> *_matrix;
    int _dimension;
    int _arches;
    int _nodes;

    void printAllPathsUtil(Node, Node, Node *, int &path_index);
};

template<class I, class W>
GraphList<I, W>::GraphList(int dim) {
    _dimension = dim;
    _arches = 0;
    _nodes = 0;
    _matrix = new InfoNode<I, W>[_dimension];
    for (int i = 0; i < _dimension; i++) {
        _matrix[i].arches.create();
    }
}


template<class I, class W>
GraphList<I, W>::GraphList(const GraphList &g) {
    _dimension = g._dimension;
    _arches = 0;
    _nodes = 0;
    _matrix = new InfoNode<I, W>[_dimension];
    for (int i = 0; i < g._dimension; i++) {
        if (!g._matrix[i].empty) {

            NodeG *new_node = new NodeG;
            _nodes++;
            _matrix[i].empty = false;
            new_node->setId(i);
            _matrix[i].Item = g._matrix[i].Item;
            typename Vector_list<InfoArch<W>>::position pos;
            pos = g._matrix[i].arches.begin();
            while (!g._matrix[i].arches.end(pos)) {
                _matrix[i].arches.push_back(g._matrix[i].arches.read(pos));
                pos = g._matrix[i].arches.next(pos);
            }
        }
    }
}


template<class I, class W>
GraphList<I, W>::~GraphList() {
    _nodes = 0;
    _arches = 0;
    delete[] _matrix;
}

template<class I, class W>
bool GraphList<I, W>::empty() const {
    return (_nodes == 0);
}

template<class I, class W>
void GraphList<I, W>::insNode(Node &n) {
    if (_nodes < _dimension) {
        for (int i = 0; i < _dimension; i++) {
            if (!_matrix[i].empty == false) {
                _nodes++;
                _matrix[i].empty = false;
                n.setId(i);
                break;
            }
        }
    }
}

template<class I, class W>
void GraphList<I, W>::insArch(Node from, Node to, W Weigth) {
    InfoArch<W> a;
    a.Weigth = Weigth;
    a._to = to;
    _matrix[from.getId()].arches.push_back(a);
}

template<class I, class W>
void GraphList<I, W>::deleteNode(Node n) {
    for (int i = 0; i < _dimension; i++) {
        if ((_matrix[i].empty == false) && i != (n.getId())) {
            typename Vector_list<InfoArch<W>>::position pos;
            pos = _matrix[i].arches.begin();
            while (!_matrix[i].arches.end(pos)) {
                if (_matrix[i].arches.read(pos)._to.getId() == n.getId()) {
                    _matrix[i].arches.erase(pos);
                }
            }
        }
    }
    _matrix[n.getId()].empty = true;
    _matrix[n.getId()].arches.clear();
    _nodes--;

}

template<class I, class W>
void GraphList<I, W>::deleteArch(Node from, Node to) {
    typename Vector_list<InfoArch<W>>::position pos;
    pos = _matrix[from.getId()].arches.begin();
    while (!_matrix[from.getId()].arches.end(pos)) {
        if (_matrix[from.getId()].arches.read(pos)._to.getId() == to.getId()) {
            _matrix[from.getId()].arches.erase(pos);
            _arches--;
        }
    }
}

template<class I, class W>
typename GraphList<I, W>::ListNodes GraphList<I, W>::Neighbor(Node n) const {
    ListNodes ln;
    typename Vector_list<InfoArch<W>>::position pos;
    pos = _matrix[n.getId()].arches.begin();
    while (!_matrix[n.getId()].arches.end(pos)) {
        NodeG *toins = new NodeG;
        *toins = _matrix[n.getId()].arches.read(pos)._to;
        ln.push_back(toins);
        pos = _matrix[n.getId()].arches.next(pos);
    }
    return ln;
}

template<class I, class W>
typename GraphList<I, W>::ListNodes GraphList<I, W>::list_nodes() const {
    ListNodes ln;
    for (int i = 0; i < _dimension; i++) {
        if (_matrix[i].empty == false) {
            NodeG *toins = new NodeG(i);
            ln.push_back(toins);
        }
    }
    return ln;
}

template<class I, class W>
I GraphList<I, W>::readItem(Node n) const {
    return _matrix[n.getId()].Item;
}

template<class I, class W>
void GraphList<I, W>::writeItem(Node n, I Item) {
    _matrix[n.getId()].Item = Item;
}

template<class I, class W>
W GraphList<I, W>::readWeigth(Node from, Node to) const {
    typename Vector_list<InfoArch<W>>::position pos;
    pos = _matrix[from.getId()].arches.begin();
    while (!_matrix[from.getId()].arches.end(pos)) {
        if (_matrix[from.getId()].arches.read(pos)._to.getId() == to.getId()) {
            return _matrix[from.getId()].arches.read(pos).Weigth;
        }
        pos = _matrix[from.getId()].arches.next(pos);
    }
}

template<class I, class W>
void GraphList<I, W>::writeWeigth(Node from, Node to, W Weigth) {
    typename Vector_list<InfoArch<W>>::position pos;
    pos = _matrix[from.getId()].arches.begin();
    bool flag = false;
    while (!_matrix[from.getId()].arches.end(pos)) {
        if (_matrix[from.getId()].arches.read(pos)._to.getId() == to.getId()) {
            flag = true;
        }
        pos = _matrix[from.getId()].arches.next(pos);
    }
    if (flag == true) {
        InfoArch<W> a;
        a.Weigth = Weigth;
        a._to = to;
        _matrix[from.getId()].arches.write(a, pos);
    }
}

template<class I, class W>
bool GraphList<I, W>::existNodo(Node n) {
    for (int i = 0; i < _dimension; i++) {
        if ((_matrix[i].empty == false) && (i == n.getId())) {
            return true;
        }
    }
    return false;
}

template<class I, class W>
bool GraphList<I, W>::existArco(Arch a) {
    for (int i = 0; i < _dimension; i++) {
        typename Vector_list<InfoArch<W>>::position pos;
        pos = _matrix[i].arches.begin();
        if (_matrix[i].empty == false) {
            while (!_matrix[i].arches.end(pos)) {
                if (_matrix[i].arches.read(pos) == a) {
                    return true;
                }
                pos = _matrix[i].arches.next(pos);
            }
        }
    }
    return false;
}

template<class I, class W>
void GraphList<I, W>::print() {
    for (int i = 0; i < _dimension; i++) {

        if (_matrix[i].empty == true) {
            cout << "( ";
            cout << "empty node";
            cout << " )" << endl;

        } else {
            cout << "( Id:[" << i << "]- Item:[" << _matrix[i].Item << "]) ";
            typename Vector_list<InfoArch<W>>::position pos;
            pos = _matrix[i].arches.begin();
            while (!_matrix[i].arches.end(pos)) {
                cout << "-> to:" << _matrix[_matrix[i].arches.read(pos)._to.getId()].Item;
                cout << "(" << _matrix[i].arches.read(pos).Weigth << ") ";
                pos = _matrix[i].arches.next(pos);

            }
            cout << endl;
        }
    }
}


template<class I, class W>
GraphList<I, W> &GraphList<I, W>::operator=(const GraphList &g) {
    _dimension = g._dimension;
    _arches = 0;
    _nodes = 0;
    _matrix = new InfoNode<I, W>[_dimension];
    for (int i = 0; i < g._dimension; i++) {
        if (!g._matrix[i].empty) {
            NodeG *new_node = new NodeG;
            _nodes++;
            _matrix[i].empty = false;
            new_node->setId(i);
            _matrix[i].Item = g._matrix[i].Item;
            typename Vector_list<InfoArch<W>>::position pos;
            pos = g._matrix[i].arches.begin();
            while (!g._matrix[i].arches.end(pos)) {
                _matrix[i].arches.push_back(g._matrix[i].arches.read(pos));
                pos = g._matrix[i].arches.next(pos);
            }
        }
    }
    return *this;
}

template<class I, class W>
bool GraphList<I, W>::operator==(GraphList &g) {
    bool compare = false;
    if (!(_nodes == g._nodes) || !(_arches == g._arches)) {
        return false;
    } else {
        int loop = max(_dimension, g._dimension);
        for (int i = 0; i < loop; i++) {
            if ((!_matrix[loop].empty) && (!g._matrix[loop].empty)) {
                if (_matrix[loop].Item != g._matrix[loop].Item) {
                    return false;
                } else {
                    typename Vector_list<InfoArch<W>>::position pos_g;
                    pos_g = g._matrix[i].arches.begin();

                    typename Vector_list<InfoArch<W>>::position pos_this;
                    pos_this = _matrix[i].arches.begin();

                    while (!g._matrix[i].arches.end(pos_g) && !this->_matrix[i].arches.end(pos_this)) {

                        if (_matrix[i].arches.read(pos_this).Weigth != g._matrix[i].arches.read(pos_g).Weigth) {
                            return false;
                        }
                        if (_matrix[_matrix[i].arches.read(pos_this)._to.getId()].Item !=
                            g._matrix[g._matrix[i].arches.read(pos_g)._to.getId()].Item) {
                            return false;
                        }
                        compare = true;

                        pos_g = g._matrix[i].arches.next(pos_g);
                        pos_this = _matrix[i].arches.next(pos_this);

                    }

                }
            }
        }
    }
    return compare;
}

//implementare la procedura int inDegree(Node N), per grafi orientati, che restituisce il numero di archi entranti in N
template<class I, class W>
int GraphList<I, W>::inDegree(Node n) {
    int count = 0;
    for (int i = 0; i < _dimension; i++) {
        if ((!_matrix[i].empty) && (i != n.getId())) {
            typename Vector_list<InfoArch<W>>::position pos;
            pos = _matrix[i].arches.begin();
            while (!_matrix[i].arches.end(pos)) {
                if (_matrix[i].arches.read(pos)._to.getId() == n.getId()) {
                    count++;
                }
                pos = _matrix[i].arches.next(pos);
            }
        }
    }
    return count;
}

//implementare la procedura int outDegree(Node N), per grafi orientati, che restituisce il numero di archi uscenti da N
template<class I, class W>
int GraphList<I, W>::outDegree(Node n) {
    return _matrix[n.getId()].arches.size();
}

//implementare la procedura double meanOutDegree(), per grafi orientati, che restituisce la media del numero di archi uscenti per ogni nodo del grafo
template<class I, class W>
double GraphList<I, W>::meanOutDegree() {
    double count = 0;
    for (int i = 0; i < _dimension; i++) {
        if (!_matrix[i].empty) {
            typename Vector_list<InfoArch<W>>::position pos;
            pos = _matrix[i].arches.begin();
            while (!_matrix[i].arches.end(pos)) {
                count++;
                pos = _matrix[i].arches.next(pos);
            }
        }
    }
    return count / _nodes;
}

//implementare la procedura findPath(Node S, Node D) che stabilisce se esiste un path dal nodo S al nodo D, e in caso positivo lo stampa a video
template<class I, class W>
void GraphList<I, W>::findPath(Node s, Node d) {
    bool *visited = new bool[_dimension];
    Node *path = new Node[_dimension];
    int path_index = 0;

    for (int i = 0; i < _dimension; i++) {
        _matrix[i].visited = false;
    }
    printAllPathsUtil(s, d, path, path_index);

}


template<class I, class W>
void GraphList<I, W>::printAllPathsUtil(Node u, Node d, Node path[], int &path_index) {
    _matrix[u.getId()].visited = true;
    path[path_index] = u.getId();
    path_index++;

    if (u.getId() == d.getId()) {
        for (int i = 0; i < path_index; i++) {
            cout << "[" << path[i].getId() << "]" << " : " << _matrix[path[i].getId()].Item << " , ";
        }
        cout << endl;
        // remove comment for only one path
        //return;
    } else {

        ListNodes curr_neighbor = Neighbor(u);
        PositionListNodes pos = curr_neighbor.begin();

        while (!curr_neighbor.end(pos)) {
            Node *n = curr_neighbor.read(pos);
            if (!_matrix[n->getId()].visited) {

                printAllPathsUtil(*n, d, path, path_index);

            }
            pos = curr_neighbor.next(pos);
        }

    }
    path_index--;
    _matrix[u.getId()].visited = false;
}

template<class I, class W>
void GraphList<I, W>::BFS(const Node &start) const {
    ListNodes nodes = list_nodes();
    PositionListNodes pos = nodes.begin();
    while (!nodes.end(pos)) {
        _matrix[nodes.read(pos)->getId()].visited = false;
        pos = nodes.next(pos);
    }
    Queue<Node> queue;
    _matrix[start.getId()].visited = true;
    queue.push(start.getId());

    while (!queue.empty()) {
        Node current = queue.top();
        cout << "[" << current.getId() << "] : " << _matrix[current.getId()].Item << " , ";
        queue.pop();

        ListNodes curr_neighbor = Neighbor(current);
        PositionListNodes pos = curr_neighbor.begin();

        while (!curr_neighbor.end(pos)) {
            if (_matrix[curr_neighbor.read(pos)->getId()].visited == false) {
                _matrix[curr_neighbor.read(pos)->getId()].visited = true;
                queue.push(curr_neighbor.read(pos)->getId());
            }
            pos = curr_neighbor.next(pos);
        }
    }
    for (int i = 0; i < _dimension; i++) {
        if (!_matrix[i].visited && !_matrix[i].empty) {
            _matrix[i].visited = true;
            queue.push(i);
        }
    }
    while (!queue.empty()) {
        cout << " -[" << queue.top().getId() << "] : " << _matrix[queue.top().getId()].Item << " , ";
        queue.pop();
    }
}

template<class I, class W>
void GraphList<I, W>::DFS(const Node &start) const {
    ListNodes nodes = list_nodes();
    PositionListNodes pos = nodes.begin();
    while (!nodes.end(pos)) {
        _matrix[nodes.read(pos)->getId()].visited = false;
        pos = nodes.next(pos);
    }

    Stack<Node> stack;
    _matrix[start.getId()].visited = true;
    stack.push(start.getId());
    while (!stack.empty()) {

        Node current = stack.top();
        cout << "[" << current.getId() << "] : " << _matrix[current.getId()].Item << " , ";
        stack.pop();

        ListNodes curr_neighbor = Neighbor(current);
        PositionListNodes pos = curr_neighbor.begin();

        while (!curr_neighbor.end(pos)) {
            if (_matrix[curr_neighbor.read(pos)->getId()].visited == false) {
                _matrix[curr_neighbor.read(pos)->getId()].visited = true;
                stack.push(curr_neighbor.read(pos)->getId());
            }
            pos = curr_neighbor.next(pos);
        }
    }
    for (int i = 0; i < _dimension; i++) {
        if (!_matrix[i].visited && !_matrix[i].empty) {
            _matrix[i].visited = true;
            stack.push(i);
        }
    }
    while (!stack.empty()) {
        cout << " -[" << stack.top().getId() << "] : " << _matrix[stack.top().getId()].Item << " , ";
        stack.pop();
    }
}

template<class I, class W>
void GraphList<I, W>::fill() {

    for (int i = 0; i < _dimension; i++) {
        NodeG *temp = new NodeG;
        insNode(*temp);
        I item;
        cout << "Inserisci valore per il nodo " << temp->getId() + 1 << ": "<< endl;
        cin >> item;
        writeItem(*temp, item);
    }
    cout << "Il grafo è stato creato" << endl;
    print();
    cout << endl;
    cout << "Vuoi inserire archi ai nodi? (s/n)" << endl;
    char ans;
    cin >> ans;
    if (ans == 's') {
        for (int j = 0; j < _dimension; ++j) {

            cout << "Quanti archi per il nodo " << _matrix[j].Item << " ?" << endl;
            int arc;
            cin >> arc;
            for (int i = 0; i < arc; i++) {
                cout << "Verso quale nodo punta l'arco " << i + 1 << " del nodo "<< _matrix[j].Item <<"? (inserire Id)" << endl;
                int nodeto;
                cin >> nodeto;
                NodeG *to = new NodeG(nodeto);

                cout << "Che peso ha questo arco? " << endl;
                W w;
                cin >> w;
                insArch(j, to->getId()-1, w);
            }
        }
    }
}

#endif //STRUTTURE_DATI_GRAPHLIST_H
