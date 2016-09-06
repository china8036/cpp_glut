cc = g++
so = /usr/lib/x86_64-linux-gnu/mesa/libGL.so /usr/lib/x86_64-linux-gnu/libGLU.so /usr/lib/x86_64-linux-gnu/libglut.so
o = main.o key.o
target = main

${target}:$o
	${cc}  -o $@ $^ ${so} 
.cpp.o: 
	${cc} -Wall -g -c $<	
clear:
	rm -rf *.o
