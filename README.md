# interviwebit
interview bit codes
vector<int> Solution::plusOne(vector<int> &A) {
    int n =A.size();
    vector<int>temp(n+1,0);
    if(n==1 && A[0]==9){
        A[0]=A[0]+1;
        temp[0]=1;
        return temp;
    }
    A[n-1]=A[n-1]+1;
    for(int i=n-1;i>0;i--){
        if(A[i]==10){
            A[i-1]=A[i-1]+(A[i]/10);
            A[i]=A[i]%10;
        }
    }
    if(A[0]==10){
        temp[0]=1;
        return temp;
    }
    if(A[0]==0){
    n=A.size();
    int c=0;
    for(int i=0;i<n;i++){
        if(A[i]!=0)
        break;
        c++;
    }
    A.erase(A.begin(),A.begin()+c);
    }
    return A;
}
