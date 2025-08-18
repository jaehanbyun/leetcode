from typing import List

class SegmentTree:
    def __init__(self, data: List[int]):
        self.n = len(data)
        # 세그 트리를 편리하게 관리하기 위해 4*n 크기로 할당
        self.tree = [0] * (4 * self.n)
        self._build(1, 0, self.n - 1, data)

    def _build(self, node: int, l: int, r: int, data: List[int]):
        """초기 빌드: 리프에 data, 내부 노드에 자식 최대값을 저장"""
        if l == r:
            self.tree[node] = data[l]
        else:
            mid = (l + r) // 2
            self._build(node * 2, l, mid, data)
            self._build(node * 2 + 1, mid + 1, r, data)
            self.tree[node] = max(self.tree[node * 2], self.tree[node * 2 + 1])

    def query(self, node: int, l: int, r: int, x: int) -> int:
        """
        현재 노드가 표현하는 구간 [l..r] 안에서
        용량 >= x 인 바구니의 가장 왼쪽 인덱스를 반환.
        없으면 -1 반환.
        """
        if self.tree[node] < x:
            # 이 구간 전체에서 x를 수용할 바구니가 없음
            return -1
        if l == r:
            # 리프에 도달: 바로 이 바구니를 사용
            return l
        mid = (l + r) // 2
        # 왼쪽 자식에 먼저 충분한 용량이 있는지 확인
        idx = self.query(node * 2, l, mid, x)
        if idx != -1:
            return idx
        # 왼쪽 자식에 없다면 오른쪽 자식 탐색
        return self.query(node * 2 + 1, mid + 1, r, x)

    def update(self, node: int, l: int, r: int, pos: int, value: int):
        """
        인덱스 pos의 바구니 용량을 value로 변경.
        리프 갱신 후, 부모 노드의 최대값도 다시 계산.
        """
        if l == r:
            self.tree[node] = value
        else:
            mid = (l + r) // 2
            if pos <= mid:
                self.update(node * 2, l, mid, pos, value)
            else:
                self.update(node * 2 + 1, mid + 1, r, pos, value)
            self.tree[node] = max(self.tree[node * 2], self.tree[node * 2 + 1])


class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        n = len(fruits)
        seg = SegmentTree(baskets)
        unplaced = 0

        for f in fruits:
            # 용량 f 이상을 수용 가능한 가장 왼쪽 바구니 인덱스 찾기
            idx = seg.query(1, 0, n - 1, f)
            if idx == -1:
                # 놓을 바구니가 없음
                unplaced += 1
            else:
                # 바구니를 사용했으므로 용량을 0으로 업데이트
                seg.update(1, 0, n - 1, idx, 0)

        return unplaced
