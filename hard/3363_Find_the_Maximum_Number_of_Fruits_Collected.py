from typing import List

class Solution:
    def maxCollectedFruits(self, fruits: List[List[int]]) -> int:
        n = len(fruits)
        NEG = -10**15               # 음의 무한대

        # 1) 1번 아이 : 주대각선 합
        diag = sum(fruits[i][i] for i in range(n))

        # 2) 대각선 셀은 0으로 만들어 2·3번 아이에게 중복 계산되지 않도록 함
        g = [row[:] for row in fruits]
        for i in range(n):
            g[i][i] = 0

        # ---------- 2번 아이 (위→아래) ----------
        dp2 = [[NEG] * n for _ in range(n)]
        dp2[0][n - 1] = g[0][n - 1]                 # 시작점
        for i in range(1, n):
            for j in range(n):
                best = max(
                    dp2[i - 1][j],                  # 바로 위
                    dp2[i - 1][j - 1] if j > 0 else NEG,
                    dp2[i - 1][j + 1] if j + 1 < n else NEG,
                )
                if best != NEG:
                    dp2[i][j] = best + g[i][j]

        # ---------- 3번 아이 (왼→오) ----------
        dp3 = [[NEG] * n for _ in range(n)]
        dp3[n - 1][0] = g[n - 1][0]                 # 시작점
        for j in range(1, n):
            for i in range(n):
                best = max(
                    dp3[i][j - 1],                  # 바로 왼
                    dp3[i - 1][j - 1] if i > 0 else NEG,
                    dp3[i + 1][j - 1] if i + 1 < n else NEG,
                )
                if best != NEG:
                    dp3[i][j] = best + g[i][j]

        # ---------- 결과 ----------
        return diag + dp2[n - 1][n - 1] + dp3[n - 1][n - 1]
