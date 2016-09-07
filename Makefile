cc = g++
path = $(shell pwd)
sopath_file = /etc/ld.so.conf.d/glut.conf
so = /usr/lib/x86_64-linux-gnu/mesa/libGL.so /usr/lib/x86_64-linux-gnu/libGLU.so /usr/lib/x86_64-linux-gnu/libglut.so
o = main.cpp libkey.so
target = main

${target}:$o
	${cc}  -o $@ main.cpp -lkey -L ${path} ${so} 
libkey.so: 
	${cc} -shared -fPIC -c key.cc -o libkey.so
install:
	rm -rf ${sopath_file}
	sudo echo "${path}" |cat >>${sopath_file}
	ldconfig	
clear:
	rm -rf *.o *.so
