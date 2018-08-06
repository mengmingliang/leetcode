class Solution {
public:
    void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
    {
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
    
    bool isIPv4(string &IP){
        vector<string> gr;
        SplitString(IP,gr,".");
        
        if(gr.size() != 4||IP[IP.size()-1] == '.'){
            return false;
        }
        
        for(int i = 0;i < gr.size(); ++i){
            if(gr[i][0] == '0' && gr[i].size() > 1){
                return false;
            }
            if(gr[i].size() == 0||gr[i].size() > 3){
                return false;
            }
            for(int j = 0; j < gr[i].size(); ++j){
                if(gr[i][j] < '0' || gr[i][j] > '9'){
                    return false;
                }
            }
            if(stoi(gr[i]) < 0||stoi(gr[i]) > 255){
                return false;
            }
        }
        
        return true;
    }
    
    bool isIPv6(string &IP){
        vector<string> gr;
        SplitString(IP,gr,":");
        
        if(gr.size() != 8||IP[IP.size()-1] == ':'){
            return false;
        }
        
        for(int i = 0;i < gr.size();++i){
            if(gr[i].size() > 4 || gr[i].size() == 0){
                return false;
            }
            for(int j = 0;j < gr[i].size(); ++j){
                char c = gr[i][j];
                if(!((c >= '0' && c <= '9')||
                     (c >= 'a' && c <= 'f')||
                     (c >= 'A' && c <= 'F'))){
                    cout<<"1"<<endl;
                    return false;
                }
            }
        }
        
        return true;
    }
    
    string validIPAddress(string IP) {
        if(IP.find('.',0) != std::string::npos){
            return isIPv4(IP)?"IPv4":"Neither";
        }    
        if(IP.find(':',0) != std::string::npos){
            return isIPv6(IP)?"IPv6":"Neither"; 
        }
        
        return "Neither";
    }
};