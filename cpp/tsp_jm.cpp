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
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	memset(cost, 0, sizeof(cost));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &cost[i][j]);

	printf("%d", tsp2(0, 1<<0));

	return 0;
}