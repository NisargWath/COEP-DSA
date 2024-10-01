#include<stdio.h>

int main() {
    FILE *fp;
    char ch;
    
    fp = fopen("/Users/appleApple/Desktop/DSA/build/File/input.txt", "r");  // Open file in read mode
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {  // Read until end of file
        printf("%c", ch);  // Print each character
    }

    fclose(fp);
    return 0;
}
