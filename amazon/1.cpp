class solution{
public:
    vector<int>  reverseList(int n){
        vector<int> ans;

        for(int i = 1;i <= n; ++i){
            if(i%2 == 0){
                ans.push_front(i);
            }else{
                ans.push_back(i);
            }
        }

        if(n%2 != 0){
            reverse(ans.begin(),ans.end());
        }

        return ans;
    }
private:
}