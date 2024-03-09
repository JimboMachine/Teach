#include <iostream>
#include <vector>

using namespace std;

int main(){
    int x,y,a;
    cin >> x >> y;
    vector<vector<int>> tmp;
    for(int i=0;i<x;i++){
        vector<int> z;
        for(int j=0;j<y;j++){
            cin >> a;
            z.push_back(a); 
            /*{{3,1,2},
               {8,5,4}
            }
        */
        }
        tmp.push_back(z);
    }
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            cout << tmp[j][i];
            if(j!=x-1){
                cout << " ";
            }
        }   
        cout << endl;
    }
    return 0;
}