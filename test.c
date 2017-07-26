#include "course_csv_writer.h"
#include <string.h>
#include <stdio.h>

int main(int argc, char** argv) {
    char testStr[100];
    int courseID;
    int testStatus;

    testStatus = 0;
    printf("Testing trimEnd...\t\t\t\t");
    strcpy(testStr, "No ending whitespace \r\n");
    trimEnd(testStr);
    if (strcmp(testStr, "No ending whitespace") != 0) {
        printf("X\n");
        testStatus = 1;
    } else {
        printf("✓\n");
    }
    printf("Testing getCourseID...\t\t\t\t");
    courseID = getCourseID("(0200)");
    if (courseID != 200) {
        printf("X\n");
        testStatus = 1;
    } else {
        printf("✓\n");
    }
    if (testStatus == 0) {
        printf("All tests pased!\n");
    }
    return testStatus;
}
