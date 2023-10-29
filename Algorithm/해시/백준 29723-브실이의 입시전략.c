#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int score;
    char name[30];
} Sub;

int compare(const void* x, const void* y) {
    Sub* xx = (Sub*)x;
    Sub* yy = (Sub*)y;

    if (xx->score < yy->score) return 1;
    if (xx->score > yy->score) return -1;
    return 0;
}

Sub sub[10001];
char ksub[10001][21];

int main() {
    int k, m, n;
    scanf("%d %d %d", &k, &m, &n);

    for (int i = 0; i < k; i++) {
        scanf("%s %d", sub[i].name, &sub[i].score);
    }

    for (int i = 0; i < n; i++) {
        scanf("%s", ksub[i]);
    }

    int min = 0, max = 0;

    // ������ �����̶� ������ ���� ��Ī

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (!strcmp(sub[j].name, ksub[i])) {
                min += sub[j].score;
                max += sub[j].score;
                sub[j].score = 0;
            }
        }
    }

    // ������ ������������ sort
    qsort(sub, k, sizeof(Sub), compare);

    // Max�� ���
    for (int i = 0; i < m - n; i++) {
        if (!sub[i].score) {
            continue;
        }
        else {
            max += sub[i].score;
        }
    }

    // Min�� ��� (�ߺ��� ������ 0������ ó���ؼ�, Sub �迭�� score�� 0�� �׸��� -n ��ŭ ����
    for (int i = 0; i < m - n; i++) {
        if (!sub[k - i - n - 1].score) {
            continue;
        }
        else {
            min += sub[k - i - n - 1].score;
        }
    }
    
    printf("%d %d\n", min, max);

    return 0;
}
