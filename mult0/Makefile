#!/usr/bin/make -f
#
# This file was automatically generated by makemakefile on Fri Sep  5 09:49:49 2008
#

BSC=bsc
BSCFLAGS=-keep-fires -cross-info
SUFFIXES=

TOPMOD = mkMult0
TOPFILE = Mult0.bsv
TOPPACK = $(basename $(TOPFILE))
SIMULATOR = bluesim

FILENAME = .lastmakesim

SRCS = *.bsv
LASTSIM := $(shell cat $(FILENAME) 2>/dev/null)

ifdef SIM
SIMULATOR := $(SIM)
endif

# This means that there is a new sim type, force an update
ifneq ($(LASTSIM), $(SIM))
.PHONY:	$(TOPPACK).bo
endif

# An override on the Make commandline, remember this
ifdef SIM
FILECMD = @echo $(SIM) > $(FILENAME)
else
FILECMD = $(shell rm $(FILENAME)  2>/dev/null)
endif

# Bluesim and Verilog simulators use two very different bsc calls
ifeq ($(SIMULATOR),bluesim)
CMD1 =	$(BSC) $(BSCFLAGS) -sim -g $(TOPMOD) -u $(TOPFILE)
CMD2 =	$(BSC) $(BSCFLAGS) -sim -o $@  -e $(TOPMOD)  $(TOPMOD).ba
else
CMD1 =	$(BSC) $(BSCFLAGS) -u -verilog -g $(TOPMOD) $(TOPFILE)
CMD2 =	$(BSC) $(BSCFLAGS) -verilog -vsim $(SIMULATOR) -e $(TOPMOD) -o $@ $(TOPMOD).v
endif

.PHONY: help
help:
	@echo "Possible targets:"
	@echo "  build         --  compile $(TOPFILE) for the default simulator ($(SIMULATOR))"
	@echo "  link          --  Link compiled files for default simulator ($(SIMULATOR))"
	@echo "  run           --  build, link, and simulate using default ($(SIMULATOR)) simulator"
	@echo "  clean         --  remove binary, executable and temporary files"
	@echo "  help          --  display this message"
	@echo " override the default simulator: make build SIM=iverilog"

# ----------------------------------------------------------------
# Executing with Bluesim simulation

.PHONY: build
build:	$(TOPPACK).bo

# compile and link the whole system
$(TOPPACK).bo: $(SRCS) Makefile 
	$(FILECMD)
	$(CMD1)

.PHONY: link
link:	$(TOPMOD)

$(TOPMOD): $(TOPPACK).bo
	$(CMD2)

# run (simulate) the system
run:	$(TOPMOD)
ifeq ($(SIMULATOR), bluesim)
	./$(TOPMOD) -m 1500
else
	./$(TOPMOD) +bscvcd +bsccycle 
endif

.PHONY: clean
clean:
	rm -f  *.bi *.bo *.ba *.info *.sched *.c *.h *.o *.so  mk*.v  *~ $(TOPMOD) v95/* >/dev/null
