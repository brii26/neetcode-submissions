impl Solution {
    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut new_nums = nums.clone();
        new_nums.sort();
        let mut result = Vec::new();
        let n = new_nums.len();
        for i in 0..n-2 {
            if i > 0 && new_nums[i] == new_nums[i-1] {
                continue;
            }
            let mut l = i+1;
            let mut r = n-1;

            while r > l {
                let sum = new_nums[i] + new_nums[l] + new_nums[r];
                if sum < 0 {
                    l+=1;
                } else if sum > 0 {
                    r-=1;
                } else {
                    result.push(vec![new_nums[i], new_nums[l], new_nums[r]]);

                    while r > l && new_nums[r] == new_nums[r-1] {
                        r-=1;
                    }

                    while r > l && new_nums[l] == new_nums[l+1] {
                        l+=1;
                    }
                    r-=1;
                    l+=1;
                }      
            }
        }
        result
    }
}
