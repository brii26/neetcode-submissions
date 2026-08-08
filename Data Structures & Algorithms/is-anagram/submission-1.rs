impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        let mut map = HashMap::new();

        for ch in s.chars() {
            *map.entry(ch).or_insert(0) += 1;
        }

        for ch in t.chars() { 
            if let Some(value) = map.get_mut(&ch) {
                *value -= 1;

                if *value == 0 {
                    map.remove(&ch);
                }

            } else { 
                return false;
            }
        }
        return  map.is_empty();
    }
}