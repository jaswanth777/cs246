#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
struct course{
              int sem;
              char *cnum;
              char *cname;
              int cdt;
              };
struct student{
               char *roll;
	       char *namofstd;
	       char grade[63][2];
               };
void gene(struct student s , struct course a[63])
{
int f;
char *l;
strcpy(l,s.roll);
strcat(l,".txt");
f=create(l, O_WRONLY | O_CREAT );
close(f);
f=open(l, O_WRONLY | O_CREAT );
write(f,s.namofstd,sizeof(s.namofstd));
close(f);
}
int main(void)
	{
	 int f1,f2,f3;
	 char *buffer = calloc(4096, sizeof(char));
	 f1 = open("students02.csv", O_RDONLY);
	 struct student std[158];
	 int current=0;
	 read(f1,buffer,4096);
	 char *name;
	 char *rollno;
	 name=strtok(buffer,",");
	 rollno=strtok(NULL,"\n");
	 current=current+2+strlen(name)+strlen(rollno);
	 printf("%s %s\n",name,rollno);
	 std[0].roll=rollno;
	 std[0].namofstd=name;
	 int j=0;
	 while(current<4055)
	       {j=j+1;
		name=strtok(NULL,",");
	 	rollno=strtok(NULL,"\n");
	 	std[j].roll=rollno;
		std[j].namofstd=name;
	 	current=current+2+strlen(name)+strlen(rollno);
		printf("%s %s\n",name,rollno);
                }
	 lseek(f1,current,SEEK_SET);
	 printf("%d",1);
	 int a=4202-current;
	 read(f1,buffer,a);
	 name=strtok(buffer,",");
	 rollno=strtok(NULL,"\n");
	 j=j+1;
	 std[j].roll=rollno;
	 std[j].namofstd=name;
	 current=current+2+strlen(name)+strlen(rollno);
	 printf("%s %s\n",name,rollno);
	while(current<4202)
	    {j=j+1;
	     name=strtok(NULL,",");
	     rollno=strtok(NULL,"\n");
	     std[j].roll=rollno;
	     std[j].namofstd=name;
	     current=current+2+strlen(name)+strlen(rollno);
	     printf("%s %s\n",name,rollno);
	     }
	 close(f1);
	 free(buffer);
	 printf("%d",2);
	 char *buffer2 = calloc(4096, sizeof(char));
	 f2 = open("courses02.csv", O_RDONLY);
	 struct course cou[63];
	 read(f2,buffer2,2333);
	 char *s;
	 char *c1;
	 char *c2;
	 char *c3;
	 int c=0;
	 s=strtok(buffer2,",");
	 cou[0].sem=atoi(s);
	 c1=strtok(NULL,",");
	 cou[0].cnum=c1;
	 c2=strtok(NULL,",");
	 cou[0].cname=c2;
	 c3=strtok(NULL,",");
	 c3=strtok(NULL,",");
	 c3=strtok(NULL,",");
	 c3=strtok(NULL,"\n");
	 cou[0].cdt=atoi(c3);
	 c=c+7+strlen(s)+strlen(c1)+strlen(c2)+strlen(c2)+3;
	 printf("%s %s %s %s\n",s,c1,c2,c3);
	 int i=0;
	 while(c<2333)
	       {
		i=i+1;
		s=strtok(NULL,",");
		cou[i].sem=atoi(s);
	 	c1=strtok(NULL,",");
		cou[i].cnum=c1;
	 	c2=strtok(NULL,",");
		cou[i].cname=c2;
	 	c3=strtok(NULL,",");
	 	c3=strtok(NULL,",");
	 	c3=strtok(NULL,",");
	 	c3=strtok(NULL,"\n");
		cou[i].cdt=atoi(c3);
	 	c=c+7+strlen(s)+strlen(c1)+strlen(c2)+strlen(c3)+3;
	 	printf("%s %s %s %s\n",s,c1,c2,c3);
                }
	 close(f2);
	 free(buffer2);
	 printf("%d",1);
	 //printf("%d",cou[62].sem);
	 char *buffer3 = calloc(20, sizeof(char));
	 f3 = open("grades02.csv",O_RDONLY);
	 read(f3,buffer3,20);
	 char *roll1;
	 char *cnum1;
	 char *g;
	 roll1=strtok(buffer3,",");
	 cnum1=strtok(NULL,",");
	 g=strtok(NULL,"\n");
	 printf("%s %s %s\n",roll1,cnum1,g);
	 int h=1;
	 while(read(f3,buffer3,20))
	       {h=h+1;
		roll1=strtok(buffer3,",");
		int p,k;
		for(k=0;k<158;k++)
			{
			 if(strcmp(std[k].roll,roll1))
                           break;
			 }
	 	cnum1=strtok(NULL,",");
	 	g=strtok(NULL,"\n");
		for(int p=0;p<63;p++)
			{
			 if(strcmp(cou[p].cnum,cnum1))
                           break;
			 }
		std[k].grade[p][0]=g[0];
		std[k].grade[p][1]=g[1];
	 	printf("%s %s %s\n",roll1,cnum1,g);
                }
	 close(f3);
	 free(buffer3);
	 printf("%d",h);
	 return 0;
		 for(int b=0;b<158;b++)
{
gene(std[b],cou);
}
	 }
