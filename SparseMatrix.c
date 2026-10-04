#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int row;
    int col;
    int value;
    struct Node *next;
};

int main()
{
    struct Node *head = NULL;
    struct Node *temp;
    struct Node *newNode;
    int r,c,i,j,value;

    scanf("%d %d",&r,&c);

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&value);

            if(value!=0)
            {
                newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->row = i;
                newNode->col = j;
                newNode->value = value;
                newNode->next = NULL;

                if(head == NULL)
                {
                    head = newNode;
                    temp = head;
                }
                else
                {
                    temp->next = newNode;
                    temp = temp->next;
                }
            }
        }
    }

    temp = head;

    while(temp != NULL)
    {
        printf("%d %d %d\n",temp->row,temp->col,temp->value);
        temp = temp->next;
    }

    return 0;
}
