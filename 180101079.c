#include<stdio.h>
#include<stdlib.h>
void i(int a,char s[10])
        {
         int i;
         FILE *f;
         f=fopen( s,"w");
         for(i=0; i<a; i++)
            {
             fprintf(f,"%d\n",rand() % 1000001);
             }
         fclose(f);
         }
void f(int a,char s[10])
        {
         int i;
         FILE *f;
         f=fopen( s,"w");
         for(i=0; i<a; i++)
            {
             fprintf(f,"%.2f\n",(rand() % 1001)/100.00);
             }
         fclose(f);
         }
void s(int a,char s[10])
        {
         int i,j;
         FILE *f;
         f=fopen( s,"w");
         char k[10];
         for(i=0; i<a; i++)
            {
             for(j=0;j<10;j++)
                {
                 k[j]='a'+rand() % 26;
                 }
             fprintf(f,"%s\n",k);
             }
         fclose(f);
         }
int main(void)
       {
        i(10000,"i10k.txt");
        i(20000,"i20k.txt");
        i(40000,"i40k.txt");
        i(80000,"i80k.txt");
        i(160000,"i160k.txt");
        i(320000,"i320k.txt");
        i(640000,"i640k.txt");
        i(128000,"i1280k.txt");
        i(256000,"i2560k.txt");
        i(512000,"i5120k.txt");

        f(10000,"f10k.txt");
        f(20000,"f20k.txt");
        f(40000,"f40k.txt");
        f(80000,"f80k.txt");
        f(160000,"f160k.txt");
        f(320000,"f320k.txt");
        f(640000,"f640k.txt");
        f(128000,"f1280k.txt");
        f(256000,"f2560k.txt");
        f(512000,"f5120k.txt");

        s(10000,"s10k.txt");
        s(20000,"s20k.txt");
        s(40000,"s40k.txt");
        s(80000,"s80k.txt");
        s(160000,"s160k.txt");
        s(320000,"s320k.txt");
        s(640000,"s640k.txt");
        s(128000,"s1280k.txt");
        s(256000,"s2560k.txt");
        s(512000,"s5120k.txt");
        return 0;
        }
