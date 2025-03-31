#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


#define MAX 255



int main(int argc, char *argv[])
{
    if(argc != 4)
    {
        printf("Must have 3 arguments");
        exit(1);
    }

    int shortLine = 0;
    int longLine = 0;
    char *inputFile = argv[1];
    char *writeFile1 = argv[2];
    char *writeFile2 = argv[3];
    FILE *fileGiven = fopen(inputFile, "r");
    FILE *fileShort = fopen(writeFile1, "w");
    FILE *fileLong = fopen(writeFile2, "w");

    char line[MAX];

    while(fgets(line, MAX, fileGiven))
    {
        if (strlen(line) < 20)
        {
            //uppercase
            for (int i = 0; line[i] != '\0'; i++)
            {
                line[i] = toupper(line[i]);
            }
            fprintf(fileShort, "%s\n", line);
            shortLine++;
        }
        else
        {
            for (int i = 0; line[i] != '\0'; i++)
            {
                line[i] = tolower(line[i]);
            }
            fprintf(fileLong, "%s\n", line);
            longLine++;
        }
    }
    printf("%d lines written to %s\n", shortLine, argv[2]);
    printf("%d lines written to %s\n", longLine, argv[3]);
}