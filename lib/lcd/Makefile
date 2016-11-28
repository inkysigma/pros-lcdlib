ROOT=../..

LIBNAME=liblcd

BINDIR=$(ROOT)/bin/lcd

-include common.mk

ASMSRC:=$(wildcard *.$(ASMEXT))
ASMOBJ:=$(patsubst %.o,$(BINDIR)/%.o,$(ASMSRC:.$(ASMEXT)=.o))
HEADERS:=$(wildcard *.$(HEXT))
### Special section for Cortex projects ###
HEADERS_2:=$(wildcard ../include/*.$(HEXT))
### End special section ###
CSRC=$(wildcard *.$(CEXT))
COBJ:=$(patsubst %.o,$(BINDIR)/%.o,$(CSRC:.$(CEXT)=.o))
CPPSRC:=$(wildcard *.$(CPPEXT))
CPPOBJ:=$(patsubst %.o,$(BINDIR)/%.o,$(CPPSRC:.$(CPPEXT)=.o))
OUT:=$(BINDIR)/$(LIBNAME)

API=$(INCLUDE)

.PHONY: all

# By default, compile program
all: $(BINDIR) .
	@echo Finished building LCD library

# Compiles the program if anything is changed
.: $(ASMOBJ) $(COBJ) $(CPPOBJ)
	@touch .
	@$(AR) rs $(BINDIR)/$(LIBNAME).a $(BINDIR)/*.o

# Assembly source file management
$(ASMOBJ): $(BINDIR)/%.o: %.$(ASMEXT)
	@echo AS $<
	@$(AS) $(AFLAGS) -o $@ $<

### Special section for Cortex projects ###

# Object management
$(COBJ): $(BINDIR)/%.o: %.$(CEXT) $(HEADERS) $(HEADERS_2)
	@echo CC $(API) $<
	@$(CC) $(API) $(CFLAGS) -o $@ $<

$(CPPOBJ): $(BINDIR)/%.o: %.$(CPPEXT) $(HEADERS) $(HEADERS_2)
	@echo CPC $(API) $<
	@$(CPPCC) $(API) $(CPPFLAGS) -o $@ $<

### End special section ###

$(BINDIR):
	@echo Started building LCD library
	-@mkdir -p $(BINDIR)
