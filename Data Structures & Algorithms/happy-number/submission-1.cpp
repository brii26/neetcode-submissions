class Solution {
public:
    int iterateNum(int n, unordered_set<int>* seen) {
        int x = 0;
        while (n) {
            int temp = n%10;
            n/=10;
            x += (temp*temp);
        }
        if (seen->contains(x) || x == 1) {
            return x;
        }
        seen->insert(x);
        return iterateNum(x, seen);
    }

    bool isHappy(int n) {
        unordered_set<int> seen;
        seen.insert(n);
        return iterateNum(n, &seen) == 1;
    }
};
