#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define INF 9999
int d[6], p[6];

bool bellmanFord(int mat[6][6], int src)
{
    int x[6];
    for(int i=0;i<6;i++)
    {
        d[i]=INF;
        p[i]=-1;
    }
    d[src]=0;
    for(int i=0;i<5;i++) //v-1=5
    {
        for(int j=0;j<6;j++)
                x[j]=d[j];

        for(int j=0;j<6;j++)
        {

            for(int k=0;k<6;k++)
            {
                if(mat[j][k]!=INF)
                {
                    if(d[j]+mat[j][k]<d[k])
                    {
                        x[k]=d[j]+mat[j][k];
                        p[k]=j;
                    }
                }
            }
        }
        for(int j=0;j<6;j++)
            d[j]=x[j];

    }
    for(int j=0;j<6;j++)
    {
        for(int k=0;k<6;k++)
        {
            if(mat[j][k]!=INF)
            {
                if(d[j]+mat[j][k]<d[k])
                {
                    return false;
                }
            }
        }
    }
    return true;
}
void path(int n)
{
    if(p[n]==-1)
        return;
    path(p[n]);
    printf("%c", 65+p[n]);
}
int main()
{
    int ara[6][6]={ {INF, 4, INF, INF, -5, 2},
                    {INF, INF, 3, INF, INF, INF},
                     {INF, INF, INF, INF, INF, -2},
                      {INF, INF, 9, INF, INF, INF},
                       {INF, INF, INF, 8, INF, INF},
                        {INF, INF, INF, 5, INF, INF} };
    if(bellmanFord(ara, 0))
    {
        for(int i=0;i<6;i++)
        {
            path(i);
            printf("%c Distance: ", 65+i);
            cout << d[i] << endl;

        }

    }
    else
        cout << "Cycle exist." << endl;
    return 0;
}
