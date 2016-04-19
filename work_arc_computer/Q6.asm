.data
	vetorA: .word 10, 45, 5, 8, 7, 100, 20, 1, 1, 1
	
.text
li $t0, 0 #indice array A
li $t1, 0 #contador 1
li $t2, 10 #tamanho total dos vetores
li $t3, 0 #valor do array A
li $t4,0
for:
	lw $t3, vetorA($t0)
	addi $t0, $t0, 4
	addi $t1, $t1, 1
	add $t4, $t3, $t4
	
bne $t1,$t2 for

div $t4,$t2

mflo $s3

#MEDIA
li $v0, 1
move $a0, $s3
syscall