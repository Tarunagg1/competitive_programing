class Solution {
     List<String> combinations = new ArrayList();
        Map <Character,String> map = new HashMap();
        String phoneDigits;
    
     public void makeMap() {
            map.put('2', "abc");
            map.put('3', "def");
            map.put('4', "ghi");
            map.put('5', "jkl");
            map.put('6', "mno");
            map.put('7', "pqrs");
            map.put('8', "tuv");
            map.put('9', "wxyz");
        }
        
        public void makeWord(int index,StringBuilder path){
            if (path.length() == phoneDigits.length()) {
                combinations.add(path.toString());
                return;
            }
            
            
            String possibleLetters = map.get(phoneDigits.charAt(index));
            for (char letter: possibleLetters.toCharArray()) {
                path.append(letter);
                makeWord(index + 1, path);
                path.deleteCharAt(path.length() - 1);
            }
        }
    
    public List<String> letterCombinations(String digits) {
        phoneDigits = digits;
        if (digits.length() == 0) {
            return combinations;
        }
        makeMap();
        makeWord(0, new StringBuilder());
        return combinations;
    }
}