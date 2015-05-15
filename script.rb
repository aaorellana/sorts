def create_random_numfile(x)
File.open("nums.txt", 'w+') {|f| 
	for i in 1..x
		f.puts(rand(10000 + 1))
	end
	}
end

def main()
	out_string = ""
	out_string << create_out_string("insertionSort")
	out_string << create_out_string("selectionSort")
	out_string << create_out_string("bubbleSort")
	out_string << create_out_string("mergeSort")
	out_string << create_out_string("quickSort")
	insert_t(out_string)
	File.open("sorts.csv", 'w+') {|f|
		f.print(out_string)
	}
	
end


def create_out_string(sort_name)

string1 = ""

	(100..10000).step(100).each do |i|
	
		create_random_numfile(i)
		
		value1 = `./mainsorts #{sort_name} #{i} nums.txt`
		
		string1 << "#{value1}, "
		
	end	
	
	string1 << "\n"
	
	return string1
end

def insert_t(n)

	(0..10000).step(1000).each do |i|
	
		n << "#{i}, "
		for j in 1..9
			n << ", "
		end
		
	end	
	n << "\n"
	return n
end

=begin
def create_sort_file(sort_name)
string1 = ", "
string2 = ""
	(100..10000).step(100).each do |i|
	
		create_random_numfile(i)
		
		string1 << "#{sort_name}#{i}, "
		
		value1 = `./mainsorts #{sort_name} #{i} nums.txt`
		
		string2 << "#{value1}, "
		
	end	
	string1 << "\n"
	File.open("#{sort_name}.csv", 'w+') {|f|
	f.puts(string1)
	f.puts(string2)
	}
end
=end	
	
=begin	
string1 = ""
string2 = ""
	(100..10000).step(100).each do |i|
	
		create_random_numfile(i)
		
		string1 << "insertionSort#{i}, selectionSort#{i}, bubbleSort#{i}, quickSort#{i},  mergeSort#{i}, "
		
		value1 = `./mainsorts insertionSort #{i} nums.txt`
		value2 = `./mainsorts insertionSort #{i} nums.txt`
		value3 = `./mainsorts insertionSort #{i} nums.txt`
		value4 = `./mainsorts insertionSort #{i} nums.txt`
		value5 = `./mainsorts insertionSort #{i} nums.txt`
		
		string2 << "#{value1}, #{value2}, #{value3}, #{value4}, #{value5}, "
		
	end	
	string1 << "\n"
	File.open("sorts.csv", 'w+') {|f|
	f.puts(string1)
	f.puts(string2)
	}	
=end	