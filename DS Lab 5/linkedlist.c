#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* next;
};

void push(struct Node** head_ref, int new_key)
{

    struct Node* new_node= (struct Node*)malloc(sizeof(struct Node));

    new_node->key = new_key;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

bool search(struct Node* head, int x)
{
    struct Node* current = head;
    while (current != NULL) {
        if (current->key == x)
            return true;
        current = current->next;
    }
    return false;
}


int main()
{

    struct Node* head = NULL;
    int x = 21;
    int n;


    push(&head, 10);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);

    while(true){
        printf("Type the Value t be checked!");
    scanf("%d",&n);


    search(head, n) ? printf("Yes\n") : printf("No\n");
    }
}
