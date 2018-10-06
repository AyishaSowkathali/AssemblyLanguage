##########################################################################
# Ayisha S.R. Sowkathali, CS 2318-260, Assignment 2 Part 1 Program D
##########################################################################
# Prompts the user to enter exam scores and calculated the weighted 
# average score usign the Formula: 
# avg score = (e1score*(410/2048))+(e2score*(256/853))+(finalscore/2)
##########################################################################
			.data
prompt1:			.asciiz "Enter Exam 1 score: "
prompt2:			.asciiz "Enter Exam 2 score: "
prompt3:			.asciiz "Enter Final Exam score: "
result:			.asciiz "Weighted Average score: "
newLine:			.asciiz "\n"
			.text
			.globl main
main:
			li $v0, 4
			la $a0, prompt1	# e1score prompt
			syscall
			li $v0, 5		
			syscall	
				
			move $t0, $v0	# $t0 has a copy of e1score
			li $t1, 410	# $t1 has 410
			mult $t0, $t1
			mflo $t2		# $t2 has e1score * 410		
			srl $t2, $t2, 11	# divide e1score*410/2048 
			
			li $v0, 4
			la $a0, prompt2	# e2score prompt
			syscall
			li $v0, 5		# read e2score
			syscall	
				
			move $t3, $v0	# $t3 has a copy of e2score	
			sll $t3, $t3, 8	# $ multiply e2score * 256
			li $t4, 853	# $t4 has 853
			div $t3, $t4
			mflo $t5		# $t5 has e2score*256/853

			li $v0, 4
			la $a0, prompt3	# final score prompt
			syscall
			li $v0, 5		# read final score
			syscall
			move $t6, $v0	# $t6 has a copy of final score	
			srl $t6, $t6, 1	# final score / 2
			
			add $v0, $t2, $t5 
			add $t9, $v0, $t6
			
			li $v0, 4
			la $a0, result	
			syscall
			move $a0, $t9
			li $v0, 1
			syscall		# weighted average displayed
					
			li $v0, 10
			syscall		# graceful exit
