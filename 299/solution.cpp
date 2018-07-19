class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0;
        int b = 0;
        string ans;
        
        vector<int> secretDigit(10,0);
        vector<int> guessDigit(10,0);
        
        for(int i = 0;i < secret.size(); ++i){
            if(secret[i] == guess[i]){
                ++a;
            }
            secretDigit[secret[i]-'0']++;
            guessDigit[guess[i]-'0']++;
        }
        
        for(int i = 0;i < 10; ++i){
            b += min(secretDigit[i],guessDigit[i]);
        }
        
        b -= a;
        ans = to_string(a) + "A" + to_string(b) + "B";
        return ans;
    }
};