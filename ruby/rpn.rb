$val = []
$his = []
$backup = []
def e(x)
    $backup = $val.dup;$val.push(x); $his.push(x);return $val
end
def add
    $backup = $val.dup;y = $val.pop;x =$val.pop;$val.push(x+y); $his.push("+");return $val
end
def mul
    $backup = $val.dup; y = $val.pop;x =$val.pop;$val.push(x*y); $his.push("×");return $val
end
def clear
    $backup = $val.dup;$val = [];$his.push("clear");return $val
end
def sub
    $backup = $val.dup;y = $val.pop;x =$val.pop;$val.push(x-y);$his.push("-");return $val
end
def div
    $backup = $val.dup; y = $val.pop;x =$val.pop;$val.push(x/y);$his.push("÷");return $val
end
def mod
    $backup = $val.dup;y = $val.pop;x =$val.pop;$val.push(x%y);$his.push("%");return $val
end
def inv
    $backup = $val.dup; x = $val.pop;$val.push(-x);$his.push("inv");return $val
end
def exch
    $backup = $val.dup;x = $val.pop;y = $val.pop;$val.push(x);$val.push(y);$his.push("exchange");return $val
end
def show
    return $his.join(" ")
end
def cancel
    i = $val.dup;$val = $backup.dup;$backup= i;$his.push("cancel");
    return $val
end 
def addall
    $backup = $val.dup
    t = 0
    $val.each do |i|
        t = t+ i
    end
    $val = [];$val.push(t)
    return $val
end