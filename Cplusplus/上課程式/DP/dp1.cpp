#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> ansList;
    while (true) {
        int n;
        cin >> n;

        if (n == 0) {
            break;
        }

        vector<int> scores(n);

        // 讀入每條路徑的原始得分
        for (int i = 0; i < n; ++i) {
            cin >> scores[i];
        }

        // 計算最佳總得分
        int totalScore = 0;
        int rest = 0;  // 用於追蹤休息的狀態

        for (int i = 0; i < n; ++i) {
            // 計算按正常速度跑的得分
            int normalScore = totalScore + scores[i];
            // 計算加速跑的得分
            int doubleScore = (rest == 0) ? totalScore + scores[i] * 2 : 0;

            // 選擇最大得分，並更新休息狀態
            if (normalScore >= doubleScore) {
                totalScore = normalScore;
                rest = 0;
            } else {
                totalScore = doubleScore;
                rest = 1;
            }
        }
        ansList.push_back(totalScore);
    }
    for(auto it :ansList){
        std::cout << it << endl;
    }

    return 0;
}
