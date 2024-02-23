#include <sys/stat.h>
#include <stdio.h>

struct stat st;
int type;
//0 = bytes
//1 = kbytes
//2 = mbytes
//3 = gbytes
//4 = tbytes
int bytes;
char* format;

int main(int argc, char** argv) {

  if(argc != 2) {
    printf("Usage: sizeof <file>\n");
    return 1;
  }
  
  stat(argv[1], &st);
   
  if(st.st_size < 1000) {
    type = 0;
    bytes = st.st_size;
    format = "bytes";
  }
  if(st.st_size >= 1000) {
    type = 1;
    bytes = st.st_size / 1000;
    format = "kilobytes";
  }
  if(st.st_size >= 1000000) {
    type = 2;
    bytes = st.st_size / 1000000;
    format = "megabytes";
  }
  if(st.st_size >= 1000000000) {
    type = 3;
    bytes = st.st_size / 1000000000;
    format = "gigabytes";
  }
  if(st.st_size >= 1000000000000) {
    type = 4;
    bytes = st.st_size / 1000000000000;
    format = "terabytes";
  }


  printf("%i %s\n", bytes, format);
  return 0;

}
