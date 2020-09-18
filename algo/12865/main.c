#include <stdio.h>
#pragma warning (disable: 4996)

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int memo[101][100001];
int obj[101][2];

int backpack(int n, int w ) {
    if (n <= 0 ) {
        return 0;
    }

    if (memo[n][w] != 0)
        return memo[n][w];

    else if (w < obj[n][0])
        memo[n][w] = backpack(n - 1, w);
    else {
        memo[n][w] =  MAX(obj[n][1] + backpack(n - 1, w-obj[n][0]), backpack(n - 1, w));
    }
    /*
    처음 코드는  return MAX(obj[n][1] + backpack(n - 1, w-obj[n][0]), backpack(n - 1, w));
    시간 초과났다

    w < obj[n][w]인 상황만 메모한거라서 완전탐색 비슷한 시간이 나왔을 것

    완전탐색에서 바꾸다가 실수했음
    
    
    
    */
    return memo[n][w];
}

int main() {
    int N, K;

    int value=0;
    scanf("%d%d", &N, &K);

    for (int i = 1; i <= N;i++) {
        scanf("%d%d", &obj[i][0], &obj[i][1]);
    } 


    int t = backpack(N, K);
    printf("%d", t);


}

