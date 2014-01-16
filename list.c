#include <...>
...
...
...
typedef struct list{
        char v[4];
        char vv[8];
        char vvv[16];
        char num;
        struct list *next;
}vlist;

vlist *g;

int clearlist(struct list *head)
{
        struct list *header;
        struct list *tmp;
        header = head;
        if(header->next == NULL)
        {
                free(header);
        }else{
                tmp = header->next;
                while(tmp->next != NULL)
                {
                        free(header);
                        header = tmp;
                        tmp = tmp->next;
                }
                free(header);
                free(tmp);
      }
}

int main(int argc, char *argv[])
{
        FILE *fp; 
        char dst[8][32];
        char mm[32], m, i, *p;  

        memset(dst, 0, 8*32);
        memset(mm, 0, 32);

        fp = fopen("/dest", "r");
        m=0;i=0;p=NULL;

        while(!feof(fp))
        {
                fgets(dst[i], 31, fp);
                if(strlen(dst[i]) >0)//if not judge this ,then when you execute it ,it will segment default!!!
                {
                        p = strstr(dst[i], "=");
                        p++;
                        while(*p != '\0')
                        {
                                mm[m] = *p;
                                m++; p++;       
                        }               
                        m=0;
                        printf("%s", mm);
                }
                memset(mm, 0, 32);
                i++;
        }
        fclose(fp);
}

#include <libgen.h>
int testdir()
{
        char cwd[32];
        memset(cwd, 0, 32);
        //printf("%s\n", getcwd(cwd, 32));
    	sprintf(cwd,"%s","/hiwork/mpp/sample/nha/cdn/vcnueai");
      	printf("%s\n",dirname(cwd));
}

int main(int argc, char *argv[])
{
        FILE *fp; 
        char dst[8][32];
        char mm[32], m, i, *p;  

        memset(dst, 0, 8*32);
        memset(mm, 0, 32);

        fp = fopen("/dest", "r");
        m=0;i=0;p=NULL;

        while(!feof(fp))
        {
                fgets(dst[i], 31, fp);
                if(strlen(dst[i]) >0)//if not judge this ,then when you execute it ,it will segment default!!!
                {
                        p = strstr(dst[i], "=");
                        p++;
                        while(*p != '\0')
                        {
                                mm[m] = *p;
                                m++; p++;       
                        }               
                        m=0;
                        printf("%s", mm);
                }
                memset(mm, 0, 32);
                i++;
        }
        fclose(fp);
}


