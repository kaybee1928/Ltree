a = open("out.txt", 'r')


b = a.readline()

c = 0
d = 0
for i in b:
    if("lol1" in i):
        c = c + 1
        d = max(d,c)
    else:
        # if(d==34):
        #     print(i)
        c = 0

print(d)

