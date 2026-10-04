#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};
void display(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}
struct Node* addPolynomial(struct Node *p1, struct Node *p2)
{
    struct Node *result = NULL;
    struct Node *temp = NULL;
    struct Node *newNode;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exp == p2->exp)
        {
            if(p1->coeff + p2->coeff != 0)
            {
                newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->coeff = p1->coeff + p2->coeff;
                newNode->exp = p1->exp;
                newNode->next = NULL;
                if (result == NULL)
                {
                    result = newNode;
                    temp = newNode;
                }
                else
                {
                    temp->next = newNode;
                    temp = temp->next;
                }
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp)
        {
            newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->coeff = p1->coeff;
            newNode->exp = p1->exp;
            p1 = p1->next;
            newNode->next = NULL;
            if (result == NULL)
            {
                result = newNode;
                temp = newNode;
            }
            else
            {
                temp->next = newNode;
                temp = temp->next;
            }
        }
        else
        {
            newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->coeff = p2->coeff;
            newNode->exp = p2->exp;
            p2 = p2->next;
            newNode->next = NULL;
            if (result == NULL)
            {
                result = newNode;
                temp = newNode;
            }
            else
            {
                temp->next = newNode;
                temp = temp->next;
            }
        }
    }
    return result;
}
int main()
{
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    struct Node *temp;
    struct Node *newNode;
    struct Node *result;
    int n1, n2;
    int i;
    scanf("%d", &n1);
    for (i = 0; i < n1; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d %d", &newNode->coeff, &newNode->exp);
        newNode->next = NULL;
        if (head1 == NULL)
        {
            head1 = newNode;
            temp = head1;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    scanf("%d", &n2);
    for (i = 0; i < n2; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d %d", &newNode->coeff, &newNode->exp);
        newNode->next = NULL;
        if (head2 == NULL)
        {
            head2 = newNode;
            temp = head2;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    result = addPolynomial(head1, head2);
    display(result);
    return 0;
}
