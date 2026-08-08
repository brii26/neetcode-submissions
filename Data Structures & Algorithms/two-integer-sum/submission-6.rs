impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map = HashMap::new();
        let n = nums.len();

        for i in 0..n {
            let pair_need = target - nums[i];

            if let Some(&j) = map.get(&pair_need) {
                return vec![j,i as i32];
            }
            map.insert(nums[i], i as i32);
        }
        vec![]
    }
}
