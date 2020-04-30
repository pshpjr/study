/*

일곱 난쟁이

문제
왕비를 피해 일곱 난쟁이들과 함께 평화롭게 생활하고 있던 백설공주에게 위기가 찾아왔다. 일과를 마치고 돌아온 난쟁이가 일곱 명이 아닌 아홉 명이었던 것이다.
아홉 명의 난쟁이는 모두 자신이 "백설 공주와 일곱 난쟁이"의 주인공이라고 주장했다. 뛰어난 수학적 직관력을 가지고 있던 백설공주는, 다행스럽게도 일곱 난쟁이의 키의 합이 100이 됨을 기억해 냈다.
아홉 난쟁이의 키가 주어졌을 때, 백설공주를 도와 일곱 난쟁이를 찾는 프로그램을 작성하시오.

입력
아홉 개의 줄에 걸쳐 난쟁이들의 키가 주어진다. 주어지는 키는 100을 넘지 않는 자연수이며, 아홉 난쟁이의 키는 모두 다르며, 가능한 정답이 여러 가지인 경우에는 아무거나 출력한다.

출력
일곱 난쟁이의 키를 오름차순으로 출력한다. 일곱 난쟁이를 찾을 수 없는 경우는 없다.

예제 입력 1
20
7
23
19
10
15
25
8
13
예제 출력 1
7
8
10
13
19
20
23

*/
#include <stdio.h>
#include <stdlib.h>

int compare (void *first, void *second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else 
        return 0;
}

int N = 9;
int main(){
	int tallSum = 0;
	int tall[9];
	
	for(int i = 0 ;i < N ;i++)
	{
		scanf("%d",&tall[i]);
		tallSum += tall[i];
	}
	
	qsort(tall, sizeof(tall)/sizeof(int), sizeof(int), compare);
	
	for(int i = 0; i<N;i++){
		for(int j = i+1;j<N; j++){
			if(tallSum-tall[i]-tall[j] == 100){
				tall[i] = 0;
				tall[j] = 0;
				goto forend;
			}
		}
	}
	forend:
	for(int i = 0; i<N;i++){
		if(tall[i] == 0) continue;
		printf("%d\n",tall[i]);
	}

}