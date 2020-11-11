#include "stdio.h"
#include "stdlib.h"
typedef struct Node {
    int val;
    struct Node* next;
} Node;

void printList(Node* list) {
    while(list) {
        printf("%d ", list->val);
        list = list->next;
    }
    printf("\n");
}

Node* partition(Node* lo, Node* hi) {
    Node* pivot = hi;
    Node* i = lo;
    for (Node* j = lo; j != hi; j = j->next) {
        if (j->val <= pivot->val) {
            int temp = i->val;
            i->val = j->val;
            j->val = temp;
            i = i->next;
        }
    }
    int temp = i->val;
    i->val = hi->val;
    hi->val = temp;
    return i;
}

void quicksort(Node* lo, Node* hi) {
    // Quick sort on a singly linked list
    if (lo == NULL || hi == NULL || lo == hi) return;
    if (lo->next == hi && lo->val <= hi->val) return;
    if (lo != hi) {
        Node* p = partition(lo, hi);
        quicksort(lo, p);
        quicksort(p->next, hi);
    }
}

int main() {
    Node* n1 = malloc(sizeof(Node));
    Node* n2 = malloc(sizeof(Node));
    Node* n3 = malloc(sizeof(Node));
    Node* n4 = malloc(sizeof(Node));
    Node* n5 = malloc(sizeof(Node));
    n1->val = 3;
    n2->val = 4;
    n3->val = 2;
    n4->val = 5;
    n5->val = 1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;

    printList(n1);
    quicksort(n1, n5);
    printList(n1);

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);

    return 0;
}
