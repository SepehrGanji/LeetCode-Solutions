class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        def area_below(y, squares):
            total = 0.0
            for xi, yi, li in squares:
                h = min(max(y - yi, 0), li)
                total += li * h
            return total
        total_area = sum(li * li for _, _, li in squares)
        target = total_area / 2.0
        lo = min(yi for _, yi, _ in squares)
        hi = max(yi + li for _, yi, li in squares)
        eps = 1e-5
        while hi - lo > eps:
            mid = (lo + hi) / 2.0
            if area_below(mid, squares) < target:
                lo = mid
            else:
                hi = mid
        return lo
        
