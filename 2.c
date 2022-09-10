#include<stdio.h>
#include<stdlib.h>

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

typedef struct{
    int value;
    int row, col;
} data;

int cmp(const void *a, const void *b){
    data *dataA = (data *)a;
    data *dataB = (data *)b;
    return dataA->value - dataB->value;
}

int main(){
    int n;
    scanf("%d",&n);
    data arr_data[100];
    for(int i=0;i<10;++i){
        for(int j=0;j<10;++j){
            int tmp = i*10+j;
            arr_data[tmp].value = arr[i][j];
            arr_data[tmp].row = i;
            arr_data[tmp].col = j;
        }
    }
    qsort(arr_data, 100, sizeof(data), cmp);
    int lidx = 0, ridx = 99;
    while(lidx < ridx){
        int sum = arr_data[lidx].value + arr_data[ridx].value;
        if(sum < n){
            ++lidx;
        }
        else if(sum > n){
            --ridx;
        }
        else{
            int lvalue = arr_data[lidx].value;
            int rvalue = arr_data[ridx].value;
            int rtmp = ridx;
            do{
                ridx = rtmp;
                do{
                    printf("(%d, %d) (%d, %d)\n",arr_data[lidx].row,arr_data[lidx].col,arr_data[ridx].row,arr_data[ridx].col);
                    --ridx;
                }while(rvalue == arr_data[ridx].value);
                ++lidx;
            }while(lvalue == arr_data[lidx].value);
        }
    }
}