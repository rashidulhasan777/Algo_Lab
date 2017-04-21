#include<stdio.h>
#include<string.h>

int m[100][100];
int s[100][100];

void LCS(char *X, char *Y){
    int i, j;
    for(i = 0; i <= strlen(X); i++){
        m[i][0] = 0;
    }

    for(i = 0; i <= strlen(X); i++){
        m[0][i] = 0;
    }

    for(i = 1; i <= strlen(X); i++){
        for(j = 1; j <= strlen(Y); j++){
            if( X[i - 1] == Y[j - 1]){
                m[i][j] = m[i-1][j-1] + 1;
                s[i][j] = 3;
            }
            else{
                if(m[i-1][j] > m[i][j-1]){
                    m[i][j] = m[i-1][j];
                    s[i][j] = 1;
                }
                else{
                    m[i][j] = m[i][j-1];
                    s[i][j] = 2;
                }
            }
        }
    }
}

void FindSeleltedLetters(char *X, char *Y, int i, int j){
    if(i == 0 || j == 0)
        return;
    else{
        if(s[i][j] == 1){
            FindSeleltedLetters(X, Y, i - 1, j);
        }
        else if(s[i][j] == 2){
            FindSeleltedLetters(X, Y, i, j - 1);
        }
        else if(s[i][j] == 3){
            FindSeleltedLetters(X, Y, i - 1, j - 1);
            printf("%c", X[i-1]);
        }
    }
}


int main(){
    char str1[100], str2[100];
    gets(str1);
    //gets(&str[1])
    gets(str2);
    int i, j;

    LCS(str1, str2);

    printf("LCS Table is as follows: \n");
    for(i = 0; i <= strlen(str1); i++){
        for(j = 0; j <= strlen(str2); j++){
            printf("%5d\t", m[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\nFollowing is LCS string: ");
    FindSeleltedLetters(str1, str2, strlen(str1), strlen(str2));
    return 0;
}
