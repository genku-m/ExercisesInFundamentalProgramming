Pixel = Struct.new(:r, :g, :b)
$img = Array.new(200) do
  Array.new(300) do Pixel.new(255,255,255) end
end
def pset(x, y, r, g, b)
  if 0 <= x && x < 300 && 0 <= y && y < 200
    $img[y][x].r = r; $img[y][x].g = g; $img[y][x].b = b
  end
end
def writeimage(name)
  open(name, "wb") do |f|
    f.puts("P6\n300 200\n255")
    $img.each do |a|
      a.each do |p| f.write(p.to_a.pack("ccc")) end
    end
  end
end
def mypicture
  pset(100, 80, 255, 0, 0)
  writeimage("t.ppm")
end

def fillcircle(x0, y0, rad, r, g, b)
    200.times do |y|
      300.times do |x|
        if (x-x0)**2 + (y-y0)**2 <= rad**2
          pset(x, y, r, g, b)
        end
      end
    end
end

