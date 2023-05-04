#include <stdio.h>
#include <stdlib.h>
struct fcfs
{
    int pid;
    int btime;
    int wtime;
    int ttime;
}
p[10];
int main()
{
    int i,n,pid;
    int totwtime=0,totttime=0;
    printf("\nfcfs scheduling...\n");
    printf("enter the no of process");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        p[i],pid=1;
        printf("\nburst time of process");
        scanf("%d",&p[i].btime);
    }
    p[0].wtime=0;
    p[0].ttime=p[0].btime;
    totttime+=p[i].ttime;
    for(i=0;i<n;i++)
    {
        p[i].wtime=p[i-1].wtime+p[i-1].btime;
        p[i].ttime=p[i].wtime+p[i].btime;
        totttime+=p[i].ttime;
        totwtime+=p[i].wtime;
    }
    printf("\n waiting time for processs");
    printf("\ntat time for process");
    printf("\n");
          
    printf("\ntwt=%d",totwtime);
    printf("\natwt=%f",(float)totwtime/n);
    printf("\ntat=%d",totttime);
    printf("\natat=%f",(float)totttime/n);
    return 0;
}
