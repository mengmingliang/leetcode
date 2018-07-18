class solution{
	public:
		vector<int> diffWaysToCompute(string input) {
			vector<int> ans;
			for(int i = 0;i < input.size(); ++i){
				if(input[i] == '+'||input[i] == '-'||input[i] == '*'){
					auto left = diffWaysToCompute(input.substr(0,i));
					auto right = diffWaysToCompute(input.substr(i+1));
												                    
					for(auto l:left){
						for(auto r:right){
							if(input[i] == '+'){
							     ans.push_back(l+r);
							}else if(input[i] == '-'){
							     ans.push_back(l-r);
							}else{
								ans.push_back(l*r);
							}
						}
					}
				}
			}
					        
		if(ans.empty()){
			ans.push_back(atoi(input.c_str()));
		}
						        
		return ans;
	}
	private:
}

