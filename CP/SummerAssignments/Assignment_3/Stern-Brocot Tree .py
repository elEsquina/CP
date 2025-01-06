def result(inp) :
    test = [[0,1], [1,1], [1,0]]
    count = 0
    def add_el(position) :
        root_val_a = test[1][0]
        root_val_b = test[1][1]
        
        if position == 'R' : 
            a = test[2][0]
            b = test[2][1]
            new_val = [root_val_a+a , root_val_b+b]
            test[0] = test[1]
            
        else : 
            a = test[0][0]
            b = test[0][1]
            new_val = [root_val_a+a , root_val_b+b]
            test[2] = test[1]
        
        test[1] = new_val 
            
            
    while count != len(inp) :
        add_el(inp[count])
        count+=1
    return str(test[1][0]) + '/' +  str(test[1][1])

n = int(input())

for i in range(n) : 
    el = input()
    print(result(el))

