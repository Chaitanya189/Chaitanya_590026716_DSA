/* ============================================================
   PROGRAM 1
   Hash Function on SAP-ID → 10 Families
   Family = sum of last 3 digits of SAP-ID % 10
   ============================================================ */
 
#include <stdio.h>
 
int hash_family(long sap_id) {
    int last3 = sap_id % 1000;
    int d1 = last3 / 100;
    int d2 = (last3 / 10) % 10;
    int d3 = last3 % 10;
    return (d1 + d2 + d3) % 10;
}
 
int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
 
    for (int i = 0; i < n; i++) {
        long sap;
        printf("Enter SAP-ID of student %d: ", i + 1);
        scanf("%ld", &sap);
        printf("SAP-ID %ld belongs to Family %d\n\n", sap, hash_family(sap));
    }
    return 0;
} 
 
/* ============================================================
   PROGRAM 2
   Hash Table using Array with Linear Probing (collision handling)
   Operations: Insert, Delete, Search
   ============================================================ */
 
#include <stdio.h>
 
#define SIZE 10
#define EMPTY -1
#define DELETED -2
 
int table[SIZE];
 
void init() {
    for (int i = 0; i < SIZE; i++)
        table[i] = EMPTY;
}
 
int hash(long sap_id) {
    int last3 = sap_id % 1000;
    int d1 = last3 / 100, d2 = (last3 / 10) % 10, d3 = last3 % 10;
    return (d1 + d2 + d3) % SIZE;
}
 
void insert(long sap_id) {
    int key = hash(sap_id);
    int start = key;
    int val = sap_id % 10000;
 
    do {
        if (table[key] == EMPTY || table[key] == DELETED) {
            table[key] = val;
            printf("Inserted %ld at index %d\n", sap_id, key);
            return;
        }
        printf("Collision at index %d, probing next...\n", key);
        key = (key + 1) % SIZE;
    } while (key != start);
 
    printf("Table is full! Cannot insert %ld\n", sap_id);
}
 
void search(long sap_id) {
    int key = hash(sap_id);
    int start = key;
    int val = sap_id % 10000;
 
    do {
        if (table[key] == EMPTY) { printf("SAP-ID %ld NOT FOUND\n", sap_id); return; }
        if (table[key] == val)   { printf("SAP-ID %ld FOUND at index %d\n", sap_id, key); return; }
        key = (key + 1) % SIZE;
    } while (key != start);
 
    printf("SAP-ID %ld NOT FOUND\n", sap_id);
}
 
void delete(long sap_id) {
    int key = hash(sap_id);
    int start = key;
    int val = sap_id % 10000;
 
    do {
        if (table[key] == EMPTY) { printf("SAP-ID %ld NOT FOUND\n", sap_id); return; }
        if (table[key] == val)   { table[key] = DELETED; printf("SAP-ID %ld DELETED from index %d\n", sap_id, key); return; }
        key = (key + 1) % SIZE;
    } while (key != start);
 
    printf("SAP-ID %ld NOT FOUND\n", sap_id);
}
 
void display() {
    printf("\nIndex | Value\n");
    printf("------+----------\n");
    for (int i = 0; i < SIZE; i++) {
        if      (table[i] == EMPTY)   printf("  %d   | empty\n", i);
        else if (table[i] == DELETED) printf("  %d   | deleted\n", i);
        else                          printf("  %d   | %d\n", i, table[i]);
    }
    printf("\n");
}
 
int main() {
    init();
    int choice;
    long sap;
 
    do {
        printf("1. Insert  2. Delete  3. Search  4. Display  0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
 
        switch (choice) {
            case 1: printf("Enter SAP-ID: "); scanf("%ld", &sap); insert(sap); break;
            case 2: printf("Enter SAP-ID: "); scanf("%ld", &sap); delete(sap); break;
            case 3: printf("Enter SAP-ID: "); scanf("%ld", &sap); search(sap); break;
            case 4: display(); break;
            case 0: printf("Exiting.\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);
 
    return 0;
} 
 
/* ============================================================
   PROGRAM 3
   Graph using Adjacency Matrix
   Display matrix, In-degree and Out-degree of a vertex
   ============================================================ */
 
#include <stdio.h>
 
#define MAX 20
 
int main() {
    int n, e;
    int adj[MAX][MAX] = {0};
 
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
 
    printf("Enter edges as pairs (u v), vertices 0-indexed:\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }
 
    printf("\nAdjacency Matrix:\n   ");
    for (int i = 0; i < n; i++) printf("%3d", i);
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%2d |", i);
        for (int j = 0; j < n; j++)
            printf("%3d", adj[i][j]);
        printf("\n");
    }
 
    int v;
    printf("\nEnter vertex to find degree (0-indexed): ");
    scanf("%d", &v);
 
    int out = 0, in = 0;
    for (int j = 0; j < n; j++) out += adj[v][j];
    for (int i = 0; i < n; i++) in  += adj[i][v];
 
    printf("Vertex %d -> Out-degree: %d, In-degree: %d\n", v, out, in);
    return 0;
}
 
 
/* ============================================================
   PROGRAM 4
   Check if a graph is Undirected
   (adj[i][j] == adj[j][i] for all i, j)
   ============================================================ */
 
#include <stdio.h>
 
#define MAX 20
 
int main() {
    int n;
    int adj[MAX][MAX];
 
    printf("Enter number of vertices: ");
    scanf("%d", &n);
 
    printf("Enter adjacency matrix (%dx%d) row by row:\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
 
    int undirected = 1;
    for (int i = 0; i < n && undirected; i++)
        for (int j = 0; j < n && undirected; j++)
            if (adj[i][j] != adj[j][i])
                undirected = 0;
 
    if (undirected)
        printf("\nThe graph is UNDIRECTED.\n");
    else
        printf("\nThe graph is DIRECTED.\n");
 
    return 0;
}
 
 
/* ============================================================
   PROGRAM 5
   BFS Traversal using a Queue
   ============================================================ */
 
#include <stdio.h>
 
#define MAX 20
 
int adj[MAX][MAX], visited[MAX];
int queue[MAX];
int front = 0, rear = 0;
 
void bfs(int n, int src) {
    visited[src] = 1;
    queue[rear++] = src;
 
    printf("BFS Traversal: ");
    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        for (int j = 0; j < n; j++) {
            if (adj[v][j] == 1 && !visited[j]) {
                visited[j] = 1;
                queue[rear++] = j;
            }
        }
    }
    printf("\n");
}
 
int main() {
    int n, src;
 
    printf("Enter number of vertices: ");
    scanf("%d", &n);
 
    printf("Enter adjacency matrix (%dx%d) row by row:\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
 
    printf("Enter starting vertex (0-indexed): ");
    scanf("%d", &src);
 
    bfs(n, src);
    return 0;
}
  
 
/* ============================================================
   PROGRAM 6
   DFS Traversal using Recursion
   ============================================================ */
 
#include <stdio.h>
 
#define MAX 20
 
int adj[MAX][MAX], visited[MAX];
int n;
 
void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int j = 0; j < n; j++)
        if (adj[v][j] == 1 && !visited[j])
            dfs(j);
}
 
int main() {
    int src;
 
    printf("Enter number of vertices: ");
    scanf("%d", &n);
 
    printf("Enter adjacency matrix (%dx%d) row by row:\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
 
    printf("Enter starting vertex (0-indexed): ");
    scanf("%d", &src);
 
    printf("DFS Traversal: ");
    dfs(src);
    printf("\n");
    return 0;
}
