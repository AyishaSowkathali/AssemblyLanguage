##########################################################################
# Ayisha S.R. Sowkathali, CS 2318-260, Assignment 2 Part 1 Program C
# Allocatea a global array enough for storing 3 integers, initializes the 
#  array and outputs the array elements
##########################################################################
			.data
intArr:			.word 1001, 2002, 3003
befSwap:			.asciiz "Array elements before swap: "
aftSwap:			.asciiz "Array elements after swap: "
			.text
			.globl main
main:				
			la $t0, intArr	# loads the array elements
			lw $t1, 0($t0)
			lw $t2, 4($t0)
			lw $t3, 8($t0)
			
			li $v0, 4		
			la $a0, befSwap
			syscall		
					# outputs the array before swap
			li $v0, 1
			move $a0, $t1
			syscall
			move $a0, $t2
			syscall
			move $a0, $t3
			syscall
				
			sw $t1, 8($t0)	# swaps the array elements
			sw $t2, 4($t0)
			sw $t3, 0($t0)
			
			li $v0, 11
			li $a0, '\n'
			syscall		# new line
			
			li $v0, 4
			la $a0, aftSwap
			syscall
			li $v0, 1
			lw $a0, 0($t0)
			syscall
			lw $a0, 4($t0)
			syscall
			lw $a0, 8($t0)
			syscall		# outputs array element after swap
			
			li $v0, 10	# graceful exit 
			syscall				
