//From Graph algorithm by Shafayet
#include<bits/stdc++.h>
using namespace std;
bool ara[10][10]= { {0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
                    {0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
                    {0, 0, 1, 1, 0, 0, 0, 1, 1, 0},
                    {0, 0, 1, 0, 1, 0, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
                    {0, 0, 0, 0, 1, 1, 0, 0, 1, 0} };
int lavel[10], parent[10], color[10];
void bfs(int source)
{
    queue<int> Q;
    memset(lavel, -1, sizeof(lavel));
    memset(parent, -1, sizeof(parent));
    memset(color, -1, sizeof(color));
    Q.push(source);
    lavel[source]=0;
    color[source]=0;
    while(!Q.empty())
    {
        int u=Q.front();
        for(int i=0;i<10;i++)
        {
            if(ara[u][i] && color[i]==-1)
            {
                Q.push(i);
                lavel[i]=lavel[u]+1;
                parent[i]=u;
                color[i]=0;


            }
        }
        color[u]=1;
        Q.pop();
    }
    for(int i=0;i<10;i++)
        cout << lavel[i]<< "\t";
    cout << endl;
    for(int i=0;i<10;i++)
        cout << parent[i] << "\t";
    cout << endl;

}
int main()
{
    bfs(0);
    return 0;
}
