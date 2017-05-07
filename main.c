#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "course_csv_writer.h"

#define MAX_LINE_SIZE 255

int main(int argc, char** argv) {
    FILE* file;
    char line[MAX_LINE_SIZE];
    int isCSV;
    int isHeader;
    size_t i;

    if (argc <= 1) {
        printf("usage: WebAdvisorExtractor [INPUT_FILE] [-csv|-h]\n");
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Filepath at \"%s\" could not be opened.\n", argv[1]);
        return 1;
    }

    isCSV = 0;
    isHeader = 0;
    for (i = 2; i < argc; i++) {
        if (strcmp(argv[i], "-csv") == 0) {
            isCSV = 1;
        } else if (strcmp(argv[i], "-h") == 0) {
            isHeader = 1;
        }
    }

    i = 0;
    if (isHeader) {
        if (isCSV) {
            printCSVHeader();
        } else {
            printf("coursedata\n");
        }
    }
    while (fgets(line, MAX_LINE_SIZE, file) != NULL) {
        if (strstr(line, "*") != NULL) {
            if (isCSV) {
                printCSV(line);
            } else {
                printf("%s", line);
            }
        }
        i++;
    }

    fclose(file);

    return 0;
}
