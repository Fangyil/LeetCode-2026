// Runtime: 247ms, Beats: 28.19%
// 超級暴力，一直mod讓數字小

#include <iostream>
using namespace std;

class Solution
{
private:
  // 題目要求
  const int mod = 1e9 + 7;

  // left shift means times, calculate times how much
  int decToBinaryBit(int n)
  {
    int bit = 1;

    while (n > 0)
    {
      n /= 2;
      bit = (bit * 2) % mod;
    }
    return bit;
  }

public:
  int concatenatedBinary(int n)
  {
    int i, j;
    long bit[n + 1], ans;

    // from right to left
    ans = n;
    // save left shift
    bit[n] = decToBinaryBit(n);

    // cout << n << endl;
    // cout << "bit: " << decToBinaryBit(n) << endl;
    // cout << "bit[" << n << "]: " << bit[n] << endl;
    // cout << "ans: " << ans << endl << endl;

    for (i = n - 1; i > 0; i--)
    {
      // temp = 0;
      bit[i] = (bit[i + 1] * decToBinaryBit(i)) % mod;
      ans = (ans + i * bit[i + 1] % mod) % mod; // let ans keep small
      // j = i;
      // while (j > 0) {
      //     temp += bit[i + 1] % mod;
      //     j--;
      // }
      // ans = (ans + temp) % mod;
      
      // cout << i << endl;
      // cout << "bit: " << decToBinaryBit(i) << endl;
      // cout << "bit[" << i << "]: " << bit[i] << endl;
      // cout << "ans: " << ans << endl << endl;
    }
    return ans;
  }
};