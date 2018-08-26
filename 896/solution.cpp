
class FreqStack {
public: unordered_map<int, int> mem;
        priority_queue<pair<int, pair<int, int>>> q;
        int time;
public:
    FreqStack() {
        mem.clear();
        time = 0;
    }
    
    void push(int x) {
        if(mem.find(x) == mem.end()){
            mem[x] = 1;//freq initial;
            q.push(make_pair(1, make_pair(time++, x)));
        } else{
            mem[x] = mem[x] + 1;
            /**/
            q.push(make_pair(mem[x], make_pair(time++, x)));
        }
    }
    
    int pop() {
        int val = q.top().second.second;
        q.pop();
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */