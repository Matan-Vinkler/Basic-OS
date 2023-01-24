; Print text:
print:
    pusha

; while(str[i] != 0) { print str[i]; i++; }

start:
    mov al, [bx]
    cmp al, 0
    je done

    mov ah, 0x0E
    int 0x10

    inc bx
    jmp start

done:
    popa
    ret


;Print hex numbers:
print_hex:
    pusha
    mov cx, 0

hex_loop:
    cmp cx, 4
    je end

    mov ax, dx
    and ax, 0x00F
    add al, 0x30
    cmp al, 0x39
    jle step2
    add al, 7

step2:
    mov bx, HEX_OUT + 5
    sub bx, cx
    mov [bx], al
    ror dx, 4

    inc cx
    jmp hex_loop

end:
    mov bx, HEX_OUT
    call print

    popa
    ret

HEX_OUT:
    db '0x0000', 0x0A, 0x0D, 0