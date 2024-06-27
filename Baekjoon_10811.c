#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    int Basket;
    int *basket;
    int *temp;
    int num;
    int num1;
    int num2;
    
    scanf("%d %d", &Basket, &num);
    basket = (int*)malloc(sizeof(int) * Basket);
    temp = (int*)malloc(sizeof(int) * Basket);
    
    for (int i = 0; i < Basket; i++) {
        basket[i] = i + 1;
        temp[i] = 0;
    }
    
    for (int i = 0; i < num; i++) {
        scanf("%d %d", &num1, &num2);
        
        if (num1 == num2) {
            continue;
        }
        
        int t = 0;
        for (int j = num1 - 1; j < num2; j++) {
            temp[t] = basket[j];
            t++;
        }
        t = 0;
        
        for (int j = 0; j < Basket / 2; j++) {
            int TEMP = temp[j];
            temp[j] = temp[Basket - j - 1];
            temp[Basket - j - 1] = TEMP;
        }
        
        for (int j = 0; j < Basket; j++) {
            if (temp[j] != 0) {
                int TEMP = temp[j];
                temp[j] = temp[t];
                temp[t] = TEMP;
                t++;
            }
        }
        t = 0;
        
        for (int j = num1 - 1; j < num2; j++) {
            basket[j] = temp[t];
            t++;
        }
        t = 0;
        
        for (int j = 0; j < Basket; j++) {
            temp[j] = 0;
        }
    }
    
    for (int i = 0; i < Basket; i++) {
        printf("%d ", basket[i]);
    }
    
    return 0;
}
