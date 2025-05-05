#==============================================================================#
#                                  MAKE CONFIG                                 #
#==============================================================================#

MAKE	= make -C
SHELL	:= bash

#==============================================================================#
#                                     NAMES                                    #
#==============================================================================#

NAME			= Fixed

###	Message Vars
_NAME			= [$(MAG)cpp$(D)]
_SUCCESS		= [$(GRN)Great Success!$(D)]
_INFO			= [$(BLU)INFO$(D)]
_SEP			= ======================

#==============================================================================#
#                                    PATHS                                     #
#==============================================================================#

SRC_PATH		= .
BUILD_PATH		= .build
TEMP_PATH		= .temp

### Files Source
FILES = main.cpp
FILES += Fixed.cpp

### Paths
SRC		= $(addprefix $(SRC_PATH)/, $(FILES))

# OBJS	= $(SRC:$(SRC_PATH)/%.cpp=%$(BUILD_PATH)/%.o)
OBJS = $(addprefix $(BUILD_PATH)/, $(FILES:.cpp=.o))

#==============================================================================#
#                              COMPILER & FLAGS                                #
#==============================================================================#

CXX				= c++
CXXFLAGS		= -std=c++98
CFLAGS			= -Wall -Wextra -Werror -g

#==============================================================================#
#                                COMMANDS                                      #
#==============================================================================#

RM		= rm -rf
AR		= ar rcs
MKDIR_P = mkdir -p

#==============================================================================#
#                                  RULES                                       #
#==============================================================================#

all: $(BUILD_PATH) $(NAME)

$(NAME): $(BUILD_PATH) $(OBJS)
	@echo "$(YEL)Compiling $(MAG)$(NAME)$(YEL) mandatory version$(D)"
	$(CXX) $(CXXFLAGS) $(CFLAGS) $(OBJS) $(INC) -o $(NAME)
	@echo "[$(_SUCCESS) compiling $(MAG)$(NAME)$(D) $(YEL);D$(D)]"
	@make --no-print-directory

-include $(BUILD_PATH)/%.d

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.cpp
	@echo -n "$(MAG)X$(D)"
	$(CXX) $(CXXFLAGS) -MMD -MP -c -g $< -o $@

$(BUILD_PATH):
	$(MKDIR_P) $(BUILD_PATH)
	@echo "* $(YEL)Creating $(CYA)$(BUILD_PATH)$(YEL) folder:$(D) $(_SUCCESS)"

$(TEMP_PATH):
	$(MKDIR_P) $(TEMP_PATH)
	@echo "* $(YEL)Creating $(CYA)$(TEMP_PATH)$(YEL) folder:$(D) $(_SUCCESS)"

##@ Test Rules 🧪

##@ Debug Rules 

debug: CXX = g++
debug: CXXFLAGS += -D DEBUG
debug: fclean all

gdb: all $(NAME) $(TEMP_PATH)			## Debug w/ gdb
	tmux split-window -h "gdb --tui --args ./$(NAME)"
	tmux resize-pane -L 5
	# tmux split-window -v "btop"
	make get_log

vgdb: all $(NAME) $(TEMP_PATH)			## Debug w/ valgrind (memcheck) & gdb
	tmux split-window -h "valgrind $(VGDB_ARGS) --log-file=gdb.txt ./$(NAME) $(ARG)"
	make vgdb_cmd
	tmux split-window -v "gdb --tui -x $(TEMP_PATH)/gdb_commands.txt $(NAME)"
	tmux resize-pane -U 18
	# tmux split-window -v "btop"
	make get_log

valgrind: all $(NAME) $(TEMP_PATH)			## Debug w/ valgrind (memcheck)
	tmux set-option remain-on-exit on
	tmux split-window -h "valgrind $(VAL_ARGS) $(VAL_LEAK) ./$(NAME) $(ARG)"

##@ Clean-up Rules 󰃢

clean: 				## Remove object files
	@echo "*** $(YEL)Removing $(MAG)$(NAME)$(D) and deps $(YEL)object files$(D)"
	@if [ -d "$(BUILD_PATH)" ] || [ -d "$(TEMP_PATH)" ]; then \
		if [ -d "$(BUILD_PATH)" ]; then \
			$(RM) $(BUILD_PATH); \
			echo "* $(YEL)Removing $(CYA)$(BUILD_PATH)$(D) folder & files$(D): $(_SUCCESS)"; \
		fi; \
		if [ -d "$(TEMP_PATH)" ]; then \
			$(RM) $(TEMP_PATH); \
			echo "* $(YEL)Removing $(CYA)$(TEMP_PATH)$(D) folder & files:$(D) $(_SUCCESS)"; \
		fi; \
	else \
		echo " $(RED)$(D) [$(GRN)Nothing to clean!$(D)]"; \
	fi

fclean: clean			## Remove executable and .gdbinit
	@if [ -f "$(NAME)" ]; then \
		if [ -f "$(NAME)" ]; then \
			$(RM) $(NAME); \
			echo "* $(YEL)Removing $(CYA)$(NAME)$(D) file: $(_SUCCESS)"; \
		fi; \
	else \
		echo " $(RED)$(D) [$(GRN)Nothing to be fcleaned!$(D)]"; \
	fi

re: fclean all	## Purge & Recompile

##@ Help 󰛵

help: 			## Display this help page
	@awk 'BEGIN {FS = ":.*##"; \
			printf "\n=> Usage:\n\tmake $(GRN)<target>$(D)\n"} \
		/^[a-zA-Z_0-9-]+:.*?##/ { \
			printf "\t$(GRN)%-18s$(D) %s\n", $$1, $$2 } \
		/^##@/ { \
			printf "\n=> %s\n", substr($$0, 5) } ' Makefile
## Tweaked from source:
### https://www.padok.fr/en/blog/beautiful-makefile-awk

.PHONY: bonus clean fclean re help

#==============================================================================#
#                                  UTILS                                       #
#==============================================================================#

# Colors
#
# Run the following command to get list of available colors
# bash -c 'for c in {0..255}; do tput setaf $c; tput setaf $c | cat -v; echo =$c; done'
#
B  		= $(shell tput bold)
BLA		= $(shell tput setaf 0)
RED		= $(shell tput setaf 1)
GRN		= $(shell tput setaf 2)
YEL		= $(shell tput setaf 3)
BLU		= $(shell tput setaf 4)
MAG		= $(shell tput setaf 5)
CYA		= $(shell tput setaf 6)
WHI		= $(shell tput setaf 7)
GRE		= $(shell tput setaf 8)
BRED 	= $(shell tput setaf 9)
BGRN	= $(shell tput setaf 10)
BYEL	= $(shell tput setaf 11)
BBLU	= $(shell tput setaf 12)
BMAG	= $(shell tput setaf 13)
BCYA	= $(shell tput setaf 14)
BWHI	= $(shell tput setaf 15)
D 		= $(shell tput sgr0)
BEL 	= $(shell tput bel)
CLR 	= $(shell tput el 1)
