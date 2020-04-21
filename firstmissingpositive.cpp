/*
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
Note:

Your algorithm should run in O(n) time and uses constant extra space.
*/



class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        auto it = find(nums.begin(),nums.end(),1);    //if 1 is not present in the array it will be the smallest positive.
        if(it==nums.end())
            return 1;
        if(n==1){
            if(nums[0]==1)    //if-> [1] ans : 2 so if there's only 1 return 1+1 = 2
                return 2;
        }
        for(int i=0;i<n;i++){   //MAKE SURE THERE IS NO NEGATIVE AND >ARRAY SIZE ELEMENTS SO THAT WE CAN REACH THE INDICES.
            if(nums[i]>n || nums[i]<=0)
                nums[i]=1;
        }
        for(int i=0;i<n;i++){
            if(abs(nums[i])==n)  //IF THE ELEMENT IS N SO THERE IS NO INDEX SO VISIT 0th ELEMENT.
                nums[0] = abs(nums[0]) * -1;
            else
                nums[abs(nums[i])] = abs(nums[abs(nums[i])]) * -1; //NEGATE AND MARK
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i]>0)
                return i;
        }
        if(nums[0]>0)
            return n;
        return n+1;
    }
};
