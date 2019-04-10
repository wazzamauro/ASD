//
// Created by Mauro Nicolì on 2019-04-08.
//

#ifndef STRUTTURE_DATI_PRIORITYQUEUE_H
#define STRUTTURE_DATI_PRIORITYQUEUE_H

template<class T>
class CodaP {

public:
    typedef T _item;

    CodaP();

    CodaP(int);

    CodaP(const CodaP<T> &);

    ~CodaP();

    void insert(_item);

    _item min();

    void deleteMin();

    CodaP &operator=(const CodaP &);

    bool operator==(CodaP &);

    void print();

    void print_tree_form();

private:

    int _dimension;

    _item *_heap;

    int _last;

    void fixUp();

    void fixDown(int, int);

    bool is_empty();

    bool is_full();
};


template<class T>
CodaP<T>::CodaP() {
    _dimension = 100;
    _heap = new _item[_dimension];
    _last = 0;
};

template<class T>
CodaP<T>::CodaP(int dim) {
    _dimension = dim;
    _heap = new _item[_dimension];
    _last = 0;
};

template<class T>
CodaP<T>::CodaP(const CodaP<T> &c) {
    _dimension = c._dimension;
    _last = c._last;
    _heap = new _item[_dimension];
    for (int i = 0; i < _last; i++) {
        _heap[i] = c._heap[i];
    }
}

template<class T>
CodaP<T>::~CodaP() {
    delete[] _heap;
}

template<class T>
void CodaP<T>::insert(_item i) {
    if (!is_full()) {
        _last++;
        _heap[_last - 1] = i;
        fixUp();
    }
};

template<class T>
typename CodaP<T>::_item CodaP<T>::min() {
    if (!is_empty()) {
        return (_heap[0]);
    }
}

template<class T>
void CodaP<T>::deleteMin() {
    if (!is_empty()) {

        //copia il valore dell'ultima foglia nella radice
        _heap[0] = _heap[_last - 1];
        _last--;
        //fai scendere verso il basso
        fixDown(1, _last);
    }
}


/* Per ripristinare i vincoli dello _heap quando la priorità di un nodo è      *
 * cresciuta, ci spostiamo nello _heap verso l'alto, scambiando, se necessario,*
 * il nodo in posizione k con il suo nodo padre (in posizione k/2),           *
 * continuando fintanto che _heap[k]<_heap[k/2] oppure fino a quando            *
 * raggiungiamo la cima dello _heap.                                           */

template<class T>
void CodaP<T>::fixUp() {
    int k = _last;

    while (k > 1 && _heap[k - 1] < _heap[k / 2 - 1]) {
        _item tmp;
        tmp = _heap[k - 1];
        _heap[k - 1] = _heap[k / 2 - 1];
        _heap[k / 2 - 1] = tmp;
        k = k / 2;
    }

}

/* Per ripristinare i vincoli dello _heap quando la priorità di un nodo si è   *
 * ridotta, ci spostiamo nello _heap verso il basso, scambiando, se necessario,*
 * il nodo in posizione k con il minore dei suoi nodi figli e arrestandoci    *
 * quando il nodo al posto k non è più grande di almeno uno dei suoi figli    *
 * oppure quando raggiungiamo il fondo dello _heap. Si noti che se N è pari e  *
 * k è N/2, allora il nodo in posizione k ha un solo figlio: questo caso      *
 * particolare deve essere trattato in modo appropriato.                      */

template<class T>
void CodaP<T>::fixDown(int k, int N) {

    short int scambio = 1;

    while (k <= N / 2 && scambio) {
        int j = 2 * k;
        _item tmp;
        if (j < N && _heap[j - 1] > _heap[j])
            j++;
        if ((scambio = (_heap[j - 1] < _heap[k - 1]))) {
            tmp = _heap[k - 1];
            _heap[k - 1] = _heap[j - 1];
            _heap[j - 1] = tmp;
            k = j;
        }
    }
}

template<class T>
bool CodaP<T>::is_empty() {
    return (_last == 0);
}

template<class T>
bool CodaP<T>::is_full() {
    return (_last == _dimension);
}

template<class T>
CodaP<T> &CodaP<T>::operator=(const CodaP &c) {
    _dimension = c._dimension;
    _last = c._last;
    _heap = new _item[_dimension];
    for (int i = 0; i < _last; i++) {
        _heap[i] = c._heap[i];
    }
    return *this;
}

template<class T>
bool CodaP<T>::operator==(CodaP &c) {
    bool flag = false;
    if (_last != c._last) {
        return false;
    } else {
        for (int i = 0; i < _last; i++) {
            if (_heap[i] != c._heap[i]) {
                return false;
            } else {
                flag = true;
            }
        }
    }
    return flag;
}

template<class T>
void CodaP<T>::print() {
    cout << "[ ";
    for (int i = 0; i < _last; i++) {
        if (i == 0) {
            cout << _heap[i];
        } else {
            cout << " , " << _heap[i];
        }
        //cout << " ]";
    }
    cout << " ]" << endl;
}

template<class T>
void CodaP<T>::print_tree_form() {
    for (int i = 0; i < _last; i++) {
        cout << _heap[i] << " : ";
        if (i < _last - 2) {
            cout << _heap[2 * i + 1];
        }
        if (i < _last - 3) {
            cout << "  " << _heap[(2 * i) + 2];
        }
        cout << endl;

    }
}

#endif //STRUTTURE_DATI_PRIORITYQUEUE_H
