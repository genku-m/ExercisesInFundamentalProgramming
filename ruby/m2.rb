class Memory
    def initialize
      @mem = nil
    end
    def put(x)
      @mem = x
    end
    def get
      return @mem
    end
end

class Concat
  def initialize
    @str = ""
  end
  def add(x)
    @str = @str + x
  end
  def get
    return @str
  end
  def reset
    @str = ""
  end
end
