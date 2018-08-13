typedef struct InNode{
    struct InNode * prev;
    string cur;
    int repeat;
    long long length;
};

class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long long idx = 0;
        string ans;
        InNode * head = NULL;
        
        for(int i = 0;i < S.size();){
            InNode * node = new InNode();
            int start = i;
            while(S[i] >= 'a' && S[i] <= 'z'){
                ++i;
                idx++;
            }
            node->prev = head;
            node->cur = S.substr(start,i-start);
            node->repeat = 1;  
            node->length = idx;
            head = node;
            
            if(i == S.size()){
                break;
            }
            if(S[i] >= '0' && S[i] <= '9'){
                int repeat = S[i] - '0';
                node->repeat = repeat;
                idx = idx*repeat;
                node->length = idx;
                ++i;
            }
        }
        
        InNode * node = head;
        while(node->prev){
            if(K <= node->length && K > node->prev->length){
                int l = node->length/node->repeat;
                while(K > l){
                    K = K-l;
                }
                if(K > node->prev->length){
                    ans.push_back(node->cur[K-(node->prev->length)-1]);
                    return ans; 
                }else{
                    continue;
                }
            }else{
                node = node->prev;
            }
        }
                
        if(K <= node->length){
            int l = node->length/node->repeat;
            while(K > l){
                K = K-l;
            }
            ans.push_back(node->cur[K-1]);
            return ans;
        }
        
        return ans;
    }
};