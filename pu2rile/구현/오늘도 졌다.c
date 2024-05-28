#include <stdio.h>

int main() {
    int j[9];
    int g[9];
    int win = 0;
    int j_score = 0;
    int g_score = 0;
    
    for (int i=0 ; i<9; i++) { //제미니스 점수 입력
        scanf("%d", &j[i]);
    }
    for (int i=0 ; i<9; i++) { //걸리버스 점수 입력
        scanf("%d", &g[i]);
    }
    
    for (int i=0 ; i<9; i++) {
        j_score += j[i]; //제미니스 점수 누적합(j_score == 총 점수)
        if (j_score > g_score) //점수 비교
            win = 1; //제미니스가 이겼다면 win = 1
        g_score += g[i]; //걸리버스 점수 누적합(g_score == 총 점수)
    }
    if (j_score < g_score && win == 1) //제미니스가 졌지만 제미니스가 이긴 적이 있다면(역전패)
        printf("Yes\n");
    else
        printf("No\n");
}
