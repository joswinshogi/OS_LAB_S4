#include<stdio.h>
int main(){
    int i,j,m,p,b=-1;
    printf("Enter the total number of memory blocks : ");
    scanf("%d",&m);
    int memory[m];
    for(i=0;i<m;i++){
        printf("Enter the size of memory block %d : ",(i+1));
        scanf("%d",&memory[i]);
    }
    printf("Enter the total number of processes : ");
    scanf("%d",&p);
    int process[p];
    for(i=0;i<p;i++){
        printf("Enter the size of process %d : ",(i+1));
        scanf("%d",&process[i]);
    }
    printf("==============================================================================\n");
    printf("                  best_fit                                 \n");
    printf("==============================================================================\n");
    printf("process no:\tprocess size\tblock no\tblock size\tfragments\n");
    printf("==============================================================================\n");

    for(i=0;i<p;i++){
        b=-1;
        for(j=0;j<m;j++){
            if(memory[j] >= process[i]){
                if(b==-1){
                    b=j;
                }
                else if(memory[b] > memory[j]){
                    b=j;

                }
            }
        }
        if(b!=-1){
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",(i+1),process[i],(b+1),memory[b],(memory[b]-process[i]));
            memory[b]=memory[b]-process[i];
        }
        else{
            printf("%d\t\t%d\t\tun-allocated\n",(i+1),process[i]);
        }

    }
    printf("==============================================================================\n");
}
/*
Enter the total number of memory blocks : 5
Enter the size of memory block 1 : 161
Enter the size of memory block 2 : 175
Enter the size of memory block 3 : 500
Enter the size of memory block 4 : 320
Enter the size of memory block 5 : 400
Enter the total number of processes : 4
Enter the size of process 1 : 75
Enter the size of process 2 : 140
Enter the size of process 3 : 200
Enter the size of process 4 : 301
==============================================================================
                  best_fit                                 
==============================================================================
process no:     process size    block no        block size      fragments
==============================================================================
1               75              1               161             86
2               140             2               175             35
3               200             4               320             120
4               301             5               400             99
==============================================================================
*/