def quadratic_formula(a,b,c)
    e = b**2 - 4*a*c
    if e < 0
        puts("実数解なし")
        exit
    end
    d = Math.sqrt(e)
    return (-b + d)/2.0*a, (-b - d)/2.0*a
end


def sum_and_product_of_roots(a,b,c)
    if b < 0
        a = -1*a
        b = -1*b
        c = -1*c
    end
    beta,alpha= quadratic_formula(a,b,c)
    beta = c/a/alpha
    return alpha,beta
end

