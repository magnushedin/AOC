def nbr_in_row(start_string, i):
    nbr = 1
    j = 1
    
    if i+j >= len(start_string):
        return str(1)
        
    while start_string[i] == start_string[i+j]:
        # print("i: {}, j: {}, nbr: {}".format(i, j, nbr))
        j += 1
        nbr += 1
        if (i+j) >= len(start_string):
            break
            
    return str(nbr)


start_string = "1113222113"
range_for_a = 40
range_for_b = 50

for i in range(range_for_b):
    print("--- Next iteration ({}) ---".format(i))
    result = ""
    i = 0
    while i < len(start_string):
        in_row = nbr_in_row(start_string, i)
        #print("{} in_row: {}".format(start_string[i], in_row))
        result += in_row
        result += str(start_string[i])
        #print("result: {}".format(result))
        i += int(in_row)
    
    start_string = result

# print(result)
print(len(result))
