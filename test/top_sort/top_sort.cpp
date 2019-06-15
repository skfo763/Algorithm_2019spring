#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

typedef struct EDGE {
	int src, dest;
	double cost;
} edge;

typedef struct ID_VAL {
	bool visited;
	int val;
} id;

void init_indegree(vector<edge> *graph, id* in_degree, int size) {
	int i, j;

	for(i=1; i<size+1; i++) {
		for(j=0; j<graph[i].size(); j++) {
			in_degree[ graph[i][j].dest ].val += 1;
		}
	}
}

void init_queue(int *queue, int size) {
	for(int i=0; i<size; i++) {
		queue[i] = 0;
	}
}

bool check_empty(int* queue, int* head, int* tail) {
	return (*head == *tail + 1);
}

void push(int* queue, int* tail, int value) {
	*tail += 1;
	queue[*tail] = value;
}

int pop(int* queue, int* head) {
	int temp = *head;
	*head += 1;
	return queue[temp];

}

void tsort(vector<edge> *graph, int node_num) {
	int i, j, check_node;
	id *in_degree = new id [node_num + 1];
	in_degree[0].val = -1;
	in_degree[0].visited = true;

	for(i=1; i<node_num+1; i++) {
		in_degree[i].val = 0;
		in_degree[i].visited = false;
	}

	int *queue = new int[node_num];
	int head = 0; int tail = -1;
	init_indegree(graph, in_degree, node_num);
	init_queue(queue, node_num);

	for(j=1; j<node_num+1; j++) {
		if(in_degree[j].val == 0 && in_degree[j].visited == false) {
			push(queue, &tail, j);
			in_degree[j].visited = true;
		}
	}

	while(!check_empty(queue, &head, &tail) || (head == 0)) {

		check_node = pop(queue, &head);

		for(j=0; j<graph[check_node].size(); j++) {
			in_degree[ graph[check_node][j].dest ].val--;
		}

		for(j=1; j<node_num+1; j++) {
			if(in_degree[j].val == 0 && in_degree[j].visited == false) {
				push(queue, &tail, j);
				in_degree[j].visited = true;
			}
		}
	}


	for(i=0; i<node_num; i++) {
		printf("%d ", queue[i]);
	}

	delete [] in_degree;
}

int main(int argc, char** argv) {

	if(argc != 1) {
		printf("Usage: ./a.out(executable_file)\n");
		return -1;
	}

	int node_num, edge_count, i, j;
	scanf("%d %d", &node_num, &edge_count);

	vector <edge> graph [node_num + 1];

	for(i=0; i<edge_count; i++) {
		int src, tar;
		double cost;
		edge e;

		scanf("%d %d %lf", &src, &tar, &cost);
		e.src = src; e.dest = tar; e.cost = cost;
		graph[src].push_back(e);
	}

	tsort(graph, node_num);

	return 0;
}
