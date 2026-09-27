class Solution {
public:
    int lengthOfLastWord(string s) {
        //traverse from end
        int i = s.length()-1;
        int count = 0;

        // skip trailing spaces
        while(i >= 0 && s[i] == ' '){
            i--;
        }

        //count length of last word untill a space comes
        while(i >= 0 && s[i] != ' '){
            count++;
            i--;
        }

        return count;
    }
};