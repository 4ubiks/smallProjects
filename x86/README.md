# x86 files

## reverse.s
RUNNING IN GDB:
```
  gdb ./reverse
	break _start
	run

	layout asm
	stepi
```
compilation steps in makefile

## encrypt.s
take your github token, split into 4 parts of 9 characters. sect order should be U->B->I->K. 
compile, and the output will be your github token
