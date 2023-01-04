#include<stdio.h>
void selectionsort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int min_pos=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min_pos]){
                min_pos=j;
            }
        }
        int temp=a[i];
        a[i]=a[min_pos];
        a[min_pos]=temp;
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
    selectionsort(a,n);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}