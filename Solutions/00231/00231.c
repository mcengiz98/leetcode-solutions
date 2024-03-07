bool isPowerOfTwo(int n) {
    if(n==0)return false;
    if(n==1) return true;
    if(n<0) return false;
    if(n%2) return false;

    while(!(n & 0x1)){
        n = n >>  1;
        printf("%d\n",n);
    }
    if(n!=1)return false;
    
    return true;

}