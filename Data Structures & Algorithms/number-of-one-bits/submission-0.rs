impl Solution {
    pub fn hamming_weight(n: u32) -> i32 {
        let mut x = n;
        let mut count = 0;
        while x > 0 {
            if  x & 1 ==1 {
                count+=1;
            }
            x = x>>1;
        }
        count
    }
}
