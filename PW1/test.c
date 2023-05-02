#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[100];
    int size_mb;
    int est_time_min;
} Program;

typedef struct Node
{
    Program program;
    struct Node *next;
} Node;

typedef struct
{
    Node *front;
    Node *rear;
} Queue;

Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int isEmpty(Queue *queue)
{
    return (queue->front == NULL);
}

void enqueue(Queue *queue, Program program)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->program = program;
    newNode->next = NULL;
    if (isEmpty(queue))
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

void dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
    }
    else
    {
        Node *temp = queue->front;
        queue->front = queue->front->next;
        if (queue->front == NULL)
        {
            queue->rear = NULL;
        }
        free(temp);
    }
}

void display(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
    }
    else
    {
        Node *temp = queue->front;
        while (temp != NULL)
        {
            printf("%s\t\t%d MB\t%d min\n", temp->program.name, temp->program.size_mb, temp->program.est_time_min);
            temp = temp->next;
        }
    }
}

int main()
{
    Queue *queue = createQueue();
    Program program1 = {"Microsoft Word", 500, 3};
    Program program2 = {"Adobe Photoshop", 2000, 10};
    Program program3 = {"Google Chrome", 200, 1};
    Program program4 = {"Spotify", 100, 2};
    Program program5 = {"Visual Studio Code", 300, 5};

    enqueue(queue, program1);
    enqueue(queue, program2);
    enqueue(queue, program3);
    enqueue(queue, program4);
    enqueue(queue, program5);

    printf("Program Name\tSize\tEstimated Time\n");
    display(queue);

    dequeue(queue);
    printf("\nAfter Dequeue\n");
    printf("Program Name\tSize\tEstimated Time\n");
    display(queue);

    return 0;
}
