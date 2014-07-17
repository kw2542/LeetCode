class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        vector<int> _num = num;
        sort(_num.begin(), _num.end());
		int best = 0;
		long long min = (long long)INT_MAX - (long long)INT_MIN;
		
		for (int i = 0; i < _num.size() - 2; i++) {
			if (i != 0 && _num[i] == _num[i - 1]) continue;
			
			int j = i + 1;
			int k = _num.size() - 1;
			
			while (j < k) {
				int sum = _num[i] + _num[j] + _num[k];
				if (abs(target - sum) < min) {
				    best = sum;
				    min = abs(target - sum);
				} 
				else if (sum < target) j++;
				else k--;
			}
		}
		return best;
    }
};