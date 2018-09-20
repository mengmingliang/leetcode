class MyCalendarTwo {
public:
    
    MyCalendarTwo(){

    }

    bool book(int start, int end) 
    {
        for(auto a: second){
            if(start >= a.second || end <= a.first){
                continue;
            }else{
                return false;
            }
        }
        
        for(auto a: first){
             if(start >= a.second || end <= a.first){
                continue;
             }else{
                 second.insert(make_pair(max(start,a.first),min(end,a.second)));
             }
        }
        first.insert(make_pair(start,end));
        
        return true;
    }
    
private:
    set<pair<int,int>> first;
    set<pair<int,int>> second;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */