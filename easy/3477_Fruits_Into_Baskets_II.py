class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        remainFruitTypes= 0

        for numFruits in fruits:
            for i in range(len(baskets)):
                if numFruits <= baskets[i]:
                    baskets[i] = 0
                    break
        
        remainFruitTypes = len(baskets) - baskets.count(0)

        return remainFruitTypes
