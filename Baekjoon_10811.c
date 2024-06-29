#include <stdio.h> 
#include <stdlib.h>
#include <string.h> // 황선준이 추가했습니다 

int main(void) {

    int Basket; // 바구니의 개수를 저장하는 변수
    int *basket; // 바구니 번호를 동적으로 할당하기 위한 포인터
    int *temp; // 임시 배열을 동적으로 할당하기 위한 포인터
    int num; // 작업의 개수를 저장하는 변수
    int num1; // 각 작업의 시작 인덱스
    int num2; // 각 작업의 끝 인덱스
    int i, j; // 반복문에서 사용할 변수
    int t = 0; // 임시 인덱스 변수
    
    scanf("%d %d", &Basket, &num); // 사용자로부터 바구니의 개수와 작업의 개수를 입력받음
    
    basket = (int*)malloc(sizeof(int) * Basket); // 사용자로부터 바구니의 개수와 작업의 개수를 입력받음
    temp = (int*)malloc(sizeof(int) * Basket);
    
    for (i = 0; i < Basket; i++) {
        basket[i] = i + 1; // basket 배열을 1부터 Basket까지의 숫자로 초기화
        temp[i] = 0; // temp 배열을 0으로 초기화
    }
    
    for (i = 0; i < num; i++) { // 작업의 개수만큼 반복
        scanf("%d %d", &num1, &num2); // 각 작업의 시작과 끝 인덱스를 입력받음
        
        if (num1 == num2) { // 시작 인덱스와 끝 인덱스가 같으면 작업을 건너뜀
            continue;
        }
        
        for (j = num1 - 1; j < num2; j++) { // basket 배열에서 num1부터 num2까지의 요소를 temp 배열에 복사
            temp[t] = basket[j];
            t++;
        }
        t = 0;
        
        for (j = 0; j < Basket / 2; j++) { // 지정된 범위 내에서 temp 배열의 요소를 뒤집음
            int TEMP = temp[j];
            temp[j] = temp[Basket - j - 1];
            temp[Basket - j - 1] = TEMP;
        }
        
        for (j = 0; j < Basket; j++) { // 0이 아닌 요소를 temp 배열의 앞부분으로 이동
            if (temp[j] != 0) {
                int TEMP = temp[j];
                temp[j] = temp[t];
                temp[t] = TEMP;
                t++;
            }
        }
        t = 0;
        
        for (j = num1 - 1; j < num2; j++) { // 뒤집힌 요소를 basket 배열에 다시 복사
            basket[j] = temp[t];
            t++;
        }
        t = 0;
        
        for (j = 0; j < Basket; j++) { // temp 배열을 0으로 초기화
            temp[j] = 0;
        }
    }
    
    for (i = 0; i < Basket; i++) { // 최종 바구니 배열을 출력
        printf("%d ", basket[i]);
    }

    // 동적으로 할당된 메모리를 해제
    free(basket);
    free(temp);
    
    return 0;
}


// 위의 코드도 좋으나, 이중 for문을 사용하여 코드를 짜보는 것이 더 효율적으로 보여, 예시코드를 드려봅니다. (by, 황선준)
/*
    #include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    int Basket; // 바구니의 개수를 저장하는 변수
    int *basket; // 바구니 번호를 동적으로 할당하기 위한 포인터
    int *temp; // 임시 배열을 동적으로 할당하기 위한 포인터
    int num; // 작업의 개수를 저장하는 변수
    int num1; // 각 작업의 시작 인덱스
    int num2; // 각 작업의 끝 인덱스
    int i, j; // 반복문에서 사용할 변수
    int t = 0; // 임시 인덱스 변수

    scanf("%d %d", &Basket, &num); // 사용자로부터 바구니의 개수와 작업의 개수를 입력받음

    basket = (int*)malloc(sizeof(int) * Basket);
    temp = (int*)malloc(sizeof(int) * Basket);

    for (i = 0; i < Basket; i++) {
        basket[i] = i + 1; // basket 배열을 1부터 Basket까지의 숫자로 초기화
    }

    for (i = 0; i < num; i++) { // 작업의 개수만큼 반복
        scanf("%d %d", &num1, &num2); // 각 작업의 시작과 끝 인덱스를 입력받음

        if (num1 == num2) { // 시작 인덱스와 끝 인덱스가 같으면 작업을 건너뜀
            continue;
        }

        // 배열 뒤집기
        for (j = num1 - 1; j < num1 - 1 + (num2 - num1 + 1) / 2; j++) {
            int TEMP = basket[j];
            basket[j] = basket[num2 - (j - (num1 - 1)) - 1];
            basket[num2 - (j - (num1 - 1)) - 1] = TEMP;
        }
    }

    // temp 배열을 0으로 초기화
    memset(temp, 0, sizeof(int) * Basket);

    for (i = 0; i < Basket; i++) { // 최종 바구니 배열을 출력
        printf("%d ", basket[i]);
    }

    // 동적으로 할당된 메모리를 해제
    free(basket);
    free(temp);

    return 0;
}

*/
