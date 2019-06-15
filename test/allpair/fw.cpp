#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

#define INF 9999999999.99

using namespace std;

int main(int argc, char** argv) {

	if(argc < 2 || argc > 3) {
		printf("Usage: ./a.out(executable_file) options(-c for minimum cost, -p for print path: can be overlapped)\n");
		return -1;
	}

	char* opt1 = argv[1];
	char* opt2 = argv[2];

	int node_num, edge_count, i, j, k;
	scanf("%d %d", &node_num, &edge_count);

	double** graph = new double* [ node_num+1 ];
	int **p = new int * [ node_num+1 ];
	bool ** b = new bool* [node_num+1 ];

	for(i=0; i<node_num+1; i++) {
		graph[i] = new double[ node_num+1 ];
		p[i] = new int[ node_num+1 ];
		b[i] = new bool[ node_num+1 ];
	}	

	for(i=1; i<node_num+1; i++) {
		for(j=1; j<node_num+1; j++) {
			if(i != j) {
				graph[i][j] = INF;
				p[i][j] = j;
				b[i][j] = false;
			} else {
				graph[i][j] = 0;
				p[i][j] = 0;
			}
		}
	}



	for(i=0; i<edge_count; i++) {
		int u, v; double cost;
		scanf("%d %d %lf", &u, &v, &cost);
		graph[u][v] = cost;
		b[u][v] = true;
	}

	for(k=1; k<node_num+1; k++) {
		for(i=1; i<node_num+1; i++) {
			for(j=1; j<node_num+1; j++) {
				b[i][j] = b[i][j] || (b[i][k] && b[k][j]);

				if(graph[i][j] > graph[i][k] + graph[k][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
					p[i][j] = p[i][k];
				}
			}
		}
	}

	int x;
	for(i=1; i<node_num+1; i++) {
		for(j=1; j<node_num+1; j++) {
			if(i != j) {

				if(b[i][j] == false) printf("%d->%d : disconnected\n", i, j);
				
				else {

					if((opt1 != NULL && strncmp(opt1, "-p", 2) == 0) || (opt2 != NULL && strncmp(opt2, "-p", 2) == 0)) {
						x = p[i][j];
						printf("%d", i);
						while(x != p[x][j]) {
							printf("->%d", x);
							x = p[x][j];
						}
						
						if(opt2 == NULL) printf("\n");
						else printf(": ");
					}
					
					if((opt1 != NULL && strncmp(opt1, "-c", 2) == 0) || (opt2 != NULL && strncmp(opt2, "-c", 2) == 0)) {
						printf("length is %0.2lf\n", graph[i][j]);
					}
				}
			}
		}
	}



	for(i=0; i<node_num+1; i++) {
		delete [] graph[i];
	}

	delete [] graph;;

	return 0;
}
