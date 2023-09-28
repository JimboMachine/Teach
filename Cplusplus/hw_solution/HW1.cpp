#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    if (N <= 0) {
        cout << "ERROR" << endl;
        return 0;
    }

    double totalCredits = 0.0;
    double totalGradePoints = 0.0;

    for (int i = 0; i < N; i++) {
        int credits;
        double grade;
        cin >> credits >> grade;

        if (credits < 0 || credits != static_cast<int>(credits)) {
            cout << "ERROR" << endl;
            return 0;
        }
        else if(grade < 0 || grade > 100 || grade != static_cast<int>(grade)){
            cout << "ERROR" << endl;
            return 0;
        }
        totalCredits += credits;
        totalGradePoints += credits * grade;
        
    }
    if(totalCredits == 0){
        cout << "ERROR" << endl;
        return 0;
    }
    double GPA = (totalGradePoints / totalCredits) / 100 * 4.3;
    if(GPA == 0)
        cout << 0;
    else
        cout << fixed << setprecision(1) << round(GPA * 10) / 10 << endl;
    return 0;
}