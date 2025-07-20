class Solution:
    def minFlips(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])

        # Convert starting matrix to bitmask. Early return if start state is zero matrix
        start_state = 0
        for row in range(m):
            for col in range(n):
                if mat[row][col]:
                    start_state |= 1<<(m - 1 - row) * n + (n - 1 - col)
        if start_state == 0:
            return 0

        # Get a bitmask for each operation, centered on cell [row][col]
        transitions = []
        for curr_row in range(m):
            for curr_col in range(n):
                transition = 0
                for row_d, col_d in [(0,0),(-1,0), (0, 1), (1, 0), (0, -1)]:
                    if 0 <= curr_row + row_d < m and 0 <= curr_col + col_d < n:
                        transition |= 1 << ((m - 1 - (curr_row + row_d)) * n) + (n - 1 - (curr_col + col_d))
                transitions.append(transition)
      
        # Typical Djikstas. Keep track of number of ops performed and for each sate, 
        # perform and push all transition ops. Return num ops if we find a 
        # zero matrix state. Otherwise default: -1
        queue = collections.deque()
        queue.append((0, start_state))
        seen = {start_state}
        while queue:
            curr_ops, curr_state = queue.popleft()
            for transition in transitions:
                new_state = curr_state ^ transition
                if new_state == 0:
                    return curr_ops + 1
                if new_state not in seen:
                    seen.add(new_state)
                    queue.append((curr_ops + 1, new_state))
        
        return -1