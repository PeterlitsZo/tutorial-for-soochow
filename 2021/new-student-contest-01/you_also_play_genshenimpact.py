atk = 0
atk_rate = 0
critical_hit = 50
ch_rate = 5

for _ in range(25):
    s = input().split('+')
    if s[0] == 'ATK':
        atk += float(s[1])
    elif s[0] == 'ATK Rate':
        atk_rate += float(s[1][:-1])
    elif s[0] == 'Crit Rate':
        ch_rate += float(s[1][:-1])
    elif s[0] == 'Crit DMG Rate':
        critical_hit += float(s[1][:-1])
atk = 1500*(1+atk_rate/100)+atk
ch_rate = min(ch_rate, 100)/100
ans = atk*(1-ch_rate)+ch_rate*(1+critical_hit/100)*atk
print(ans)

