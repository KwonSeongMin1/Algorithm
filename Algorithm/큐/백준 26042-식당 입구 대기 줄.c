#include <stdio.h>

int line[100001];
int main() {
	int n;
	int min = 100001, max = 0;	// 결과 추출용
	int k = 0, l = 0;	// 결과 계산용
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d", &x);

		// 1일때 입력받고 저장
		if (x == 1) {
			scanf("%d", &y);
			line[k++] = y;
		}

		// 2일때 맨 앞 값 추출
		else {
			line[l++] = 0;
		}

		// k = 입력받은 값 개수, l = 추출한 값 개수
		if (max < k - l) {
			max = k - l;
			min = line[k - 1];
		}
		else if (max == k - l) {
			if (min > line[k - 1]) min = line[k - 1];
		}
	}

	printf("%d %d", max, min);
}