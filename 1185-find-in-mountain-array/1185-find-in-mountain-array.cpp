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
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        
        // Find the peak index using binary search.
        int peakIndex = findPeak(mountainArr, 0, n - 1);
        
        // Search in the increasing part of the mountain.
        int increasingIndex = binarySearchIncreasing(mountainArr, target, 0, peakIndex);
        if (increasingIndex != -1) {
            return increasingIndex;
        }
        
        // Search in the decreasing part of the mountain.
        int decreasingIndex = binarySearchDecreasing(mountainArr, target, peakIndex, n - 1);
        return decreasingIndex;
    }
    
private:
    int findPeak(MountainArray &mountainArr, int left, int right) {
        while (left < right) {
            int mid = left + (right - left) / 2;
            int midVal = mountainArr.get(mid);
            int nextVal = mountainArr.get(mid + 1);
            if (midVal < nextVal) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    
    int binarySearchIncreasing(MountainArray &mountainArr, int target, int left, int right) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midVal = mountainArr.get(mid);
            if (midVal == target) {
                return mid;
            } else if (midVal < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
    
    int binarySearchDecreasing(MountainArray &mountainArr, int target, int left, int right) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midVal = mountainArr.get(mid);
            if (midVal == target) {
                return mid;
            } else if (midVal < target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};
