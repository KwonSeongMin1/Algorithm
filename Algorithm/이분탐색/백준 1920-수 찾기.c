#include <stdio.h>

int compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

int num[100001];

int main() {
	int a, b, c, flag;

	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		scanf("%d", &num[i]);
	}

	qsort(num, a, sizeof(int), compare);

	scanf("%d", &b);

	for (int i = 0; i < b; i++) {
		flag = 1;
		scanf("%d", &c);
		
		int start = 0;
		int end = a - 1;
		int mid;
		while (start <= end) {
			mid = (start + end) / 2;
			if (num[mid] == c) {
				printf("1\n");
				flag = 0;
				break;
			}
			else if (num[mid] > c) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}

		if (flag) printf("0\n");

	}
}