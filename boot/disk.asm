disk_load:
    pusha

    push dx

    mov ah, 0x02   ; ah = operation read
    mov al, dh     ; al = number of sectors to read
    mov cl, 0x02   ; cl = the second sector
    mov ch, 0x00   ; ch = cylinder 0
                   ; dl = drive number (get it from BIOS; 0 = floppy, 1 = floppy2, 0x80 = hdd, 0x81 = hdd2)
    mov dh, 0x00   ; dh = head number

                   ; es:bx = pointer to buffer where the data will be stored

    int 0x13
    jc disk_error

    pop dx
    cmp al, dh
    jne sectors_error

    popa
    ret

disk_error:
    mov bx, DISK_ERROR
    call print
    mov dh, ah     ; ah = error code, dl = disk drive that dropped the error
    call print_hex
    jmp disk_loop

sectors_error:
    mov bx, SECTORS_ERROR
    call print

disk_loop:
    jmp $

DISK_ERROR: db "Disk read error", 0x0A, 0x0D, 0
SECTORS_ERROR: db "Incorrect number of sectors read", 0