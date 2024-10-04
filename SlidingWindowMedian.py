import heapq
from heapq import heappush, heappop
from bisect import insort, bisect_left

class SlidingWindowMedian:
    def __init__(self):
        # Min heap for the right half
        self.min_heap = []
        # Max heap (inverted sign) for the left half
        self.max_heap = []

    def add_num(self, num):
        # Add to the max heap first
        if not self.max_heap or num <= -self.max_heap[0]:
            heappush(self.max_heap, -num)
        else:
            heappush(self.min_heap, num)
        
        # Balance the two heaps
        if len(self.max_heap) > len(self.min_heap) + 1:
            heappush(self.min_heap, -heappop(self.max_heap))
        elif len(self.min_heap) > len(self.max_heap):
            heappush(self.max_heap, -heappop(self.min_heap))
    
    def remove_num(self, num):
        # Remove num from either the max heap or the min heap
        if num <= -self.max_heap[0]:
            # Remove from max heap
            self.max_heap.remove(-num)
            heapq.heapify(self.max_heap)
        else:
            # Remove from min heap
            self.min_heap.remove(num)
            heapq.heapify(self.min_heap)

        # Balance the two heaps
        if len(self.max_heap) > len(self.min_heap) + 1:
            heappush(self.min_heap, -heappop(self.max_heap))
        elif len(self.min_heap) > len(self.max_heap):
            heappush(self.max_heap, -heappop(self.min_heap))

    def find_median(self):
        if len(self.max_heap) == len(self.min_heap):
            return (-self.max_heap[0] + self.min_heap[0]) / 2.0
        return -self.max_heap[0] * 1.0

class Solution:
    def medianSlidingWindow(self,nums, k):
        result = []
        sliding_window = SlidingWindowMedian()
        
        for i in range(len(nums)):
            sliding_window.add_num(nums[i])
            
            if i >= k - 1:
                result.append(sliding_window.find_median())
                sliding_window.remove_num(nums[i - k + 1])

        return result


