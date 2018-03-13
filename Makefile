SUBDIRS      =	src

all:
	@echo "## MAKE ALL ##"
	@for i in $(SUBDIRS); \
	do ($(MAKE) $(MFLAGS) -C $$i all) || exit 1;done

clean:
	@echo "## MAKE CLEAN ##"
	@for i in $(SUBDIRS); \
	do ($(MAKE) $(MFLAGS) -C $$i clean) || exit 1;done
