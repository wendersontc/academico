.data
	vetor: .word 332,13,160,315,62,1,2,4,3,72
	lblMenor: .asciiz  "Menor valor:"
	lblMaior: .asciiz  "Maior valor:"	
	quebraLinha: .asciiz  "\n"
.text

li $t0, 0 #indice do meu array  i = 0
li $t1, 0 #maior posicao
li $t2, 0 #menor posicao
li $t3, 0 #contador
li $t4, 10 #quantidade de elementos do array
li $t5, 0 #valor do array

	lw $t2,vetor($t0)
	lw $t1,vetor($t0)
	
maior: addi $t2, $t5,0 #ok
menor: addi $t1, $t5,0 #ok
for: addi $t3,$t3,1
	lw $t5, vetor($t0)
     	addi $t0, $t0, 4
     	
     	blt $t2,$t5 maior
     	bgt $t1,$t5 menor
bne $t3, $t4 for
	
	#imprime menor
	li $v0,4
	la $a0,lblMenor
	syscall
	
	li $v0, 1
	move $a0, $t1
	syscall
	
	li $v0,4
	la $a0,quebraLinha
	syscall
	
	#imprime maior
	li $v0,4
	la $a0,lblMaior
	syscall
	
	li $v0, 1
	move $a0, $t2
	syscall


		

