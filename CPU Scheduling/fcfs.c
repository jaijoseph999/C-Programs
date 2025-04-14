#include<stdio.h>
struct process{
    int pid,at,bt,ct,tt,wt;
}p[100],temp;
int main(){
    int n;
    printf("Enter the number of process:");
    scanf("%d",&n);
    printf("Enter the arrival and burst time for each process:\n");
    for(int i=0;i<n;i++){
        p[i].pid=i;
        printf("process %d:",i+1);
        scanf("%d%d",&p[i].at,&p[i].bt);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].at>p[j+1].at){
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    p[0].ct=p[0].at+p[0].bt;
    p[0].tt=p[0].ct-p[0].at;
    p[0].wt=0;
    for(int i=1;i<n;i++){
        if(p[i].at<p[i-1].ct){
        p[i].ct=p[i-1].ct+p[i].bt;
        p[i].tt=p[i].ct-p[i].at;
        p[i].wt=p[i].tt-p[i].bt;}
        else{
            p[i].ct=p[i].at+p[i].bt;
            p[i].tt=p[i].ct-p[i].at;
            p[i].wt=0;
        }
    }
    printf("Gantt Chart\n");
    for(int i=0;i<=n;i++){
            printf("-------");
            if(p[i].ct<p[i+1].at)
             printf("-------");
    }
    printf("\n |");
    for(int i=0;i<n;i++){
        printf("  P%d  ",p[i].pid);
        printf(" |");
        if(p[i].ct<p[i+1].at){
        printf("      ");
            printf(" |");
        }
    }
    printf("\n");
    for(int i=0;i<=n;i++){
            printf("-------");
            if(p[i].ct<p[i+1].at)
            printf("-------");
    }
    printf("\n");
    printf("%2d",p[0].at);
    for(int i=0;i<n;i++){
        printf("      %2d",p[i].ct);
        if(p[i].ct<p[i+1].at){
            printf("      %2d",p[i+1].at);
        }
    }
    printf("\n TABLE \n");
    printf("_\n");
    printf("| pid | Arrivaltime | BurstTime | CompletionTime | TurnaroudTime | WaitTime |\n");
    printf("-----------------------------------------------------------------------------\n");
    for(int i=0;i<n;i++)
    printf("| %2d  |     %2d      |     %2d    |       %2d       |       %2d      |     %2d   |\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt);
    printf("-----------------------------------------------------------------------------\n");
    double tsum=0,wsum=0;
    for(int i=0;i<n;i++){
        tsum=tsum+p[i].tt;
        wsum=wsum+p[i].wt;
    }
    printf("Average Turnaround Time: %lf\n",tsum/n);
    printf("Average Waiting Time: %lf\n",wsum/n);
    printf(" ");
}
