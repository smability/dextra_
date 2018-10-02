#python3.x

from random import randint

#board initial modes
def boardInitialSTATE():
    STATE = [0, 1, -1]
    mode = randint(0, 2)
    return STATE[mode]

def genericboard(n,m,k):
    
    #non positive number detection
    if (n or m or k) < 0:
        print('Please input positive numbers')
        return 
   
    print('number of balls: ',k)
    print('board size: ',n,'x',m)
    print('Switch ball board initial states: ')
    
    #board matrix; n=x=j=columns m=y=i=rows,
    b = [[0 for x in range(n)] for y in range(m)] 
    
    for i in range(len(b)): # i = rows
        for j in range(len(b[i])):#j = columns
            b[i][j] = boardInitialSTATE();#board state
            print(b[i][j], end = " ")  #default ends in a new line
            if (j==n-1): 
                print("")
    
    #assign m and n, rows and columns value, to rows and columns variables
    rows = m
    columns = n
    
    #board initial conditions
    m = 0
    n = 0
    count = 0 #ball counter 
    right = 0 #in case first element of matrix b is zero
    
    #board algorithm m=y=rows,n=x=columns, k = number of balls
    while k > 0: #k is ball number
        if b[m][n] == 1:
            
            right = 1 #set right flag to 1

            b[m][n] = -1 #change board state
          
            n+=1 #move ball to right (next column)
            
            #right-button edge counter
            if (n == columns-1) and (m == rows): 
                    count+=1 #ball exit-counter
            
            #ball leaving the board
            if (n == columns) or (m == rows): 
                k-=1     #ball leaves the board
                n = 0   #new start at 0,0
                m = 0
            
        elif b[m][n] == -1:
            
            right = 0 #set right flag to zero

            b[m][n] = 1#change board state
            
            m+=1 #move ball down (next row)
            
            #right-button edge counter
            if (n == columns-1) and (m == rows): 
                    count+=1 #ball exit-counter
            
            #ball leaving the board
            if (n == columns) or (m == rows): 
                k-=1    #ball leaves the board
                n = 0   #new start at 0,0
                m = 0
        
        elif b[m][n] == 0: #missing condition if element of first location is 0
        
            if right == 1:
                n+=1 #continue moving to the right
            else:
                m+=1 #continue moving down, continue moving down if 0,0 = 0
                
            #right-button edge counter
            if (n == columns-1) and (m == rows): 
                    count+=1 #ball exit-counter
            
            #ball leaving the board
            if (n == columns) or (m == rows): 
                k-=1    #ball leaves the board
                n = 0   #new start at 0,0
                m = 0
        else:
            print('invalid state!')
            break
        
    print('Switch ball board final states: ')
    
    for i in range(len(b)): # i = rows
        for j in range(len(b[i])):#j = columns
            print(b[i][j], end = " ")  #default ends in a new line
            if (j==columns-1): 
                print("")

    return count
    
#numberofballs is the board switch ball output
numberofballs = genericboard(1,1,3) #genericboard(columns,rows,balls)

print('balls leaving right-bottom edge = ', numberofballs) 
