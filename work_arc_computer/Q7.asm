.data
prompt: .asciiz  "\n\Entre com 10 numeros: " 
newLine: .asciiz "\n"                               
theString: .asciiz "           "                    

.text 
main:
    la $a0, prompt   
    li $v0, 4        
    syscall          

    la $a0,theString  
    li $a1,11        
    li $v0,8          
    syscall

    li $s7,10          

    jal uppercase  
    jal sort
    jal print
    j exit

uppercase:

    la $s0, theString    
    add $t6,$zero,$zero  



    lupper:
        beq $t6,$s7,done 

        add $s2,$s0,$t6 
        lb  $t1,0($s2)

        sgt  $t2,$t1,96
        slti $t3,$t1,123
        and $t3,$t2,$t3

        beq $t3,$zero,isUpper
        addi $t1,$t1,-32
        sb   $t1, 0($s2)

        isUpper:
        addi $t6,$t6,1
        j lupper
sort:   
    add $t0,$zero,$zero 

    loop:
        beq $t0,$s7,done

        sub $t7,$s7,$t0
        addi $t7,$t7,-1
        add $t1,$zero,$zero
 
        jLoop:
            beq $t1,$t7,continue

            add $t6,$s0,$t1
            lb  $s1,0($t6)
            lb  $s2,1($t6)

            sgt $t2, $s1,$s2

            beq $t2, $zero, good
            sb  $s2,0($t6)
            sb  $s1,1($t6)

            good:
            addi $t1,$t1,1
            j jLoop

        continue:
        addi $t0,$t0,1
        j loop

print:

    la $a0,newLine
    li $v0,4
    syscall 
    add $t6,$zero,$zero 

    lprint:
        beq $t6,$s7,done  

        add $t1,$s0,$t6 
        lb $a0, 0($t1)  
        li $v0, 11      
        syscall         

        addi $t6,$t6,1  
        j lprint
done:
    jr $ra
exit: