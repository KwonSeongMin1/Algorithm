#include <stdio.h>
#include <string.h>

int main() {

	int n;
	int count = 0;	// �����
	scanf("%d", &n);

	char word[51][51];	// �Է��� word
	char savedWord[51][51];	// ������ word 

	for (int i = 0; i < n; i++) {
		scanf("%s", word[i]);
	}


	for (int i = 0; i < n; i++) {
		int flag = 1;	// ���� �ܾ savedWord�� ����Ǿ� ���� ���� �� �Ǵ�
		int l = strlen(word[i]);	// cycle ���� Ƚ��
		while (l--) {
			for (int j = 0; j < count; j++) {	// savedWord�� ����� �ܾ�� ��Ī
				if (!strcmp(savedWord[j], word[i])) {
					flag = 0;
					break;
				}
			}

			// word cycle ������
			char t = word[i][0];
			for (int j = 1; j < strlen(word[i]); j++) {
				word[i][j - 1] = word[i][j];
			}
			word[i][strlen(word[i]) - 1] = t;
		}


		// ����Ǿ� ���� ������ ����
		if (flag) {
			strcpy(savedWord[count++], word[i]);
		}
	}
	printf("%d", count);
}