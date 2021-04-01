all: mt page_size memory-layout broken_program bugged_program bugged_program2

mt: mt.c
	gcc mt.c -Wall -o mt

page_size: page_size.c
	gcc page_size.c -Wall -o page_size

memory-layout: memory-layout.c
	gcc memory-layout.c -Wall -o memory-layout

broken_program: broken_program.c
	gcc broken_program.c -Wall -o broken_program

bugged_program: bugged_program.c
	gcc bugged_program.c -Wall -fno-stack-protector -o bugged_program

bugged_program2: bugged_program2.c
	gcc bugged_program2.c -Wall -fno-stack-protector -o bugged_program2


clean: 
	rm mt page_size memory-layout broken_program bugged_program bugged_program2