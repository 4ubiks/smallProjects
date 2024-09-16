-- prints the sum of 'n' times each natural number. stops when the sum is greater than 'intStop'
-- used to help find a recursive solution in discrete mathematics

io.write("Enter number to multiply x integers by: ")
local base = io.read('n')

io.write('\nEnter the integer to stop at: ')
local intStop = io.read('n')

for i=0, intStop do
    io.write("\n7 times ", i, "= ")
    io.write(i * base)
    if (i * base) > intStop then
        break
    end
end