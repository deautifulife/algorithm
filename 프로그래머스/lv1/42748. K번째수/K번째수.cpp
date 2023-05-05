#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0; i<commands.size(); i++){
        vector<int> cut_array;
        for(int j=commands[i][0]; j<=commands[i][1]; j++){
            cut_array.push_back(array[j-1]);
        }
        sort(cut_array.begin(), cut_array.end());
        answer.push_back(cut_array[commands[i][2]-1]); 
    }
    return answer;
}