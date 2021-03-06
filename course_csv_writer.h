#ifndef __COURSE_CSV_WRITER_H__
#define __COURSE_CSV_WRITER_H__

#define DIGITS_LENGTH 4
#define TITLE_LENGTH 100

typedef struct CourseCSV_struct {
    char courseType[DIGITS_LENGTH + 1];
    char courseDigits[DIGITS_LENGTH + 1];
    char sectionDigits[DIGITS_LENGTH + 1];
    int courseID;
    char courseTitle[TITLE_LENGTH + 1];
} CourseCSV;

void printCSVHeader();
void printCSV(char* line);

void trimEnd(char* str);
int getCourseID(char* idStr);

#endif /* end of include guard: __COURSE_CSV_WRITER_H__ */
