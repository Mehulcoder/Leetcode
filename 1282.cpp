class Solution {
public:
	vector<vector<int>> groupThePeople(vector<int>& groupSizes) {

		vector<int> edges[505];
		for (int i = 0; i < groupSizes.size(); ++i) {
			int temp = groupSizes[i];
			edges[temp].push_back(i);
		}

		vector<vector<int>> ans;
		for (int i = 0; i < 505; ++i) {
			if (edges[i].size() != 0) {
				vector<int> temp;
				int sz = i;
				int count = 0;
				for (int j = 0; j < edges[i].size(); ++j) {
					temp.push_back(edges[i][j]);
					count++;
					if (count == sz) {
						count = 0;
						ans.push_back(temp);
						temp.clear();
					}
				}
			}
		}

		return ans;
	}
};