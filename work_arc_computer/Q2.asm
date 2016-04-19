li $t0,0
li $t1,5 #valor do indice do fatorial
li $t2,0
li $t3,1
li $t4,1

.data
	resultado: .word 0
	 saida: .asciiz  "Resultado:"
.text

beq $t1, $t0 exit

x: addi $t0,$t0,1
	mul $t3,$t3,$t4 
	addi $t4,$t0,1		
bne $t0,$t1 x

sw $t0,resultado
j quit
exit: addi $t3, $zero, 1
quit:

#saida
li $v0, 4
la $a0, saida
syscall


li $v0, 1
move $a0, $t3
syscall


