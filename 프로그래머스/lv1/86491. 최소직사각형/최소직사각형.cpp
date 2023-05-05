#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int maxw=0, maxh=0;
    for(int i=0; i<sizes.size(); i++){
        if(sizes[i][0] > sizes[i][1]){
            maxw = max(maxw, sizes[i][0]);
            maxh = max(maxh, sizes[i][1]);
        }
        else{
            maxw = max(maxw, sizes[i][1]);
            maxh = max(maxh, sizes[i][0]);
        }
    }
    answer = maxw * maxh;
    return answer;
}