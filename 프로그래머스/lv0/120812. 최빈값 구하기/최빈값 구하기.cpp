#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int solution(vector<int> array) {
    int answer = -1;
    int max = -1;
    
    //값의 카운트를 셀 벡터의 최댓값 구하기
    for(int i=0;i<array.size();i++)
    {
        if(array[i] > max)
            max = array[i];
    }
    
    //max 길이의 배열 생성
    int arr[max+1];
    
    for(int i=0; i<max+1; i++) {
        arr[i] = 0;
    }
    
    //카운팅
    for(int i=0; i<array.size(); i++)
        arr[array[i]]++;
      
    //가장 많이 카운트 된 배열을 추출하기
    int maxv = -1;
    int arrv = -1;
    for(int i=0; i<max+1;i++) {
        if(arr[i]>maxv)
        {
            maxv = arr[i];
            arrv = i; //배열은 0부터니까            
        }
        else if(arr[i]==maxv) {
            maxv = arr[i];
            arrv= -1;
        }
    }
    answer = arrv; 
    
    return answer;
}