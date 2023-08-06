#include<stdio.h>
int main(){
    int i,j,size,n,req[50],init,temp,point,total_disk;
    printf("Enter the total number of processes : ");
    scanf("%d",&n);
    printf("Enter the request sequence : ");
    for(i=0;i<n;i++){
        scanf("%d",&req[i]);
    }
    printf("Enter the disk size : ");
    scanf("%d",&size);
    size=size-1;
    printf("Eneter the head position : ");
    scanf("%d",&init);

    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(req[j] > req[j+1]){
                temp=req[j];
                req[j]=req[j+1];
                req[j+1]=temp;
            }
        }
    }
    point = init;
    for(i=0;i<n;i++){
        if(req[i] > point){
            point=req[i-1];
            break;
        }
    }
    total_disk=(size-init)+(point)+size;
    printf("Total number of disk movement = %d ", total_disk);

}
/*
Enter the total number of processes : 7
Enter the request sequence : 82 170 43 140 24 16 190
Enter the disk size : 200
Eneter the head position : 50
Total number of disk movement = 391
*/