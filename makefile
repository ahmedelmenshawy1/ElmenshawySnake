all:main.c
#	gcc -E main.c -o output.i
#	gcc -S main.c -o output.asm
#	gcc -C main.c -o output.obj
	gcc -O main.c -o ElmenshawySnake.exe
	
	
preprocessor: main.c
	gcc -E main.c -o output.i


	
	
#extern var	
#all:main.c
#	gcc -E main.c -o 	output.i
#	gcc -S main.c -o 	mainOutput.asm
#	gcc -S extern.c -o externOutput.asm
#	gcc -C main.c extern.c -o output.obj
#	gcc -O main.c extern.c -o output.exe
	