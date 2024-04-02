def remove_char_at(s, n):
    if n < 0 or n >= len(s):
        return "Index out of range"
    
    result = ''
    for i in range(len(s)):
        if i != n:
            result += s[i]
    return result

