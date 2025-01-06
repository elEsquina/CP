def solve():
    
    t = int(input())
    results = []
    
    for _ in range(t):
        n = int(input())
        m = int(input())
        k = int(input())
        
        heights = []
        for i in range(n):
            row = list(map(int, int(input())))
            heights.append(row)
        
        types = []
        for i in range(n):
            types.append(int(input()))
        
        sum_snowy = 0
        sum_non_snowy = 0
        
        for i in range(n):
            for j in range(m):
                if types[i][j] == '0':
                    sum_snowy += heights[i][j]
                else:
                    sum_non_snowy += heights[i][j]
        
        possible = False
        
        # Sliding window to check all submatrices of size k x k
        for start_row in range(n - k + 1):
            if possible:
                break
            
            snowy_row_sum = [0] * (m - k + 1)
            non_snowy_row_sum = [0] * (m - k + 1)
            
            # Compute initial row sums
            for j in range(m - k + 1):
                for l in range(k):
                    if types[start_row + l][j] == '0':
                        snowy_row_sum[j] += heights[start_row + l][j]
                    else:
                        non_snowy_row_sum[j] += heights[start_row + l][j]
            
            # Check all possible starting columns in the current row
            for start_col in range(m - k + 1):
                if possible:
                    break
                
                adjustment = (sum_non_snowy - sum_snowy) - \
                             (non_snowy_row_sum[start_col] - snowy_row_sum[start_col])
                
                if adjustment == 0:
                    possible = True
                    break
                
                for j in range(1, m - k + 1):
                    if types[start_row][start_col + j - 1] == '0':
                        snowy_row_sum[start_col + j] += heights[start_row][start_col + j + k - 1]
                    else:
                        non_snowy_row_sum[start_col + j] += heights[start_row][start_col + j + k - 1]
                    
                    if types[start_row + k - 1][start_col + j - 1] == '0':
                        snowy_row_sum[start_col + j] -= heights[start_row + k - 1][start_col + j - 1]
                    else:
                        non_snowy_row_sum[start_col + j] -= heights[start_row + k - 1][start_col + j - 1]
                    
                    adjustment = (sum_non_snowy - sum_snowy) - \
                                 (non_snowy_row_sum[start_col + j] - snowy_row_sum[start_col + j])
                    
                    if adjustment == 0:
                        possible = True
                        break
        
        if possible:
            results.append("YES")
        else:
            results.append("NO")
    
    print("\n".join(results))

