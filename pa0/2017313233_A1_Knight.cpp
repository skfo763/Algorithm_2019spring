#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char **argv) {
	int size, sX, sY, eX, eY, i, j;
	FILE *fp = fopen(argv[1], "rt");
	FILE *output_fp;

	fscanf(fp, "%d %d %d %d %d", &size, &sX, &sY, &eX, &eY);	

	int moveX[8] = {1, 2, 2, 1, -1, -2, -2, -1 };
	int moveY[8] = {-2, -1, 1, 2, 2, 1, -1, -2 };
	
	int** map_arr = new int*[size];
	for(i=0; i<size; i++) {
		map_arr[i] = new int[size];
	}

	for(i=0; i<size; i++) {
		for(j=0; j<size; j++) {
			map_arr[i][j] = -1;
		}
	}

	queue <pair<int, int>> Q;
	Q.push(make_pair(sX, sY));
	map_arr[sX][sY] = 0;
	
	while(!Q.empty()) {
		int currX = Q.front().first;
		int currY = Q.front().second;
		Q.pop();

		if(currX == eX && currY == eY) break;

		for(i=0; i<8; i++) {
			int nextX = currX + moveX[i];
			int nextY = currY + moveY[i];

			if(nextX >= 0 && nextY >= 0 && nextX < size && nextY < size) {
				if(map_arr[nextX][nextY] == -1) {
					Q.push(make_pair(nextX, nextY));
					map_arr[nextX][nextY] = map_arr[currX][currY]+1;
				}			
			}
		}
	}
	
	output_fp = fopen(argv[2], "wt");
	fprintf(output_fp, "%d\n", map_arr[eX][eY]);
	
	for(i=0; i<size; i++) {
		delete[] map_arr[i];
	}

	delete[] map_arr;

	return 0;
}




