#include<iostream>

using namespace std;

int knapsack(int val[], int amt[], int n, int bagSize)
{
    int sum=0;
    int tempValue[n];
    for(int i=0;i<n;i++)
        tempValue[i]=val[i];
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(val[j]<val[j+1])
                swap(val[j], val[j+1]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(val[i]==tempValue[j])
            {
                swap(amt[i], amt[j]);
                //cout << val[i] << "\t" << amt[i] << endl;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        if(amt[i]>=bagSize)
        {
            sum+=bagSize*val[i];
            bagSize=0;
            break;
        }
        else
        {
            sum+=amt[i]*val[i];
            bagSize-=amt[i];
        }
        //cout << "Sum " << sum << endl;
    }
    return sum;
}

int main()
{
    int n, bagSize;
    cin >> n;
    cin >> bagSize;
    int value[n], amount[n];
    for(int i=0;i<n;i++)
    {
        cin >> value[i] >> amount[i];
    }
    cout << "Maximum amount : " << knapsack(value, amount, n, bagSize) << endl;

    return 0;
}
