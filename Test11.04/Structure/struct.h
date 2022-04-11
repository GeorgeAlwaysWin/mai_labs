#ifndef STRUCT_H
#define STRUCT_H
#include <stdlib.h>


typedef struct _Node { //узел - структурная единица связного списка, на основе которого строится дек
    //int *value; //значение узла (для задания можно обойтись без него)
    struct _Node *next; //ссылка на следующий узел
    struct _Node *prev; //ссылка на прошлый узел
} Node;

typedef struct _Deque {
    size_t size;  //размер дека
    Node *head; //ссылка на первый элемент
    Node *tail; //ссылка на последний элемент
} Deque;

Deque* Deque_init(); //создание дека
void Deque_push_front(Deque *d); //добавление узла в начало
void Deque_pop_back(Deque *d); //удаление последнего элемента
//для полноценного дека (двусторонней очереди) необходимо реализовать еще:
//void Deque_pop_front(Deque *d); //удаление первого элемента
//void Deque_push_back(Deque *d); //добавление в конец
//void Deque_get_size(Deque *d); //получение размера дека
//void Deque_destroy(Deque *d); //удаление дека


#endif