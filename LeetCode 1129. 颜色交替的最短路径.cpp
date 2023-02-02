#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAXN 110

class Solution
{
private:
  vector<int> redGraph[110];
  vector<int> blueGraph[110];
  queue<pair<int, int>> q;
  bool vis[110][2];
  int ans[110][2];
  vector<int> ret;

public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges,
                                       vector<vector<int>> &blueEdges)
  {

    for (int i = 0; i < n; i++)
    {
      ans[i][0] = ans[i][1] = -1;
    }

    for (auto &edge : redEdges)
    {
      redGraph[edge[0]].push_back(edge[1]);
    }
    for (auto &edge : blueEdges)
    {
      blueGraph[edge[0]].push_back(edge[1]);
    }

    q.push(make_pair(0, 0));
    q.push(make_pair(0, 1));
    ans[0][0] = ans[0][1] = 0;

    while (!q.empty())
    {
      pair<int, int> now = q.front();
      q.pop();
      // col: 0 RED, 1 BLUE
      int col = now.second;
      if (col)
        for (auto i : redGraph[now.first])
        {
          if (vis[i][0])
          {
            continue;
          }
          q.push(make_pair(i, 0));
          vis[i][0] = true;
          if (ans[i][0] == -1)
          {
            ans[i][0] = ans[now.first][1] + 1;
          }
        }

      if (!col)
        for (auto i : blueGraph[now.first])
        {
          if (vis[i][1])
          {
            continue;
          }
          q.push(make_pair(i, 1));
          vis[i][1] = true;
          if (ans[i][1] == -1)
          {
            ans[i][1] = ans[now.first][0] + 1;
          }
        }
    }
    for (int i = 0; i < n; i++)
    {
      if (ans[i][0] == -1)
        ret.push_back(ans[i][1]);
      else if (ans[i][1] == -1)
        ret.push_back(ans[i][0]);
      else
        ret.push_back(min(ans[i][0], ans[i][1]));
    }
    return ret;
  }
};

Solution s;

int main()
{
  cout << "Solution";
  return 0;
}