class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        r=len(matrix)
        c=len(matrix[0])
        result=[[0]*r for _ in range(c)]
        
        for i in range(c):
            for j in range(r):
                result[i][j] = matrix[j][i]
                
        return result