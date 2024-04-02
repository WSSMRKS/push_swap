# Directories #
SRCDIR =
HDRDIR =
OBJDIR =
LIBFTDIR = libft/
# Names #
NAME = push_swap
BONUS_NAME = checker
VISU = push_swap_visualizer
TESTER1 = 42_push_swap_tester
TESTER2 = Push-Swap-Tester
# Compiler & COptions & CFlags #
CFLAGS = -g -Werror -Wall -Wextra
TESTFLAGS = -g3
COPTIONS = -c
CC = cc
# Source Files #
SRC =			push_swap.c			push_swap_utils.c		push_swap_lst_fncts_1.c	push_swap_lst_fncts_2.c	push_swap_lst_fncts_3.c \
				push_swap_solve.c	push_swap_solve_utils_1.c	push_swap_solve_utils_2.c	push_swap_solve_utils_3.c
MAIN_SRC =
BONUS_SRC =		push_swap_bonus.c			push_swap_utils.c		push_swap_lst_fncts_1.c	push_swap_lst_fncts_2.c	push_swap_lst_fncts_3.c \
				push_swap_bonus_utils.c
TEST_SRC = test.sh
HEADERS = push_swap.h libft.h
LIBFT_SRC = libft.a
# Object Files #
SRC_OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
MAIN_OBJ = $(MAIN_SRC:.c=.o)
TEST_OBJ = $(TEST_SRC:.c=.o)
# Tester directorys #
TESTDIR1 = $(TESTER1)/
TESTDIR2 = $(TESTER2)/
VISDIR = $(VISU)/


# Targets #
all: $(NAME) bonus

fully: $(NAME) bonus tester1 tester2 visu

$(NAME): libft $(SRC_OBJ)
	$(CC) $(CFLAGS) $(SRC_OBJ) $(LIBFT_SRC) -o $(NAME)

bonus: libft $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT_SRC) -o $(BONUS_NAME)

libft:
  ifeq ("$(wildcard $(LIBFTDIR))", "")
	@echo "Directory does not exist."
#	@git submodule add git@github.com:WSSMRKS/libft.git
  else
	@echo "Skipping download because directory already exists."
	$(MAKE) all -C libft/
	@cp -rf libft/libft.h ./
	@cp -rf libft/libft.a ./
  endif

exes: $(NAME) bonus clean

ex: $(NAME) clean

ex_bonus: bonus clean

# Compile .c to .o #
%.o: %.c
	@$(CC) $(CFLAGS) $(COPTIONS) $^ -o $@

# Checkers, Testers #
CHECKER = checker_linux

dl_checker:
  ifeq ("$(wildcard $(CHECKER))", "")
	@echo "downloading provided checker_linux"
	wget https://cdn.intra.42.fr/document/document/24664/checker_linux
  else
	@echo "checker_linux already there"
  endif

rm_checker:
	@rm -rf $(CHECKER)
	@echo "provided checker_linux removed"

tester1:
  ifeq ("$(wildcard $(TESTDIR1))", "")
	@echo "cloning $(TESTER1)"
	git clone git@github.com:WSSMRKS/42_push_swap_tester.git
  else
	@echo "tester1 already cloned"
	@echo "starting $(TESTER1)"
	bash $(TESTDIR1)/test.sh
  endif

rm_tester1:
	@rm -rf $(TESTDIR1)
#	@rm -f push_swap_test_linux.sh
	@echo "$(TESTER1) removed"

tester2:
  ifeq ("$(wildcard $(TESTDIR2))", "")
	@echo "cloning $(TESTER2)"
	git clone https://github.com/gemartin99/Push-Swap-Tester.git
	cp Push-Swap-Tester/push_swap_test_linux.sh ./
  else
	@echo "running $(TESTER2) with bonus"
	bash push_swap_test_linux.sh
  endif

tester2_bonus:
  ifeq ("$(wildcard $(TESTDIR2))", "")
	@echo "cloning $(TESTER2)"
	git clone https://github.com/gemartin99/Push-Swap-Tester.git
	cp Push-Swap-Tester/push_swap_test_linux.sh ./
  else
	@echo "running $(TESTER2) for bonus"
	bash push_swap_test_linux.sh -b
  endif


rm_tester2:
	@rm -rf Push-Swap-Tester
	@rm -f push_swap_test_linux.sh
	@echo "$(TESTER2) removed"

visu:
  ifeq ("$(wildcard $(VISDIR))", "")
	@echo "visualizer not yet available"
	git clone https://github.com/o-reo/push_swap_visualizer.git
#	sudo apt-get update
#	sudo apt-get install cmake
#	sudo apt-get install g++
#	sudo apt-get install clang
#	sudo apt-get install libgl1-mesa-dev libglu1-mesa-dev
#	sudo apt-get install libx11-dev libxrandr-dev
#	sudo apt-get install libudev-dev
#	sudo apt-get install libfreetype-dev
	mkdir push_swap_visualizer/build
	cd push_swap_visualizer/build && cmake ..
	$(MAKE) -C push_swap_visualizer/build
  else
	@echo "visualizer already available"
	cd push_swap_visualizer/build/ && ./bin/visualizer
  endif

rm_visu:
	@rm -rf push_swap_visualizer
	@echo "$(VISU) removed"


clean:
	@rm -f $(SRC_OBJ)
	@rm -f $(MAIN_OBJ)
	@rm -f $(BONUS_OBJ)
	@rm -f $(TEST_OBJ)
  ifeq ("$(wildcard $(LIBFTDIR))", "")
	@echo "libft: Directory does not exist."
  else
	$(MAKE) fclean -C libft/
	@echo "libft folder cleaned"
  endif
	@rm -f libft.a
	@rm -f libft.h

fclean: clean rm_tester1 rm_tester2 rm_visu
	@rm -f $(NAME) $(MAIN_NAME) $(BONUS_NAME)
	@echo "\"$(NAME)\" deleted"

re: fclean all

name:
	@echo "$(NAME)"

help:
	@echo "Possible Commands:"
	@echo "all --> Compile whole project including bonus"
	@echo "fully --> Whole projects including testers and visualizer"
	@echo "name --> Display project name"
	@echo "bonus --> Compile bonus"
	@echo "dl_checker --> download checker_linux provided with subject"
	@echo "tester1 --> first time: git clone 42_push_swap_tester by wssmrks (me)"
	@echo "tester1 --> second time: Run 42_push_swap_tester by wssmrks (me)"
	@echo "tester2 --> first time: git clone Push-Swap-Tester by gemartin99"
	@echo "tester2 --> second time: Run Push-Swap-Tester by gemartin99"
	@echo "visu --> git clone and make push_swap_visualizer by o-reo"
	@echo "clean --> Delete all object files"
	@echo "fclean --> Delete everything besides source files"
	@echo "re --> recompile everything (fclean, all)"
	@echo "libft --> Compile libft and copy libft.h and libft.a to project folder"
	@echo "rm_tester1 --> remove 42_push_swap_tester by wssmrks (me)"
	@echo "rm_tester2 --> remove Push-Swap-Tester by gemartin99"
	@echo "rm_visu --> remove push_swap_visualizer by o-reo"
	@echo "rm_checker --> remove checker_linux provided with subject"

.PHONY: all name test test_strict run bonus debug fclean clean re help libft
