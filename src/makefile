list.o : list_string.c list_string.h
	clang -Wall -Wextra -pedantic -O0 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls -c list_string.c
tableau.o : tableau.c tableau.h list_string.h
	clang -Wall -Wextra -pedantic -O0 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls -c tableau.c
dico.o : dico.h dico.c tableau.h list_string.h
	clang -Wall -Wextra -pedantic -O0 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls -c dico.c
test_dico.o : test_dico.c dico.h list_string.h tableau.h
	clang -Wall -Wextra -pedantic -O0 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls -c test_dico.c
list_char.o : list_char.c list_char.h
	clang -Wall -Wextra -pedantic -O0 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls -c list_char.c
list_char_test.o : list_char_test.c list_char.c list_char.h
	clang -Wall -Wextra -pedantic -O0 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls -c list_char_test.c
	clang -Wall -Wextra -pedantic -O0 -g3 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls  list_char_test.o -o list_char_test
wsolf.o : wsolf.c wsolf.h
	clang -Wall -Wextra -pedantic -O0 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls -c wsolf.c
wsolf_test.o: wsolf_test.c wsolf.h
	clang -Wall -Wextra -pedantic -O0 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls -c wsolf_test.c
wsolf_test : wsolf_test.o wsolf.o
	clang -Wall -Wextra -pedantic -O0 -g3 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls  wsolf_test.o wsolf.o -o wsolf_test
test_dico : test_dico.o dico.o list_string.o tableau.o
	clang -Wall -Wextra -pedantic -O0 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls dico.o test_dico.o list_string.o tableau.o -o test_dico
propose_word.o : propose_word.c propose_word.h
	clang -Wall -Wextra -pedantic -O0 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls -c propose_word.c
propose_word_test.o: propose_word.h propose_word_test.c
	clang -Wall -Wextra -pedantic -O0 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls -c propose_word_test.c
propose_word_test : propose_word.o propose_word_test.o list_char.o list_string.o
	clang -Wall -Wextra -pedantic -O0 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls propose_word.o propose_word_test.o list_string.o list_char.o -o propose_word_test
terminal.o : tableau.h dico.h terminal.c 
	clang -Wall -Wextra -pedantic -O0 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls -c terminal.c
terminal : list.o tableau.o dico.o list_char.o wsolf.o terminal.o propose_word.o
	clang -Wall -Wextra -pedantic -O0 -g3 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls list_string.o tableau.o dico.o list_char.o wsolf.o propose_word.o terminal.o -o terminal
clean :
	@rm -rf list.o tableau.o dico.o test_dico.o test_dico list_string.o list_char.o list_char_test.o wsolf.o terminal terminal.o wsolf_test wsolf_test.o terminal terminal.o propose_word.o propose_word_test.o propose_word_test