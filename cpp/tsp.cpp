#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <set>
#include <cmath>
#include <time.h>
#include <limits.h>

using namespace std;

//typedef int long long;
typedef long long LL;
typedef vector<LL> VLL;

#define MAX_NODE 23

using namespace std;

int n;
int cost[MAX_NODE][MAX_NODE];
int dp[MAX_NODE][1 << MAX_NODE];

int tsp2(int here, int visited) {
	if (visited == (1 << n) - 1) {
		return cost[here][0];
	}

	int& ret = dp[here][visited];
	if (ret >= 0) {
		return ret;
	}
	ret = INT_MAX;

	for (int next = 0; next < n; next++) {
		if (visited & (1 << next)) {
			continue;

		}

		int candidate_dist = cost[here][next] + tsp2(next, visited + (1 << next));
		ret = min(ret, candidate_dist);
	}

	return ret;
}

int main() {
	FILE* result = NULL;
	result = fopen("result.txt", "w");

	for (int i = 0; i<23; i++) {
		memset(cost, 0, sizeof(cost));
		memset(dp, -1, sizeof(dp));
		if (n == MAX_NODE + 1) break;
		FILE* fp = NULL;
		char file_name[100];
		sprintf(file_name, "%d", i+2);

		strcat(file_name, ".txt");

		fp = fopen(file_name, "r");

		fscanf(fp, "%d", &n);

		clock_t st = clock();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				fscanf(fp, "%d", &cost[i][j]);


		int ans = tsp2(0, 1);
		clock_t fin = clock();

		printf("Minimum Cost When N=%d :: %d. Execution time : %d ms\n", n, ans, fin - st);
		fprintf(result, "Minimum Cost When N=%d :: %d. Execution time : %d ms\n", n, ans, fin - st);

		fclose(fp);
	}
	fclose(result);
	return 0;
}