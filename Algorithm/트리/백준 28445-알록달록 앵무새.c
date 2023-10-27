#include <stdio.h>

int main() {
	char color[4][21];
	for (int i = 0; i < 4; i++) {
		scanf("%s", &color[i]);
	}

	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 4; j++) {
			if (strcmp(color[i], color[j]) > 0) {
				char tmp[21];
				strcpy(tmp,color[i]);
				strcpy(color[i], color[j]);
				strcpy(color[j], tmp);
			}
			else if (strcmp(color[i], color[j]) == 0) {
				strcpy(color[j], "");
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (strcmp(color[i], "") && strcmp(color[j], "")) printf("%s %s\n", color[i], color[j]);
		}
	}
}