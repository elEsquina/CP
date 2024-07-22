def accepted(computers, t_bug):
    for i in range(len(computers[t_bug])):
        for j in range(i + 1, len(computers[t_bug])):
            if abs(computers[t_bug][i][0] - computers[t_bug][j][0]) % t_bug != 0:
                return False
    return True

def find_actual_year(case_number, bugs):
    computers = bugs
    for key in bugs:
        if not accepted(bugs, key):
            print(f"Case #{case_number}:\nUnknown bugs detected.\n")
            return

    max_ai = [max(comps, key=lambda x: x[1])[1] for comps in computers.values()]
    start_year = max(max_ai)

    found_year = None

    year = start_year
    while year < 10000:
        valid = True
        for comps in computers.values():
            for yi, ai, bi in comps:
                if (year - ai) % (bi - ai) + ai != yi:
                    valid = False
                    break
            if not valid:
                break

        if valid:
            found_year = year
            break
        year += 1

    if found_year is not None:
        print(f"Case #{case_number}:\nThe actual year is {found_year}.\n")
    else:
        print(f"Case #{case_number}:\nUnknown bugs detected.\n")

count = 1
while True:
    n = int(input().strip())
    if n == 0:
        break

    inputs = []
    for _ in range(n):
        x = list(map(int, input().strip().split()))
        inputs.append(x)

    bugs = {}
    for comp in inputs:
        diff = comp[2] - comp[1]
        if diff in bugs:
            bugs[diff].append(comp)
        else:
            bugs[diff] = [comp]

    find_actual_year(count, bugs)
    count += 1
