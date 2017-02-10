#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define inf 100
int d[5], p[5], f[5];
vector<char> s;
int extractMin()
{
    int m=inf, pos;
    for(int i=0;i<5;i++)
    {
        if(d[i]<m && f[i]==0)
        {
            m=d[i];
            pos=i;
        }
    }
    f[pos]=1;
    return pos;
}

void disktra(int g[5][5], int src)
{
    int u;
    for(int i=0;i<5;i++)
    {
        d[i]=inf;
        p[i]=-1;
        f[i]=0;
    }
    d[src]=0;

    for(int i=0;i<5;i++)
    {
        u=extractMin();
        for(int v=0;v<5;v++)
        {
            if(g[u][v]<inf && (d[v]>d[u]+g[u][v]) )
            {
                d[v]=d[u]+g[u][v];
                p[v]=u;
            }
        }
    }
}

void show(int a)
{
    static int b=0;

    if(p[a]==-1)
        return;
    show(p[a]);
    s.push_back(65+p[a]);
    if(b==1)
        printf("(%c,%c)", 65+p[a], 65+a);
    else
        printf("(%c,%c),", 65+p[a], 65+a);
    b++;
}

int main()
{
    int ara[5][5]={ {inf, 5, inf, 10, 8}, {inf, inf, 2, 1, inf}, {inf, inf, inf, 1, inf}, {inf, inf, inf, inf, 3}, {inf, inf, 4, inf, inf} };
    disktra(ara, 0);
    for(int i=0;i<5;i++)
        printf("%d\n", d[i]);
    char c;
    cout << "Enter a node: ";
    cin >> c;
    cout << "{";
    show(c-'A');
    cout << "}";

    return 0;
}
