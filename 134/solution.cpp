class Solution {
public:
    bool canStartFrom(vector<int> & gas,vector<int>& cost,int start,int & end){
        int rest = gas[start];
        int n = gas.size();
        
        for(int i = start;i < cost.size()-1; ++i){
            rest -= cost[i];
            if(rest < 0){
                end = i;
                return false;
            }else{
                rest += gas[i+1];
            }
        }
        
        rest -= cost[n-1];
        if(rest < 0){
            end = n-1;
            return false;
        }
        
        for(int i = 0;i < start; ++i){
            rest += gas[i];
            rest -= cost[i];
            if(rest < 0){
                end = i;
                return false;
            }
        }
        
        return true;
    }
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = 0;
        int end = 0;
        
        for(int i = 0; i < n; ++i){
            if(canStartFrom(gas,cost,i,end)){
                return i;
            }
        }
        
        return -1;
    }
};