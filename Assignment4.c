// ============================================================
// 1. Queue using Array
// ============================================================
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1)
        printf("Queue Overflow! Cannot insert %d\n", value);
    else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = value;
        printf("%d inserted into queue\n", value);
    }
}

void dequeue() {
    if (front == -1 || front > rear)
        printf("Queue Underflow! Queue is empty\n");
    else {
        printf("%d deleted from queue\n", queue[front]);
        front++;
        if (front > rear) front = rear = -1;
    }
}

void display() {
    if (front == -1)
        printf("Queue is empty\n");
    else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

void peek() {
    if (front == -1)
        printf("Queue is empty\n");
    else
        printf("Front element: %d\n", queue[front]);
}

// ============================================================
// 2. Queue using Linked List
// ============================================================
struct Node {
    int data;
    struct Node* next;
};
struct Node *frontLL = NULL, *rearLL = NULL;

void enqueueLL(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (rearLL == NULL) {
        frontLL = rearLL = newNode;
    } else {
        rearLL->next = newNode;
        rearLL = newNode;
    }
    printf("%d inserted into queue\n", value);
}

void dequeueLL() {
    if (frontLL == NULL) {
        printf("Queue Underflow! Queue is empty\n");
        return;
    }
    struct Node* temp = frontLL;
    printf("%d deleted from queue\n", temp->data);
    frontLL = frontLL->next;
    if (frontLL == NULL) rearLL = NULL;
    free(temp);
}

void displayLL() {
    if (frontLL == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = frontLL;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void peekLL() {
    if (frontLL == NULL)
        printf("Queue is empty\n");
    else
        printf("Front element: %d\n", frontLL->data);
}

// ============================================================
// 3. Palindrome using Array and Queue
// ============================================================
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 100

char queuePal[MAX_SIZE];
int frontPal = -1, rearPal = -1;

void enqueuePal(char ch) {
    if (rearPal == MAX_SIZE - 1) return;
    if (frontPal == -1) frontPal = 0;
    rearPal++;
    queuePal[rearPal] = ch;
}

char dequeuePal() {
    if (frontPal == -1 || frontPal > rearPal) return '\0';
    char ch = queuePal[frontPal];
    frontPal++;
    if (frontPal > rearPal) frontPal = rearPal = -1;
    return ch;
}

int isPalindrome(char str[]) {
    int len = strlen(str);
    frontPal = rearPal = -1;
    for (int i = 0; i < len; i++) {
        char ch = tolower(str[i]);
        if (isalnum(ch)) enqueuePal(ch);
    }
    int frontIdx = frontPal, rearIdx = rearPal;
    while (frontIdx <= rearIdx) {
        if (queuePal[frontIdx] != queuePal[rearIdx])
            return 0;
        frontIdx++;
        rearIdx--;
    }
    return 1;
}

// ============================================================
// 4. Circular Queue using Array
// ============================================================
#define CMAX 5
int cqueue[CMAX];
int cfront = -1, crear = -1;

void enqueueC(int value) {
    if ((cfront == 0 && crear == CMAX - 1) || (crear == (cfront - 1) % (CMAX - 1))) {
        printf("Circular Queue Overflow! Cannot insert %d\n", value);
        return;
    }
    if (cfront == -1) {
        cfront = crear = 0;
    } else if (crear == CMAX - 1 && cfront != 0) {
        crear = 0;
    } else {
        crear++;
    }
    cqueue[crear] = value;
    printf("%d inserted into circular queue\n", value);
}

void dequeueC() {
    if (cfront == -1) {
        printf("Circular Queue Underflow! Queue is empty\n");
        return;
    }
    printf("%d deleted from circular queue\n", cqueue[cfront]);
    if (cfront == crear) {
        cfront = crear = -1;
    } else if (cfront == CMAX - 1) {
        cfront = 0;
    } else {
        cfront++;
    }
}

void displayC() {
    if (cfront == -1) {
        printf("Circular Queue is empty\n");
        return;
    }
    printf("Circular Queue elements: ");
    if (crear >= cfront) {
        for (int i = cfront; i <= crear; i++)
            printf("%d ", cqueue[i]);
    } else {
        for (int i = cfront; i < CMAX; i++)
            printf("%d ", cqueue[i]);
        for (int i = 0; i <= crear; i++)
            printf("%d ", cqueue[i]);
    }
    printf("\n");
}

// ============================================================
// 5. Stack using two Queues (Array-based)
// ============================================================
#define MAXSTACK 100
int q1[MAXSTACK], q2[MAXSTACK];
int front1 = -1, rear1 = -1, front2 = -1, rear2 = -1;
int sizeStack = 0;

void enqueueStack(int q, int value) {
    if (q == 1) {
        if (rear1 == MAXSTACK - 1) return;
        if (front1 == -1) front1 = 0;
        rear1++;
        q1[rear1] = value;
    } else {
        if (rear2 == MAXSTACK - 1) return;
        if (front2 == -1) front2 = 0;
        rear2++;
        q2[rear2] = value;
    }
}

int dequeueStack(int q) {
    int val;
    if (q == 1) {
        if (front1 == -1 || front1 > rear1) return -1;
        val = q1[front1];
        front1++;
        if (front1 > rear1) front1 = rear1 = -1;
        return val;
    } else {
        if (front2 == -1 || front2 > rear2) return -1;
        val = q2[front2];
        front2++;
        if (front2 > rear2) front2 = rear2 = -1;
        return val;
    }
}

int isEmptyStack() {
    return (sizeStack == 0);
}

void push(int value) {
    enqueueStack(1, value);
    sizeStack++;
    printf("%d pushed to stack\n", value);
}

int pop() {
    if (isEmptyStack()) {
        printf("Stack Underflow! Stack is empty\n");
        return -1;
    }
    while (sizeStack > 1) {
        int val = dequeueStack(1);
        enqueueStack(2, val);
        sizeStack--;
    }
    int popped = dequeueStack(1);
    sizeStack--;
    while (front2 != -1 && front2 <= rear2) {
        int val = dequeueStack(2);
        enqueueStack(1, val);
        sizeStack++;
    }
    printf("%d popped from stack\n", popped);
    return popped;
}

void peekStack() {
    if (isEmptyStack()) {
        printf("Stack is empty\n");
        return;
    }
    while (sizeStack > 1) {
        int val = dequeueStack(1);
        enqueueStack(2, val);
        sizeStack--;
    }
    int topVal = q1[front1];
    while (front2 != -1 && front2 <= rear2) {
        int val = dequeueStack(2);
        enqueueStack(1, val);
        sizeStack++;
    }
    printf("Top element: %d\n", topVal);
}

void displayStack() {
    if (isEmptyStack()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    int tempQ1[MAXSTACK], tempF = front1, tempR = rear1;
    while (tempF <= tempR && tempF != -1) {
        printf("%d ", q1[tempR]);
        tempR--;
    }
    printf("\n");
}

int main() {
    printf("========== 1. Queue using Array ==========\n");
    enqueue(10); enqueue(20); enqueue(30);
    display(); peek(); dequeue(); display();

    printf("\n========== 2. Queue using Linked List ==========\n");
    enqueueLL(40); enqueueLL(50); enqueueLL(60);
    displayLL(); peekLL(); dequeueLL(); displayLL();

    printf("\n========== 3. Palindrome Check ==========\n");
    char str1[] = "A man, a plan, a canal: panama";
    char str2[] = "Hello World";
    printf("\"%s\" is %s palindrome\n", str1, isPalindrome(str1) ? "a" : "not a");
    printf("\"%s\" is %s palindrome\n", str2, isPalindrome(str2) ? "a" : "not a");

    printf("\n========== 4. Circular Queue ==========\n");
    enqueueC(1); enqueueC(2); enqueueC(3); enqueueC(4); enqueueC(5);
    displayC(); dequeueC(); dequeueC(); enqueueC(6); displayC();

    printf("\n========== 5. Stack using two Queues ==========\n");
    push(100); push(200); push(300);
    displayStack(); peekStack(); pop(); displayStack();

    return 0;
}
