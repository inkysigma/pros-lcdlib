# Universal C Makefile for MCU targets

# Path to project root (for top-level, so the project is in ./; first-level, ../; etc.)
ROOT=.
# Binary output directory
BINDIR=$(ROOT)/bin
SUBBIN=
LIBDIR=$(ROOT)/lib
LIBS=lcd
# Subdirectories to include in the build
SUBDIRS=src
LCDLIB=$(BINDIR)/lcd/lcdlib.o

# Nothing below here needs to be modified by typical users

# Include common aspects of this project
-include $(ROOT)/common.mk

ASMSRC:=$(wildcard *.$(ASMEXT))
ASMOBJ:=$(patsubst %.o,$(BINDIR)/%.o,$(ASMSRC:.$(ASMEXT)=.o))
HEADERS:=$(wildcard *.$(HEXT))
CSRC=$(wildcard *.$(CEXT))
COBJ:=$(patsubst %.o,$(BINDIR)/%.o,$(CSRC:.$(CEXT)=.o))
CPPSRC:=$(wildcard *.$(CPPEXT))
CPPOBJ:=$(patsubst %.o,$(BINDIR)/%.o,$(CPPSRC:.$(CPPEXT)=.o))
OUT:=$(BINDIR)/$(OUTNAME)

.PHONY: all clean upload _force_look

# By default, compile program
all: $(BINDIR) $(OUT)

# Remove all intermediate object files (remove the binary directory)
clean:
	-rm -f $(OUT)
	-rm -rf $(BINDIR)

# Uploads program to device
upload: all
	$(UPLOAD)

# Phony force-look target
_force_look:
	@true

# Looks in subdirectories for things to make
$(SUBDIRS): %: _force_look
	@$(MAKE) --no-print-directory -C $@

# Ensure binary directory exists
$(BINDIR):
	-@mkdir -p $(BINDIR)

# Compile program
$(OUT): $(SUBDIRS) $(ASMOBJ) $(COBJ) $(CPPOBJ) $(LIBS)
	@echo LN $(BINDIR)/*.o $(SUBBIN) $(LIBRARIES) $(LIBS)/$(LIBS).a to $@
	@echo Building final output
	@$(CC) $(LDFLAGS) $(BINDIR)/*.o $(SUBBIN) $(LIBRARIES) $(BINDIR)/$(LIBS)/lib$(LIBS).a -o $@
	@$(MCUPREFIX)size $(SIZEFLAGS) $(OUT)
	$(MCUPREPARE)

$(LIBS): %: _force_look
	@$(MAKE) --no-print-directory -C $(LIBDIR)/$@

# Assembly source file management
$(ASMOBJ): $(BINDIR)/%.o: %.$(ASMEXT) $(HEADERS)
	@echo AS $<
	@$(AS) $(AFLAGS) -o $@ $<

# Object management
$(COBJ): $(BINDIR)/%.o: %.$(CEXT) $(HEADERS)
	@echo CC $(INCLUDE) $<
	$(CC) $(INCLUDE) $(CFLAGS) -o $@ $<

$(CPPOBJ): $(BINDIR)/%.o: %.$(CPPEXT) $(HEADERS)
	@echo CPC $(INCLUDE) $<
	@$(CPPCC) $(INCLUDE) $(CPPFLAGS) -o $@ $<
