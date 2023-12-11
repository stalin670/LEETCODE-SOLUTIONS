class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        cnt=1
        ans=1
        x=arr[0]
        for i in range(1,len(arr)):
            if arr[i]==arr[i-1]:
                cnt+=1
                if cnt>ans:
                    ans=cnt
                    x=arr[i-1]
            else:
                cnt=1
                    
        return x