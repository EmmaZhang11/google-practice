#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (string& d : dictionary) {
            int n = d.length();
            string abbr = d;
            if(n > 2)abbr = d[0] + to_string(n-2) + d[n - 1];
            mp[abbr].insert(d);
        }
    }
    
    bool isUnique(string word) {
        int n = word.length();
        string abbr = word;
        if(n > 2)abbr = word[0] + to_string(n-2) + word[n - 1];
        if(mp.find(abbr) == mp.end()) return true;
        unordered_set<string> set = mp[abbr];
        if(set.size() == 1 && *set.begin() == word) return true;
        return false;
    }
private:
    unordered_map<string, unordered_set<string>> mp;
};



int main()
{
    // Your ValidWordAbbr object will be instantiated and called as such:
    vector<string> dictionary = {"deer", "door", "cake", "card" };
    ValidWordAbbr vwa(dictionary);
    cout << vwa.isUnique("dear");
    cout << vwa.isUnique("cart");
    cout << vwa.isUnique("cane");
    cout << vwa.isUnique("card");
    return 0;
}
