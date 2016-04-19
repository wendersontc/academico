#[(w+x)-(y+z)]*w

.data

w: .word 10
x: .word 20
y: .word 30
z: .word 40

.text

lw $t1,w 
lw $t2,x 
lw $t3,y 
lw $t4,z 

add $k0,$t1,$t2
add $k1,$t3,$t4
sub $gp,$k0,$k1 
mul $t5,$gp,$t1

li $v0, 1
move $a0, $t5
syscall