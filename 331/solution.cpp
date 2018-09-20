class Solution {
public:
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
    
    bool isValidSerialization(string preorder) {
        int child = 0;
        int num = 0;
        
        vector<string> node;
        SplitString(preorder,node,",");
        
        for(int i = 0;i < node.size(); ++i){
            if(node[i] == "#"){
                child++;
            }else{
                num++;
            }
            
            if((child == (num + 1) && i < (node.size()-1))||child > (num + 1)){
                return false;
            }
            
        }
        
        if(child != (num+1)){
            return false;
        }
        
        return true;
    }
};