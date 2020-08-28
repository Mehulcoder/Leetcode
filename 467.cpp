class Solution {
public:
	int findSubstringInWraproundString(string p) {
		// count[i] is the maximum unique substring end with ith letter.
		// 0 - 'a', 1 - 'b', ..., 25 - 'z'.
		int* count = new int[26];

		// store longest contiguous substring ends at current position.
		int maxLengthCur = 0;

		for (int i = 0; i < p.size(); i++) {
			if (i > 0 && (p[i] - p[i - 1] == 1 || (p[i - 1] - p[i] == 25))) {
				maxLengthCur++;
			} else {
				maxLengthCur = 1;
			}

			int index = p.at(i) - 'a';
			count[index] = max(count[index], maxLengthCur);
		}

		// Sum to get result
		int sum = 0;
		for (int i = 0; i < 26; i++) {
			sum += count[i];
		}
		return sum;
	}
};