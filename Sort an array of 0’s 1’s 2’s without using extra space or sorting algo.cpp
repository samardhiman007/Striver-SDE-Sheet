//Problem Statement
//Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

//We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

//You must solve this problem without using the library's sort function.

//Example 1:

//Input: nums = [2,0,2,1,1,0]
//Output: [0,0,1,1,2,2]
//Example 2:

//Input: nums = [2,0,1]
//Output: [0,1,2]




// Brute Force Solution just by counting the number of 0's , 1's and 2's and then firstly store 0 then 1 and then 2
// Time complexity would be O(N) and Space complexity O(1)

class Solution {
public:
    void sortColors(vector<int>& nums){
        int c1=0,c2=0,c3=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
                c1++;
             if(nums[i]==1)
                c2++;
            if(nums[i]==2)
                c3++;
        }
        
        int i=0;
        while(c1>0){
            nums[i++]=0;
            c1--;
        }
        
        while(c2>0){
            nums[i++]=1;
            c2--;
        }
        
        while(c3>0){
            nums[i++]=2;
            c3--;
        }
    }
};


// Optimized Solution 
// Slightly variant of Dutch National Flag Algorithm

class Solution {
public:
    void sortColors(vector<int>& nums){
     int low=0;
    int high=nums.size()-1;
    int mid=0;
        
    while(mid<=high){
            switch(nums[mid]){

                case 0: 
                    swap(nums[low++],nums[mid++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid],nums[high--]);
            }
             
        }
    
    }
    };

