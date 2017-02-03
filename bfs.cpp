#include<iostream>
#include<queue>
using namespace std;
int d[5], c[5], p[5];
void bfs(int graph[5][5], int source)
{
    int u;
    queue<int> myqueue;
    for(int i=0;i<5;i++)
    {
        c[i]=0;
        p[i]=-1;
        d[i]=10000;
    }
    myqueue.push(source);
    c[source]=1;
    d[source]=0;
    while(!myqueue.empty())
    {
        u=myqueue.front();
        for(int i=0;i<5;i++)
        {
            if(graph[u][i]==1 && c[i]==0)
            {
                myqueue.push(i);
                d[i]=d[u]+1;
                c[i]=1;
                p[i]=u;
            }
        }
        c[u]=2;
        myqueue.pop();
    }
}

int main()
{
    int mat[5][5]={ {0,1,1,0,1},{1,0,0,0,1}, {1,0,0,1,0}, {0,0,1,0,1}, {1,1,0,1,0} };
    bfs(mat, 0);
    for(int i=0;i<5;i++)
        cout << d[i] << "\t";
    return 0;
}
