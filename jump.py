def find_jumps(target):
    def backtrack(current, n, path):
        if current == target:
            return path
        if n > abs(target) * 2:
            return None
        path_right = backtrack(current + n, n + 1, path + [current + n])
        if path_right:
            return path_right
        path_left = backtrack(current - n, n + 1, path + [current - n])
        if path_left:
            return path_left
        return None

    return backtrack(0, 1, [0])