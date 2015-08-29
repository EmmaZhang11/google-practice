//把一个List<String> serialize成一个String；把一个serialize得到的String还原成List<String>

#include <iostream>
#include <vector>

using namespace std;
string serialize(vector<string> list){
    string ans;
    for(auto s : list){
        int len = s.size();
        string tmp = to_string(len) + " " + s;
        ans += tmp;
    }
    return ans;
}

vector<string> deserialize(string s) {
    vector<string> ans;
    while(!s.empty()){
        int index = s.find_first_of(' ');
        int len = stoi(s.substr(0, index));
        string tmp = s.substr(index + 1, len);
        ans.push_back(tmp);
        s = s.substr(index + 1 + len);
    }
        return ans;
}
                       
int main(int argc, const char * argv[]) {
    vector<string> ori = {"111","aa#%dd","dd$d22"};
    string test = serialize(ori);
    vector<string> ans = deserialize(test);
    return 0;
}
