//
// Created by 我叫城北徐公° on 2022/11/2.
//
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void test_file()
{
//    FILE* file = fopen( "/Users/alex/Desktop/file.txt", "a");
//    fputs("JQKA", file);
////    char buf[1024] = {0};
////    fgets(buf, 1024, file);
////    printf("%s\n", buf);
////
//    fflush(file);
//    fclose(file);
    int fd = open("/Users/alex/Desktop/file.txt", O_RDWR | O_CREAT | O_APPEND);
    write(fd, "BCDEFGHIJKLMN", 5);
    fsync(fd);
    close(fd);
}

//int main(void)
//{
//    test_file();
//}