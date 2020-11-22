
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        len = mountainArr.length();
        t = target;
        int peakIndex = findPeak(mountainArr);
        if (m[peakIndex] == target) {
            return peakIndex;
        }
        int left = binary_search_left(mountainArr, 0, peakIndex - 1);
        if (left != -1) {
            return left;
        }
        int right = binary_search_right(mountainArr, peakIndex + 1, len - 1);
        if (right != -1) {
            return right;
        }
        return -1;
    }
private:
    int t;
    int len;
    unordered_map<int, int> m;
    int findPeak(MountainArray &mountainArr) {
        int left = 0;
        int right = len - 1;
        
        while (left <= right) {
            
            int mid = (left + right) / 2;
            if (mid == 0) return 1;
            if (mid == len - 1) return len - 2;
            int midValue = m.count(mid) ? m[mid] : mountainArr.get(mid);
            int leftValue = m.count(mid - 1) ? m[mid - 1] : mountainArr.get(mid - 1);
            int rightValue = m.count(mid + 1) ? m[mid + 1] : mountainArr.get(mid + 1);
            m[mid] = midValue; m[mid - 1] = leftValue; m[mid + 1] = rightValue;
            if (midValue > leftValue && midValue > rightValue) return mid;
            if (leftValue < midValue && midValue < rightValue) left = mid + 1;
            if (leftValue > midValue && midValue > rightValue) right = mid - 1;
        }
        
        return left;
    }
    
    int binary_search_left(MountainArray &mountainArr, int l, int r) {
        int left = l;
        int right = r;
        while (left <= right) {
            int mid = (left + right) / 2;
            int midValue = m.count(mid) ? m[mid] : mountainArr.get(mid);
            m[mid] = midValue;
            if (midValue == t) {
                return mid;
            }
            if (midValue > t) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
    
    int binary_search_right(MountainArray &mountainArr, int l, int r) {
        int left = l;
        int right = r;
        while (left <= right) {
            int mid = (left + right) / 2;
            int midValue = m.count(mid) ? m[mid] : mountainArr.get(mid);
            m[mid] = midValue;
            if (midValue == t) {
                return mid;
            }
            if (midValue < t) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};
