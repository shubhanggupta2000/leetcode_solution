    for word in words2:
        if seen.get(word, None) != None:
            seen[word] -= 1

    res = 0
    for item in seen:
        if seen[item] == 0:
            res += 1

    return res
    `