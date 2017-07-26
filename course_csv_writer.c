#include "course_csv_writer.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void printCSVHeader() {
    printf("type,coursecode,sectioncode,id,coursetitle\n");
}

void trimEnd(char* str) {
    size_t length;
    size_t i;

    if (str == NULL) {
        return;
    }

    length = strlen(str);

    for (i = length - 1; i > 0; i--) {
        if (str[i] == '\n' || str[i] == '\r' || str[i] == ' ') {
            str[i] = '\0';
        } else {
            break;
        }
    }
}

/**
Turns something like this: "(2750)"
into an integer like: 2750
Note: "(0200)" -> 200
On error, returns a 0 and errno updated
to reflect error
*/
int getCourseID(char* idStr) {
    int result;
    size_t length;
    char* copyStr;

    if (idStr == NULL) {
        return 0;
    }

    length = strlen(idStr);
    if (length <= 2) {
        return 0;
    }

    copyStr = malloc(sizeof *copyStr * (length + 1));
    if (copyStr == NULL) {
        return 0;
    }

    strncpy(copyStr, idStr, sizeof *copyStr * (length + 1));

    copyStr[length - 1] = '\0';

    result = atoi(&copyStr[1]);

    free(copyStr);
    return result;
}

/**
The format looks like this:
TYPE*COURSE CODE*SECTION CODE (ID) COURSE TITLE
This function is undefined for any other type of string.
*/
void printCSV(char* line) {
    CourseCSV csv;
    int staIndex;
    char* ptr;
    size_t length;
    size_t i;

    //Bound checks
    if (line == NULL) {
        return;
    }

    length = strlen(line);
    if (length == 0) {
        return;
    }

    //Remove any ending whitespace
    trimEnd(line);

    //Begin extracting course type, course code, section code, and id
    staIndex = 0;
    ptr = line;
    for (i = 0; i < length; i++) {
        switch (line[i]) {
            case '*': {
                switch (staIndex) {
                    case 0:
                        line[i] = '\0';
                        strncpy(csv.courseType, ptr, DIGITS_LENGTH);
                        ptr = &line[i + 1];
                        break;
                    case 1:
                        line[i] = '\0';
                        strncpy(csv.courseDigits, ptr, DIGITS_LENGTH);
                        ptr = &line[i + 1];
                        break;
                }
                staIndex++;
                break;
            }
            case ' ': {
                switch (staIndex) {
                    case 2:
                        line[i] = '\0';
                        strncpy(csv.sectionDigits, ptr, DIGITS_LENGTH);
                        ptr = &line[i + 1];
                        break;
                    case 3:
                        line[i] = '\0';
                        csv.courseID = getCourseID(ptr);
                        ptr = &line[i + 1];
                        break;
                }
                staIndex++;
            }
        }
    }

    //Remaining text is for the course title
    strncpy(csv.courseTitle, ptr, TITLE_LENGTH);

    csv.courseType[DIGITS_LENGTH] = '\0';
    csv.courseDigits[DIGITS_LENGTH] = '\0';
    csv.sectionDigits[DIGITS_LENGTH] = '\0';
    csv.courseTitle[TITLE_LENGTH] = '\0';

    printf("%s,%s,%s,%d,\"%s\"\n", csv.courseType, csv.courseDigits, csv.sectionDigits, csv.courseID, csv.courseTitle);
}
