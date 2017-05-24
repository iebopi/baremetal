all : start.o main.o led.o timer.o
	arm-linux-gnueabihf-ld -Tled.lds -o led.elf $^
	arm-linux-gnueabihf-objcopy -O binary led.elf led.bin

%.o : %.S
	arm-linux-gnueabihf-gcc -g -c $^
	
%.o : %.c
	arm-linux-gnueabihf-gcc -g -c $^

.PHONY:clean
clean :
	rm *.o *.elf *.bin

