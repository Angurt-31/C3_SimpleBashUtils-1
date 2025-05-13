SHELL :=  /bin/bash
FLAG = -Wall -Wextra -Werror
FILE = *.txt
CHECK = 2>&1 valgrind --tool=memcheck --leak-check=yes --leak-check=full --show-leak-kinds=all

all: s21_grep tests

s21_grep: s21_grep.h s21_grep.c
	gcc $(FLAG) s21_grep.c -o s21_grep -lpcre

rebuild:
	make clean
	make s21_grep

tests:
	#-diff <(./s21_grep test $(FILE)) <(grep test $(FILE))
	#-diff <(./s21_grep -e test $(FILE)) <(grep -e test $(FILE))
	#-diff <(./s21_grep -v $(FILE)) <(grep -v $(FILE))
	#-diff <(./s21_grep -i test $(FILE)) <(grep -i test $(FILE))
	#-diff <(./s21_grep -c test $(FILE)) <(grep -c test $(FILE))
	#-diff <(./s21_grep -l test $(FILE)) <(grep -l test $(FILE))
	#-diff <(./s21_grep -n test $(FILE)) <(grep -n test $(FILE))
	#-diff <(./s21_grep -s test $(FILE)) <(grep -s test $(FILE))
	#-diff <(./s21_grep -o test $(FILE)) <(grep -o test $(FILE))
	#-diff <(./s21_grep -h test $(FILE)) <(grep -h test $(FILE))
	#-diff <(./s21_grep -iv test $(FILE)) <(grep -iv test $(FILE))
	#-diff <(./s21_grep -in test $(FILE)) <(grep -in test $(FILE))
	#-diff <(./s21_grep -ie "^tes" $(FILE)) <(grep -ie "^tes" $(FILE))
	#-diff <(./s21_grep -ince "^te" $(FILE)) <(grep -ince "^te" $(FILE))
	#-diff <(./s21_grep -lh test $(FILE)) <(grep -lh test $(FILE))
	#-diff <(./s21_grep -e test -e for $(FILE)) <(grep -e test -e for $(FILE))
	#-diff <(./s21_grep -f for_F.txt $(FILE)) <(grep -f for_F.txt $(FILE))
	#-diff <(./s21_grep -oh test $(FILE)) <(grep -oh tesst $(FILE))
	#-diff <(./s21_grep -oinc for $(FILE)) <(grep -oinc for $(FILE))
	#-diff <(./s21_grep -oc for $(FILE)) <(grep -oc for $(FILE))
	#-diff <(./s21_grep -iv for $(FILE)) <(grep -iv for $(FILE))
	#-diff <(./s21_grep -oi for $(FILE)) <(grep -oi for $(FILE))
	#-diff <(./s21_grep -ocl test $(FILE)) <(grep -ocl test $(FILE))
	#-diff <(./s21_grep -oihln -e test -e for -f pattern.reg $(FILE)) <(grep -oihln -e test -e for -f pattern.reg $(FILE))


clean:
	rm -rf *.o
