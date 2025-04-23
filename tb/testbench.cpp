#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>
#include "Vtcpip_top.h"
#include "verilated_vcd_c.h"

#define MAX_SIM_CYCLE       1000000
#define SYS_CLOCK_PERIOD    2                // 450MHZ, which should be 2.222, we use 2
#define PHY_CLOCK_PERIOD    40               // 25MHZ, MII 100M use 25MHZ

uint64_t main_time = 0;

uint64_t sim_main_time_now() {
    return main_time;
}

void one_cycle(Vtcpip_top *top, VerilatedVcdC *tfp) {
    static uint64_t last_phy_toggle_time = 0;

    top->i_sys_clk = 0;
    top->eval();
    main_time += SYS_CLOCK_PERIOD / 2;
    tfp->dump(main_time);

    top->i_sys_clk = 1;
    top->eval();
    main_time += SYS_CLOCK_PERIOD / 2;
    tfp->dump(main_time);

    if (main_time - last_phy_toggle_time >= PHY_CLOCK_PERIOD / 2) {                     // everytime main_time minus last i_rx_clk is greater or equal PHY_CLOCK_PEIOD, clock changes
        top->i_mii_tx_clk = !top->i_mii_tx_clk;
        top->i_mii_rx_clk = !top->i_mii_rx_clk;
        last_phy_toggle_time = main_time;
    }
}

int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    
    Vtcpip_top *top = new Vtcpip_top;
    VerilatedVcdC *tfp = new VerilatedVcdC;
    top->trace(tfp, 0);
    tfp->open("wave.vcd");

    // initial
    top->i_rstn = 0;
    for (int i = 0; i < 15; i++) {
        one_cycle(top, tfp);
    }
    top->i_rstn = 1;

    // start
    for (int i = 0; i <= MAX_SIM_CYCLE; i++){
            one_cycle(top, tfp);
    }
    printf("Test done!\n");

    tfp->flush();
    tfp->close();
    delete top;
    delete tfp;
    return 0;
}