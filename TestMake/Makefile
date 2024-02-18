
##############################################

PATH_OUT = Out

include ./User/MakeConfig.mak

INC_FILES := $(foreach INC_DIRS,$(INC_DIRS),-I$(wildcard $(INC_DIRS)))
SRC_FILES := $(foreach SRC_DIRS,$(SRC_DIRS),$(wildcard $(SRC_DIRS)/*))

#INC_FILES := $(wildcard $(INC_DIRS)/*) 
#FILE_NAME := $(notdir $(INC_FILES))

OBJ_FILES := $(notdir $(SRC_FILES))
OBJ_FILES := $(subst .c,.o,$(OBJ_FILES))
OBJ_FILES := $(foreach OBJ_FILES,$(OBJ_FILES),$(PATH_OUT)/$(OBJ_FILES))

vpath %.c $(SRC_DIRS)

$(PATH_OUT)/%.o:%.c
	gcc -c $(INC_FILES) $^ -o $@


#################################################################################################
# $(PATH_OUT)/sum.o:sum.c
	# gcc -E $(INC_FILES) Driver/SUM/src/sum.c -o $(PATH_OUT)/sum.i
	# gcc -S $(PATH_OUT)/sum.i -o $(PATH_OUT)/sum.s
	# as $(PATH_OUT)/sum.s -o $(PATH_OUT)/sum.o

# $(PATH_OUT)/SUBTRACTION.o:SUBTRACTION.c 
	# gcc -E $(INC_FILES) Driver/SUBTRACTION/src/SUBTRACTION.c -o $(PATH_OUT)/SUBTRACTION.i
	# gcc -S $(PATH_OUT)/SUBTRACTION.i -o $(PATH_OUT)/SUBTRACTION.s 
	# as $(PATH_OUT)/SUBTRACTION.s -o $(PATH_OUT)/SUBTRACTION.o 

# $(PATH_OUT)/main.o:main.c
	# gcc -E $(INC_FILES) User/Src/main.c -o $(PATH_OUT)/main.i
	# gcc -S $(PATH_OUT)/main.i -o $(PATH_OUT)/main.s 
	# as $(PATH_OUT)/main.s -o $(PATH_OUT)/main.o 
#################################################################################################

# .PHONY: build
# build:$(PATH_OUT)/main.o $(PATH_OUT)/sum.o $(PATH_OUT)/SUBTRACTION.o
	# gcc $^ -o $(PATH_OUT)/main.exe

$(PATH_OUT)/main.exe:$(OBJ_FILES)
	gcc $^ -o $@

.PHONY: build
build:$(PATH_OUT)/main.exe

print-%:
	@echo $($(subst print-,,$@))

.PHONY: run
run: 
	$(PATH_OUT)/main.exe
clean:
	rm ./Out/*

############################################
#all:
	#@gcc -E main.c -o main.i
	#@gcc -S main.i -o main.s
	#@as main.s -o main.o
	
	#@gcc -E sum.c -o sum.i
	#@gcc -S sum.i -o sum.s 
	#@as sum.s -o sum.o
	
	#@gcc -v -o main main.o sum.o
#run:
	#main.exe