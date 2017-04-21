#include<stdio.h>
#include<string.h>

int m[100][100];
int s[100][100];

void MatrixChain(int *p, int n){
    int i, j, k, l, q;
    for(i = 1; i <= n; i++){
        m[i][i] = 0;
        s[i][i] = -1;
    }

    for(l = 2; l <= n; l++){
        for(i = 1; i <= n - l + 1; i++){
            j = i + l - 1;
            m[i][j] = 99999;
            for(k = i; k < j; k++){
                q = m[i][k] + m[k+1][j] + p[i-1]*p[j]*p[k];
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

}

void FindOptimalResult(int i, int j){
    if(s[i][j] == -1){
        printf("A%d", i);
        return;
    }
    else{
        printf("(");
        FindOptimalResult(i, s[i][j]);
        FindOptimalResult(s[i][j] + 1, j);
        printf(")");
    }
}


int main(){
    int dimension[] = {10, 25, 5, 12, 15, 10, 20};
    int i, j, n = 6;

    MatrixChain(dimension, n);

    printf("Matrix Chain Table is as follows: \n");
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            if(i <= j)
                printf("%5d\t", m[i][j]);
            else
                printf("\t");
        }
        printf("\n");
    }

    printf("\n\n\nFollowing is Optimal Matrix operation order: ");
    FindOptimalResult(1, n);
    return 0;
}
