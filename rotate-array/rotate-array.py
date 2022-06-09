class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if k == 0:
            return
        length = len(nums)
        time = gcd(length,k)
        for i in range(time):
            new = (k+i)%length
            tempOld = nums[new]
            tempNew = 0
            nums[new] = nums[i]
            while new != i:
                new = (new+k)%length
                tempNew = nums[new]
                nums[new] = tempOld
                tempOld = tempNew
            
            
            
                        
        