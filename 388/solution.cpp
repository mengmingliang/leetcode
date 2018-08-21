
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
    
    int lengthLongestPath(string input) {
        vector<pair<string,int>> dir;
        vector<string> file;
        int ans = 0;
        int level = 0;
        string fileName;
        
        /*
        SplitString(input,file,"\n");
        for(int i = 0;i < file.size(); ++i){
            cout<<file[i]<<endl;
        }*/
        
        for(int i = 0;i < file.size(); ++i){
           level = 0;
           for(int j = 0;j < file[i].size(); ++j){
               if(file[i][j] == '\t'){
                   level++;
                   continue;
               }
               
               if(file[i][j] != '\t' && 
                  file[i][j] != '\n'){
                   fileName = file[i].substr(j,file[i].size()-j);
                   break;
               }
           }
           
           int sum = 0;
            string tmp;
           if(fileName.find(".") != std::string::npos){
               if(level > 0){
                   int top = dir.size()-1;
                   while(!dir.empty() && level <= dir[top].second){
                       dir.pop_back();
                       top = dir.size()-1;
                   }
                   for(int i = 0;i < dir.size(); ++i){
                       sum += dir[i].first.size() + 1;
                       //tmp += dir[i].first + "/";
                   }
               }
               sum += fileName.size();
               ans = max(sum,ans);
               //cout<<tmp<<endl;
               //tmp += fileName;
               continue;
           } 
            
           if(dir.empty()){
               dir.push_back(make_pair(fileName,level));
           }else{
               int top = dir.size()-1;
               while(!dir.empty() && level <= dir[top].second){
                   dir.pop_back();
                   top = dir.size()-1;
               }
               dir.push_back(make_pair(fileName,level));
           }
        }
        
        return ans;
    }
};