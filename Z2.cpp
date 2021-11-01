#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

struct node
{
	int vertex;
	struct node* next;
};
struct node* createNode(int);
struct Graph
{
	int* visited;
	int numVertices;
	struct node** adjLists;
};


struct Graph* createGraph(int vertices);

void addEdge(struct Graph* graph, int src, int dest);

void printGraph(struct Graph* graph);
void search(struct Graph* graph);
void DFS2(struct Graph* graph, int vertex);

int main1()
{
	setlocale(LC_ALL, "Rus");
	int versh, * a, i, ver, conect;
	printf("Введите количество вершин: ");
	scanf("%d", &versh);

	a = (int*)malloc(versh * sizeof(int));

	struct Graph* graph = createGraph(versh);

	for (i = 0; i < versh - 1; i++)
	{
		conect = i + 1;
		ver = conect - 1;
		addEdge(graph, ver, conect);
	}



	printGraph(graph);
	DFS2(graph, 2);
	search(graph);
	return 0;
}


struct node* createNode(int v)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->vertex = v;
	newNode->next = NULL;
	return newNode;
}

struct Graph* createGraph(int vertices)
{
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->numVertices = vertices;

	graph->adjLists = (struct node**)malloc(vertices * sizeof(struct node*));

	graph->visited = 0;

	int i;
	for (i = 0; i < vertices; i++)
		graph->adjLists[i] = NULL;

	return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{

	struct node* newNode = createNode(dest);
	newNode->next = graph->adjLists[src];
	graph->adjLists[src] = newNode;


	newNode = createNode(src);
	newNode->next = graph->adjLists[dest];
	graph->adjLists[dest] = newNode;
}

void printGraph(struct Graph* graph)
{
	int v;
	for (v = 0; v < graph->numVertices; v++)
	{
		struct node* temp = graph->adjLists[v];
		printf("\n Список смежности вершины %d\n ", v+1);
		while (temp)
		{
			printf("%d -> ", temp->vertex);
			temp = temp->next;
		}
		printf("\n");
	}
}

void DFS2(struct Graph* graph, int vertex) {
	struct node* adjList = graph->adjLists[vertex];
	struct node* temp = adjList;
	int visited[2];
	visited[vertex] = 1;

	printf(" вершина %d \n", vertex);

	while (temp != NULL) {
		int connectedVertex = temp->vertex;

		if (visited[connectedVertex] == 0) {
			DFS2(graph, connectedVertex);
		}
		temp = temp->next;
	}
}


void search(struct Graph* graph)
{
	int v;
	printf("\n Список смежности вершины");
	for (v = 0; v < graph->numVertices; v++)
	{
		struct node* temp = graph->adjLists[v];

		while (temp)
		{
			printf("% d", temp->vertex);

			temp = temp->next;

		}

	}
}
//////////////////////////////

//поиск в глубину
void DFS(int st, int** graph, int size, bool* visited)
{
	int r;
	cout << st + 1 << " ";
	visited[st] = true;
	for (r = 0; r <= size; r++)
		if ((graph[st][r] != 0) && (!visited[r]))
			DFS(r, graph, size, visited);
}


void dfs1(int p, int** G, int N)
{
	queue<int> S;

	int* v;
	int t;

	v = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++) {
		v[i] = 0;
	}
	S.push(p);
	v[p] += 1;
	while (!S.empty())
	{
		t = S.front();
		S.pop();
		cout << t + 1 << " ";
		for (int i = 0; i < N; i++)
			if (G[t][i] && !v[i])
			{
				S.push(i);
				v[i] += 1;
			}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");

	int start, i, j;

	int size, ** graph, n;


	cout << "Введите размерность: " << endl;
	cin >> size;


	srand(time(NULL));
	graph = (int**)malloc(size * sizeof(int));

	for (int i = 0; i < size; i++)
	{
		graph[i] = (int*)malloc(size * sizeof(int));
	}
	bool* visited = new bool[size];

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < i + 1; j++) {
			int num = rand() % 2;
			graph[i][j] = num;
			graph[j][i] = num;
		}
	}


	cout << "Матрица смежности графа: " << endl;
	for (i = 0; i < size; i++)
	{
		visited[i] = false;
		for (j = 0; j < size; j++)
			cout << " " << graph[i][j];
		cout << endl;
	}
	cout << "Стартовая вершина "; cin >> start;
	//массив посещенных вершин
	bool* vis = new bool[size];
	cout << "Порядок обхода рекурсивный метод: ";

	int start1 = start, size1 = size;

	DFS(start - 1, graph, size, visited);
	cout << "\n " << endl;
	cout << "Порядок обхода не рекурсивный метод: ";
	dfs1(start - 1, graph, size);
	delete[]visited;

	cout << "\n " << endl;
	cout << "Порядок обхода списки \n";
	main1();
	return(0);
}
