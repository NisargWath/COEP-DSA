#include<stdio.h>

int main() {
    FILE *fp;
    char ch;
    
    fp = fopen("/Users/appleApple/Desktop/DSA/build/File/input.txt", "w");  // Opening file in write mode
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("Keep typing characters. Type 'q' to terminate\n");
    
    while(1) {
        scanf(" %c", &ch);
        if (ch == 'q')  // Exit on 'q'
            break;
        fputc(ch, fp);  // Write character to file
    }

    fclose(fp);
    return 0;  // Correct spelling from 'reutrn' to 'return'
}
