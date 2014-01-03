#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{
  char str1[] = "ls";
  char str2[] = "-al";

  char str[32];
  memset(str, 0, 32);

  sprintf(str, "%s%s%s", str1, " ", str2);

  system(str);  //fork->exec->waitpid;
  return 0;
}


int main(int argc, char *argv[])
{
  int fd;
  char str1[] = "you";
  char str2[] = "are";
  char str3[] = "a";
  char str4[] = "super man!";
  
  char str[32];
  memset(str, 0, 32);
  
  fd = open("/test", O_RDWR|O_CREAT, 0700);
  if(fd < 0)
  {
    printf("create and open file failed !\n");
    return -1;
  }
  sprintf(str, "%s%s%s%s%s%s%s%s", str1, " ", str2, " ", str3, " ", str4, "\n");
  write(fd, str, 32);
  if(fsync(fd) == -1)
  {
    printf("data buffer can't write back to disk!\n");
    close(fd);
    return -1;
  }
  close(fd);
  return 0;
}
