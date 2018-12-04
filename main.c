#include <stdio.h>
#include <malloc.h>
#include "liste.h"
int main() {
    MonoList *list = createMonoList(3);
    fillMonoList(list);

    printf("\n\n\n\n\n");
    printMonoList(list);

    addElement(6,&list,1);
    addElement(9,&list,3);

    printf("1-1-1-1-1-1-1-1-1-1-1-1-1-1\n\n\n\n\n");
    printMonoList(list);


    addElement(15646,&list,1);
    printf("2-2-2-2-2-2-2-2-2-2-2-2-2-2\n\n\n\n\n");
    printMonoList(list);

    headPush(&list,524);
    headPush(&list,521);
    headPush(&list,522);


    printf("3-3-3-3-3-3-3-3-3-3-3-3-3-3\n\n\n\n\n");
    printMonoList(list);

    tailPush(&list,523);
    tailPush(&list,525);


    tailPush(&list,524);
    tailPush(&list,521);
    tailPush(&list,522);


    printf("4-4-4-4-4-4-4-4-4-4-4-4-4-4\n\n\n\n\n");

    delElement(2,&list);
    printf("\n\n\n\n");
    printMonoList(list);



    //pop element from tail
    return 0;

}