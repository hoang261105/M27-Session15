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

// Ham them canh vao danh sach ke
void addEdge(int u, int v) {
    adjList[u].vertices[adjList[u].size++] = v;
    adjList[v].vertices[adjList[v].size++] = u;
}

// Ham DFS de duyet do thi
void DFS(int vertex) {
    visited[vertex] = true;
    for (int i = 0; i < adjList[vertex].size; i++) {
        int neighbor = adjList[vertex].vertices[i];
        if (!visited[neighbor]) {
            DFS(neighbor);
        }
    }
}

// Ham kiem tra do thi lien thong
bool isConnected(int V) {
    // Dat lai trang thai da tham
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    // Goi DFS tu dinh dau tien (dinh 0)
    DFS(0);

    // Kiem tra tat ca cac dinh da duoc tham
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            return false; // Co dinh chua duoc tham
        }
    }
    return true;
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
    if (isConnected(V)) {
        printf("\nDo thi lien thong\n");
    } else {
        printf("\nDo thi khong lien thong\n");
    }

    return 0;
}

