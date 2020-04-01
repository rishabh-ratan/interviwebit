# interviwebit
interview bit codes
// [1,2,3] : [1,2,4] || [9,9,9] : [1,0,0,0] || [0,1,2,3] : [1,2,4]
vector<int> Solution::plusOne(vector<int> &A) {
    int n =A.size();
    vector<int>temp(n+1,0); //to deal if all elements are 9. ex : for [9,9] o/p : [1,0,0] which is temp with temp[0]=1.
    if(n==1 && A[0]==9){   //for [9] : [1,0]
        temp[0]=1;
        return temp;
    }
    A[n-1]=A[n-1]+1; //adding 1 to the last element of the the array. [1,2,3] : [1,2,3+1] : [1,2,4] 
    for(int i=n-1;i>0;i--){ //traversing from back to check if any element becomes 10 after adding 1.
        if(A[i]==10){ //if it's 10
            A[i-1]=A[i-1]+(A[i]/10); //the previous element will be added with the carry which is 1 in case of 10 (10/10==1)
            A[i]=A[i]%10; //the current element will become 0 as [9] : [1,"0"]
        }
    }
    if(A[0]==10){ //if the initial element is 10, it means all the elements were 9 so we can simply
        temp[0]=1; //take temp and initialise it's first element as 1. i.e for [9,9,9] : [1,0,0,0]
        return temp;
    }
    if(A[0]==0){ //if i/p array had leading zeroes it will be there in o/p so remove them.
    n=A.size();
    int c=0;
    for(int i=0;i<n;i++){
        if(A[i]!=0)
        break;
        c++;
    }
    A.erase(A.begin(),A.begin()+c); //removing leading 0s.
    }
    return A;
}
