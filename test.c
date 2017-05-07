#include <stdio.h>
#include <string.h>
#include "course_csv_writer.h"

int main(int argc, char** argv) {
    char testStr[100];

    printf("Testing CSV Header print...\n");
    printCSVHeader();
    printf("Testing CSV data print...\n");
    strcpy(testStr, "ZOO*4920*01 (6652) Lab Studies in Ornithology");
    printCSV(testStr);
    printf("Testing complete.\n");

    return 0;
}
