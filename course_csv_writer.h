#ifndef __COURSE_CSV_WRITER_H__
#define __COURSE_CSV_WRITER_H__

#define DIGITS_LENGTH 5
#define TITLE_LENGTH 101

typedef struct CourseCSV_struct {
    char courseType[DIGITS_LENGTH];
    char courseDigits[DIGITS_LENGTH];
    char sectionDigits[DIGITS_LENGTH];
    int courseID;
    char courseTitle[TITLE_LENGTH];
} CourseCSV;

void printCSVHeader();
void printCSV(char* line);

#endif /* end of include guard: __COURSE_CSV_WRITER_H__ */
