import time

def eratosthenis(possitive):
    start = time.time()
    new_array= list(range(2,possitive+1))
    #print(new_array)

    p=new_array[0]
    k=0
    while ((p**2) <= possitive):
        for j in reversed(new_array):
                
                
            if (((j % p)==0)and(j!=p)):
                
                new_array.remove(j)      
        k+=1
        p=new_array[k]
            
                
    
    #print(new_array)

    if new_array[-1]==possitive:
        print("prwtos")
    else:
        print("not prwtos")
    end = time.time()

    print("complited in:",end - start,"sec")
    del new_array
    del start
    del end

    return 0
######################################################


while True:
    try:
        
        i=input()
        i=int(i)
        if i<0:
            print("give possitive int")
            continue
        eratosthenis(i)
        break

    except ValueError:
        print("give possitive int")