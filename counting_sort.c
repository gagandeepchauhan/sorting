#include <stdio.h>
void counting_sort(int[],int);
int n;
int main(){
    int i,a[20],k;
    printf("Enter the no. of elements :\n");
    scanf("%d",&n);
    printf("Enter %d elements\n",n);
    for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    printf("Enter largest element : ");
    scanf("%d",&k);
    counting_sort(a,k);
    
    return 0;
}
void counting_sort(int a[],int k){
    int c[k+1],b[n],i,j;
    for(i=0;i<=k;i++)
    c[i]=0;
    for(j=1;j<=n;j++)
    c[a[j]]=c[a[j]]+1;//filled indexes in c corresponds to the no. of times the indexed element occur in 'a'
    for(i=1;i<=k;i++)
    c[i]=c[i]+c[i-1];//from now any value at index 'x' in 'c' array denotes the no. of elements less than or equal to 'x'
    //above loop can run straight or backward , no matter .
    for(j=1;j<=n;j++){
        b[c[a[j]]]=a[j];
        c[a[j]]=c[a[j]]-1;
    }
    printf("Sorted array is : ");
    for(i=1;i<=n;i++)
    printf("%d ",b[i]);
}
