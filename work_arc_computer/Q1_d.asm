#w*(x+y)+w*(x+z)
#500          600   = 1100

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

add $k0,$t2,$t3
add $k1,$t2,$t4
mul $gp,$t1,$k0 
mul $sp,$t1,$k1
add $at,$gp,$sp


li $v0, 1
move $a0, $at
syscall