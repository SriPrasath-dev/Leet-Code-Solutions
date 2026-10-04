#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// INSERT AT BEGINNING
struct Node* insertBeg(struct Node *head, int value) {

    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = head;

    head = newNode;

    return head;
}

// INSERT AT END
struct Node* insertEnd(struct Node *head, int value) {

    struct Node *newNode = malloc(sizeof(struct Node));
    struct Node *temp = head;

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        temp = head;
    }
    else {
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        temp = newNode;
    }

    return head;
}

// INSERT AT POSITION
struct Node* insertPos(struct Node *head, int value, int pos) {

    struct Node *newNode = malloc(sizeof(struct Node));
    struct Node *temp = head;

    newNode->data = value;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return head;
    }

    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// DISPLAY
void display(struct Node *head) {

    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {

    struct Node *head = NULL;

    head = insertBeg(head, 20);
    head = insertEnd(head, 40);
    head = insertPos(head, 30, 2);

    display(head);

    return 0;
}
