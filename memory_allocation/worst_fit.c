#include<stdio.h>
int main(){
    int i,j,m,p,w=-1;
    printf("Enter the number of memory blocks : ");
    scanf("%d",&m);
    int memory[m];
    for(i=0;i<m;i++){
        printf("Enter the size of memory block %d : ",(i+1));
        scanf("%d",&memory[i]);
    }
    printf("Enter the number of process blocks : ");
    scanf("%d",&p);
    int process[p];
    for(i=0;i<p;i++){
        printf("Enter the size of process block %d : ",(i+1));
        scanf("%d",&process[i]);
    }
    printf("==============================================================================\n");
    printf("                  best_fit                                 \n");
    printf("==============================================================================\n");
    printf("process no:\tprocess size\tblock no\tblock size\tfragments\n");
    printf("==============================================================================\n");

    for(i=0;i<p;i++){
        w=-1;
        for(j=0;j<m;j++){
            if(memory[j] >= process[i]){
                if(w==-1){
                    w=j;
                }
                else if(memory[w] < memory[j]){
                    w=j;
                }

            }
        }
        if(w != -1){
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",(i+1),process[i],(w+1),memory[w],(memory[w]-process[i]));
            memory[w]=memory[w]-process[i];
        }
        else{
            printf("%d\t\t%d\t\tun-allocated\n",(i+1),process[i]);
        }
    }
    printf("==============================================================================\n");

}
/*
Enter the number of memory blocks : 5
Enter the size of memory block 1 : 161
Enter the size of memory block 2 : 175
Enter the size of memory block 3 : 500
Enter the size of memory block 4 : 320
Enter the size of memory block 5 : 400
Enter the number of process blocks : 4
Enter the size of process block 1 : 75
Enter the size of process block 2 : 140
Enter the size of process block 3 : 200
Enter the size of process block 4 : 301
==============================================================================
                  best_fit                                 
==============================================================================
process no:     process size    block no        block size      fragments
==============================================================================
1               75              3               500             425
2               140             3               425             285
3               200             5               400             200
4               301             4               320             19
============================================================================== 
*/