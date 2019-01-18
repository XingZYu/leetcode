class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        map = {}
        for index, num in enumerate(nums):
            diff = target-num
            if diff in map:
                return [map[diff], index]
            map[num] = index
        return None
