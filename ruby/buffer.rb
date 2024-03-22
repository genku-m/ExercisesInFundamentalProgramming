class Buffer
    Cell = Struct.new(:data, :next)
    def initialize
      @tail = @cur = Cell.new("EOF", nil)
      @head = @prev = Cell.new("", @cur)
    end
    def atend
      return @cur == @tail
    end
    def top
      @prev = @head; @cur = @head.next
    end
    def forward
      if atend then return end
      @prev = @cur; @cur = @cur.next
    end
    def insert(s)
      @prev.next = Cell.new(s, @cur); @prev = @prev.next
    end
    def print
      puts("  " + @cur.data)
    end
    def delete
        if atend then return end
        @cur = @prev.next = @cur.next
    end
  end