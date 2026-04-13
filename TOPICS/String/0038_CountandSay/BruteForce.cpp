// Runtime: 4ms, beats: 50.54%

#include <iostream>
using namespace std;

class Solution {
  public:
    string countAndSay(int n) {
        string rle;
        int j, k, count, length;

        for (int i = 1; i <= n; i++) {
            j = k = count = 0;
            length = rle.size() + 1;
            // cout << "Times: " << i << endl;

            if (i == 1)
                rle += "1";
            else
                while (j < length && k < length && length > 1) {
                    if (k < length - 1 && rle[j] == rle[k]) {
                        // cout << "HERE!\n";
                        count++;
                        k++;
                    } else {
                        rle += count + '0';
                        // cout << rle << " ";
                        rle += rle[j];
                        // cout << rle << endl;
                        rle.erase(j, k);
                        // cout << "New RLE: " << rle << endl;
                        j = k = 0;
                        length -= count;
                        // cout << "Length: " << length << endl;
                        count = 0;
                    }

                    // cout << rle << ", count: " << count << ", j: " << j << " " << k << endl;
                }
            // cout << "RLE: " << rle << endl<< endl;
        }

        return rle;
    }
};
