#!/usr/bin/tclsh
set MATRIX_FILE {random_matrix.txt}
set MATRIX_LENGTH 1000
set RAND_SIGNAL [list {} {-}]

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

proc rand_integer_negative {limit} {
	
}

set lst_opcoes {-9 -8 -7 -6 -5 -4 -3 -2 -1 0 1 2 3 4 5 6 7 8 9}
set lst_opcoes_rand [expr [llength $lst_opcoes] -1]
puts $lst_opcoes_rand

set channel [open $matrix_file w]
set i 0
while {$i < $matrix_length} {
#	puts -nonewline $channel " [lindex $RAND_SIGNAL [rand_integer 1]][rand_integer 9]"
	puts -nonewline $channel " [lindex $lst_opcoes [rand_integer $lst_opcoes_rand]]"
	incr i
}
