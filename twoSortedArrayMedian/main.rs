impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let m:usize = nums1.len();
        let n:usize = nums2.len();

        println!("{m}");
        println!("{n}");

        let mut nums = Vec::with_capacity(m+n);

        for i in 0..m {
            nums[i] = nums1[i];
        }

        for i in 0..n {
            nums[(m-1+i)] = nums2[i];
        }

        let mut numsSum:i32 = 0;
        for i in 0..nums.len() {
            numsSum += nums[i];
        }

        return ((numsSum as f64)/((m+n) as f64));
    }
}