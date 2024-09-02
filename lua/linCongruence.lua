-- linear congruenial method thing
io.write("Enter the mod, multiplier, increment, and seed value: ")
local mod, mult, inc, seed = io.read('n', 'n', 'n', 'n')
print('\n')
io.write("Enter the number of times you'd like to loop: ")
local max = io.read('n')
local curr = 0

local vals = {}
vals[0] = seed;

for i=1, max do
    curr = ((mult*seed) + inc)%mod
    vals[i] = curr
    seed = curr
end

for j=0, max do
    print("x", j, "= ", vals[j])
end