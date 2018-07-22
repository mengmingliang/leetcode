#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define ERROR -1
#define TRUN_LEFT -2
#define TURN_RIGHT -3

class Solution {
public:
    int changeDirction(int direction,int turn){
        if(direction == UP){
            if(turn == TRUN_LEFT){
                return LEFT;
            }else{
                return RIGHT;
            }
        }else if(direction == DOWN){
            if(turn == TRUN_LEFT){
                return RIGHT;
            }else{
                return LEFT;
            }
        }else if(direction == LEFT){
            if(turn == TRUN_LEFT){
                return DOWN;
            }else{
                return UP;
            }
        }else if(direction == RIGHT){
            if(turn == TRUN_LEFT){
                return UP;
            }else{
                return DOWN;
            }
        }else{
            return ERROR;
        }
    }
    
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        map<int,vector<int>> obXMap;
        map<int,vector<int>> obYMap;
        vector<int> obstacle;
        int ans = 0;
        int x = 0;
        int y = 0;
        
        for(int i = 0;i < obstacles.size();++i){
            if(obXMap.find(obstacles[i][0])!=obXMap.end()){
                obXMap[obstacles[i][0]].push_back(obstacles[i][1]);
            }else{
                obXMap[obstacles[i][0]] = obstacle;
                obXMap[obstacles[i][0]].push_back(obstacles[i][1]);
            }
            if(obYMap.find(obstacles[i][1])!=obYMap.end()){
                obYMap[obstacles[i][1]].push_back(obstacles[i][0]);
            }else{
                obYMap[obstacles[i][1]] = obstacle;
                obYMap[obstacles[i][1]].push_back(obstacles[i][0]);
            }
        }
        
        for(auto e : obXMap ){
            sort(e.second.begin(),e.second.end());
        }
        for(auto e : obYMap ){
            sort(e.second.begin(),e.second.end());
        }
        
        int direction = UP;
        for(int i = 0;i < commands.size(); ++i){
            if(commands[i] < 0){
                direction =  changeDirction(direction,commands[i]);
            }else{
                /*up*/
                if(direction == UP){
                    int next = y + commands[i];
                    if(obXMap.find(x) == obXMap.end()){
                        y = next;
                    }else{
                        vector<int>::iterator it = upper_bound(obXMap[x].begin(),obXMap[x].end(),y);
                        if(it == obXMap[x].end()){
                            y = next;
                        }else{
                            if(*it <= next){
                                y = *it - 1;
                            }else{
                                y = next;
                            }
                        }
                    }
                }else if(direction == DOWN){/*down*/
                    int next = y - commands[i];
                    if(obXMap.find(x) == obXMap.end()){
                        y = next;
                    }else{
                        vector<int>::iterator it = upper_bound(obXMap[x].begin(),obXMap[x].end(),y,greater<int>());
                        if(it == obXMap[x].end()){
                            y = next;
                        }else{
                            cout<<*it<<endl;
                            if(*it >= next){
                                y = *it + 1;
                            }else{
                                y = next;
                            }
                        }
                    }
                }else if(direction == RIGHT){/*right*/
                    int next = x + commands[i];
                    if(obYMap.find(y) == obYMap.end()){
                        x = next;
                    }else{
                        vector<int>::iterator it = upper_bound(obYMap[y].begin(),obYMap[y].end(),x);
                        if(it == obYMap[y].end()){
                            x = next;
                        }else{
                            if(*it <= next){
                                x = *it - 1;
                            }else{
                                x = next;
                            }
                        }
                    }
                }else if(direction == LEFT){/*left*/
                    int next = x - commands[i];
                    if(obYMap.find(y) == obYMap.end()){
                        x = next;
                    }else{
                        vector<int>::iterator it = upper_bound(obYMap[y].begin(),obYMap[y].end(),x,greater<int>());
                        if(it == obYMap[y].end()){
                            x = next;
                        }else{
                            if(*it >= next){
                                x = *it + 1;
                            }else{
                                x = next;
                            }
                        }
                    }
                }else{
                    return 0;
                }
                
            }
            ans = max(ans,int(pow(x,2) + pow(y,2)));
        }
        
        return ans;
    }
};

