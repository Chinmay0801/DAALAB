#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum number of vertices

// Structure to represent a node in adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure to represent a graph
typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX];  // Array of adjacency lists
    int visited[MAX];  // To track visited nodes
} Graph;

// Stack for push/pop tracking
int stack[MAX], top = -1;

// Function to create a new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    
    return graph;
}

// Function to add an edge (undirected graph)
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src (since the graph is undirected)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to push onto stack (records push order)
void push(int v) {
    stack[++top] = v;
}

// Function to pop from stack (records pop order)
int pop() {
    return stack[top--];
}

// DFS function
void DFS(Graph* graph, int vertex) {
    push(vertex);  // Push order (Entering vertex)
    graph->visited[vertex] = 1;
    printf("Push: %d\n", vertex);  // Record push order
    
    Node* temp = graph->adjLists[vertex];
    
    while (temp) {
        int adjVertex = temp->vertex;
        if (graph->visited[adjVertex] == 0) {
            DFS(graph, adjVertex);
        }
        temp = temp->next;
    }
    
    printf("Pop: %d\n", pop());  // Record pop order
}

// Driver function
int main() {
    int vertices, edges;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    Graph* graph = createGraph(vertices);
    
    printf("Enter edges (format: src dest):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);
    
    printf("\nDFS Traversal with Push and Pop Order:\n");
    DFS(graph, startVertex);

    return 0;
}
