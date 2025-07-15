        count, p, t = 0, len(players) - 1, len(trainers) - 1
        while t >= 0 and p >= 0:
            if players[p] <= trainers[t]:
                count += 1
                t -= 1
            p -= 1
        return count