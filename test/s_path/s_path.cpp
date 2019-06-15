#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

#define INF 9999999999.99

using namespace std;

typedef struct EDGE {
	int src, dest;
	double cost;
} edge;

typedef struct DIKJ_TABLE {
	bool visited;
	double dist;
	int prev;
} d_table;


void dijkstra_algorithm(vector<edge> *graph, int node_num, int start) {
	vector<d_table> table;
	d_table p;
	p.visited = true;
	p.dist = INF;
	p.prev = 0;
	table.push_back(p);
	
	int i, j, visit_node, min_node;
	double min_val;

	for(i=0; i<node_num; i++) {
		d_table t;
		t.visited = false;
		t.dist = INF;
		t.prev = 0;
		table.push_back(t);
	}

	visit_node = start;
	table[visit_node].dist = 0;

	while(1) {
		table[visit_node].visited = true;	
		
		for(i=0; i<graph[visit_node].size(); i++) {
			int temp_dest = graph[visit_node][i].dest;
			double new_dist = table[visit_node].dist + graph[visit_node][i].cost;
			
			if(table[temp_dest].dist > new_dist && table[temp_dest].visited == false) {
				table[temp_dest].dist = new_dist;
				table[temp_dest].prev = visit_node;
			}
		}

		min_val = INF;
		min_node = -1;

		for(j=1; j<table.size(); j++) {
			if(table[j].dist < min_val && table[j].visited == false) {
				min_val = table[j].dist;
				min_node = j;
			}
		}

		if(min_node == -1) {
			break;
		} else {
			visit_node = min_node;
		}
	}

	double max_val = -1;
	int max_node = 0;

	for(i=1; i<table.size(); i++) {
		if(table[i].visited == false) {
			printf("The graph is disconnected.\n");
			exit(-1);
		}

		if(table[i].dist > max_val) {
			max_val = table[i].dist;
			max_node = i;
		}
	}

	printf("Last-reached node is %d -> %d (cost: %0.2lf)\n", start, max_node, max_val);
}

int main(int argc, char** argv) {
	
	if(argc != 1) {
		printf("Usage: ./a.out(executable_file)\n");
		return -1;
	}

	int node_num, edge_count, start, i, j;
	scanf("%d %d %d", &node_num, &edge_count, &start);

	vector <edge> graph [node_num + 1];

	for(i=0; i<edge_count; i++) {
		int src, tar;
		double cost;
		edge e;

		scanf("%d %d %lf", &src, &tar, &cost);
		e.src = src; e.dest = tar; e.cost = cost;
		graph[src].push_back(e);
	}

	dijkstra_algorithm(graph, node_num, start);

	return 0;
}
