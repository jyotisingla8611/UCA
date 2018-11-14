// C or C++ program for insertion and
// deletion in Circular Queue
#include <stdio.h>
#include<stdlib.h>
#include<limits.h>
// Structure of a Node
typedef struct Node
{
    int data;
    struct Node* next;
}Node;

typedef struct Queue
{
    struct Node *front, *rear;
}Queue;

Node* create_node() {
    Node *nn = (Node*)malloc(sizeof(Node));
    nn->next = NULL;
    return nn;
}

Queue* create_queue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to create Circular queue
void enQueue(Queue *q, int value)
{
    Node *temp = create_node();
    temp->data = value;
    if (q->front == NULL)
        q->front = temp;
    else
        q->rear->next = temp;

    q->rear = temp;
    q->rear->next = q->front;
  //  printf("%d %d %d\n ",q->front->data,q->rear->data,q->rear->next->data);
}

// Function to delete element from Circular Queue
int deQueue(Queue *q)
{
    if (q->front == NULL)
    {
        printf ("Queue is empty");
        return INT_MIN;
    }

    // If this is the last node to be deleted
    int value; // Value to be dequeued
    if (q->front == q->rear)
    {
        value = q->front->data;
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    }
    else  // There are more than one nodes
    {
        Node *temp = q->front;
        value = temp->data;
        q->front = q->front->next;
        q->rear->next= temp; //temp == q->front
        free(temp);
    }

   return value ;
}

// Function displaying the elements of Circular Queue
void displayQueue(Queue *q)
{
    Node *temp = q->front;
    printf("\nElements in Circular Queue are: ");
    while (temp->next != q->front)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
}

/* Driver of the program */
int main()
{
    // Create a queue and initialize front and rear
    Queue *q = create_queue();
    q->front = q->rear = NULL;

    // Inserting elements in Circular Queue
    enQueue(q, 14);
    enQueue(q, 22);
    enQueue(q, 6);

    // Display elements present in Circular Queue
    displayQueue(q);

    // Deleting elements from Circular Queue
    printf("\nDeleted value = %d", deQueue(q));
    printf("\nDeleted value = %d", deQueue(q));

    // Remaining elements in Circular Queue
    displayQueue(q);

    enQueue(q, 9);
    enQueue(q, 20);
    displayQueue(q);

    return 0;
}
