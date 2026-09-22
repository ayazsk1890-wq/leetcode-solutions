class Solution:
    def moveZeroes(self, nums: list[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # Tracks the position where the next non-zero element should go
        insert_pos = 0
        
        for i in range(len(nums)):
            if nums[i] != 0:
                # Swap the non-zero element to the insert position
                nums[insert_pos], nums[i] = nums[i], nums[insert_pos]
                insert_pos += 1
        