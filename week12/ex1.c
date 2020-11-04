#include <stdio.h>


int main() {
    char s[20];
    int n = 20;

    FILE* file;
    fopen_s(&file, "/dev/random", "r");

    FILE* file2;
    fopen_s(&file2, "ex1.txt", "w");

    fread(&s, 1, n, &file);   
    
    fprintf(file, "%s", s);
    fclose(file);
    fclose(file2);
    return 0;
}