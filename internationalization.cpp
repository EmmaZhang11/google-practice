#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> internationalization(vector<string> &dict){
        vector<string> ans;
        for(int i = 0; i < dict.size(); i++){
            string word = dict[i];
            string decode;
            vector<bool> v (word.size(), false);
            v[0] = true;
            v[word.size()-1] = true;
            for(int j = 0; j < dict.size(); j++){
                int len = dict[i].size();
                if(j != i && dict[i].size() == dict[j].size()){
                    if(dict[i][0] != dict[j][0] || dict[i][len-1] != dict[j][len-1]) continue;
                    for(int k = 1; k < dict[i].size() - 1; k++){
                        if(dict[i][k] != dict[j][k]){
                            v[k] = true;
                            break;
                        }
                    }
                }
            }
            int pre = 0;
            decode += dict[i][0];
            for(int k = 1; k < dict[i].size(); k++){
                if(v[k]){
                    if(k - pre - 1 > 0)
                        decode += to_string(k - pre - 1);
                    decode += dict[i][k];
                    pre = k;
                } 
            }
            ans.push_back(decode);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<string> test = {"abcdefg", "abbc","aebc", "abcde", "abdff", "aecde","abcfe"};
    vector<string> re = s.internationalization(test);
    return 0;
}
