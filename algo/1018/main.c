#include <stdio.h>
#pragma warning (disable: 4996)

//w = 1, b= 0; 좌상단부터 쭉 적어넣었을 때
int main() {
	int N, M, min = 64;
	char inp[51][51];
	char table[8][8] = { "WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW" };

	scanf("%d%d", &N, &M);

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			scanf(" %c", &inp[i][j]);
		}

	}

	for (int i = 0;i < N-7;i++) {
		for (int j = 0;j < M-7;j++) {
			int count = 0;
			for (int byeon=0; byeon < 8;byeon++) {
				for (int su=0;su < 8;su++){
					if (table[byeon][su] != inp[i + byeon][j + su]) count++;
				
				}				
			}
			count = count < 64 - count ? count : 64 - count;
			min = min < count ? min : count;
		}

	}

	printf("%d", min);

}

