#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool checkXMatrix(vector<vector<int>> &grid) {
    for (int i = 0, ii = grid.size(); i < ii; ++i) {
      for (int j = 0, jj = ii; j < jj; ++j) {
        if (i == j || i + j == ii - 1) {
          if (grid[i][j] == 0)
            return false;
        } else {
          if (grid[i][j] != 0)
            return false;
        }
      }
    }
    return true;
  }
};

int main() {
  int x;
  cout << "ASDAS";
  return 0;
}