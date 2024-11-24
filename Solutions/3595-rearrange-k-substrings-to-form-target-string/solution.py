class Solution:
    def isPossibleToRearrange(self, s: str, t: str, k: int) -> bool:
        if k == 1:
            return s == t
        n = len(s) // k
        s_substrings = [s[i:i+n] for i in range(0, len(s), n)]
        t_substrings = [t[i:i+n] for i in range(0, len(t), n)]
        return sorted(s_substrings) == sorted(t_substrings)
