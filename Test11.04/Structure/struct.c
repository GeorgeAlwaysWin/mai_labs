#include "struct.h"

Deque* Deque_init() { //создание экземпляра Дека
    Deque *d = (Deque*) malloc(sizeof(Deque));
    d->size = 0;
    d->head = NULL;
    d->tail = NULL;
    return d;
}

void Deque_push_front(Deque *d) { //добавление узла в начало
    Node *nd = (Node*) malloc(sizeof(Node));
    nd->next = d->head;
    nd->prev = NULL;
    if (d->head) {
        d->head->prev = nd;
    }
    if (d->tail==NULL){
        d->tail = nd;
    }
    d->head = nd;
    d->size++;
}

void Deque_pop_back(Deque *d) { //удаление последнего элемента
    Node *end;
    if (d->tail == NULL) {
        exit(1); //если нечего удалять, выдается ошибка
    }
    end = d->tail;
    d->tail = d->tail->prev;
    if (d->tail) {
        d->tail->next = NULL;
    }
    if (end == d->head) {
        d->head = NULL; //если в деке один элемент, то удаляется и голова, и хвост
    }
    //если бы узлы хранили значения, здесь было бы val=end->value;
    free(end);

    d->size--;
    //если бы в узлах хранились значения, то здесь было бы return val;
}
