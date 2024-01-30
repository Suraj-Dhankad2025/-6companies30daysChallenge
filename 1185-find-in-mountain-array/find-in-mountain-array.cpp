/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &a) {
        int s = 0;
        int len = a.length()-1;
        int e = len;
        int ans=-1;
        int peakInd=-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            int ele = a.get(mid);
            int r = a.get(mid+1);
            if(ele<r){
                peakInd = s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        s=0;
        e = peakInd;
        while(s<=e){
            int mid = s + (e-s)/2;
            int ele = a.get(mid);
            if(ele==target){
                return mid;
            }
            if(ele<target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        s=peakInd+1;
        e = len;
        while(s<=e){
            int mid = s + (e-s)/2;
            int ele = a.get(mid);
            if(ele==target){
                return mid;
            }
            if(ele<target){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};