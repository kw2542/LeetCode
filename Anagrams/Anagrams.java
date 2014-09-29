public class Solution {
    public List<String> anagrams(String[] strs) {
        HashMap<String, List<String>> map = new HashMap<>();
        for (int i = 0; i < strs.length; ++i) {
            char [] c = strs[i].toCharArray();
            Arrays.sort(c);
            String s = new String(c);
            List<String> list = map.get(s);
            if (list == null) {
                list = new ArrayList<String>();
                map.put(s, list);
            }
            list.add(strs[i]);
        }
        List<String> res = new ArrayList<String>();
        for (String key : map.keySet()) {
            List<String> l = map.get(key);
            if (l.size() > 1) {
                for (String s : l) {
                    res.add(s);
                }
            }
        }
        return res;
    }
}