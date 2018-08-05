/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

/*
 for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '[') {
                st.push(NestedInteger());
                start = i + 1;
            } else if (s[i] == ',' || s[i] == ']') {
                if (i > start) {
                    st.top().add(NestedInteger(stoi(s.substr(start, i - start))));
                }
                start = i + 1;
                if (s[i] == ']') {
                    if (st.size() > 1) {
                        NestedInteger t = st.top(); st.pop();
                        st.top().add(t);
                    }
                }
            }
        }
        return st.top();
*/

class Solution {
public:
    NestedInteger deserialize(string s) {
        NestedInteger ans;
        int n = s.size();
        stack<NestedInteger> st;
        
        if(s.size() <= 0){
            return ans;
        }
        
        if(s[0] != '['){
            ans.setInteger(stoi(s));
            return ans;
        }
        
        for(int i = 0;i < n;){
            if(s[i] == '['){
                st.push(NestedInteger());
                ++i;
            }else if(s[i] == ']'){
                NestedInteger t = st.top();
                st.pop();
                if(!st.empty()){
                    st.top().add(t);
                }else{
                    st.push(t);
                }
                ++i;
            }else if(s[i] == ','){
                ++i;
            }else{
                int val = 0;
                bool flag = true;
                if(s[i] == '-'){
                    flag = false;
                    ++i;
                }
                
                while(i < n && s[i] >= '0' && s[i] <= '9'){
                    val = val*10 + s[i] - '0';
                    ++i;
                }
                if(!flag){
                    val *= -1;
                }
                st.top().add(NestedInteger(val));                
            }
        }
        
        
        return st.top();
    }
};