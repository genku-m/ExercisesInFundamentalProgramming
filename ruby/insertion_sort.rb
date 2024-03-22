def insertionsort (n)
    1.step(n.length-1) do |i|
        x= n[i]
        k=shifrlager(n,i,x)
        n[k]= x
    end
    return n
end

def shifrlager(n,i,x)
    while i > 0 && n[i-1] > x do n[i] =n[i-1]
        i=i-1
    end
    return i
end