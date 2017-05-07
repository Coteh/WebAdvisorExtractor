#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 255

int main(int argc, char** argv) {
    FILE* file;
    FILE* output;
    char line[MAX_LINE_SIZE];
    int isWriting;
    size_t i;

    if (argc <= 1) {
        printf("usage: WebAdvisorExtractor [INPUT_FILE] -s [OUTPUT_FILE]\n");
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Filepath at \"%s\" could not be opened.\n", argv[1]);
        return 1;
    }

    isWriting = 0;
    if (argc > 2 && strcmp(argv[2], "-s") == 0) {
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
    } else {
        output = stdout;
    }

    i = 0;
    while (fgets(line, MAX_LINE_SIZE, file) != NULL) {
        if (strstr(line, "*") != NULL) {
            fprintf(output, "%s", line);
        }
        i++;
    }

    if (isWriting) {
        fclose(output);
    }
    fclose(file);

    return 0;
}
