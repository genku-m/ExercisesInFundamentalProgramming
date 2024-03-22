def is_prime_number(n)
    if n - n.to_i != 0
        return false
    end
    if n < 2
        return false
    end
    if n == 2
        return true
    elsif n % 2 == 0 then
        return false
    else i = 3
        while i < Math.sqrt(n)
            if n % i == 0 then
                return false
            end
            i += 2
        end
        return true
    end
end
