#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct queue
{
    struct node *front;
    struct node *rear;
};

struct queue* createqueue()
{
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->rear = NULL;
    q->front = NULL;
    return q;
}

void enqueue(int item, struct queue *q)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = NULL;
    if (q->front == NULL) {
        q->front = newnode;
        q->rear = newnode;
    }
    else {
        q->rear->next = newnode;
        q->rear = newnode;
    }
}

void dequeue(struct queue *q)
{
    struct node *temp = q->front;
    if (q->rear == q->front && q->rear == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("Popped element is %d\n", temp->data);
        q->front = temp->next;
        free(temp);
    }
}

void display(struct queue *q)
{
    struct node *temp;
    temp = q->front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int a, e, flag = 1;
    struct queue *q = createqueue();
    while (flag == 1)
    {
        printf("Enter your choice (1-Enqueue, 2-Dequeue, 3-Display, 4-Exit): ");
        scanf("%d", &a);
        switch (a)
        {
            case 1:
                printf("Enter the value to be entered: ");
                scanf("%d", &e);
                enqueue(e, q);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Enter a valid number\n");
        }
    }
    return 0;
}
