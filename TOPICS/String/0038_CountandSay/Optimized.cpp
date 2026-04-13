// Runtime: 0ms, beats: 100.00%
// using two string

#include <iostream>
using namespace std;

class Solution {
  public:
    string countAndSay(int n) {
        string rle, tmp;
        int j, k, count, length;

        for (int i = 1; i <= n; i++) {
            j = k = count = 0;
            length = rle.size();
            // cout << "Times: " << i << endl;

            tmp = rle;
            rle.clear();

            if (i == 1)
                rle += "1";
            else
                while (j < length && k <= length) {
                    if (k < length && tmp[j] == tmp[k]) {
                        // cout << "HERE!\n";
                        count++;
                        k++;
                    } else {
                        rle += count + '0';
                        // cout << rle << " ";
                        rle += tmp[j];
                        // cout << rle << endl;
                        // cout << "New RLE: " << rle << endl;
                        j = k;
                        // cout << "Length: " << length << endl;
                        count = 0;
                    }

                    // cout << tmp << ", count: " << count << ", j: " << j << " " << k << endl;
                }
            // cout << "RLE: " << rle << endl
            //      << endl;
        }

        return rle;
    }
};
