all: perimeter.c main.c
		gcc -o perimeter perimeter.c main.c

clean:
		rm -rf perimeter
		rm -rf test

test:
		gcc -o test perimeter.c tests/test.c
