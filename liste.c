//
// Created by gnp on 27/11/18.
//

#include <malloc.h>
#include "liste.h"

MonoList* createElement(int value){
    MonoList *to_ret = (MonoList*)malloc(sizeof(MonoList));
    to_ret->value = value;
    to_ret->next = NULL;
    return to_ret;
}


MonoList*   createMonoList(int n){
    MonoList* list = (MonoList*) malloc(sizeof(MonoList));
    MonoList* temp = list;

    for(int i=1;i<n;i++){
        temp->next = (MonoList*) malloc(sizeof(MonoList));
        temp = temp->next;
    }

    temp->next = NULL;
    return list;
};


void delElement(int pos,MonoList** list_){
  MonoList *to_del = NULL, *list = *list_;
  int len = lenMonoList(list);

  if(pos == 1){
      to_del = list;
      *list_ = list->next;
  }else if(pos==len){
      to_del = getLastElement(list);
      getElementAt(list,pos-1)->next = NULL;
  }else{
      to_del = getElementAt(list,pos);
      getElementAt(list,pos-1)->next = getElementAt(list,pos+1);
  }

  free(to_del);
};

void        addElement(int value,MonoList **list_,int pos){
    MonoList *to_add = createElement(value);
    MonoList *list = *list_;

    int len = lenMonoList(list);
    if(len+1==pos)
        getLastElement(list)->next = to_add;
    else if(pos==1){
        to_add->next = list;
        *list_ = to_add;
    }else {

        for (int i = 0; i < pos - 2; i++)
            list = list->next;

        to_add->next = list->next;
        list->next = to_add;
    }
};

void    printMonoList(MonoList* list){
    if(!list)
        return;

    int counter = 0;
    printf("Value at position %d is %d\n", counter++, list->value);
    while(list->next!= NULL){
        list = list->next;
        printf("Value at position %d is %d\n", counter++, list->value);
    }
}

void fillMonoList(MonoList *list){
    if(!list)
        return;

    int counter = 0;
    printf("Insert the value at the %d position:\t", counter++);
    scanf("%d",&list->value);

    while(list->next!= NULL){
        list = list->next;
        printf("Insert the value at the %d position:\t", counter++);
        scanf("%d",&list->value);
    }
}

int lenMonoList(MonoList *list){
    int len = 0;

    if(list!=NULL)
        while(list->next!= NULL){
            len++;
            list = list->next;
        }

    return len;
}

MonoList*   getLastElement(MonoList *list){
    if(!list)
        return NULL;

    for(;list->next!=NULL;list=list->next);
    return list;
}

MonoList* getElementAt(MonoList* list,int pos){
    if(!list)
        return list;

    return pos==1 ? list : getElementAt(list->next,--pos);
}

MonoList* sortElement(int value,MonoList *list){
    int len = lenMonoList(list);
    MonoList *to_ret = NULL,*tmp = list;
    for(int i=0;i<len;i++){

    }
}

MonoList*   extractElement(MonoList **list,int pos){
    if(*list==NULL)
        return NULL;
    int len = lenMonoList(*list);

    MonoList *to_ret = NULL, *tmp = NULL;

    if(len +1== pos){
        tmp = getElementAt(*list,pos-1);
        to_ret = tmp->next;
        tmp->next = NULL;
    }else if(pos==1){
        to_ret = *list;
        (*list) = (*list)->next;
    }else{
        tmp = getElementAt(list,pos-1);
        to_ret = tmp->next;
        tmp->next = to_ret->next;
    }

    return to_ret;
}

void        headPush(MonoList **list,int value){

    if(*list == NULL) {
        MonoList *ele = createElement(value);
        *list = ele;
    }else
        addElement(value,list,1);

}

MonoList*   headPop(MonoList **list){
    return extractElement(list,1);
};

void        tailPush(MonoList **list,int value){
    MonoList *last = getLastElement(*list);
    MonoList *ele = createElement(value);
    tailPushOptimized(list,ele,&last);
};

MonoList*   tailPop(MonoList **list){
    MonoList *last = getLastElement(list);
    tailPopOptimized(list,last);
};


void        tailPushOptimized(MonoList**list,MonoList *ele,MonoList **last){
    if(*list == *last)
        (*list)->next = ele;
    else
        (*last)->next = ele;
}

MonoList*   tailPopOptimized(MonoList**list,MonoList **nm1_last){
    MonoList    *to_ret = NULL;

    if(*list==NULL)
        return NULL;
    else{
        if(*list == *nm1_last) {
            to_ret = *nm1_last;
            *nm1_last = NULL;
        }else {
            to_ret = (*nm1_last)->next;
            (*nm1_last)->next = NULL;
        }
    }

    return to_ret;
}