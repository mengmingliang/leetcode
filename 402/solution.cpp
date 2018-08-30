class Solution {
public:
    string removeKdigits(string num, int k) {
       stack<char> s;
       string ans;
       string pre;
       int idx = 0;
        
       if(k >= num.size()){
           return "0";
       }
        
       while(k > 0 && idx < num.size()){
           if(s.empty()){
               s.push(num[idx++]);
           }else{
               if(s.top() > num[idx]){
                   while(k > 0 && !s.empty() && s.top() > num[idx]){
                       s.pop();
                       k--;
                   }   
               }
               s.push(num[idx++]);
           }
       }
       
       while(k> 0 && !s.empty()){
           s.pop();
           k--;
       }
        
       while(!s.empty()){
           ans.push_back(s.top());
           s.pop();
       } 
       reverse(ans.begin(),ans.end());        
       ans += num.substr(idx,num.size()-idx); 
        
       int zero = 0;
       for(int i = 0;i < ans.size()-1; ++i){
           if(ans[i] == '0'){
               zero++;
           }else{
               break;
           }
       }
        
       ans = ans.substr(zero,ans.size()-zero);
        
       return ans;
    }
};