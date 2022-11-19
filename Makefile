user_test: main.c
	gcc -g -o $@ $^
clean:
	rm user_test
