class Solution:
    def minCost(self, nums: List[int]) -> int:
        n = len(nums)
        distinct = sorted(set(nums))
        m = len(distinct)
        idx = {x: i for i, x in enumerate(distinct)}
        INF = 10**18
        dp = [[INF]*(m+1) for _ in range(n+1)]
        dp[n][m] = 0
        for k in range(m):
            dp[n][k] = distinct[k]
        for i in range(n-1, -1, -1):
            r = n - i
            if r == 1:
                dp[i][m] = nums[i]
            elif r == 2:
                dp[i][m] = max(nums[i], nums[i+1])
            else:
                dp[i][m] = min(
                    max(nums[i], nums[i+1]) + dp[i+3][idx[nums[i+2]]],
                    max(nums[i], nums[i+2]) + dp[i+3][idx[nums[i+1]]],
                    max(nums[i+1], nums[i+2]) + dp[i+3][idx[nums[i]]]
                )
            for k in range(m):
                c = distinct[k]
                if r == 0:
                    dp[i][k] = c
                elif r == 1:
                    dp[i][k] = max(c, nums[i])
                else:
                    dp[i][k] = min(
                        max(c, nums[i]) + dp[i+2][idx[nums[i+1]]],
                        max(c, nums[i+1]) + dp[i+2][idx[nums[i]]],
                        max(nums[i], nums[i+1]) + dp[i+2][k]
                    )
        return dp[0][m]
