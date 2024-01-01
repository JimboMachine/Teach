#include <iostream>
#include <vector>
using namespace std;

int main()
{    
    vector <int> A;
    int n,ans=0,max=0;
    cin >> n;
    for(int i=0;i<2*n;i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
        if(x>max)
            max = x;
    }
    vector <int> A1 (max, -1);
    for(int i=0;i<=2*n;i+=2)
    {
        for(int j=A[i];j<A[i+1];j++)
        {
            A1[j]=1;
        }
    }
    for(int i=0;i<=max;i++)
    {
        if(A1[i]==1)
        ans++;
    }
    cout << ans;
    return 0;
}