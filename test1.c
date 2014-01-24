#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>

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


/*
local->tm_year
*/

int main(int argc, char *argv[])
{
  time_t stime;
  struct tm *local;
  
  stime = time(NULL);
  
  local = gmtime(&stime);
  
  printf("%d-%d-%d-%d-%d-%d\n",local->tm_year+1900, local->tm_mon+1, local->tm_mday, local->tm_hour+8, local->tm_min, local->tm_sec);
  //note :tm_hour+8,  peking time
}

int main(int  argc, char *argv[])
{
    char  *str="hello!";
    char *p;
    p=str;
    printf("%c\n", *p);
    p = p+2;
    printf("%c\n",p[-1]);
    return 0;
}
