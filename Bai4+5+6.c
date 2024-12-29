#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Danh sach ke
typedef struct {
    int vertices[MAX];
    int size;
} AdjList;

AdjList adjList[MAX];
bool visited[MAX];
bool recStack[MAX];

// Ham them canh vao danh sach ke
void addEdge(int u, int v) {
    adjList[u].vertices[adjList[u].size++] = v;
}

// Ham DFS de phat hien chu trinh
bool DFS(int vertex) {
    visited[vertex] = true;
    recStack[vertex] = true;

    for (int i = 0; i < adjList[vertex].size; i++) {
        int neighbor = adjList[vertex].vertices[i];

        if (!visited[neighbor]) {
            if (DFS(neighbor)) {
                return true;
            }
        } else if (recStack[neighbor]) {
            return true;
        }
    }

    recStack[vertex] = false;
    return false;
}

// Ham kiem tra chu trinh trong do thi
bool hasCycle(int V) {
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (DFS(i)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int V, E;

    // Nhap so dinh va so canh
    printf("Nhap so dinh (V): ");
    scanf("%d", &V);
    printf("Nhap so canh (E): ");
    scanf("%d", &E);

    // Khoi tao danh sach ke
    for (int i = 0; i < V; i++) {
        adjList[i].size = 0;
    }

    // Nhap danh sach cac canh
    printf("Nhap danh sach cac canh (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Kiem tra va in ket qua
    if (hasCycle(V)) {
        printf("\nDo thi co chu trinh\n");
    } else {
        printf("\nDo thi khong co chu trinh\n");
    }

    return 0;
}

