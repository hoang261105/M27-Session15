#include<stdio.h>

#define V 4

int visited[V];
int graph[V][V];

// Ham duyet theo chieu sau DFS
void DFSFunction(int v, int n){
	printf("%d\t", v);
	visited[v] = 1;
	for(int i=0; i<n; i++){
		if(visited[i] == 0 && graph[v][i] == 1){
			DFSFunction(i, n);
		}
	}
}

int main(){
	int n, u, v;
	int start;
	int edge;
	printf("Nhap vao so dinh: ");
	scanf("%d", &n);
	printf("Nhap vao so canh: ");
	scanf("%d", &edge);
	
	printf("Nhap vao cac canh thuoc dinh: ");
	for(int i=0; i<edge; i++){
		scanf("%d %d", &u, &v);
		graph[u][v] = 1;
		graph[v][u] = 1;
	}
	printf("Nhap vao dinh bat dau: ");
	scanf("%d", &start);
	
	DFSFunction(start, n);
	
	return 0;
}
