#include<stdio.h>

struct Term{
    float coeff;
    int exp;
};

struct Poly{
    int n;
    struct Term *t;
};

struct Poly p;

void main(){
    printf("Enter number of terms");
    scanf("%d",&p.n);

    for(int i =0;i<p.n;i++){
        printf("Enter coefficient and exponent");
        scanf("%f",&(p.t[i].coeff));
        scanf("%d",&(p.t[i].exp));
    }

    for(int i=0;i<p.n;i++){
        printf("%fx^%d",p.t[i].coeff,p.t[i].exp);
    }
}