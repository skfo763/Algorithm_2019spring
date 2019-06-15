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
} edge;

typedef struct CT_VAL {
	bool visited;
	int id_num, prev;
	int time;
	int ctime;
} ct;

void init_indegree(vector<edge> *graph, ct* in_degree, int* task_time, int size) {
	int i, j;

	for(i=1; i<size+1; i++) {
		in_degree[i].time = task_time[i];

		for(j=0; j<graph[i].size(); j++) {
			in_degree[ graph[i][j].dest ].id_num += 1;
		}
	}
}

void cpath(vector<edge> *graph, int* task_time, int node_num) {
	ct* in_degree = new ct [ node_num + 1 ];
	queue<int> q;
	int i, j, check_node;

	for(i=1; i<=node_num; i++) {
		in_degree[i].visited = false;
		in_degree[i].id_num = 0;
		in_degree[i].prev = 0;
		in_degree[i].time = 0;
		in_degree[i].ctime = 0;
	}
	
	init_indegree(graph, in_degree, task_time, node_num);

	for(i=1; i<node_num+1; i++) {
		if(in_degree[i].id_num == 0 && in_degree[i].visited == false) {
			q.push(i);
			in_degree[i].visited = true;
		}
	}

	while(!q.empty()) {
		check_node = q.front();
		in_degree[check_node].ctime += in_degree[check_node].time;
		q.pop();

		for(j=0; j<graph[check_node].size(); j++) {
			in_degree[ graph[check_node][j].dest ].id_num--;
			in_degree[ graph[check_node][j].dest ].ctime = max(in_degree[check_node].ctime, in_degree[ graph[check_node][j].dest ].ctime);
			in_degree[ graph[check_node][j].dest ].prev = j;
		}

		for(j=1; j<=node_num; j++) {
			if(in_degree[j].id_num == 0 && in_degree[j].visited == false) {
				q.push(j);
				in_degree[j].visited = true;		
			}
		}
	}

	int result = 0;
	for(i=1; i<=node_num; i++) {
		if(in_degree[i].id_num != 0) {
			printf("-1\n");
			exit(-1);
		} else {
			result = max(result, in_degree[i].ctime);					
		}
	}

	printf("%d\n", result);
}

int main(int argc, char** argv) {

	if(argc != 1) {
		printf("Usage: ./a.out(executable_file)\n");
		return -1;
	}

	int node_num, edge_count, i, j;
	scanf("%d %d", &node_num, &edge_count);
	int* time = new int[ node_num + 1 ];
	vector <edge> graph [ node_num + 1 ];
	
	for(i=1; i<=node_num; i++) {
		int t;
		scanf("%d", &t);
		time[i] = t;
	}

	for(i=0; i<edge_count; i++) {
		int src, tar;
		edge e;

		scanf("%d %d", &src, &tar);
		e.src = src; e.dest = tar;
		graph[src].push_back(e);
	}

	cpath(graph, time, node_num);

	return 0;
}
