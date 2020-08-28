class Solution {
public:

    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }

    int maximumSum(vector<int>& arr) {
        int size = arr.size();
        if (size == 1) return arr[ 0 ];

        // dropped record the maximum sum ended at current index with one number being dropped
        int dropped = max(arr[ 0 ], arr[ 1 ]);

        // not dropped must take arr[ 1 ] at index = 1
        int notDropped = max(arr[ 0 ] + arr[ 1 ], arr[ 1 ]);
        int ans = max(dropped, notDropped);

        for (int i = 2; i < size; i++) {
            dropped = max(notDropped, arr[ i ] + dropped);
            notDropped = max(notDropped + arr[ i ], arr[ i ]);
            ans = max(ans, max(dropped, notDropped));
        }
        return ans;
    }
};