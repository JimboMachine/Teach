#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N,direction,number;
    cin >> N;
    if(N <3 || N %2==0)
        return 0;
    cin >> direction;
    if(direction > 4 || direction < 0)
        return 0;
    vector<vector<int>> arr;

    for(int i = 0; i < N ;i++){
        vector<int> tmp;
        for(int j = 0;j < N;j++){
            cin >> number;
            tmp.push_back(number);
        }
        arr.push_back(tmp);
    }
    // test vector
    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < N; j++){
    //         cout << arr[i][j];
    //     }
    //     cout << "\n";
    // }

    //run matrix
    int start = N/2, x= start ,y = start; // start  = N/2
    int step = 1,move = 0,turn = 0;
    while(step <= N){
        cout << arr[x][y];
        // cout << x << y << endl;
        // cout << move << turn << endl;
        if(turn > 0 && turn %2 == 0){
            step = step + turn/2;
            turn = 0;
        }
        if(direction == 0){
            if(y-1 < 0){
                direction = 1;
                move = 0;
                turn++;
                if(step == N)
                    break;
                continue;
            }
            y = y - 1;
        }
        else if(direction == 1){
            if(x-1 < 0){
                direction = 2;
                move = 0;
                turn++;
                if(step == N)
                    break;
                continue;
            }
            x = x - 1;
        }
        else if(direction == 2){
            if(y+1 >= N){
                direction = 3;
                move = 0;
                turn++;
                if(step == N)
                    break;
                continue;
            }
            y = y + 1;
        }
        else if(direction == 3){
            if(x+1 >= N){
                direction = 0;
                move = 0;
                turn++;
                if(step == N)
                    break;
                continue;
            }
            x = x + 1;
        }
        move++;

        if(move  == step){
            move = 0;
            turn++;
            direction = (direction+1)%4;
        }
    }
    return 0;
}