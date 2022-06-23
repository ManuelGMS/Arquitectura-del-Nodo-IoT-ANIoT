//******************************************************************************
//**** PRACTICA 3 (CONTINUACION) ANIOT
//**** 
//******************************************************************************

#define NUM_READS 20

// Lecturas tomadas
static const int tab_distance[NUM_READS] = {9999, 1000, 900, 700, 600, 500, 400,  350,  300,  250,  240,  220,  200,  150,  140,  130,  120,  110,  0};
static const int tab_adc[NUM_READS] =      {0,    200,  270, 360, 600, 750, 1030, 1200, 1500, 1900, 1970, 2230, 2300, 3250, 3410, 3830, 4000, 4095, 4095};


int get_ir_distance(int adc_read);
