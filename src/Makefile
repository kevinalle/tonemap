GCC = gcc

all: fuse gui

fuse: fuse.o cExpofuse.o asmExpofuse.o asmMatrix.o cMatrix.o
	$(GCC) $^ -Wall -O0 -o $@ -lopencv_core -lopencv_imgproc -lopencv_highgui

fuse_no_asm: fuse.o cExpofuse_no_asm.o cMatrix_no_asm.o
	$(GCC) $^ -Wall -O0 -o $@ -lopencv_core -lopencv_imgproc -lopencv_highgui

gui: gui.o cExpofuse.o asmExpofuse.o asmMatrix.o cMatrix.o
	$(GCC) $^ -Wall -O3 -o $@ `pkg-config --cflags --libs gtk+-2.0` -lopencv_core -lopencv_imgproc -lopencv_highgui

test: test.c cExpofuse.o asmExpofuse.o asmMatrix.o cMatrix.o
	$(GCC) -c test.c -o test.o
	$(GCC) $^ -o test -lopencv_core -lopencv_imgproc -lopencv_highgui

gui.o: gui.c expofuse.h
	$(GCC) -O3 -Wall -c $< -o $@ -lpthread `pkg-config --cflags gtk+-2.0`

fuse.o: fuse.c expofuse.h Matrix.h
	$(GCC) -O0 -Wall -c $< -o $@

cExpofuse.o: expofuse.c Matrix.h asmExpofuse.o
	$(GCC) -Wall -O0 -c $< -o $@ `pkg-config --cflags opencv`

cExpofuse_no_asm.o: expofuse.c Matrix.h
	$(GCC) -Wall -O0 -c $< -o $@ -D NO_ASM `pkg-config --cflags opencv`

asmExpofuse.o: expofuse.asm
	nasm -felf64 -o $@ $<

cMatrix.o: Matrix.c Matrix.h
	$(GCC) -O2 -Wall -c $< -o $@

cMatrix_no_asm.o: Matrix.c Matrix.h
	$(GCC) -O2 -Wall -c $< -o $@ -D NO_ASM

asmMatrix.o: Matrix.asm
	nasm -felf64 -O3 -o $@ $<

clean:
	rm -rf *.o gui fuse test
