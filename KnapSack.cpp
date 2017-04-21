#include<stdio.h>
int m[100][100];
int s[100][100];

void KnapSack(int *value, int *weight, int n, int K){
    int i, j;
    for(i = 0; i <= n; i++){
        m[i][0] = 0;
    }

    for(i = 0; i <= K; i++){
        m[0][i] = 0;
    }

    for(i = 1; i <= n; i++){
        for(j = 1; j <= K; j++){
            if( (j - weight[i]) >= 0){
                if(m[i-1][j] > m[i-1][j - weight[i]] + value[i]){
                    m[i][j] = m[i-1][j];
                    s[i][j] = 0;
                }
                else{
                    m[i][j] = m[i-1][j - weight[i]] + value[i];
                    s[i][j] = 1;
                }

            }
            else{
                m[i][j] = m[i-1][j];
                s[i][j] = 0;
            }
        }
    }
}

void FindSeleltedItems(int *wgt, int i, int j){
    if(i == 0)
        return;
    else{
        if(s[i][j] == 0){
            FindSeleltedItems(wgt, i - 1, j);
        }
        else{
            FindSeleltedItems(wgt, i - 1, j - wgt[i]);
            printf("Item No: %d\n", i);
        }
    }
}


int main(){
    int value[10] = {0, 100, 50, 30, 50, 90};
    int weight [10] = {0, 5, 2, 4, 3, 4};
    int i, j;

    int itemNo = 5;
    int KW = 10;

    KnapSack(value, weight, itemNo, KW);

    printf("Knapsack Table is as follows: \n");
    for(i = 0; i <= itemNo; i++){
        for(j = 0; j <= KW; j++){
            printf("%5d\t", m[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\nFollowing Numbered Items are Selected\n");
    FindSeleltedItems(weight, itemNo, KW);
    return 0;
}
