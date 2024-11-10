#include<stdio.h>
#include<stdlib.h>

int main() {
    int arr[10] = {1, 2, 3, 2, 1, 4, 35, 56, 5, 5};
    int max_value = 100;  
    int *hash = (int *)calloc(max_value, sizeof(int));  
    for (int i = 0; i < 10; i++) {
        if (arr[i] < max_value) {  
            hash[arr[i]] += 1;
        }
    }
    
    int q = 5;  
    while (q--) {
        int n;
        scanf("%d", &n);
        
        if (n < max_value && n >= 0) {  
            printf("%d\n", hash[n]);
        } else {
            printf("Out of range\n");
        }
    }
    
    free(hash); 
    return 0;
}
