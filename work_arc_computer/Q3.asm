.text
#$t1 - a       #$t3 - x       #st5 - n        
#$t2 - b       #t4 - i

#1 1 2 3 5 8 13 21 34 55 89
li $t1,1
li $t2,1
li $t5,9

li $t4, 1
FOR:
beq $t5,$t4,END
add $t3,$t1,$t2
move $t1,$t2
move $t2,$t3
addi $t4,$t4,1
j FOR
END:

li $v0, 1
move $a0, $t1
syscall
