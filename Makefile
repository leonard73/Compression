src:=demo.c
build:
		gcc $(src)  -o demo
clean:
		rm -rf demo
run:
		./demo
all:
		make clean
		make build
		make run