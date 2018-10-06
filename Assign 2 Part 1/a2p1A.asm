##########################################################################
# Ayisha S.R. Sowkathali, CS 2318-260, Assignment 2 Part 1 Program A
##########################################################################
			.data

intPrompt:		.asciiz "Enter an integer: "
strPrompt:		.asciiz "Enter a string (up to 50 characters): "
charPrompt:		.asciiz "Enter a char: "
displayInt:		.asciiz "Integer entered: "
displayStr:		.asciiz "String entered: "		
displayChar:		.asciiz "Char entered: "
newLine:			.asciiz "\n"
buffer:			.space	51

			.text
			.globl main
main:			
			li $v0, 4
			la $a0, intPrompt
			syscall		# integer prompt
			li $v0, 5
			syscall		# integer read
			move $t0, $v0	# int copied to temp register
			li $v0, 4
			la $a0, displayInt
			syscall
			li $v0, 1
			move $a0, $t0	
			syscall		# integer displayed
			
			li $v0, 4
			la $a0, newLine
			syscall		# new line
			li $v0, 4
			la $a0, newLine
			syscall		# new line
				
			li $v0, 4
			la $a0, strPrompt	# string prompt
			syscall				
			li $v0, 8
			la $a0, buffer
			li $a1, 51	# string read
			syscall			
			li $v0, 4
			la $a0, newLine
			syscall		# new line		
			li $v0, 4
			la $a0, displayStr
			syscall
			la $a0, buffer
			syscall		# string displayed
			
			li $v0, 4
			la $a0, newLine
			syscall		# new line
			li $v0, 4
			la $a0, newLine
			syscall		# new line
			
			li $v0, 4
			la $a0, charPrompt
			syscall		# char prompt
			li $v0, 12
			syscall		# char read
			move $t0, $v0
			li $v0, 4
			la $a0, newLine
			syscall		# new line
			li $v0, 4
			la $a0, displayChar
			syscall
			li $v0, 11
			move $a0, $t0
			syscall
			li $v0, 4
			la $a0, newLine
			syscall		# new line
																				
			li, $v0, 10
			syscall		# graceful exit
