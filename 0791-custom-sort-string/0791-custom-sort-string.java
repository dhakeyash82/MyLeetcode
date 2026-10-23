import java.util.HashMap;

class Solution {
    public String customSortString(String order, String s) {
    
        HashMap<Character, Integer> countMap = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            countMap.put(c, countMap.getOrDefault(c, 0) + 1);
        }
        
        StringBuilder result = new StringBuilder();
        
    
        for (int i = 0; i < order.length(); i++) {
            char c = order.charAt(i);
            if (countMap.containsKey(c)) {
                int frequency = countMap.get(c);
                for (int j = 0; j < frequency; j++) {
                    result.append(c);
                }
                
                countMap.remove(c);
            }
        }
        
       
        for (char c : countMap.keySet()) {
            int frequency = countMap.get(c);
            for (int j = 0; j < frequency; j++) {
                result.append(c);
            }
        }
        
        return result.toString();
    }
}