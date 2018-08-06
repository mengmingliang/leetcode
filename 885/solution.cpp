
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;
        int l = 0;
        int r = people.size()-1;
        int two = 0;
        sort(people.begin(),people.end());
        
        while(l < r){
            if(people[l] + people[r] > limit){
                r--;
            }else{
                two++;
                l++;
                r--;
            }
        }
        
        return people.size() - two;
    }
};