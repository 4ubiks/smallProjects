# for a demo where recursion is explained to someone like they are five

def count_down(n):
    if n <= 0: 
        print("You've counted all the blocks!")
        return
    else:
        print("Blocks left: ", n)
        count_down(n - 1) 

block = 5
print("We have", block, "blocks")
count_down(block)