#include <stdlib.h>

typedef struct ListEl {
    int data;
    struct ListEl * nxt;
} ListEl;

ListEl * list_build();
ListEl * insertAHead();
ListEl * insertAtTheEnd();
ListEl * searchAValue();
ListEl * listCopy();

int main()
{
    ListEl * head;
    head = list_build();

    ListEl * headSecond;

    ListEl * valueSearched;

    int ListLength;

    head = insertAHead(head, 56);
    head = insertAHead(head, 32);
    head = insertAHead(head, 0);
    head = insertAHead(head, 21);
    head = insertAtTheEnd(head, 226);

    printTheList(head);

    ListLength = LengthOfTheList(head);
    printf("\nlength : %d \n", ListLength);

    valueSearched = searchAValue(head, 0);
    if(valueSearched) printf("%d", valueSearched->data);

    //headSecond = listcopy(head);

    deleteTheList(head);

    return 0;
}

ListEl * list_build(void)
{
    int values[] = { 8, 14, 13, 17, 1, 19, 16, 5, 3, 11, 2,
                     15, 9, 10, 6, 22, 4, 7, 18, 27, -1 };
    ListEl * lis = NULL;

    int i;
    for (i = 0; values[i] != -1; ++i) {
        ListEl * u;
        u = (ListEl*) malloc(sizeof(ListEl));
        u->nxt = lis;
        u->data = values[i];
        lis = u;
    }
    return lis;
}

void printTheList(ListEl * h)
{
    ListEl * it = h;

    while(it)
    {
        printf("%d ", it->data);
        it = it->nxt;
    }
}

int LengthOfTheList(ListEl * h)
{
    int ct = 0;
    ListEl * it = h;

    while(it)
    {
        ct++;
        it = it->nxt;
    }

    return ct;
}

void deleteTheList(ListEl * h)
{
    ListEl * it = h;
    ListEl * tmp;

    while(it)
    {   tmp = it;
        it = it->nxt;
        free(tmp);
    }
}

ListEl * insertAHead(ListEl * h, int a)
{
    ListEl * u;
    u = (ListEl*)malloc(sizeof(ListEl));
    u->data = a;
    u->nxt = h;

    return u;
}

ListEl * insertAtTheEnd(ListEl * h, int a)
{
    ListEl * it;

    ListEl * u;
    u = (ListEl*)malloc(sizeof(ListEl));
    u->data = a;
    u->nxt = NULL;

    if(h == NULL) return u;

    while(it->nxt) it = it->nxt;
    it->nxt = u;
    return h;
}

ListEl * searchAValue(ListEl * h, int a)
{
    ListEl * it = h;

    while(it)
    {
        if(it->data == a) return it;
        it = it->nxt;
    }
    return NULL;
}

ListEl * listCopy(ListEl * h)
{
    ListEl * it = h;
    ListEl * temp = NULL;
    ListEl * newHead = NULL;

    while(it)
    {
        ListEl * u;
        u = (ListEl*)malloc(sizeof(ListEl));
        u->data = it->data;

        if(temp) temp->nxt = u;
        temp = u;

        if(!newHead) newHead = u;
    }

    return newHead;
}

