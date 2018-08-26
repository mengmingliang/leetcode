class Solution {
public:
    bool isSame(string & A,string & B){
        vector<int> odd(26,0);
        vector<int> even(26,0);
        
        if(A.size() != B.size()){
            return false;
        }
        
        for(int i = 0;i < A.size(); ++i){
            if(i%2 == 0){
                even[A[i]-'a']++;
            }else{
                odd[A[i]-'a']++;
            }
        }
        
        for(int i = 0;i < B.size(); ++i){
            if(i%2 == 0){
                even[B[i]-'a']--;
                if(even[B[i]] < 0){
                    return false;
                }
            }else{
                odd[B[i]-'a']--;
                if(odd[B[i]-'a'] < 0){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    string parseString(string & A){
        string key;
        vector<int> odd(26,0);
        vector<int> even(26,0);
        
        for(int i = 0;i < A.size(); ++i){
            if(i%2 == 0){
                even[A[i]-'a']++;
            }else{
                odd[A[i]-'a']++;
            }
        }
        
        for(int i = 0;i < 26; ++i){
            if(even[i] == 0){
                key += "00";
            }else if(even[i] < 10 && even[i] > 0){
                key += "0";
                key += to_string(even[i]);
            }else{
                key += to_string(even[i]);
            }
        }
        
        for(int i = 0;i < 26; ++i){
            if(odd[i] == 0){
                key += "00";
            }else if(odd[i] < 10 && odd[i] > 0){
                key += "0";
                key += to_string(odd[i]);
            }else{
                key += to_string(odd[i]);
            }
        }
        
        return key;
    }
    
    int numSpecialEquivGroups(vector<string>& A) {
        int n = A.size();
        int ans = 0;
        map<string,int> keyMap;
        
        if(n <= 0){
            return 0;
        }
        
        for(int i = 0;i < A.size(); ++i){
            string key = parseString(A[i]);
            //cout<<key<<endl;
            if(keyMap.find(key) == keyMap.end()){
                keyMap[key]++;
            }else{
                keyMap[key] = 1;
            }
        }
        
        return keyMap.size();
    }
};