class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        queue<pair<int,int>> qu;
        vector<vector<int>> price(n,vector<int>(n,0));
        vector<vector<int>> next(n,vector<int>());
        int ans = INT_MAX;
                
        for(auto l : flights){
            price[l[0]][l[1]] = l[2];
            next[l[0]].push_back(l[1]);
        }
        
        if(src == dst){
            return 0;
        }
        
        qu.push(make_pair(src,0));
        int step = 0;
        while(!qu.empty()){
            if(step > K){
                break;
            }
            
            int level = qu.size();
            for(int i = 0;i < level; ++i){
                pair<int,int> tmp = qu.front();
                qu.pop();
                int station = tmp.first;
                int cost = tmp.second;
                
                for(int j = 0;j < next[station].size(); ++j){
                    if(next[station][j] == dst){
                        ans = min(ans,cost + price[station][next[station][j]]);
                    }else{
                        qu.push(make_pair(next[station][j],cost + price[station][next[station][j]]));
                    }
                }
            }
            step++;
        }
        
        if(ans == INT_MAX){
            return -1;
        }
        
        return ans;
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
	//res终点dst的最小费用
	//cnt是飞了几次航班，
	int res = INT_MAX, cnt = 0;
	unordered_map<int, vector<vector<int>>> m;
	//m表示：起始地:[{终止地1，费用1},{终止地2，费用2}......]的集合
	for (auto flight : flights) {
		m[flight[0]].push_back({ flight[1],flight[2] });
	}
	//q中存储的是当前BFS的扩展到的最外围的航班，初始化为src节点，格式为：[{终止地1，从起点src到达终止地1的费用},{终止地2，从起点src到达终止地2的费用}。。。]
	queue<vector<int>> q;
	q.push({ src,0 });
	//BFS向外扩展
	while (!q.empty()) {
		int len = q.size();
		for (int i = 0; i <len; i++) {
			auto old = q.front();
			q.pop();
			//old为老节点的信息，格式{终止地old，从起点src到达终止地old的费用}
			if (old[0] == dst) res = min(res, old[1]);
			//查询从老节点能到达的所有节点
			for (auto newI : m[old[0]]) {
				//newI为新节点的信息（相对old为起点算的），格式{old为起点，下一个节点，费用}
				//如果到达下一个节点的费用大于res，那么意味着到达下一个节点的费用已经比找到到达终点dst的费用还高，则不用遍历这条路径了
				if (newI[1] + old[1]> res) continue;
				//把新节点放入队列
				q.push({ newI[0],  newI[1] + old[1] });
			}
		}
		cnt++;
		//K表示经停K次，cnt表示飞了cnt次航班，所以只有cnt>(K+1)才能跳出循环
		if (cnt > (K+1)) break;
	}
	return res == INT_MAX ? -1 : res;
    }
};

