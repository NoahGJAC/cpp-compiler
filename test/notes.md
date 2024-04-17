## Steps for the setup
Install WSL, and a distribution (Ubuntu-22.04)
	Following these steps:  
		- https://learn.microsoft.com/en-us/windows/wsl/install-manual#step-4---download-the-linux-kernel-update-package  
		- https://code.visualstudio.com/docs/remote/wsl  
		- https://learn.microsoft.com/en-us/windows/wsl/install  

## Playing around with assembly  

Create a test.asm file  

After installing NASM in the Linux environment  

	run $ nasm -felf64.test.asm  

open new test.o object file with hex editor in vs code  

Now, use ld linker to link the object file with the output to test  

	run $ ld test.o -o test  

The linker will output a ./test executable file. You can directly run the file  

	run $ ./test  

In my case, the file simply exits with an error code, we can test that it works with  

	run $ echo $?
