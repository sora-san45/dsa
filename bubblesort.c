//modified code to improve time complexity of best case O(n)

#include<stdio.h>
void bubblesort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int swapped=0;
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                swapped=1;

            }
        }
        if(swapped==0){
            break;
        }
    }
}
void main(){
    int n;
    printf("Enter number of elements in array");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements into array");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    bubblesort(a,n);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}