/*16.  Write a program to perform the Depth First Search using adjacency list or 
adjacency matrix, use the map of the historical places around Pune city as the 
graph, and identify the famous landmarks as nodes.  (Shaniwar Wada, Aga 
Khan Palace, Pataleshwar Cave Temple, Lal Mahal, Shinde Chhatri, Sinhagad 
Fort, Parvati Hill Temple, Vishrambaug Wada, Bhide Wada)*/

#include <stdio.h>
#define MAX 9   // total number of landmarks

// Adjacency matrix representation of the graph
int adj[MAX][MAX] = {
    // SW, AK, PC, LM, SC, SF, PH, VW, BW
    {0,0,1,1,0,0,0,1,1}, // Shaniwar Wada
    {0,0,1,0,1,0,0,0,0}, // Aga Khan Palace
    {1,1,0,0,0,0,1,0,0}, // Pataleshwar Cave Temple
    {1,0,0,0,0,0,0,1,0}, // Lal Mahal
    {0,1,0,0,0,0,1,0,0}, // Shinde Chhatri
    {0,0,0,0,0,0,1,0,0}, // Sinhagad Fort
    {0,0,1,0,1,1,0,0,0}, // Parvati Hill Temple
    {1,0,0,1,0,0,0,0,1}, // Vishrambaug Wada
    {1,0,0,0,0,0,0,1,0}  // Bhide Wada
};

// Landmark names (nodes)
char *places[MAX] = {
    "Shaniwar Wada",
    "Aga Khan Palace",
    "Pataleshwar Cave Temple",
    "Lal Mahal",
    "Shinde Chhatri",
    "Sinhagad Fort",
    "Parvati Hill Temple",
    "Vishrambaug Wada",
    "Bhide Wada"
};

// Visited array to track visited nodes
int visited[MAX];

// DFS function
void DFS(int start) {
    printf("%s\n", places[start]); // Visit the node
    visited[start] = 1;           // Mark it as visited

    // Explore all connected (adjacent) nodes
    for (int i = 0; i < MAX; i++) {
        if (adj[start][i] == 1 && visited[i] == 0) {
            DFS(i); // Recursive call to visit the next node
        }
    }
}

int main() {
    int start;

    printf("List of Landmarks:\n");
    for (int i = 0; i < MAX; i++)
        printf("%d. %s\n", i, places[i]);

    printf("\nEnter the starting landmark index (0–8): ");
    scanf("%d", &start);

    if (start < 0 || start >= MAX) {
        printf("Invalid starting point!\n");
        return 0;
    }

    // Initialize visited array
    for (int i = 0; i < MAX; i++)
        visited[i] = 0;

    printf("\nDFS Traversal starting from %s:\n", places[start]);
    DFS(start);

    return 0;
}