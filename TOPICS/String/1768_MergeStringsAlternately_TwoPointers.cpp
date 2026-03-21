//Runtime: 0ms, Beats: 100.00%

#include <iostream>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0;
        string merged;
        // cout << word1.size() << " " << word2.size() << endl;
        while (i < word1.size() && j < word2.size()) {
            merged += word1[i];
            merged += word2[j];
            // cout << word1[i] << word2[j] << endl;
            // cout << merged << endl;
            i++;
            j++;
        }
        if (i < word1.size())
            merged += word1.substr(i);
        if (j < word2.size())
            merged += word2.substr(j);

        return merged;
    }
};
