ifeq ($(OS), Windows_NT)
	#WINDOWS USE THESE DEFINITIONS
	RM = -del /q /f
	MKDIR = mkdir
	SLASH = \\
	SWALLOW_OUTPUT = >nul 2>nul
else
	#LINUX USE THESE DEFINITIONS
	RM = -rm -f
	MKDIR = mkdir
	SLASH = /
	SWALLOW_OUTPUT =
endif 

# source files.
SRC = \
..\..\..\SourceFiles\CBucketSort.c \
..\..\..\SourceFiles\CBucketSortFactory.c

OBJ = $(SRC:.c=.o)

OUT = lib6343D68AB28A4F8FABE90F23A040FC88.a
OUT_DIR = ..\..\..\BuildFiles\K210\StaticDebug

# include directories
INCLUDES = \
-I ..\..\..\HeaderFiles \
-I ..\..\..\SharedFiles \
-I ..\..\..\..\Eco.Core1\SharedFiles \
-I ..\..\..\..\Eco.InterfaceBus1\SharedFiles \
-I ..\..\..\..\Eco.MemoryManager1\SharedFiles
 
# C++ compiler flags (-g -O2 -Wall)
CCFLAGS = -Wall -Wno-missing-braces -mcmodel=medany -mabi=lp64f -march=rv64imafc -mstrict-align -fno-tree-loop-vectorize -fno-tree-slp-vectorize -DECO_LIB -DECO_K210 -DUGUID_UTILITY
 
# compiler
ARMGNU  = $(ECO_TOOLCHAIN)/gcc-riscv64-8.2.0/bin/
CCC = $(ARMGNU)riscv64-unknown-elf-gcc
 
# library paths
LIBS = -lc -lm -lgcc
 
# compile flags
LDFLAGS = -g
 
.SUFFIXES: .c

all: $(OUT)

.c.o:
	$(CCC) $(INCLUDES) $(CCFLAGS) -c $< -o $@
 
$(OUT): $(OBJ)
	if not exist $(OUT_DIR) $(MKDIR) $(OUT_DIR)
	$(ARMGNU)riscv64-unknown-elf-ar rcs $(OUT_DIR)\$(OUT) $(OBJ)
	$(RM) $(OBJ)

clean:
	$(RM) $(OBJ) $(OUT_DIR)\$(OUT)