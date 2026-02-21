-- Demo for Liberty University Software Development Club
-- Introduction to Lua

-- comment code: Ctrl+K, Ctrl+C
-- uncomment code: Ctrl+K, U

-- Basic prints
    io.write("Hello world!")
    print("Hello world!")
    print("io.write():")
    for i=1, 5 do
        io.write(i)
    end

    print("\n\nprint():")
    for i=1, 5 do
        print(i)
    end


-- variables
    firstVar = 1
    local secondVar = 2

    -- '..' vs '+'
    print(1 + "1")

    local append = "1"
    append = append .. "1"
    print(append)

-- Read in values
    io.read("n") -- numeral as int
    io.read("a") -- entire file
    io.read("l") -- line, skipping end of line
    io.read("L") -- line, including end of line

    io.write("Read in value: ")
    local literal = io.read()

    io.write("Read in value: ")
    local intread = io.read("n")

    print(literal .. " with io.read() is: " .. type(literal))
    print(intread .. " with io.read('n') is " .. type(intread))


-- Conditional Statements

    -- if, else
    if secondVar == 2 then
        print("two equals two")
    end

    -- if [condition] then
    --     code
    -- end

    while (True == True) do
        print("false")
    end

    while (1 ~= 2) do
        print("not equal")
    end

-- Tables
    local array = {"element", "of", "array"}
    for v=1, #array do
        print(array[v])
    end

    local dict = {
        ['man'] = "moon",
        ['fish'] = "out of water",
        ['LDA'] = "03"
    }

    for k,v in pairs(dict) do
        print(k, v)
    end


-- Graphs

    local graph = {
        A = {"B", "C"},
        B = {"A", "D", "E"},
        C = {"A", "F"},
        D = {"B"},
        E = {"B", "F"},
        F = {"C", "E"}
    }

    for k,v in pairs(graph) do
        print(k)
    end

    local graphKeys = {}
    for k in pairs(graph) do
        table.insert(graphKeys, k)
    end

    table.sort(graphKeys)

    for _, key in ipairs(graphKeys) do
        print(key)
    end

    function depthFirst(graph, node, visited)
        if visited[node] then return end
        visited[node] = true
        print(node)

        for _, neighbor in pairs(graph[node]) do
            depthFirst(graph, neighbor, visited)
        end
    end

    local visited = {}
    depthFirst(graph, "A", visited)
