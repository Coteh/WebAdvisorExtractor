#ifndef __COURSE_CSV_WRITER_H__
#define __COURSE_CSV_WRITER_H__

#define DIGITS_LENGTH 4
#define TITLE_LENGTH 100

#include <stdio.h>

typedef struct CourseCSV_struct {
    char courseType[DIGITS_LENGTH + 1];
    char courseDigits[DIGITS_LENGTH + 1];
    char sectionDigits[DIGITS_LENGTH + 1];
    int courseID;
    char courseTitle[TITLE_LENGTH + 1];
} CourseCSV;

void printCSVHeader(FILE* file);
void printCSV(FILE* file, char* line);

#endif /* end of include guard: __COURSE_CSV_WRITER_H__ */
