total = ""
j = 1
while (len(total) <= 10 ** 15):
    total += str(j)
    j+=1
       
for i in range(int(input())):
    k = int(input())       
    final = str(total)[:k]
    final = int(final)
    ans = 0
    for j in range(len(str(final))):
        ans += int(str(final)[j])
    
    print(ans)
