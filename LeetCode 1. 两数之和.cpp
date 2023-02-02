#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  struct Node {
    Node(int index, int value) : index(index), value(value) {}
    int index;
    int value;
  };
  static bool compare(Node x, Node y) { return x.value < y.value; }

  vector<int> twoSum(vector<int> &nums, int target) {
    vector<Node> newNums;
    for (int i = 0, ii = nums.size(); i < ii; i++) {
      newNums.push_back(Node(i, nums[i]));
    }
    vector<int> ret;
    sort(newNums.begin(), newNums.end(), compare);
    for (int i = 0, j = newNums.size() - 1; i < j;) {
      if (newNums[i].value + newNums[j].value > target)
        --j;
      else if (newNums[i].value + newNums[j].value < target)
        ++i;
      else {
        ret.push_back(newNums[i].index), ret.push_back(newNums[j].index);
        // cout << ret.size() << endl;
        break;
      }
    }
    return ret;
  }
};

int main() {

  int target = 6;
  Solution s;
  vector<int> nums;
  nums.push_back(3);
  nums.push_back(2);
  nums.push_back(4);
  // nums.push_back(15);
  s.twoSum(nums, target);
}