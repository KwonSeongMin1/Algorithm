#include <stdio.h>
#include <string.h>
int main(){
	int N, c, i, count, banana = 0, strawberry = 0, lime = 0, plum = 0;
	scanf("%d", &N);
	getchar();
	while (N--) {
		i = 0;
		char fruit[20] = { 0 };
		
		while ((c = getchar()) != '\n') {
			fruit[i++] = c;
		}
		char* f = strtok(fruit, " ");
		if (strcmp(f, "BANANA") == 0) {
			f = strtok(NULL, " ");
			banana += *f - 48;
		}
		if (strcmp(f, "STRAWBERRY") == 0) {
			f = strtok(NULL, " ");
			strawberry += *f - 48;
		}
		if (strcmp(f, "LIME") == 0) {
			f = strtok(NULL, " ");
			lime += *f - 48;
		}
		if (strcmp(f, "PLUM") == 0) {
			f = strtok(NULL, " ");
			plum += *f - 48;
		}
	}
	if (banana == 5 || strawberry == 5 || lime == 5 || plum == 5) printf("YES");
	else printf("NO");
}