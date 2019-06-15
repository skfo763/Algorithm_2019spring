#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

#define INF 99999999999.99

using namespace std;

typedef struct EDGE {
	int src, dest;
	double cost;
} edge;

typedef struct PRIMS_TABLE {
	bool visited;
	double dist;
	int parent;
} table;

struct cmp {
	bool operator()(edge a, edge b) {
		return a.cost > b.cost;
	}
};

void init_set(int *arr, int size) {
	for(int i=1; i<size+1; i++) {
		arr[i] = i;
	}
}

int find_set(int *arr, int x) {
	while(arr[x] != x) {
		x = arr[x];
	}

	return x;
}

bool check_union(int *arr, int x, int y) {
	if(find_set(arr, x) != find_set(arr, y)) return false;
	else return true;
}

void union_set(int *arr, int x, int y) {
	x = find_set(arr, x);
	y = find_set(arr, y);

	if(x != y) {
		arr[y] = x;
	}
}

void kruskal_algorithm(vector < edge > *graph, int* set, int node_num) {
	priority_queue <edge, vector<edge>, cmp> edge_q;
	int i, j, src, dest;
	double result = 0;

	for(i=1; i<node_num+1; i++) {
		
		for(j=0; j<graph[i].size(); j++) {
			edge_q.push(graph[i][j]);			
		}
	}

	while(!edge_q.empty()) {
		src = edge_q.top().src;
		dest = edge_q.top().dest;
		
		if(check_union(set, src, dest) == false) {
			union_set(set, src, dest);
			result += edge_q.top().cost;
		}
		
		edge_q.pop();	
	}

	printf("total tree-edge cost : %0.4lf\n", result); 
}

void prims_algorithm(vector<edge> *graph, int node_num) {
	vector<table> p_table;
	table p;
	p.visited = true;
	p.dist = INF;
	p.parent = 0;
	p_table.push_back(p);

	int i, j, visit_node, min_node;
	double min_val;
	
	for(i=0; i<node_num; i++) {
		table t;
		t.visited = false;
		t.dist = INF;
		t.parent = 0;
		p_table.push_back(t);
	}
	
	visit_node = 1;
	p_table[visit_node].dist = 0;
	p_table[visit_node].parent = 0;

	while(1) {
		p_table[visit_node].visited = true;

		for(i=0; i<graph[visit_node].size(); i++) {
			int tar = graph[visit_node][i].dest;
			
			if(p_table[tar].dist > graph[visit_node][i].cost && p_table[tar].visited == false) {
				p_table[tar].dist = graph[visit_node][i].cost;
				p_table[tar].parent = visit_node;
			}
		}

		min_val = INF;
		min_node = -1;
		for(j=1; j<p_table.size(); j++) {	
			if(p_table[j].dist < min_val && p_table[j].visited == false) {
				min_val = p_table[j].dist;
				min_node = j;
			}
		}

		if(min_node == -1) {
			break;	
		} else {
			visit_node = min_node;
		}
	}
	
	double result = 0;
	for(i=1; i<p_table.size(); i++) {
		if(p_table[i].visited == false) {
			printf("there is no MST in given graph\n");
			exit(-1);
		}

		result += p_table[i].dist;
	}

	printf("\n");
	printf("total tree-edge cost : %0.4lf\n", result);
}

int main(int argc, char** argv) {

	if(argc != 2) {
		printf("Usage: ./a.out(executable_file) options(-k for kruskal algorithm, -p for prims algorithm)\n");
		return -1;
	}

	char* opt = argv[1];
	int node_num, edge_count, i, j;
	scanf("%d %d", &node_num, &edge_count);
	
	vector<edge> graph [ node_num + 1 ];
	int *set = new int [ node_num + 1 ];
	init_set(set, node_num);

	for(i=0; i<edge_count; i++) {
		int src, tar;
		double cost;
		edge e, e2;

		scanf("%d %d %lf", &src, &tar, &cost);
		e.src = src;
		e.dest = tar;
		e.cost = cost;

		e2.src = tar;
		e2.dest = src;
		e2.cost = cost;

		graph[src].push_back(e);
		graph[tar].push_back(e2);
	}

	if(strncmp(opt, "-k", 2) == 0) {
		kruskal_algorithm(graph, set, node_num);
	
	} else if(strncmp(opt, "-p", 2) == 0) {
		prims_algorithm(graph, node_num);
		
	}

	delete [] set;
	return 0;
}




