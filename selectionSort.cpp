#include <iostream>
using namespace std;

int main()
{
    int n, maximum, temp, index;
    cin >> n;
    int ara[n];
    for(int i=0;i<n;i++)
        cin >> ara[i];
    for(int i=0;i<n;i++)
    {
        index=0;
        for(int j=1;j<n-i;j++)
        {
            if(ara[index]<ara[j])
            {
                index=j;
            }
        }
        if(index!=0)
        {
            temp=ara[n-i-1];
            ara[n-i-1]=ara[index];
            ara[index]=temp;
        }
    }
    for(int i=0;i<n;i++)
        cout << ara[i] << "\t";
    return 0;
}
