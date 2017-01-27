#include <iostream>
using namespace std;

int main()
{
    int n, flag;
    cin >> n;
    int ara[n];
    for(int i=0;i<n;i++)
        cin >> ara[i];
    for(int i=0;i<n;i++)
    {
        flag=0;
        for(int j=0;j<n-i-1;j++)
        {
            if(ara[j]>ara[j+1])
            {
                swap(ara[j], ara[j+1]);
                flag++;
            }
        }
        if(flag==0)
            break;
    }
    for(int i=0;i<n;i++)
        cout << ara[i] << "\t";
    return 0;
}
