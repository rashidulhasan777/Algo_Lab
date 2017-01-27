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
        maximum=ara[0];
        index=0;
        for(int j=1;j<n-i;j++)
        {
            if(maximum<ara[j])
            {
                maximum=ara[j];
                index=j;
            }
        }
        temp=ara[n-i-1];
        ara[n-i-1]=ara[index];
        ara[index]=temp;
    }
    for(int i=0;i<n;i++)
        cout << ara[i] << "\t";
    return 0;
}
