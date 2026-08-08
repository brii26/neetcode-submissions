use std::collections::HashSet;

impl Solution {
    pub fn has_duplicate(nums: Vec<i32>) -> bool {
        let mut nums_set = HashSet::new();

        for num in &nums {
            if (nums_set.contains(num)) {
                return true;
            }
            nums_set.insert(num);
        }
        
        return false;
    }
}
