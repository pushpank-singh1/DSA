class Solution {
public:
    bool isValid(string str) {
        stack<char> s;

        for(int i=0; i<str.size(); i++){
            // push open brackets
            if(str[i] == '(' || str[i] == '{' || str[i] == '['){
                s.push(str[i]);
            } else { // closing bracket
                // corner case 2
                if(s.size() == 0){
                    return false;
                }

                // check pair of open and close
                if((s.top() == '(' && str[i] == ')') || 
                    (s.top() == '{' && str[i] == '}') || 
                      (s.top() == '[' && str[i] == ']')){
                        s.pop();
                } else {
                    //corner case 1
                    return false;
                }
            }
        }

        return s.size() == 0; //corner case 3
    }
};