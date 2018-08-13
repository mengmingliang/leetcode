class Solution {
public:
    int gcd(int a, int b)
    {
        if (a < b){
            return gcd(b, a);
        }
        int c = a % b;
        if (c == 0){
            return b;
        }else{
            return gcd(b, c);
        }
    }
    
    string fractionAddition(string expression) {
        vector<pair<int,int>> nums;
        vector<char> ops;
        string ans;
        int first = 0;
        int second = 0;
        string flag;
        
        for(int i = 0;i < expression.size(); ++i){
            if(i > 0 && expression[i-1] != '+' && expression[i-1] != '-'&&
               (expression[i] == '-' || expression[i] == '+')){
                ops.push_back(expression[i]);
                continue;
            }
            if(expression[i] == '/'){
                int l = i-1;
                int r = i+1;
                while(expression[l] >= '0' && expression[l] <= '9'){
                    l--;
                }
                if(expression[l] == '-' && (l == 0||(l > 0 && (expression[l-1] =='+' || expression[l-1] =='-')))){
                    l--;
                }
                while(expression[r] >= '0' && expression[r] <= '9'){
                    r++;
                }
                nums.push_back(make_pair(stoi(expression.substr(l+1,i-l)),stoi(expression.substr(i+1,r-i))));
            }
        }
        
        /*
        for(int i = 0;i < nums.size(); ++i){
            cout<<nums[i].first<<"/"<<nums[i].second<<endl;
        }
        
        for(int i = 0;i < ops.size(); ++i){
            cout<<ops[i]<<endl;
        }
        */
        
        first = nums[0].first;
        second = nums[0].second;
        for(int i = 0;i < ops.size(); ++i){
            if(ops[i] == '-'){
                first = first*nums[i+1].second - second*nums[i+1].first;
            }else{
                first = first*nums[i+1].second + second*nums[i+1].first;
            }
            second = second*nums[i+1].second;
            //cout<<first<<"/"<<second<<endl;
        }
        
       
        if(first == 0){
            return "0/1";
        }
        if((first > 0 && second > 0)||(first < 0 && second < 0)){
            flag = "";
        }else{
            flag = "-";
        }
        
        int div = gcd(abs(first),abs(second));
        first = abs(first)/div;
        second = abs(second)/div;
        ans = flag + to_string(first) + "/" + to_string(second); 
            
        return ans;
    }
};