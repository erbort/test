#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


int main(int argc, char *argv[])
{
  int fd;
  char str[3][64];
  memset(str, 0, 3*64);

  sprintf(str[0], "%s%s%s%s", "ifconfig eth0 hw ether ", "00:0c:30:a5:17:3d", ";", "\n"); //note "\n"
  sprintf(str[1], "%s%s%s%s%s%s%s", "ifconfig eth0 ", "192.168.1.253", " ", "netmask ", "255.255.255.0", ";" , "\n");
  sprintf(str[2], "%s%s%s%s", "route add default gw ", "192.168.1.0", ";" , "\n");

  
  fd = open("/netconfig", O_RDWR|O_CREAT, 0766);
  write(fd, "#!/bin/sh\n", strlen("#!/bin/sh\n"));    //note strlen()
  write(fd, str[0], strlen(str[0]));
  write(fd, str[1], strlen(str[1]));
  write(fd, str[2], strlen(str[2]));
  fsync(fd);
  close(fd);

  FILE *fp;
  char rd[64];
  memset(rd, 0, 64);
  fp = fopen("/netconfig", "r");
  while(!feof(fp))
  {
    fgets(rd, 64, fp);
    printf(“%s”, rd);
    memset(rd, 0, 64);
  }
  fclose(fp);
  
}
