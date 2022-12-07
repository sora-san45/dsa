#include<stdio.h>
void read_norm(int mat[][100],int a, int b){
    printf("Enter a sparse matrix:");
    for(int i =0;i<a;i++){
        for(int j =0;j<b;j++){
            scanf("%d",&mat[i][j]);
        }
    }
}

void print_norm(int mat[][100],int a, int b){
    for(int i =0;i<a;i++){
        for(int j =0;j<b;j++){
            scanf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

int* coordinate_list(int mat[][100],int a, int b){
    //number of columns is equal to number of non zero elements
    int col =0;
    for(int i =0;i<a;i++){
        for(int j =0;j<b;j++){
            if(mat[i][j]!=0){
                col++;
            }
        }
    }
    //creation of coordinate list
    int m =0;
    int cmat[3][col];
    for(int i =0;i<a;i++){
        for(int j =0;j<b;j++){
            if (mat[i][j]!=0){
                cmat[0][m]=i;
                cmat[1][m]=j;
                cmat[2][m]=mat[i][j];
            }
        }
    }
    return cmat;
}

void addn(int mat1[][100], int mat2[][100],int a,int b,int c,int d){
    int cmat1=*(coordinate_list(mat1,a,b));
    int cmat2=*(coordinate_list(mat2,c,d))
}
void trans(int mat[][100], int a,int b){}
void main(){
    printf("Enter number of rows and columns for matrix1");
    int r1,c1;
    scanf("%d%d",&r1,&c1);
    int mat1[r1][c1];
    read_norm(mat1,r1,c1);
    print_norm(mat1,r1,c1);
    printf("Enter number of rows and columns for matrix2");
    int r2,c2;
    scanf("%d%d",&r2,&c2);
    int mat2[r2][c2];
    read_norm(mat2,r2,c2);
    print_norm(mat2,r2,c2);

    if(r1==r2 && c1==c2){
        addn(mat1,mat2,r1,c1,r2,c2);
    }

}