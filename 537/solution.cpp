class Solution {
public:
    bool strToNum(string s,int &a,int &b){
        for(int i = 0;i < s.size(); ++i){
            if(s[i] == '+' ){
                a = atoi((s.substr(0,i)).c_str());
                b = atoi((s.substr(i+1,s.size()-i-2)).c_str());
            }
        }
        
        return true;
    }
    
    string complexNumberMultiply(string a, string b) {
        vector<int> num(4,0);
        string ans;
        
        strToNum(a,num[0],num[1]);
        strToNum(b,num[2],num[3]);
        
        for(int i = 0;i < 4; ++i){
            cout<<num[i]<<endl;
        }
        
        ans = to_string(num[0]*num[2]-num[1]*num[3]) + "+" + \
              to_string(num[0]*num[3] + num[1]*num[2]) + "i";
        
        return ans;
    }
};