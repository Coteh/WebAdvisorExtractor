#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "course_csv_writer.h"

#define MAX_LINE_SIZE 255

int main(int argc, char** argv) {
    FILE* file;
    FILE* output;
    char line[MAX_LINE_SIZE];
    int isWriting;
    int isCSV;
    size_t i;

    if (argc <= 1) {
        printf("usage: WebAdvisorExtractor [INPUT_FILE] -s [OUTPUT_FILE] -csv\n");
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Filepath at \"%s\" could not be opened.\n", argv[1]);
        return 1;
    }

    isWriting = 0;
    isCSV = 0;
    output = stdout;
    for (i = 2; i < argc; i++) {
        if (strcmp(argv[2], "-s") == 0) {
            if (argc == 3) {
                fprintf(stderr, "Must provide a file to output to.\n");
                return 1;
            }
            output = fopen(argv[3], "w");
            if (output == NULL) {
                fprintf(stderr, "Filepath at \"%s\" could not be opened for writing.\n", argv[3]);
                fclose(file);
                return 1;
            }
            isWriting = 1;
        } else if (strcmp(argv[2], "-csv") == 0) {
            isCSV = 1;
        }
    }

    i = 0;
    while (fgets(line, MAX_LINE_SIZE, file) != NULL) {
        if (strstr(line, "*") != NULL) {
            if (isCSV) {
                printCSV(output, line);
            } else {
                fprintf(output, "%s", line);
            }
        }
        i++;
    }

    if (isWriting) {
        fclose(output);
    }
    fclose(file);

    return 0;
}
