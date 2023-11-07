class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        n=len(dist)
        l=[(dist[i]+speed[i]-1)//speed[i] for i in range(n)]
        l.sort()
        ans=0
        t=0
        for i in range(n):
            if l[i]-i>0:
                ans+=1
            else:
                break
        return ans
