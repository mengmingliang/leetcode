class Solution {
public:
    /*string to integer*/
    int str2int(const string &string_temp){  
        int int_temp = 0;
        stringstream stream(string_temp);  
        stream>>int_temp;  
        
        return int_temp;
    }  
    
    bool isDigit(char c){
        if(c >= '0' && c <= '9'){
            return true;
        }
        
        return false;
    }
    
    bool isOps(char c){
        if(c == '+' || c == '-' ||
           c == '*' || c == '/'){
            return true;
        }
        
        return false;
    }
    
    /*split string by key*/
    void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c){
      std::string::size_type pos1, pos2;
      pos2 = s.find(c);
      pos1 = 0;
        
      while(std::string::npos != pos2){
        v.push_back(s.substr(pos1, pos2-pos1));

        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
      }
        
      if(pos1 != s.length())
         v.push_back(s.substr(pos1));
    }
    
    bool parseExpr(string s,int &a,int &b){
        char op = '#';
        int n = s.size();
        int i = 0;
        
        a = 0;
        b = 0;
        
        if(s.size() <= 0){
            return false;
        }
        
        /*parse expression */
        while(i < n){
            if(isDigit(s[i])){
                string num;
                while(i < n && isDigit(s[i])){
                    num.push_back(s[i]);
                    ++i;
                }
                cout<<num<<endl;
                if(i < n && s[i] == 'x'){
                    if(op == '#'){
                        b = str2int(num);
                    }else if(op == '-'){
                        b = b - str2int(num);
                    }else if(op == '+'){
                        b = b + str2int(num);
                    }else{
                        
                    }
                    ++i;
                }else{
                    if(op == '#'){
                        a = str2int(num);
                    }else if(op == '-'){
                        a = a - str2int(num);
                    }else if(op == '+'){
                        a = a + str2int(num);
                    }else{
                        
                    }
                }
            }else if(isOps(s[i])){
                op = s[i];
                ++i;
            }else if(s[i] == 'x'){
                if(op == '#'){
                    b = 1;
                }else if(op == '-'){
                    b = b - 1;
                }else if(op == '+'){
                    b = b + 1;
                }else{
                    
                }
                ++i;
            }else{
                ++i;
            }
            //cout<<a<<"+"<<b<<"x"<<endl;
        }
        
        return true;
    }
    
    
    
    string solveEquation(string equation) {
        string ans = "";
        vector<string> expr;
        int la = 0;
        int lb = 0;
        int ra = 0;
        int rb = 0;
     
        SplitString(equation,expr,"=");
        parseExpr(expr[0],la,lb);
        parseExpr(expr[1],ra,rb);
        //cout<<la<<"+"<<lb<<"x"<<endl;
        //cout<<ra<<"+"<<rb<<"x"<<endl;
        
        if(la == ra && lb == rb){
            return "Infinite solutions";
        }
        
        if(lb == rb && la != ra){
            return "No solution"; 
        }
        
        int res = (ra - la)/(lb - rb);
        ans = "x=" + to_string(res);
        
        return ans;
    }
};