-- 'figure out how many binary numbers of length 'n' there are with a pair of consecutive zeros'
-- this program was written for one specific problem in my discrete mathematics homework. 
-- i got bored, lol. 

io.write("enter your 'n': ")
local n = io.read('n')
local num = {}
local tot = 0

-- the first two numbers have to be zero, because they do
num[0]=0 
num[1]=0

for i=0, n-2 do
    tot = (num[i] + num[i+1] + 2^i)
    num[i+2] = (num[i] + num[i+1] + 2^i)
    print(tot)
end

print("there are ", tot, " possible combinations with bit strings of length ", n)