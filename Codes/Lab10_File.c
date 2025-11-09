//ShreyaGawhane-IT-B-120
/*Write a C program (name it "filecopy. c")  that copies the contents of one file to a destination file.
This program will read data from one file and copy them to another. The first input that the program will need is the names of the two files: 
input file ("input.txt") and output file ("output.txt"). Once the two file names have been obtained,the program must open the input file and create
and open the output file.*/
#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *srcFile, *destFile;
    char srcName[100], destName[100];
    char ch;

    printf("Enter the source file name (e.g., input.txt): ");
    scanf("%s", srcName);

    printf("Enter the destination file name (e.g., output.txt): ");
    scanf("%s", destName);

    srcFile = fopen(srcName, "r");
    if (srcFile == NULL) {
        printf("Error: Cannot open source file '%s'\n", srcName);
        exit(1);
    }

    destFile = fopen(destName, "w");
    if (destFile == NULL) {
        printf("Error: Cannot create destination file '%s'\n", destName);
        fclose(srcFile);
        exit(1);
    }

    while ((ch = fgetc(srcFile)) != EOF) {
        fputc(ch, destFile);
    }

    printf("File copied successfully from '%s' to '%s'.\n", srcName, destName);

    fclose(srcFile);
    fclose(destFile);
    return 0;
}
