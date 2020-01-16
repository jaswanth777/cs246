#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int cmp(const void *vp, const void *vq);
void i(int k,char sin[10],char sout[20])
        {
        clock_t begin=clock();
         int i,a[k];
         FILE *f,*q;
         f=fopen(sin,"r");
         q=fopen(sout,"w");
         for(i=0;i<k;i++)
            {
            fscanf(f,"%d",a+i);
            }
         qsort(a,k, sizeof(int),cmp);
         for(i=0;i<k;i++)
            {
            fprintf(q,"%d\n",a[i]);
            }
         fclose(f);
         fclose(q);
        clock_t end=clock();
        double diff=(double)(end-begin)/CLOCKS_PER_SEC;
        printf("%f",diff);
         }  
int main(void)
        {
        i(10000,"i10k.txt","i10kout.txt");
        i(20000,"i20k.txt","i20kout.txt");
        i(40000,"i40k.txt","i40kout.txt");
        i(80000,"i80k.txt","i80kout.txt");
        i(160000,"i160k.txt","i160kout.txt");
        i(320000,"i320k.txt","i320kout.txt");
        i(640000,"i640k.txt","i640kout.txt");
        i(128000,"i1280k.txt","i1280kout.txt");
        i(256000,"i2560k.txt","i2560kout.txt");
        i(512000,"i5120k.txt","i5120kout.txt");
        return 0;
         }
int cmp(const void *vp, const void *vq)
{
const float *p=vp;
const float *q=vq;
float diff=*p-*q;
return ((diff>=0.0) ? ((diff>0.0) ? +1 : 0) : -1);
}
