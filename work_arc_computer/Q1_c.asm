#(W+Y+Z)+(W+Y-Z)+(W-Y+Z)
#90

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
add $k1,$k0,$t4
add $gp,$t1,$t3 
sub $sp,$gp,$t4
sub $at,$t1,$t3
add $v0,$at,$t4
add $t5,$k1,$sp
add $t6,$t5,$v0

li $v0, 1
move $a0, $t6
syscall