#include<iostream>
#include<vector>
using namespace std;

long long F[1000005]; //用來存算完的結果

long long f(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    
    //發現f(n)已經計算過了
    if(F[n]!=-1) return F[n]; //可以直接從陣列裡拿值出來用
        
    //f(n)還沒被計算過，那就算一下吧
    F[n]=f(n-1)+f(n-2); //算完先存起來
    return F[n];
}

int main()
{
    for(int i=0;i<1000000;i++)
        F[i]=-1; //先把F[i]通通改成-1，代表還沒算過f(i)
    
    int n;
    cin>>n;
    cout<<f(n)<<endl;
}