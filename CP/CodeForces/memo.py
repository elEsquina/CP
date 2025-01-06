def main():
    input()
    S = input()
    T = input()
    freqS = [1 if i == 'A' else 0  for i in S]
    freqT = [1 if i == 'A' else 0  for i in T]

    if len(S) != len(T):
        print(-1)

    S = freqS; T = freqT
    count = 0
    for i in range(len(S)): 
        if T[i] == 0 and S[i] == 1:
            found = False
            for j in range(i, len(S)):
                if S[j] == 0 and T[j] == 1:
                    found = True
                    count += 1
                    freqS[j] = 2; freqS[i] = 2
                    freqT[j] = 2; freqT[i] = 2
                    break
                
        if S[i] == 0 and T[i] == 1:
            found = False
            for j in range(i, len(S)):
                if S[j] == 1 and T[j] == 0:
                    found = True
                    count += 1
                    freqS[j] = 2; freqS[i] = 2
                    freqT[j] = 2; freqT[i] = 2
                    break

            if not found: 
                print(-1)
                return

            
    print(count)
    

main()


