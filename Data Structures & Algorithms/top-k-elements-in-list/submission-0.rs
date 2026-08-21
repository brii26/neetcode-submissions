impl Solution {
    pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let mut map: HashMap<i32,i32> = HashMap::new();
        let mut minheap = BinaryHeap::new();
        let n = nums.len();

        // create a hashmap freq -> occurance O(n)
        for i in 0..n {
            *map.entry(nums[i]).or_insert(0) += 1;
        }

        // create a minheap to store tuples of freq, num O(n)
        for (key, freq) in map.iter() {
            minheap.push(Reverse((freq,key)));
            if minheap.len() > k as usize {
                minheap.pop();
            }
        }

        // create a vector for return push all elements within heapmin , O(k)
        let mut result:Vec<i32> = Vec::new();
        for Reverse((_,num)) in minheap.iter() {
            result.push(**num);
        }

        result
    }
}
