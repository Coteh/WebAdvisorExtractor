#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "course_csv_writer.h"

#define MAX_LINE_SIZE 255

void printUsage() {
    printf("usage: WebAdvisorExtractor [OPTIONS]... [INPUT_FILE]\n");
}

void printHelp() {
    printUsage();
    printf("\n-csv\t\t\tFormat output to CSV specification.\n-d\t\t\tPlace headers on top of output.\n-h, --help\t\tShow help.\n");
}

int main(int argc, char** argv) {
    FILE* file;
    char line[MAX_LINE_SIZE];
    int isCSV;
    int isHeader;
    size_t i;

    isCSV = 0;
    isHeader = 0;
    file = NULL;

    if (argc <= 1) {
        printUsage();
        return 1;
    }

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-csv") == 0) {
            isCSV = 1;
        } else if (strcmp(argv[i], "-d") == 0) {
            isHeader = 1;
        } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            printHelp();
            if (file != NULL) {
                fclose(file);
            }
            return 1;
        } else {
            file = fopen(argv[i], "r");
            if (file == NULL) {
                fprintf(stderr, "Filepath at \"%s\" could not be opened.\n", argv[1]);
                return 1;
            }
        }
    }

    if (file == NULL) {
        fprintf(stderr, "No file specified.");
        return 1;
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
