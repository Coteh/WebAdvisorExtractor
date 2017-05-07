#include <stdio.h>
#include <string.h>
#include "course_csv_writer.h"

int main(int argc, char** argv) {
    char testStr[100];

    printf("Testing CSV Header print...\n");
    printCSVHeader(stdout);
    printf("Testing CSV data print...\n");
    strcpy(testStr, "ZOO*4920*01 (6652) Lab Studies in Ornithology");
    printCSV(stdout, testStr);
    printf("Testing CSV bounds...\n");
    strcpy(testStr, "CHOPITOFF*123456789*123456789 (123456789) The rest of this should be printed in title");
    printCSV(stdout, testStr);
    printf("Testing complete.\n");

    return 0;
}
