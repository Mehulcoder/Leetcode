class Solution {
public:
        vector<vector> merge(vector<vector>& intervals) {
                if (intervals.size() == 0 || intervals.size() == 1) {
                        return intervals;
                }

                sort(intervals.begin(), intervals.end());
                vector<vector<int>>ans;
                stack<vector<int>>s;
                s.push(intervals[0]);
                for (int i = 1; i < intervals.size(); i++) {
                        vector<int>temp = s.top();
                        if (temp[1] < intervals[i][0]) {
                                s.push(intervals[i]);
                        } else if (temp[1] < intervals[i][1]) {
                                temp[1] = intervals[i][1];
                                s.pop();
                                s.push(temp);
                        }
                }
                while (!s.empty()) {
                        ans.push_back(s.top());
                        s.pop();
                }

                return ans;
        }
}