#include <stdio.h>
#include <string.h>

int main() {

	int n;
	int count = 0;	// 결과값
	scanf("%d", &n);

	char word[51][51];	// 입력할 word
	char savedWord[51][51];	// 저장할 word 

	for (int i = 0; i < n; i++) {
		scanf("%s", word[i]);
	}


	for (int i = 0; i < n; i++) {
		int flag = 1;	// 비교한 단어가 savedWord에 저장되어 있지 않을 때 판단
		int l = strlen(word[i]);	// cycle 돌릴 횟수
		while (l--) {
			for (int j = 0; j < count; j++) {	// savedWord에 저장된 단어랑 매칭
				if (!strcmp(savedWord[j], word[i])) {
					flag = 0;
					break;
				}
			}

			// word cycle 돌리기
			char t = word[i][0];
			for (int j = 1; j < strlen(word[i]); j++) {
				word[i][j - 1] = word[i][j];
			}
			word[i][strlen(word[i]) - 1] = t;
		}


		// 저장되어 있지 않으면 저장
		if (flag) {
			strcpy(savedWord[count++], word[i]);
		}
	}
	printf("%d", count);
}