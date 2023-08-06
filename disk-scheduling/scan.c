#include<stdio.h>
int main(){
    int i,j,n,size,req[20],init,dir,temp,total_disk;
    printf("Enter the number of processes : ");
    scanf("%d",&n);
    printf("Enter the request sequences : ");
    for(i=0;i<n;i++){
        scanf("%d",&req[i]);
    }
    printf("Enter the disk size : ");
    scanf("%d",&size);
    size=size-1;
    printf("Enter the head position : ");
    scanf("%d",&init);
    printf("Enter the direction:(0:Left to Right\t1:Right to Left) of the head : ");
    scanf("%d",&dir);

    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(req[j] > req[j+1]){
                temp=req[j];
                req[j]=req[j+1];
                req[j+1]=temp;
            }
        }
    }
    if(!dir){
        total_disk=(size-init)+(size-req[0]);
    }
    else{
        total_disk=(init+req[n-1]);
    }
    printf("Total disk movement = %d ",total_disk);

}

/*
Enter the number of processes : 7
Enter the request sequences : 82 170 43 140 24 16 190
Enter the disk size : 200
Enter the head position : 50
Enter the direction:(0:Left to Right    1:Right to Left) of the head : 0
Total disk movement = 332 
*/