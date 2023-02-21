#include<stdio.h>
#define size 6
int table[size];

void add(int d){
    int pos=d%size;
    if(table[pos]==0){
        table[pos]=d;
    }
    else{
        int count=1;
        int j=(pos+1)%size;
        while(count<=size){
            if(table[j]==0){
                table[j]=d;
                break;
            }
            j=(j+1)%size;
            count++;
        }
        if(count>size){
            printf("\nTable full\n");
        }
    }
}
void print(){
    for(int i=0;i<size;i++){
        printf("%d ",table[i]);
    }
}
void main(){
     //initialize all locations with 0
    for(int i=0;i<size;i++){
        table[i]=0;
    }
    int i,num,val;
    printf("Enter the number of elements\n");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
    printf("Enter Elements\n");
    scanf("%d",&val);
    add(val);
    }
    printf("\n The hash table is\n");
    print();

}