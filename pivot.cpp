class Solution {
public:
    int sumn(int n ){
        return n * (n+1)/2;
    }
    int pivotInteger(int n) {
        int total = sumn(n);
        for(int i =1;i<=n;i++){
            if(sumn(i) == (total- sumn(i) + i)){
                return i;
            }
        }
        return -1;
    }
};
