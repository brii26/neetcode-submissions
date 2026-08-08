impl Solution {
    pub fn max_area(heights: Vec<i32>) -> i32 {
        let mut l = 0;
        let mut r = heights.len()-1;
        let mut ma = 0;

        while r > l {
            let mh = if heights[l] < heights[r] { heights[l] } else { heights[r] };
            let a = mh * (r-l) as i32;
            ma = if a > ma { a } else { ma };

            if heights[l] < heights[r] {
                l += 1;
            } else {
                r -=1;
            }
        }

        ma
    }
}
