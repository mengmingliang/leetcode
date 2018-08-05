class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long area = (C-A)*(D-B) + (G-E)*(H-F);
        long x1 = max(A,E);
        long y1 = max(B,F);
        long x2 = min(C,G);
        long y2 = min(D,H);
        int w = max(long(0),x2-x1);
        int h = max(long(0),y2-y1);
        
        return area - w*h;
    }
};