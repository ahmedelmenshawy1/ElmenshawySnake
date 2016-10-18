all:main.c
	gcc -O main.c -o ElmenshawySnake.exe
	
	
preprocessor: main.c
	gcc -E main.c -o output.i
