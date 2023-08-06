#include<stdio.h>
int main(){
    int i,j,p,m,f=0;
    printf("Enter the total number of memory blocks : ");
    scanf("%d",&m);
    int memory[m];
    for(i=0;i<m;i++){
        printf("Enter size of memory block %d : ",(i+1));
        scanf("%d",&memory[i]);
    }
    printf("Enter the total number of processes blocks : ");
    scanf("%d",&p);
    int process[p];
    for(i=0;i<p;i++){
        printf("Enter size of process block %d : ",(i+1));
        scanf("%d",&process[i]);
    }
    printf("==============================================================================\n");
    printf("                  best_fit                                 \n");
    printf("==============================================================================\n");
    printf("process no:\tprocess size\tblock no\tblock size\tfragments\n");
    printf("==============================================================================\n");

    for(i=0;i<p;i++){
        for(j=0;j<m;j++){
            if(memory[j] >= process[i]){
                printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",(i+1),process[i],(j+1),memory[j],(memory[j]-process[i]));
                memory[j]=memory[j]-process[i];
                f=1;
                break;
            }
        }
        if(f==0){
            printf("%d\t\t%d\t\tun-allocated\n",(i+1),process[i]);
        }
    }
    printf("==============================================================================\n");
}
/*
Enter the total number of memory blocks : 5
Enter size of memory block 1 : 161
Enter size of memory block 2 : 175
Enter size of memory block 3 : 500
Enter size of memory block 4 : 320
Enter size of memory block 5 : 400
Enter the total number of processes blocks : 4
Enter size of process block 1 : 75
Enter size of process block 2 : 140
Enter size of process block 3 : 200
Enter size of process block 4 : 301
==============================================================================
                  best_fit                                 
==============================================================================
process no:     process size    block no        block size      fragments
==============================================================================
1               75              1               161             86
2               140             2               175             35
3               200             3               500             300
4               301             4               320             19
==============================================================================
*/