#include <stdio.h>
int n[500001];
int m[500001];

int compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

int main() {
	int N, M;
	scanf("%d", &N);
	

	for (int i = 0; i < N; i++) {
		scanf("%d", &n[i]);
	}

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &m[i]);
	}

	qsort(n, N, sizeof(int), compare);

	/*for (int i = 0; i < N-1; i++) {
		for (int j = i+1; j < N; j++) {
			if (n[i] > n[j]) {
				int tmp = n[i];
				n[i] = n[j];
				n[j] = tmp;
			}
		}
	}*/

	int i = 0;

	while (i != M) {
		int start = 0;
		int end = N - 1;
		int mid;
		int flag = 1;
		while (start <= end) {
			mid = (start + end) / 2;
			if (n[mid] == m[i]) {
				printf("1 ");
				flag = 0;
				break;
			}
			else if (n[mid] > m[i]) {
				end = mid-1;
			}
			else {
				start = mid + 1;
			}
		}
		if (flag) {
			printf("0 ");
		}
		i++;
	}
}