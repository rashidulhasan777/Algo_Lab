#include<iostream>
using namespace std;

int main()
{
    int coins[9]={1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int exchangeAmount, total=0, n;
    cin >> exchangeAmount;
    for(int i=0;i<9;i++)
    {
       // while(exchangeAmount!=0)
        //{
            if(coins[i]<=exchangeAmount)
            {
                n=(int)exchangeAmount/coins[i];
                exchangeAmount-=(n*coins[i]);
                total+=n;
                cout << coins[i] << " Taka " << n << " notes." << endl;
            }
            if(exchangeAmount==0)
                break;
        //}
    }
    cout << total;
    return 0;
}
