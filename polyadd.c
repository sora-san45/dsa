#include<stdio.h>

struct polynomial{
    int expo;
    int coef;
};

struct polynomial p1[10],p2[10],p3[10];
void readPoly(struct polynomial p[], int n){
    printf("\n Enter terms : \n");
    for(int i=0;i<n;i++){
        printf("\n Enter coefficent \n");
        scanf("%d",&p[i].coef);
        printf("\n Enter exponent \n");
        scanf("%d",&p[i].expo);
    }
}
void printPoly(struct polynomial p[], int n){
    for(int i=0;i<n-1;i++){
        printf("%dx^%d +",p[i].coef,p[i].expo);
    }
    printf("%dx^%d",p[n-1].coef,p[n-1].expo);
    printf("\n");

}
int addPoly(struct polynomial p1[],struct polynomial p2[],struct polynomial p3[], int n1 , int n2){
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(p1[i].expo==p2[j].expo){
            p3[k].expo=p1[i].expo;
            p3[k].coef=p1[i].coef+p2[j].coef;
            i++,j++,k++;
        }
        else if(p1[i].expo>p2[i].expo){
            p3[k].expo=p1[i].expo;
            p3[k].coef=p1[i].coef;
            i++,k++;
        }
        else{
            p3[k].expo=p2[i].expo;
            p3[k].coef=p2[i].coef;
            j++,k++;
        }
    }
    while(i<n1){
        p3[k].expo=p1[i].expo;
        p3[k].coef=p1[i].coef;
        i++,k++;
    }
    while(j<n2){
        p3[k].expo=p2[i].expo;
        p3[k].coef=p2[i].coef;
        j++,k++;
    }
    return k;
}
void main(){
    int n1;
    printf("Enter number of terms in p1\n");
    scanf("%d",&n1);
    readPoly(p1,n1);
    printPoly(p1,n1);
    int n2;
    printf("Enter number of terms in p2\n");
    scanf("%d",&n2);
    readPoly(p2,n2);
    printPoly(p2,n2);
    int n3=addPoly(p1,p2,p3,n1,n2);
    printPoly(p3,n3);
}