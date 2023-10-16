# rotating twins problem

a = list(str(input("Enter a string\n")))
b = list(str(input("Enter a string\n")))

def rotatingtwins(a,b):
    if(len(a) != len(b)):
        return False
    else:
        for i in range(0,len(a)):
            c = []
            for j in range(i,len(a)):
                c.append(a[j])
            for k in range(0,i):
                c.append(a[k])
            if c == b:
                return True
        return False
print(rotatingtwins(a,b))
