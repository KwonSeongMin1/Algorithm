#include <stdio.h>

int main() {
	int count, result = 1, m = 0;
	int stick[100001];

	scanf("%d", &count);

	for (int i = 0; i < count; i++) {
		scanf("%d", &stick[i]);
	}

	m = stick[count - 1];	// �� ������

	for (int i = count - 1; i > 0; i--) {
		if (m < stick[i - 1]) {
			result++;
			m = stick[i - 1];	// ���� ū ������ üũ
		}
	}
	printf("%d", result);
}