#符号版本
myproc:main.o proc.o
	gcc -o $@ $^ 		 
main.o:main.c
	gcc -c $< 
proc.o:proc.c
	gcc -c $<

.PHONY:clean
clean:
	rm -f *.o myproc

# $@代表目标文件，$^代表依赖文件
# $<代表依赖关系中的一个一个的依赖文件

#完全版本
#myproc:main.o proc.o
#	gcc -o myproc main.o proc.o 
#main.o:main.c
#	gcc -c main.c 
#proc.o:proc.c
#	gcc -c proc.c
#
#.PHONY:clean
#clean:
#	rm -f *.o myproc
