#include <stdio.h>
#include <string.h>

typedef struct stu {
	int vote;
	char name[11];
}Stu;

int compare(const void* x, const void* y) {
	Stu* xx = ((Stu*)x)->vote;
	Stu* yy = ((Stu*)y)->vote;

	if (xx->vote < yy->vote) return 1;
	if (xx->vote > yy->vote) return -1;
	return strcmp(xx->name, yy->name);
}



int main() {
	int student;
	char n[101][11];
	Stu list[101];
	scanf("%d", &student);

	for (int i = 0; i < n; i++) {
		scanf("%s", n[i]);
		list[i].vote = 0;
		strcpy(list[i].name, n[i]);
	}

	int i = 0;
	char* name = strtok(n, " ");
	while (name != NULL) {
		strcpy(list[i++].name, name);
		name = strtok(NULL, " ");
	}
	for (int i = 0; i < student; i++) {
		getchar();
		scanf("%[^\n]s", &n);
		char* vote = strtok(n, " ");
		while (vote != NULL) {
			for (int i = 0; i < student; i++) {
				if (!strcmp(list[i].name, vote)) list[i].vote++;
			}
			vote = strtok(NULL, " ");
		}
	}
	qsort(list, student, sizeof(Stu),compare);

	for (int i = 0; i < student; i++) {
		printf("%s %d\n", list[i].name, list[i].vote);
	}
}