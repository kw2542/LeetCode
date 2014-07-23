public class Solution {
    public List<List<Integer>> fourSum(int[] num, int target) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
		
		int[] _num = num;
		
		Arrays.sort(_num);
		for (int t = 0; t < _num.length - 3; ++t) {
		    if (t != 0 && _num[t] == _num[t - 1]) continue;
    		for (int i = t + 1; i < _num.length - 2; ++i) {
    			if (i != t + 1 && _num[i] == _num[i - 1]) continue;
    			
    			int j = i + 1;
    			int k = _num.length - 1;
    			
    			while (j < k) {
    				int sum = _num[t] + _num[i] + _num[j] + _num[k];
    				if (sum == target) {
    					List<Integer> tmp = new ArrayList<Integer>();
    					tmp.add(_num[t]);
    					tmp.add(_num[i]);
    					tmp.add(_num[j]);
    					tmp.add(_num[k]);
    					res.add(tmp);
    					j++;
    					k--;
    					while (j < k && _num[j] == _num[j - 1]) j++;
    					while (j < k && _num[k] == _num[k + 1]) k--;
    				} 
    				else if (sum < target) j++;
    				else k--;
    			}
    		}
		}
		return res;
    }
}