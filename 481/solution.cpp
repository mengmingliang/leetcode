class Solution {
public:
    int magicalString(int n) {
        if(n <= 0){
            return 0;
        }
        
        if(n <= 3){
            return 1;
        }
        
        string src = "122";
        string des = "12";
        
        int ans = 1;
        int first = 2;
        int second = 2;
        
        while(src.size() < n){
            char key = src[first];
            char pre = src[second];
            des.push_back(key);
            first++;
            
            if(key == '1'){
                if(pre == '1'){
                    src.push_back('2');
                }else{
                    src.push_back('1');
                    ans++;
                }
                second++;
            }else{
                if(pre == '1'){
                    src.push_back('2');
                    src.push_back('2');
                }else{
                    src.push_back('1');
                    ans++;
                    if(src.size() < n){
                        src.push_back('1');
                        ans++;
                    }else{
                        break;
                    }
                }
                second++;
                second++;
            }
        }
        
        //cout<<src<<endl;
        //cout<<des<<endl;
        
        return ans;
    }
};