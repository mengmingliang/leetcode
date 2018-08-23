class solution{
public:
    int  lastDay(int f,int d,int x,int p){
        int waste = p + x;
        if(f*x <= d){
            return d/x;
        }else{
            return f + (d-f*x)/(p+x);
        } 
    }
}