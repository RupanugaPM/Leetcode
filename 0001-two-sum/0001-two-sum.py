class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums1=list(nums)
        nums1.sort()
        l=0
        r=len(nums1)-1
        while l<r:
            if nums1[l]+nums1[r]==target:
                k=nums1[l]
                m=nums1[r]  
                x=nums.index(k)
                if(k==m):
                    return [x,list(nums[x+1:]).index(m)+x+1]
                return [x,nums.index(m)]
            elif nums1[l]+nums1[r]>target:
                r=r-1
            else:
                l=l+1