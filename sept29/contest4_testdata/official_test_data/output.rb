name = "periodni"
files = Dir["**/#{name}/#{name}.in.*"];
p "Merging #{files.size} files"
input = File.open("#{name}/input.in", "w+") do |f|
  f.write(files.size)
  f.write("\n")
  files.each do |inp|
    f.write(File.read(inp))
  end
end

other = Dir["**/#{name}/#{name}.in.*"];
p "Merging #{other.size} files as output"
output = File.open("#{name}/output.out", "w+") do |f|
  other.each do |out|
    f.write(File.read(out))
  end
end
