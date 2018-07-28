#!/usr/bin/tclsh
set MATRIX_FILE {random_matrix.txt}
set MATRIX_LENGTH 1000
set ::RAND_SIGNAL(0) {}
set ::RAND_SIGNAL(1) {-}
set ::RAND_VALUE(0) 9
set ::RAND_VALUE(1) 8

puts "What is the name of file (default: $MATRIX_FILE)"
gets stdin matrix_file

puts "What is the length of matrix (default: $MATRIX_LENGTH)"
gets stdin matrix_length

#TODO: validate negative values!

foreach {var default} {matrix_file MATRIX_FILE matrix_length MATRIX_LENGTH} {
	if "[string trim $$var] == {}" {
		eval set $var $$default
	}
}

puts "Your choise:"
puts $matrix_file
puts $matrix_length

proc rand_integer {limit} {
	return [string index [expr rand() * $limit] 0]
}

proc rand_integer_signal {} {
	set bit [expr rand() > 0.5]
	return $::RAND_SIGNAL($bit)[expr [rand_integer $::RAND_VALUE($bit)] + $bit]
}

set channel [open $matrix_file w]

for {set i 0} {$i < $matrix_length} {incr i} {
	set line ""
	for {set j 0} {$j < $matrix_length} {incr j} {
		append line "[rand_integer_signal] "
	}
	puts $channel [string trimright $line]

}

