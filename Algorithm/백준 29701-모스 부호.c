#include <stdio.h>
#include <string.h>
int main() {
	char real[43] = { 'A','B','C','D','E','F','G','H','I','J','K','L','N','M','O'
	,'P','Q','R','S','T','U','V','W','X','Y','Z','1','2','3','4','5','6','7','8'
	,'9','0',',','.','?',':','-','@' };
	char mos[43][7] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
	"-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--",
	"-..-","-.--","--..",".----","..---","...--","....-",".....","-....","--...",
	"---..","----.","-----","--..--",".-.-.-","..--..","---...","-....-",".--.-."};

	int n,c,a;
	scanf("%d", &n);
	getchar();

	a = 0;
	char word[512] = { 0 };
	while ((c = getchar()) != '\n') {
		word[a++] = c;
	}
	char* cc = strtok(word, " ");
	for(int i=0;i<n;i++) {
		for (int j = 0; j < 43; j++) {
			if (strcmp(cc, mos[j]) == 0) printf("%c", real[j]);
		}
		cc = strtok(NULL, " ");
	}
}