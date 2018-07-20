class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        string ans;
        
        if(k >= num.size()){
            return "0";
        }
        
        if( k == 0){
            return num;
        }
        
        reverse(num.begin(),num.end());
        cout<<"asd"<<endl;
        
        for(int i = 0;i < num.size(); ++i){
            if(k == 0){
                for(int j = i;j < num.size(); ++j){
                    s.push(num[j]);
                }
                break;
            }
            if(s.empty()){
                s.push(num[i]);
            }else{
                if(num[i] > s.top()){
                    k--;
                    continue;
                }else if(num[i] == s.top()){
                    s.push(num[i]);
                }else{
                    while(s.top() > num[i] && k > 0 && !s.empty()){
                        s.pop();
                        k--;
                    }
                    if(k == 0){
                        for(int j = i;j < num.size(); ++j){
                            s.push(num[j]);
                        }
                        break;
                    }else{
                        s.push(num[i]);
                    }
                }
            }
        }
        
        cout<<"asdds"<<endl;
        
        if(k != 0){
            while(k > 0 && !s.empty()){
                s.pop();
                k--;
            }
        }
            
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
};