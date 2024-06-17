# problem statement (Arista Networks coding problem solution)
# Maximize the number of candies that can be bought
# You have N amount to spend
# A is the cost of candy with a plastic wrapper and B is the cost of candy with a paper wrapper
# The plastic wrapper can further be sold for some amount C

N = int(input("Enter the spending limit\n"))
A = int(input("Enter the price of the plastic wrapped candy\n"))
B = int(input("Enter the price of the paper wrapped candy\n"))
C = int(input("Enter the value of the plastic wrapper\n"))

def no_of_candy(N,A,B,C):
    count = 0
    if(A<B):
        while(N >= A):
            count+=1
            N = N - A + C
    elif(N-A+C > N-B):
        while(N >= A):
            count +=1
            N = N - A + C
        while(N >= B):
            count += 1
            N = N - B
    else:
       while(N >= B):
            count += 1
            N = N - B
    return count
print("Maximum number of candies that can be bought is "+str(no_of_candy(N,A,B,C))+"\n")
        
            
