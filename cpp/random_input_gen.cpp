#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

int main() {

	int n=30;
	int arr[30][30];
	while (n--) {
		if (n == 1) break;
		FILE* fp = NULL;
		char buffer[100];
		sprintf(buffer,"%d",n);
		char temp[100];
		char* str = strcpy(temp, buffer);

		fp = fopen(strcat(str, ".txt"),"w");

		fprintf(fp, "%d\n", n);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					arr[i][j] = arr[j][i] = 0; continue;
				}
				arr[i][j] = arr[j][i] = rand() % 50 + 10;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				fprintf(fp, "%d ", arr[i][j]);
			}
			fprintf(fp, "\n");
		}

		printf("%d is done.\n", n);
	}
	return 0;
}
