class Union {
public:

  vector<int > parent;
  Union(int n) {
    parent.resize(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  int findParent(int x) {
    return parent[x] == x ? x : (parent[x] = findParent(parent[x]));
  }

  void unionAB(int a, int b) {
    int parA = findParent(a);
    int parB = findParent(b);
    if (parA == parB) {
      return;
    }
    parent[parB] = parA;
  }
};

class Solution {
public:
  Solution() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  }
  vector<int > row, col;
  int removeStones(vector<vector<int> >& stones) {
    int n = stones.size();
    row.resize(10004, -1);
    col.resize(10004, -1);
    Union U(n);
    for (int i = 0; i < stones.size(); i++) {
      int fx = stones[i][0];
      int fy = stones[i][1];
      // cout<<fx<<", "<<fy<<"\n";
      if (row[fx] != -1) {
        U.unionAB(row[fx], i);
      }
      if (col[fy] != -1) {
        U.unionAB(col[fy], i);
      }
      row[fx] = i;
      col[fy] = i;
    }
    int ans = 0;
    for (int i = 0; i < n ; i++) {
      if (U.parent[i] == i) {
        ans++;
      }
    }
    return n - ans;
  }
};