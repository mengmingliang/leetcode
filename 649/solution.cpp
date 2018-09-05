class Solution {
public:
    string predictPartyVictory(string senate) {
        int cntR = 0;
        int cntD = 0;
        int n = senate.size();
        string ans;
        
        for(auto c: senate){
            if(c == 'R'){
                cntR++;
            }else{
                cntD++;
            }
        }
        
        if(cntR == 0){
            return "Dire";
        }
        
        if(cntD == 0){
            return "Radiant";
        }
        
        while(cntR > 0 && cntD > 0){
            for(int i = 0;i < n; ++i){
                if(senate[i] == 'R'){
                    for(int j = i+1; j <= i+n; ++j){
                        if(senate[j%n] == 'D'){
                           senate[j%n] = 'B';
                           cntD--;
                           break;
                        }
                    }
                }
                
                if(senate[i] == 'D'){
                    for(int j = i+1; j <= i+n; ++j){
                        if(senate[j%n] == 'R'){
                           senate[j%n] = 'B';
                           cntR--;
                           break;
                        }
                    }
                }
            }
        }
        
        if(cntR == 0){
            return "Dire";
        }else{
            return "Radiant";
        }
    }
};