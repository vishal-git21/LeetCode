class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        i = 0
        l = []
        while i < len(prices)-1:
            if prices[i] <= prices[i+1]:
                l.append([prices[i],prices[i+1]])
            i+=1
        k = 0
        while k < len(l)-2:
            if l[k+1][1] - l[k][0] >= l[k+1][1] - l[k+1][0] + l[k][1] - l[k][0]:
                l[k][1] = l[k+1][1]
                l.pop(k+1)

            k+=1
        sum = 0
        for i in l:
            print(i)
            sum += i[1]-i[0]
        return sum
