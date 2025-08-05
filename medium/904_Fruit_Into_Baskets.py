# class Solution:
#     def totalFruit(self, fruits: List[int]) -> int:
#         maxFruits = 0
#         lenFruits = len(fruits)

#         for i in range(lenFruits):
#             baskets = set()
#             curFruits = 0

#             for j in range(i, lenFruits):
#                 fruit = fruits[j]
#                 if fruit in baskets or len(baskets) < 2:
#                     baskets.add(fruit)
#                     curFruits += 1
#                 else:
#                     break

#             maxFruits = max(curFruits, maxFruits)

#         return maxFruits

class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        maxFruits = 0
        lenFruits = len(fruits)
        baskets = dict()
        end = -1

        for i in range(lenFruits):
            while end < lenFruits - 1:
                nextFruit = fruits[end + 1]

                if len(baskets) >= 2 and nextFruit not in baskets :
                    break
                
                end += 1
                baskets[nextFruit] = baskets.get(nextFruit, 0) + 1

            maxFruits = max(maxFruits, end - i + 1)

            baskets[fruits[i]] -= 1
            if baskets[fruits[i]] == 0:
                del baskets[fruits[i]]

        return maxFruits

