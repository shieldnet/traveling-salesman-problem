#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <time.h>

#define MAX 20
#define INF 987654321

using namespace std;

typedef long long LL;

int n;
int cost[MAX][MAX];

int tsp_brute_force(vector<int>& path, vector<bool>& visited, int curr) {
	if (path.size() == n) {
		return curr += cost[path[0]][path.back()];
	}

	int ret = INF;

	for (int next = 0; next < n; next++) {
		if (visited[next])continue;
		int here = path.back();
		path.push_back(next);

		visited[next] = true;

		int candidate = tsp_brute_force(path, visited, curr + cost[here][next]);

		ret = std::min(ret, candidate);
		visited[next] = false;
		path.pop_back();
	}

	return ret;
}

int main() {
	FILE* result = NULL;
	result = fopen("result_bfs.txt", "w");
	n = 1;
	for (int i = 0; i<23; i++) {
		vector<int> path;
		vector<bool> visited(MAX,false);
		path.push_back(0);
		visited[0] = true;
		memset(cost, 0, sizeof(cost));
		n++;
		if (n == 13) break;
		FILE* fp = NULL;
		char file_name[100];

		sprintf(file_name, "%d", n);

		strcat(file_name, ".txt");

		fp = fopen(file_name, "r");

		fscanf(fp, "%d ", &n);

		clock_t st = clock();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				fscanf(fp, " %d", &cost[i][j]);


		int ans = tsp_brute_force(path, visited, 0);
		clock_t fin = clock();

		printf("Minimum Cost When N=%d :: %d. Execution time : %d ms\n", n, ans, fin - st);
		fprintf(result, "Minimum Cost When N=%d :: %d. Execution time : %d ms\n", n, ans, fin - st);

		fclose(fp);
	}

	fclose(result);
	return 0;
}
