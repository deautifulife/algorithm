#include <iostream>
#include <iomanip>  // 소수점 출력용
#include <map>
using namespace std;

int main() {
    string grade;
    cin >> grade;

    // 학점 문자열과 점수를 매핑
    map<string, double> scoreMap = {
        {"A+", 4.3}, {"A0", 4.0}, {"A-", 3.7},
        {"B+", 3.3}, {"B0", 3.0}, {"B-", 2.7},
        {"C+", 2.3}, {"C0", 2.0}, {"C-", 1.7},
        {"D+", 1.3}, {"D0", 1.0}, {"D-", 0.7},
        {"F", 0.0}
    };

    // 점수 출력 (소수점 1자리 고정)
    cout << fixed << setprecision(1) << scoreMap[grade] << endl;

    return 0;
}
