#include <stdio.h>
#pragma warning (disable:4996)
#define INF 100000000
int W[17][17];
int cash[17][1 << 17];
int N;
int minLength(int here, int visited) {
    visited |= (1 << here);

    int min = cash[here][visited];
    int temp = INF;

    if (min) return min;
    if (visited == ((1 << N) - 1)) {
        if (W[here][0] == 0) return INF;
        else return W[here][0];
    }

    min = INF;

    for (int i = 0; i < N; i++) {
        if (W[here][i] && !(i != here && (visited & (1 << i)))) {
            temp = W[here][i] + minLength(i, visited | (1 << i));
            min = min < temp ? min : temp;
        }

    }
    
    return cash[here][visited] = min;
}
int main() {
    scanf("%d", &N);

    for (int i = 0; i < N;i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &W[i][j]);
        }
    }

    printf("%d",minLength(0,0));

    return 0;
}