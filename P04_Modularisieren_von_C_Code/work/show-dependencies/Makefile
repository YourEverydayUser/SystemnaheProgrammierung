SNP_SHARED_MAKEFILE := $(if $(SNP_SHARED_MAKEFILE),$(SNP_SHARED_MAKEFILE),"~/snp/shared.mk")

TARGET     := bin/dep2dot
SOURCES    := src/main.c src/data.c src/output.c
TSTSOURCES := tests/tests.c

include $(SNP_SHARED_MAKEFILE)


# DEPFILES :=  ... define a list of png file names: %.c -> %.c.png
DEPFILES:= $(SOURCES:%.c=%.c.png)

# define dep target as .PHONEY
.PHONY: default
default: $(TARGET)


# define dep target depending on FULLTARGET and DEPFILES above
dep: $(SOURCES) $(DEPFILES)
	echo "### $@ finished ###"
# action: echo some text telling that the target is done using $@ - the echo command shall not be echoed before execution


# define new suffix rule for %.png depending on %.dot
# action: dot -Tpng $< >$@ || $(RM) $@

%.png: %.dot
	dot -Tpng $< >$@ || $(RM) $@

# define new suffix rule for %.dot depending on %.dep
# action: call $(TARGET) $(@:.dot=) <$< >$@ || $(RM) $@

%.dot: %.dep
	call $(TARGET) $(@:.dot=) <$< >$@ || $(RM) $@

# converts any .c file into a .c.dep file by means of GCC -H switch
# note: it removes intermediate files which were created as side effect
%.c.dep: %.c
	$(COMPILE.c) -H -o $@.x $< 2>$@ && $(RM) $@.x $@.d


# cleanup all results, including the ones od creating the dependencies
dep-clean: clean
	$(RM) $(DEPFILES) $(wildcard src/*.dep src/*.dot)

