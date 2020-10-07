class Solution {
public:
	int bitwiseComplement(int num) {

		// calculating number of bits
		// in the number
		if (num == 0) return 1;
		int x = log2(num) + 1;

		// Inverting the bits one by one
		for (int i = 0; i < x; i++)
			num = (num ^ (1 << i));

		return  num;
	}
};