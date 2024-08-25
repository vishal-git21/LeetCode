from itertools import product

def is_substring(small_str, candidates):
    for candidate in candidates:
        if small_str in candidate:
            return True
    return False

def smallestString(N, S):
    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    
    for length in range(1, 22):
        for candidate in product(alphabet, repeat=length):
            candidate_str = ''.join(candidate)
            if not is_substring(candidate_str, S):
                return candidate_str

N = int(input())
S = [input().strip() for _ in range(N)]

print(smallestString(N, S))

