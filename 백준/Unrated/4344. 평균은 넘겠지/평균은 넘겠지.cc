#include <iostream>
#include<algorithm> //reverse 쓰기위함

using namespace std;

int main() {
    int testcase;
    cin >> testcase;
    float avg[testcase][1002];
    for(int i=0;i<testcase; i++) {
        for(int j=0; j<1002; j++)
            avg[i][j] = 0;
    }
    
    //데이터 입력 및 계산
    for(int i=0; i<testcase; i++) {
        int numstudent;
        cin>>numstudent;
        for(int j=0; j<numstudent; j++) {
            cin>>avg[i][j];
            avg[i][1000] = avg[i][1000] + avg[i][j];
        }
        avg[i][1000] = avg[i][1000] / (float)numstudent; //각 배열 1000에 평균값 저장

        //평균 넘는 학생들 비율 계산
        for(int j=0; j<numstudent; j++) {
            if(avg[i][j]>avg[i][1000])
                avg[i][1001]++;
        }    
        avg[i][1001] = avg[i][1001]/numstudent;
    }

    //소수점 표현
    cout<<fixed;
    cout.precision(3);

    
    for(int i=0; i<testcase; i++) {
        cout<<avg[i][1001]*100<<"%"<<endl;
    }
    return 0;
}