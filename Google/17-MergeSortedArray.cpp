/*
 * Edge cases:
 * 1 - At most 1 vector can be empty
 * 2 - If one of them is already done, the merge should add the other array
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        int insert_pos = m + n - 1;

        // We only need to loop as long as there are elements in nums2
        while (p2 >= 0) {
            // If nums1 still has elements AND the current nums1 element is larger
            if (p1 >= 0 && nums1[p1] > nums2[p2]) {
                nums1[insert_pos--] = nums1[p1--];
            } else {
                // Either nums1 is empty, or nums2 has the larger (or equal) element
                nums1[insert_pos--] = nums2[p2--];
            }
        }
    }
};
