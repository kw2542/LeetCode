public class Solution {
    public int threeSumClosest(int[] num, int target) {
        int[] _num = num;
		int best = 0;
		long min = (long)Integer.MAX_VALUE - (long)Integer.MIN_VALUE;
		
		Arrays.sort(_num);
		
		for (int i = 0; i < _num.length - 2; i++) {
			if (i != 0 && _num[i] == _num[i - 1]) continue;
			
			int j = i + 1;
			int k = _num.length - 1;
			
			while (j < k) {
				int sum = _num[i] + _num[j] + _num[k];
				if (Math.abs(target - sum) < min) {
				    best = sum;
				    min = Math.abs(target - sum);
				} 
				else if (sum < target) j++;
				else k--;
			}
		}
		return best;
    }
}