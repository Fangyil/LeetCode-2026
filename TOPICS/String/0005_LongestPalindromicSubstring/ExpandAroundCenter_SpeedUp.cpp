// Runtime: 89ms, Beats: 31.34%
// v2 change order(simplify), change 'expandAroundCenter' comparison and return, a little better than v1,v2
// ref.  1 - https://vocus.cc/article/672addd2fd89780001160aae
//       2 - https://medium.com/@ron910517/5-longest-palindrome-substring-最長回文子字串-994c1a4a0a20

#include <iostream>
using namespace std;

class Solution
{
private:
  // find longest palindromic
  string expandAroundCenter(string s, int l, int r)
  {
    while (l > -1 && r < s.length() && s[l] == s[r])
    {
      l--;
      r++;
    }
    return s.substr(l + 1, r - l - 1);
  }

public:
  string longestPalindrome(string s)
  {

    int i;
    string ans, odd_palindromic, even_palindromic;

    ans.clear();
    for (i = 0; i < s.length(); i++)
    {
      odd_palindromic = expandAroundCenter(s, i, i);
      if (ans.size() < odd_palindromic.size())
        ans = odd_palindromic;

      even_palindromic = expandAroundCenter(s, i, i + 1);
      if (ans.size() < even_palindromic.size())
        ans = even_palindromic;

      // cout << i << endl;
      // cout << "odd_palindromic: " << odd_palindromic << endl;
      // cout << "even_palindromic: " << even_palindromic << endl;
      // cout << "ans: " << ans << endl << endl;
    }
    return ans;
  }
};
