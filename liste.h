//
// Created by gnp on 27/11/18.
//

#ifndef POLI_LISTE_H
#define POLI_LISTE_H

typedef struct MonoList{
    int value;
    struct MonoList *next;
}MonoList;


MonoList*   createElement(int value);
MonoList*   createMonoList(int n);
MonoList*   getLastElement(MonoList *list);
MonoList*   getElementAt(MonoList *list,int pos);
MonoList*   extractElement(MonoList **list,int pos);
MonoList*   searchElement(int value,MonoList* list);

void        delElement(int pos,MonoList** list_);
void        addElement(int value,MonoList **list,int pos);
void        printMonoList(MonoList* list);
void        fillMonoList(MonoList *list);
int         lenMonoList(MonoList *list);
#define PRINT_ELEMENT(x) printf("value:\t%d\n",x->value)


void        headPush(MonoList **list,int value);
MonoList*   headPop(MonoList **list);

void        tailPush(MonoList **list,int value);
MonoList*   tailPop(MonoList **list);
void        tailPushOptimized(MonoList**list,MonoList *ele,MonoList **last);
MonoList*   tailPopOptimized(MonoList**list,MonoList **last);
#endif //POLI_LISTE_H
