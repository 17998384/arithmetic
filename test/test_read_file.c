//
// Created by 我叫城北徐公° on 2022/1/21.
//

#include <stdio.h>
#include <sys/file.h>
#include <stddef.h>
#include <unistd.h>


int main_test_read_file(void)
{
    FILE* file = fopen("/Users/alex/Desktop/000170.sst", "r+");
    char buffer[1024] = {0};
    size_t readNum = fread(buffer, 1, 1023, file);
    printf("readNum : %ld\n", readNum);
    printf("%s\n", buffer);
    fclose(file);

    //get tmp file
    FILE* tmpFile = tmpfile();
//    fwrite(buffer, 1, 8, tmpFile);
//    char tmpBuffer[1024];
//    fread(tmpBuffer, 1, 8, tmpFile);
//
    fclose(tmpFile);

    return 0;
}