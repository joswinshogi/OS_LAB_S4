#include<stdio.h>
#include<stdlib.h>

int main(){
    int i,j,n,req[30],size,init,total_disk=0;
    printf("Enter the number of processes : \n");
    scanf("%d",&n);
    printf("Enter the request sequence : \n");
    for(i=0;i<n;i++){
        scanf("%d",&req[i]);
    }

    printf("Enter the disk size : \n");
    scanf("%d",&size);
    size=size-1;
    printf("Enter the initial head position : \n");
    scanf("%d",&init);

    for(i=0;i<n;i++){
        total_disk=total_disk+abs(req[i]-init);
        init=req[i];
    }

    printf("Total disk movement = %d ", total_disk);


}
/*
Enter the number of processes : 
8
Enter the request sequence : 
98 183 37 122 14 124 65 67
Enter the disk size : 
200
Enter the initial head position : 
53
Total disk movement = 640
*/