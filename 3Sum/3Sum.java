public class Solution {
	public static List<List<Integer>> threeSum(int[] num) {
		List<List<Integer>> res = new ArrayList<List<Integer>>();
		
		int[] _num = num;
		
		Arrays.sort(_num);
		
		for (int i = 0; i < _num.length - 2; i++) {
			if (i != 0 && _num[i] == _num[i - 1]) continue;
			
			int j = i + 1;
			int k = _num.length - 1;
			
			while (j < k) {
				int sum = _num[i] + _num[j] + _num[k];
				if (sum == 0) {
					List<Integer> tmp = new ArrayList<Integer>();
					tmp.add(_num[i]);
					tmp.add(_num[j]);
					tmp.add(_num[k]);
					res.add(tmp);
					j++;
					k--;
					while (j < k && _num[j] == _num[j - 1]) j++;
					while (j < k && _num[k] == _num[k + 1]) k--;
				} 
				else if (sum < 0) j++;
				else k--;
			}
		}
		return res;
	}
}