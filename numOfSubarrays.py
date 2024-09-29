class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        if len(arr) < k:
            return 0
        else:
            count = 0
            left = 0
            subavg = sum(arr[0:k])/k
            right = k
            if subavg >= threshold:
                count += 1
            while right < len(arr):
                subavg -= arr[left]/k
                subavg += arr[right]/k
                if subavg >= threshold:
                    count +=1
                left+=1
                right+=1
            return count

        