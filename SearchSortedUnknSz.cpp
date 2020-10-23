/*
Link : https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/
Given an integer array sorted in ascending order, write a function to search target in nums.  
If target exists, then return its index, otherwise return -1. However, the array size is unknown to you. 
You may only access the array using an ArrayReader interface, where ArrayReader.get(k) returns the element of the array at index k (0-indexed).

You may assume all integers in the array are less than 10000, and if you access the array out of bounds, ArrayReader.get will return 2147483647.

 

Example 1:

Input: array = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
Example 2:

Input: array = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
 

Constraints:

You may assume that all elements in the array are unique.
The value of each element in the array will be in the range [-9999, 9999].
The length of the array will be in the range [1, 10^4].
*/
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
    int binSearch(const ArrayReader& reader, int low, int high,int val){
        if(low > high)
            return -1;
        int mid = (low+high)/2;
        int x = reader.get(mid);
        if(x == val)
            return mid;
        if(x == 2147483647 or val < x)
            return binSearch(reader,low,mid-1,val);
        return binSearch(reader,mid+1,high,val);
    }
public:
    int search(const ArrayReader& reader, int target) {
        int low = 0;
        int high = 1;
        int ind = -1;
        while(true){
            ind = binSearch(reader, low, high, target);
            if(ind != -1)
                break;
            if(reader.get(high) > target)
                break;
            low = high + 1;
            high *= 2;
        }
        return ind;
    }
};
