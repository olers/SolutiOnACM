#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
  char map[30];
  string ans = "";

public:
  string decodeMessage(string key, string message) {
    int index = 0;
    for (int i = 0; i < 30; i++) {
      map[i] = 0;
    }

    for (auto i : key) {
      if (i < 'a' || i > 'z')
        continue;
      if (map[i - 'a'] == 0) {
        map[i - 'a'] = 'a' + index++;
      }
    }
    for (auto i : message) {
      ans += i >= 'a' && i <= 'z' ? map[i - 'a'] : i;
      //   printf("%c", i >= 'a' && i <= 'z' ? map[i - 'a'] : i);
    }
    return ans;
  }
};

Solution s;
string key = "the quick brown fox jumps over the lazy dog";
string message = "vkbs bs t suepuv";

int main() {
  cout << s.decodeMessage(key, message);
  return 0;
}