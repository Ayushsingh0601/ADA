//Implement the program for linear search and perform it's analysis

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count,n=10;
void linearsearch(int key,int *a){
    count=0;
    int i;
    for(i=0;i<n;i++)
    {
        count++;
        if(a[i]==key)
        {
            printf("Key found at position %d",(i+1));
            return;
        }
    }
}

void main()
{
    int *a;
    FILE *fp1,*fp2,*fp3;
    system("rm best.txt avg.txt worst.txt");
    fp1=fopen("best.txt","a");
    fp2=fopen("avg.txt","a");
    fp3=fopen("worst.txt","a");
    srand(time(0));
    int i,key;
    for(n=10;n<100;n=n+10){
        a=(int *)malloc(n*sizeof(int));
        i=0;
        while(i!=n)
        {
            a[i]=rand()%100;
            printf("%d",a[i]);
            i++;
        }

        //Best case analysis 
        key=a[0];
        linearsearch(key,a);
        fprintf(fp1,"%d\t%d\n",count);


         //Average case analysis 
        key=7777;
        linearsearch(key,a);
        fprintf(fp2,"%d\t%d\n",count);
        

         //Worst case analysis 
        key=a[n/2];
        linearsearch(key,a);
        fprintf(fp3,"%d\t%d\n",count);
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

}
