require 'benchmark'


def gcd1(x,y)
    if x > y
        small = y
    else 
        small = x
    end
    small.downto(1) do |i|
        if x % i == 0 && y % i== 0 then  return i end
    end
end

def gcd2(x,y)
    while x != y do
        if x > y
            x = x-y
        else
            y= y-x
        end
    end
    return x
end
def gcd3(x,y)
    loop do
        if x > y
            x=x % y; if x == 0 then return y end
        else
            y=  y % x; if  y == 0 then return x end
        end
    end
end


time1 = Benchmark.realtime do
    (0...10_000).each { gcd1(rand(10000)+1,rand(10000)+1)}
  end
p time1

time2 = Benchmark.realtime do
    (0...10_000).each { gcd2(rand(10000)+1,rand(10000)+1)}
  end
p time2


time3 = Benchmark.realtime do
    (0...10_000).each { gcd3(rand(10000)+1,rand(10000)+1)}
  end
p time3