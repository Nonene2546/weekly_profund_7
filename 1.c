#include<stdio.h>

int arr[10][10] = {
    {95,68,95,42,65,31,42,51,42,68},
    {59,74,21,35,62,14,21,35,26,28},
    {29,24,16,25,42,36,25,16,24,25},
    {32,12,36,24,15,32,16,95,75,85},
    {62,43,19,86,24,37,19,65,53,28},
    {64,29,21,53,24,16,58,75,14,25},
    {35,62,95,86,47,85,78,14,63,29},
    {86,47,68,32,12,36,69,86,74,48},
    {46,26,53,69,78,46,14,21,34,26},
    {38,69,47,28,34,16,24,28,59,68}
};

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<100;++i){
        for(int j=i+1;j<100;++j){
            if(arr[i/10][i%10]+arr[j/10][j%10]==n)
                printf("(%d, %d) (%d, %d)\n",i/10,i%10,j/10,j%10);
        }
    }
}