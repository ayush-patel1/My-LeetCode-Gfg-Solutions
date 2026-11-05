class Solution(object):
    def twoSum(self, nums, target):
        n = len(nums)

        arr = [(nums[i], i) for i in range(n)]
        arr.sort()

        l, r = 0, n - 1

        while l < r:
            sm = arr[l][0] + arr[r][0]

            if sm == target:
                return [arr[l][1], arr[r][1]]
            elif sm < target:
                l += 1
            else:
                r -= 1

        return []