TCPIP = tcpip_top
GTKWAVE = gtkwave

V_SRC = $(wildcard ./rtl/tcpip_top.v)
V_SRC += $(wildcard ./rtl/modules/*.v)

TESTBENCH_SRC = $(wildcard ./tb/*.cpp)
HEX_FILES = $(wildcard ./tb/*.hex)

INC = -I./rtl

.DEFAULT_GOAL := all
all: run

obj_dir/V${TCPIP}.mk: ${V_SRC} ${TESTBENCH_SRC}
	verilator -Wall --cc --exe ${TESTBENCH_SRC} ${INC} ${V_SRC} --trace --public --Wno-UNUSED --Wno-UNOPTFLAT

obj_dir/V${TCPIP}.exe: obj_dir/V${TCPIP}.mk
	$(MAKE) -C obj_dir -f V${TCPIP}.mk

.PHONY: run
run: obj_dir/V${TCPIP}.exe
	cp ${HEX_FILES} obj_dir/  
	cd obj_dir && ./Vtcpip_top

.PHONY: wave
wave: 
	${GTKWAVE} ./obj_dir/wave.vcd

.PHONY: clean
clean:
	rm -rf obj_dir wave.vcd