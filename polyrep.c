#include<stdio.h>

struct Term{
    float coeff;
    int exp;
};

struct Poly{
    int n;
    struct Term *t;
};

struct Poly p1,p2;

void main(){
    printf("Enter number of terms : ");
    scanf("%d",&p1.n);

    for(int i =0;i<p1.n;i++){
        printf("Enter coefficient and exponent");
        scanf("%f",&(p1.t[i].coeff));
        scanf("%d",&(p1.t[i].exp));
    }

    for(int i=0;i<p1.n;i++){
        printf("%fx^%d",p1.t[i].coeff,p1.t[i].exp);
    }

    printf("Enter number of terms :");
    scanf("%d",&p2.n);

    for(int i =0;i<p2.n;i++){
        printf("Enter coefficient and exponent");
        scanf("%f",&(p2.t[i].coeff));
        scanf("%d",&(p2.t[i].exp));
    }

    for(int i=0;i<p2.n;i++){
        printf("%fx^%d",p2.t[i].coeff,p2.t[i].exp);
    }
}