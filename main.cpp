#include <stdio.h>
#include <string.h>

void printReversed(FILE *file);

int main()
{
    FILE *file;
    char s[10000];

    file = fopen("varshini.txt", "w");
    if (file == NULL)
    {
        puts("Cannot open file for writing");
        return 1;
    }
    printf("Enter the introduction of varshini (Press Enter on an empty line to stop):\n");
    while (strlen(fgets(s, sizeof(s), stdin)) > 1)
    {
        fputs(s, file);
        fputs("\n", file);
    }
    fclose(file);
    printf("\nIntroduction of varshini being read now...\n");
    file = fopen("varshini.txt", "r");
    if (file == NULL)
    {
        puts("Cannot open file for reading");
        return 2;
    }
    while (fgets(s, sizeof(s), file) != NULL)
    {
        printf("%s", s);
    }
    fclose(file);
    file = fopen("varshini.txt", "r");
    if (file == NULL)
    {
        puts("Cannot open file for reading");
        return 3;
    }
    printf("\nReversed content of the file:\n");
    printReversed(file);

    fclose(file);
    return 0;
}
void printReversed(FILE *file)
{
    char s[10000];
    if (fgets(s, sizeof(s), file) == NULL)
        return;
    printReversed(file);
    printf("%s", s);
}
