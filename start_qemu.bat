echo "Will running on qemu, ctl-A X to exit qemu process"

:: This command for MINI-UART
:: qemu-system-aarch64 -M raspi3b -smp 4 -serial null -serial mon:stdio -nographic -kernel kernel-qemu.img

:: This command for UART
qemu-system-aarch64 -M raspi3b -smp 4 -nographic -kernel kernel-qemu.img

:: This command for Monitor
:: qemu-system-aarch64 -M raspi3b -m 1G -nographic -no-reboot -kernel kernel-qemu.img -monitor telnet:127.0.0.1:1235,server,nowait -serial stdio