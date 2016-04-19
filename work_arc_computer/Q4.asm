.data
	resultado: .word 0
	saida: .asciiz "\n Resultado:"
.text 

li $t0,2 #base
li $t1,5 #expoente
li $t2,0 #resultado1
li $t3,1 #contador1
li $t4,0 #contador2
li $t5,1 #contador3
li $t6,0 #total
li $t7,0 #aux2


beq $t0, $zero zero
beq $t1, $zero um


addi $t7,$t0,0
parte1:
	parte2:
	 add $t2,$t2,$t0 #T2 GUARDA O VALOR QUE SERA SOMADO
	 addi $t4,$t4,1
	bne $t4,$t7 parte2
	add $t7,$t2,0
	addi $t3,$t3,1
bne $t3,$t1 parte1


zero:
	add $t2, $t2, $zero
	j exit
um: 
	addi $t2, $zero, 1
	j exit

#saida
exit:
li $v0, 4
la $a0, saida
syscall

li $v0, 1
move $a0, $t2
syscall