impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut map: HashMap<[i32;26], i32> = HashMap::new();
        let mut groups: Vec<Vec<String>> = vec![];
        for str in strs{
            let mut arr = [0;26];
            for ch in str.bytes() {
                arr[(ch - b'a') as usize] += 1;
            }
            if let Some(&z) = map.get(&arr) {
                groups[z as usize].push(str);
            } else {
                let index = groups.len();
                groups.push(vec![str]);
                map.insert(arr, index as i32);
            }
        }
        groups
    }
}
