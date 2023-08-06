#include<stdio.h>

typedef struct{
    int ArrT;
    int ComT;
    int BurT;
    int Tat;
    int Wt;
}process;
process pr[50],temp;

int main(){
    int i,j,n,com=0;
    float ATAT,AWT,Ttat=0,Twt=0;
    printf("Enter the number of process : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the arrival time of P%d : ",i);
        scanf("%d",&pr[i].ArrT);
        printf("Enter the burst time of P%d : ",i);
        scanf("%d",&pr[i].BurT);
    }

    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(pr[j].ArrT > pr[j+1].ArrT){
                temp=pr[j];
                pr[j]=pr[j+1];
                pr[j+1]=temp;

            }
        }
    }
    for(i=0;i<n;i++){
        if(com < pr[i].ArrT){
            com=pr[i].ArrT;
        }
        pr[i].ComT=pr[i].BurT+com;
        pr[i].Tat=pr[i].ComT-pr[i].ArrT;
        pr[i].Wt=pr[i].Tat-pr[i].BurT;
        com=pr[i].ComT;
    }

    printf("\nprocess\tarr\ttat\twt\n");
    for(i=0;i<n;i++){
        printf("\nP%d\t%d\t%d\t%d\n",i,pr[i].ArrT,pr[i].Tat,pr[i].Wt);
        Ttat=Ttat+pr[i].Tat;
        Twt=Twt+pr[i].Wt;
    }
    ATAT=Ttat/n;
    AWT=Twt/n;
    printf("Average Turn Around Time = %f ",ATAT);
    printf("\nAverage Waiting Time = %f ",AWT);
}

/*
Enter the number of process : 4
Enter the arrival time of P0 : 0
Enter the burst time of P0 : 2
Enter the arrival time of P1 : 1
Enter the burst time of P1 : 6
Enter the arrival time of P2 : 2
Enter the burst time of P2 : 4
Enter the arrival time of P3 : 3
Enter the burst time of P3 : 9

process arr     tat     wt

P0      0       2       0

P1      1       7       1

P2      2       10      6

P3      3       18      9
Average Turn Around Time = 9.250000 
Average Waiting Time = 4.000000   
*/