#include <stdio.h>
#include <stdlib.h>
void Push();
void Pop();
void Display();
void Peek();

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *top = NULL, *newNode, *head, *temp;
int max, count = 0;

int main()
{
    printf("\033[1;33menter the maximum size of stack: \033[0m");
    scanf("%d", &max);
    int choice;
    while (1)
    {
        printf("\n\x1b[32m1.PUSH\x1b[0m\n\x1b[31m2.POP\x1b[0m\n\x1b[34m3.PEEK\x1b[0m\n\x1b[35m4.DISPLAY\x1b[0m\n\x1b[36m5.EXIT\x1b[0m\n\nChoose an operation: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Push();
            break;
        case 2:
            Pop();
            break;
        case 3:
            Peek();
            break;
        case 4:
            Display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\033choose a valid operation!");
        }
    }
    return 0;
}

void Push()
{
    if (count == max)
    {
        printf("Stack is overflow!");
    }
    else
    {
        printf("enter the element to push: ");
        newNode = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        printf("Element is pushed successfully");
        if (count == 0)
        {
            top = newNode;
            head = top;
            newNode->next = NULL;
        }
        else
        {
            top->next = newNode;
            newNode->next = NULL;
            top = newNode;
        }
        count++;
    }
}

void Pop()
{
    if (count == 0)
    {
        printf("Stack is underflow!");
    }
    else
    {
        temp = head;
        if (temp == top)
        {
            head = NULL;
            free(top);
            count = 0;
        }
        while (temp != top)
        {

            if (temp->next == top)
            {
                free(temp->next);
                count--;
                temp->next = NULL;
                top = temp;
                break;
            }
            if (temp == top)
            {
                break;
            }
            temp = temp->next;
        }

        printf("Element is poped successfully!");
    }
}

void Display()
{
    if (count == 0)
    {
        printf("stack is underflow!");
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
    }
}
void Peek()
{
    if (count == 0)
    {
        printf("Stack is underflow! ");
    }
    else
    {
        printf("The peek element is %d ", top->data);
    }
}
